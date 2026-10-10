#!/usr/bin/env python3

###
# Helper for decompiling functions one at a time, made to be driven by a human or an AI agent.
# Run inside the container (./dev.sh python tools/decomp.py ...), after a successful `ninja`.
# `info` and `diff` don't run ninja: several agents can use them at the same time on different source files.
#
#   info <func>              Module, address, size, assembly and external symbols of a function
#   new <func>... [--file F] Creates a source file per function (or appends them to F) with a stub, declares it in
#                            delinks.txt and delinks the original code
#   diff <func>              Compiles the function and prints its match percentage and an instruction diff
#   complete <file>...       Checks that every function of the files matches, marks them `complete`, rebuilds once
#   todo <module>            Lists the functions of a module that are not decompiled yet
###

import argparse
import json
import re
import shlex
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

root_path = Path(__file__).resolve().parent.parent
GAME_VERSION = "usa"
config_root = root_path / "config" / GAME_VERSION / "arm9"
build_root = root_path / "build" / GAME_VERSION
asm_root = build_root / "asm"
scratch_root = build_root / "scratch"

SYMBOL_RE = re.compile(r"^(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:(0x[0-9a-fA-F]+)")


@dataclass
class Symbol:
    name: str
    kind: str
    args: str
    addr: int
    module: str
    config_dir: Path

    @property
    def size(self) -> int:
        m = re.search(r"size=(0x[0-9a-fA-F]+)", self.args)
        return int(m.group(1), 16) if m else 0

    @property
    def mode(self) -> str:
        return "thumb" if "thumb" in self.args else "arm"


def run(cmd: list[str], check: bool = True, quiet: bool = False) -> subprocess.CompletedProcess:
    result = subprocess.run([str(c) for c in cmd], cwd=root_path, capture_output=True, text=True)
    if check and result.returncode != 0:
        print((result.stdout + result.stderr).strip()[-4000:])
        sys.exit(f"Command failed: {' '.join(str(c) for c in cmd)}")
    return result


def module_dirs() -> dict[str, Path]:
    dirs = {"main": config_root, "itcm": config_root / "itcm", "dtcm": config_root / "dtcm"}
    for d in sorted((config_root / "overlays").iterdir()):
        dirs[d.name] = d
    return dirs


def load_symbols() -> dict[str, Symbol]:
    symbols: dict[str, Symbol] = {}
    for module, d in module_dirs().items():
        path = d / "symbols.txt"
        if not path.is_file():
            continue
        for line in path.read_text().splitlines():
            m = SYMBOL_RE.match(line.strip())
            if m:
                symbols[m.group(1)] = Symbol(m.group(1), m.group(2), m.group(3) or "", int(m.group(4), 16), module, d)
    return symbols


def find_function(name: str) -> Symbol:
    sym = load_symbols().get(name)
    if sym is None or sym.kind != "function":
        sys.exit(f"Unknown function '{name}'")
    return sym


def function_asm(name: str) -> str:
    if not asm_root.is_dir():
        run(["ninja", "dis"])
    for path in asm_root.rglob("*.s"):
        text = path.read_text()
        start = re.search(rf"^\s*(arm|thumb)_func_start {re.escape(name)}\n", text, re.M)
        if not start:
            continue
        end = re.search(rf"^\s*(arm|thumb)_func_end {re.escape(name)}\n", text[start.start():], re.M)
        return text[start.start(): start.start() + end.end()].rstrip()
    run(["ninja", "dis"])
    sys.exit(f"Assembly for {name} not found, `ninja dis` was rerun: try again")


# ---------------------------------------------------------------------------------------------------------------------
# delinks.txt handling

def parse_delinks(path: Path) -> tuple[str, list[dict]]:
    """Returns the module header and the list of file entries."""
    text = path.read_text()
    blocks = re.split(r"\n\s*\n", text.strip("\n"))
    header = blocks[0]
    files = []
    for block in blocks[1:]:
        lines = block.splitlines()
        entry = {"name": lines[0].rstrip(":"), "complete": False, "sections": []}
        for line in lines[1:]:
            line = line.strip()
            if line == "complete":
                entry["complete"] = True
            elif line:
                m = re.match(r"(\S+)\s+start:(0x[0-9a-fA-F]+)\s+end:(0x[0-9a-fA-F]+)", line)
                entry["sections"].append([m.group(1), int(m.group(2), 16), int(m.group(3), 16)])
        files.append(entry)
    return header, files


def write_delinks(path: Path, header: str, files: list[dict]):
    out = [header]
    for entry in files:
        lines = [f"{entry['name']}:"]
        if entry["complete"]:
            lines.append("    complete")
        for section, start, end in entry["sections"]:
            lines.append(f"    {section:<11} start:0x{start:08x} end:0x{end:08x}")
        out.append("\n".join(lines))
    path.write_text("\n\n".join(out) + "\n")


def file_entry_for(sym: Symbol) -> tuple[Path, str, list[dict], dict | None]:
    path = sym.config_dir / "delinks.txt"
    header, files = parse_delinks(path)
    for entry in files:
        for section, start, end in entry["sections"]:
            if section == ".text" and start <= sym.addr < end:
                return path, header, files, entry
    return path, header, files, None


def functions_in_range(module: str, start: int, end: int) -> list[Symbol]:
    syms = [s for s in load_symbols().values() if s.module == module and s.kind == "function" and start <= s.addr < end]
    return sorted(syms, key=lambda s: s.addr)


def object_paths(source: str) -> tuple[Path, Path]:
    stem = Path(source).with_suffix(".o")
    return build_root / "delinks" / stem, build_root / stem


# ---------------------------------------------------------------------------------------------------------------------
# Commands

def cmd_info(args):
    sym = find_function(args.function)
    print(f"{sym.name}: {sym.mode} function in {sym.module}, address 0x{sym.addr:08x}, size 0x{sym.size:x}")
    _, _, _, entry = file_entry_for(sym)
    print(f"Source file: {entry['name'] + (' (complete)' if entry['complete'] else '') if entry else 'none yet'}")
    print()
    asm = function_asm(sym.name)
    print(asm)

    symbols = load_symbols()
    referenced = sorted(set(re.findall(r"\b((?:func|data)_\w+|[A-Z][A-Za-z0-9_]+)\b", asm)) - {sym.name})
    pools = re.findall(r"^\s*(\.L_[0-9a-f]+):", asm, re.M)
    print("\nReferenced symbols:")
    for name in referenced:
        if name in symbols:
            s = symbols[name]
            print(f"  {name}: {s.kind}{'(' + s.args + ')' if s.args else ''} in {s.module} at 0x{s.addr:08x}")
    if pools:
        print("\nLiteral pool entries are listed after the function in the assembly above (.word).")


def add_function(sym: Symbol, file: str | None) -> str:
    path, header, files, entry = file_entry_for(sym)
    if entry is not None:
        sys.exit(f"{sym.name} already belongs to {entry['name']}")
    start, end = sym.addr, sym.addr + sym.size

    stub = (f'extern "C" void {sym.name}() {{\n'
            f'    // TODO: decompile\n'
            f'}}\n')
    if file:
        source = file
        target = next((f for f in files if f["name"] == source), None)
        if target is None:
            sys.exit(f"{source} is not declared in {path.relative_to(root_path)}")
        text_sections = [s for s in target["sections"] if s[0] == ".text"]
        if text_sections[0][2] == start:
            text_sections[0][2] = end
        elif text_sections[0][1] == end:
            text_sections[0][1] = start
        else:
            sys.exit(f"{sym.name} is not adjacent to the .text range of {source}")
        source_path = root_path / source
        source_path.write_text(source_path.read_text().rstrip("\n") + "\n\n" + stub)
    else:
        source = f"src/{sym.module}/{sym.name}.cpp"
        source_path = root_path / source
        source_path.parent.mkdir(parents=True, exist_ok=True)
        source_path.write_text('#include "types.h"\n\n' + stub)
        files.append({"name": source, "complete": False, "sections": [[".text", start, end]]})
    write_delinks(path, header, files)
    print(f"{source}: added {sym.name} (.text 0x{start:08x}-0x{end:08x}, not complete)")
    return source


def cmd_new(args):
    for name in args.functions:
        add_function(find_function(name), args.file)
    run(["python", "tools/configure.py", GAME_VERSION])
    run(["ninja", "delink"])


def objdiff_percent(target: Path, base: Path, name: str, relaxed: bool) -> tuple[float | None, dict | None, dict | None]:
    extra = ["-c", "functionRelocDiffs=none"] if relaxed else []
    with tempfile.NamedTemporaryFile(suffix=".json") as tmp:
        run(["./objdiff-cli", "diff", "-1", target, "-2", base, name, *extra, "-o", tmp.name, "--format", "json"])
        data = json.load(open(tmp.name))

    def get(side: str):
        for s in data[side]["symbols"]:
            if s.get("name") == name and s.get("kind") == "SYMBOL_FUNCTION":
                return s
        return None

    left, right = get("left"), get("right")
    return (right.get("match_percent", 0.0) if right else None), left, right


def mwcc_command(source: str, out_dir: Path) -> list[str]:
    """The `mwcc` command of build.ninja for one source file. Compiling outside of ninja lets several agents work at the
    same time: concurrent ninja runs in the same build directory would corrupt its state."""
    text = (root_path / "build.ninja").read_text().replace("$\n", "")
    command = re.search(r"^rule mwcc\n\s+command = (.*)$", text, re.M).group(1).split(" && ")[0]
    obj = (build_root / Path(source).with_suffix(".o")).relative_to(root_path)
    edge = re.search(rf"^build {re.escape(str(obj))}: mwcc .*\n((?:  \w+ = .*\n)+)", text, re.M)
    if edge is None:
        sys.exit(f"{source} is not in build.ninja: run `./dev.sh python tools/configure.py {GAME_VERSION}`")
    variables = dict(line.strip().split(" = ", 1) for line in edge.group(1).splitlines())
    variables.update({"in": source, "basedir": str(out_dir.relative_to(root_path))})
    command = re.sub(r"\$(\w+)", lambda m: variables.get(m.group(1), ""), command)
    return [arg for arg in shlex.split(command) if arg != "-MD"]


def diff_function(sym: Symbol, source: str, verbose: bool) -> float:
    """Returns 100.0 when the instructions match. Relocations that only differ by target address (calls to functions
    of the same file, which mwcc puts in separate sections) are ignored here: `complete` verifies them by linking."""
    target, _ = object_paths(source)
    if not target.is_file():
        print(f"{target.relative_to(root_path)} is missing: run `./dev.sh ninja delink`")
        return -1.0
    base = scratch_root / Path(source).with_suffix(".o")
    base.parent.mkdir(parents=True, exist_ok=True)
    base.unlink(missing_ok=True)
    build = run(mwcc_command(source, base.parent), check=False)
    if build.returncode != 0 or not base.is_file():
        # Under wibo, mwcc can't load its message strings: errors only give a line number, show that line
        print("Compilation failed (mwcc only reports line numbers):")
        lines = (root_path / source).read_text().splitlines()
        for number in dict.fromkeys(int(n) for n in re.findall(r"^\S+:(\d+):", build.stdout, re.M)):
            print(f"  {source}:{number}: {lines[number - 1].strip() if number <= len(lines) else ''}")
        return -1.0
    percent, left, right = objdiff_percent(target, base, sym.name, relaxed=False)
    if right is None:
        print(f"{sym.name} not found in the compiled object: check its name and that it is extern \"C\"")
        return -1.0
    if percent < 100.0:
        relaxed, _, _ = objdiff_percent(target, base, sym.name, relaxed=True)
        if relaxed == 100.0:
            if verbose:
                print(f"Instructions match, only relocation target addresses differ (objdiff: {percent:.2f}%).")
            return 100.0
    if verbose and percent < 100.0:
        li, ri = left.get("instructions", []), right.get("instructions", [])
        print(f"{'original':<40} | compiled")
        for i in range(max(len(li), len(ri))):
            a = li[i].get("instruction", {}).get("formatted", "") if i < len(li) else ""
            b = ri[i].get("instruction", {}).get("formatted", "") if i < len(ri) else ""
            kind = (li[i].get("diff_kind") if i < len(li) else None) or (ri[i].get("diff_kind") if i < len(ri) else None)
            marker = "!!" if kind else "  "
            print(f"{marker} {a:<37} | {b:<37} {kind.replace('DIFF_', '').lower() if kind else ''}")
    return percent


def cmd_diff(args):
    sym = find_function(args.function)
    _, _, _, entry = file_entry_for(sym)
    if entry is None:
        sys.exit(f"{sym.name} has no source file yet, run `new` first")
    percent = diff_function(sym, entry["name"], verbose=True)
    if percent >= 0:
        print(f"\n{sym.name}: {percent:.2f}%{'  MATCH' if percent == 100.0 else ''}")


def find_file_entry(source: str) -> tuple[Path, str, str, list[dict], dict]:
    for module, d in module_dirs().items():
        header, files = parse_delinks(d / "delinks.txt")
        for entry in files:
            if entry["name"] == source:
                return d / "delinks.txt", module, header, files, entry
    sys.exit(f"{source} is not declared in any delinks.txt")


def set_complete(source: str, complete: bool):
    path, _, header, files, entry = find_file_entry(source)
    entry["complete"] = complete
    write_delinks(path, header, files)


def cmd_complete(args):
    for source in args.files:
        _, module, _, _, entry = find_file_entry(source)
        if entry["complete"]:
            sys.exit(f"{source} is already complete")
        text = [s for s in entry["sections"] if s[0] == ".text"][0]
        failed = []
        print(source)
        for sym in functions_in_range(module, text[1], text[2]):
            percent = diff_function(sym, source, verbose=False)
            print(f"  {sym.name}: {percent:.2f}%")
            if percent != 100.0:
                failed.append(sym.name)
        if failed:
            sys.exit(f"{source} is not complete, functions below 100%: {', '.join(failed)}")

    for source in args.files:
        set_complete(source, True)
    result = run(["ninja"], check=False)
    if result.returncode != 0:
        for source in args.files:
            set_complete(source, False)
        run(["ninja"], check=False)
        print("\n".join((result.stdout + result.stderr).splitlines()[-30:]))
        sys.exit("Full build failed with these files complete, reverted")
    print(f"{len(args.files)} file(s) complete, all modules still match")


def cmd_todo(args):
    dirs = module_dirs()
    if args.module not in dirs:
        sys.exit(f"Unknown module '{args.module}'")
    _, files = parse_delinks(dirs[args.module] / "delinks.txt")
    covered = [(s[1], s[2], f) for f in files for s in f["sections"] if s[0] == ".text"]
    for sym in sorted((s for s in load_symbols().values() if s.module == args.module and s.kind == "function"),
                      key=lambda s: s.addr):
        owner = next((f for start, end, f in covered if start <= sym.addr < end), None)
        status = "complete" if owner and owner["complete"] else ("in progress" if owner else "todo")
        print(f"0x{sym.addr:08x}  size 0x{sym.size:<5x} {status:<12} {sym.name}")


def main():
    parser = argparse.ArgumentParser(description="Decompilation helper")
    sub = parser.add_subparsers(dest="command", required=True)
    p = sub.add_parser("info"); p.add_argument("function"); p.set_defaults(func=cmd_info)
    p = sub.add_parser("new"); p.add_argument("functions", nargs="+"); p.add_argument("--file"); p.set_defaults(func=cmd_new)
    p = sub.add_parser("diff"); p.add_argument("function"); p.set_defaults(func=cmd_diff)
    p = sub.add_parser("complete"); p.add_argument("files", nargs="+"); p.set_defaults(func=cmd_complete)
    p = sub.add_parser("todo"); p.add_argument("module"); p.set_defaults(func=cmd_todo)
    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
