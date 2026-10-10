#!/usr/bin/env python3

###
# Compiles a source file with every mwccarm version in tools/mwccarm/ and reports, for each function,
# how well it matches the original code (objdiff match percentage).
# Used to identify the compiler version and flags of the game.
#
# Functions must be declared `extern "C"` and named after the original symbol (e.g. func_ov122_0206d978),
# so that objdiff can pair them with the delinked code.
#
# Usage (inside the container, after `ninja`):
#   python tools/probe_compilers.py build/probe/test.cpp
#   python tools/probe_compilers.py build/probe/test.cpp --versions 2.0/sp1p5 2.0/sp2 --extra-flags "-O4,s"
###

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

root_path = Path(__file__).resolve().parent.parent
mwcc_root = root_path / "tools" / "mwccarm"

# Keep in sync with CC_FLAGS in tools/configure.py
DEFAULT_FLAGS = [
    "-O4,p", "-enum min", "-char signed", "-str noreuse", "-proc arm946e", "-gccext,on", "-fp soft", "-inline noauto",
    "-lang=c++", "-Cpp_exceptions off", "-RTTI off", "-interworking", "-w off", "-sym on", "-gccinc", "-nolink",
    "-msgstyle gcc",
]

parser = argparse.ArgumentParser(description="Finds which compiler versions match the given functions")
parser.add_argument("source", type=Path, help="C/C++ file with extern \"C\" functions named after original symbols")
parser.add_argument("--game-version", default="usa", help="Game version whose delinked objects are compared")
parser.add_argument("--versions", nargs="*", help="Compiler versions to test (default: all under tools/mwccarm/)")
parser.add_argument("--extra-flags", default="", help="Extra compiler flags appended to the defaults")
args = parser.parse_args()

delinks_path = root_path / "build" / args.game_version / "delinks"


def compiler_versions() -> list[str]:
    if args.versions:
        return args.versions
    return sorted(
        str(exe.parent.relative_to(mwcc_root))
        for exe in mwcc_root.glob("*/*/mwccarm.exe")
    )


def function_names(source: Path) -> list[str]:
    return re.findall(r'\b(func_(?:ov\d{3}_)?[0-9a-f]{8})\s*\(', source.read_text())


def target_object(symbol: str) -> Path:
    m = re.match(r"func_(ov\d{3})_", symbol)
    module = m.group(1) if m else "main"
    candidates = sorted(delinks_path.glob(f"*{module}*.o"))
    if len(candidates) == 0:
        sys.exit(f"No delinked object found for {symbol} in {delinks_path}, run `ninja` first")
    for candidate in candidates:
        out = subprocess.run(["nm", candidate], capture_output=True, text=True)
        if re.search(rf"\b{symbol}$", out.stdout, re.M):
            return candidate
    sys.exit(f"{symbol} not found in {[c.name for c in candidates]}")


def compile(version: str, source: Path, out: Path) -> str | None:
    cc = mwcc_root / version / "mwccarm.exe"
    cmd = ["./wibo", "./sjiswrap.exe", str(cc.relative_to(root_path)), *" ".join(DEFAULT_FLAGS).split(),
           *args.extra_flags.split(), "-c", str(source), "-o", str(out)]
    result = subprocess.run(cmd, cwd=root_path, capture_output=True, text=True)
    if result.returncode != 0 or not out.is_file():
        return (result.stdout + result.stderr).strip().splitlines()[-1] if (result.stdout + result.stderr).strip() else "error"
    return None


def match_percent(target: Path, base: Path, symbol: str) -> float | None:
    with tempfile.NamedTemporaryFile(suffix=".json") as tmp:
        result = subprocess.run(
            ["./objdiff-cli", "diff", "-1", str(target), "-2", str(base), symbol, "-o", tmp.name, "--format", "json"],
            cwd=root_path, capture_output=True, text=True)
        if result.returncode != 0:
            return None
        data = json.load(open(tmp.name))
    for sym in data["right"]["symbols"]:
        if sym.get("name") == symbol and sym.get("kind") == "SYMBOL_FUNCTION":
            return sym.get("match_percent", 0.0)
    return None


def main():
    source = args.source.resolve()
    symbols = function_names(source)
    if len(symbols) == 0:
        sys.exit("No function named func_... found in the source file")
    targets = {symbol: target_object(symbol) for symbol in symbols}

    versions = compiler_versions()
    width = max(len(v) for v in versions)
    short = [s.replace("func_", "") for s in symbols]
    print(f"{'compiler':<{width}}  " + "  ".join(f"{s:>16}" for s in short) + "   all")

    full_matches = []
    with tempfile.TemporaryDirectory(dir=root_path / "build") as tmp_dir:
        for version in versions:
            out = Path(tmp_dir) / f"{version.replace('/', '_')}.o"
            error = compile(version, source, out)
            if error is not None:
                print(f"{version:<{width}}  compile error: {error}")
                continue
            scores = [match_percent(targets[s], out, s) for s in symbols]
            cells = [f"{'-' if p is None else f'{p:.1f}%':>16}" for p in scores]
            all_match = all(p == 100.0 for p in scores)
            if all_match:
                full_matches.append(version)
            print(f"{version:<{width}}  " + "  ".join(cells) + ("   ✔" if all_match else ""), flush=True)

    print()
    if full_matches:
        print("Versions matching every function: " + ", ".join(full_matches))
    else:
        print("No version matches every function")


if __name__ == "__main__":
    main()
