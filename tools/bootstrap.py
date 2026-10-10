#!/usr/bin/env python3

###
# One-time project setup for a new game version:
#   1. finds the base ROM in extract/ and detects its version from the ROM header
#   2. checks (or records) its SHA-1
#   3. downloads the toolchain (dsd, objdiff, mwccarm, wibo, sjiswrap)
#   4. extracts the ROM with `dsd rom extract`
#   5. generates the dsd config with `dsd init`
#
# Usage (inside the container):
#   python tools/bootstrap.py [--version usa] [--force]
###

import argparse
import hashlib
import shutil
import subprocess
import sys
from pathlib import Path

GAME = "bis"
GAME_CODE_PREFIX = "CLJ"
REGIONS = {
    "E": "usa",
    "P": "eur",
    "J": "jpn",
    "K": "kor",
}

root_path = Path(__file__).resolve().parent.parent
extract_path = root_path / "extract"
config_path = root_path / "config"
build_path = root_path / "build"
tools_path = root_path / "tools"
arm7_bios_path = root_path / "arm7_bios.bin"

# Keep in sync with tools/configure.py
DSD_VERSION = "v0.12.1"
OBJDIFF_VERSION = "v3.8.2"
WIBO_VERSION = "0.6.16"
SJISWRAP_VERSION = "v1.2.2"

parser = argparse.ArgumentParser(description="Sets up the project from a base ROM")
parser.add_argument("--version", type=str, required=False, help="Force game version (usa, eur, jpn, kor)")
parser.add_argument("--force", action="store_true", help="Redo extraction and dsd init even if they already exist")
args = parser.parse_args()


def step(message: str):
    print(f"\n==> {message}", flush=True)


def fail(message: str):
    print(f"\nERROR: {message}", file=sys.stderr)
    exit(1)


def run(cmd: list[str]):
    print("$ " + " ".join(str(c) for c in cmd), flush=True)
    result = subprocess.run([str(c) for c in cmd], cwd=root_path)
    if result.returncode != 0:
        fail(f"command failed with exit code {result.returncode}")


def read_game_code(rom: Path) -> str:
    with rom.open("rb") as f:
        header = f.read(0x10)
    if len(header) < 0x10:
        fail(f"{rom} is too small to be a DS ROM")
    return header[0x0C:0x10].decode("ascii", errors="replace")


def find_base_rom() -> tuple[Path, str]:
    candidates = sorted(p for p in extract_path.glob("*.nds") if p.is_file())
    if len(candidates) == 0:
        fail(f"no .nds file found in {extract_path.relative_to(root_path)}/, put your dumped ROM there (see extract/README.md)")

    if args.version is not None:
        named = extract_path / f"baserom_{GAME}_{args.version}.nds"
        if named.is_file():
            return named, args.version
        if len(candidates) > 1:
            fail(f"several ROMs found, rename the one to use to {named.name}")
        return candidates[0], args.version

    found: list[tuple[Path, str]] = []
    for rom in candidates:
        code = read_game_code(rom)
        if not code.startswith(GAME_CODE_PREFIX):
            print(f"Skipping {rom.name}: game code {code!r} is not Bowser's Inside Story ({GAME_CODE_PREFIX}x)")
            continue
        version = REGIONS.get(code[3])
        if version is None:
            fail(f"{rom.name}: unknown region in game code {code!r}, rerun with --version <name>")
        found.append((rom, version))

    if len(found) == 0:
        fail("no Bowser's Inside Story ROM found in extract/")
    if len(found) > 1:
        names = ", ".join(f"{rom.name} ({version})" for rom, version in found)
        fail(f"several ROMs found: {names}. Rerun with --version <name>")
    return found[0]


def sha1_of(path: Path) -> str:
    h = hashlib.sha1()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def download(tool: str, tag: str, path: Path):
    if path.exists():
        print(f"{tool}: already present")
        return
    run([sys.executable, "tools/download_tool.py", tool, tag, "--path", path])


def main():
    step("Locating base ROM")
    rom, version = find_base_rom()
    base_rom = extract_path / f"baserom_{GAME}_{version}.nds"
    if rom != base_rom:
        print(f"Renaming {rom.name} -> {base_rom.name}")
        rom.rename(base_rom)
    print(f"Version: {version}")

    step("Checking SHA-1")
    sha1_file = root_path / f"{GAME}_{version}.sha1"
    digest = sha1_of(base_rom)
    if sha1_file.is_file():
        expected = sha1_file.read_text().split(" ", 1)[0].strip()
        if digest != expected:
            fail(f"{base_rom.name} has SHA-1 {digest}, expected {expected} ({sha1_file.name}). Bad dump or other revision?")
        print(f"{base_rom.name}: OK ({digest})")
    else:
        sha1_file.write_text(f"{digest} {GAME}_{version}.nds\n")
        print(f"Recorded {digest} in {sha1_file.name}")
        print("Compare it against the No-Intro database to make sure your dump is clean before going further.")

    step("Downloading toolchain")
    download("dsd", DSD_VERSION, root_path / "dsd")
    download("objdiff", OBJDIFF_VERSION, root_path / "objdiff-cli")
    download("wibo", WIBO_VERSION, root_path / "wibo")
    download("sjiswrap", SJISWRAP_VERSION, root_path / "sjiswrap.exe")
    if not (tools_path / "mwccarm").is_dir():
        run([sys.executable, "tools/download_tool.py", "mwccarm", "latest", "--path", tools_path])
    else:
        print("mwccarm: already present")
    run(["./dsd", "--version"])

    game_extract = extract_path / version
    rom_config = game_extract / "config.yaml"
    step(f"Extracting ROM to extract/{version}/")
    if rom_config.is_file() and not args.force:
        print("Already extracted (use --force to redo)")
    else:
        if game_extract.exists():
            shutil.rmtree(game_extract)
        cmd = ["./dsd", "rom", "extract", "--rom", base_rom, "--output-path", game_extract]
        if arm7_bios_path.is_file():
            cmd += ["--arm7-bios", arm7_bios_path]
        run(cmd)

    game_config = config_path / version / "arm9"
    step(f"Generating dsd config in config/{version}/arm9/")
    if (game_config / "config.yaml").is_file() and not args.force:
        print("Already initialized (use --force to redo)")
    else:
        if game_config.exists():
            shutil.rmtree(game_config)
        # dsd init writes its files to <output-path>/arm9/
        run(["./dsd", "init",
             "--rom-config", rom_config,
             "--output-path", config_path / version,
             "--build-path", build_path / version])
        if not (game_config / "config.yaml").is_file():
            fail(f"dsd init did not create {game_config / 'config.yaml'}, check its output above")

    step("Done")
    print(f"Next: python tools/configure.py {version} && ninja")


if __name__ == "__main__":
    main()
