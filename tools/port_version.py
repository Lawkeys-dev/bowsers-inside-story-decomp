#!/usr/bin/env python3

###
# Ports the decompilation progress of the reference version (usa) to another version (eur).
# Run inside the container after `tools/bootstrap.py` for the target version, then rerun it after decompiling new functions:
#   python tools/port_version.py eur
#
#   1. aligns the symbol list of every module of both versions (same kinds in the same order)
#   2. renames the target's symbols to the reference names, so one source file links in every version
#   3. rewrites the target's delinks.txt with the reference file entries, at the target's addresses
#
# The target's delinks.txt file entries are generated: edit the reference version instead. A `complete` file whose code
# differs in the target makes its `ninja` fail: the function then needs version-specific code (`#ifdef eur`).
###

import argparse
import difflib
import re
import sys
from pathlib import Path

from decomp import SYMBOL_RE, parse_delinks, write_delinks

root_path = Path(__file__).resolve().parent.parent
REFERENCE_VERSION = "usa"


def load_symbols(path: Path) -> list[tuple[str, str, str, int]]:
    symbols = []
    for line in path.read_text().splitlines():
        m = SYMBOL_RE.match(line.strip())
        if m:
            symbols.append((m.group(1), m.group(2), m.group(3) or "", int(m.group(4), 16)))
    return symbols


def shape(symbol: tuple[str, str, str, int]) -> tuple[str, str]:
    # Function sizes may differ between versions, the kind and the arm/thumb mode may not
    return symbol[1], re.sub(r",?size=0x[0-9a-fA-F]+", "", symbol[2])


def size(symbol: tuple[str, str, str, int]) -> int | None:
    m = re.search(r"size=(0x[0-9a-fA-F]+)", symbol[2])
    return int(m.group(1), 16) if m else None


def main():
    parser = argparse.ArgumentParser(description="Ports delinks and symbol names from the reference version")
    parser.add_argument("version", help="Target version, e.g. eur")
    args = parser.parse_args()

    ref_root = root_path / "config" / REFERENCE_VERSION / "arm9"
    dst_root = root_path / "config" / args.version / "arm9"
    if not dst_root.is_dir():
        sys.exit(f"config/{args.version}/ not found: run `python tools/bootstrap.py` with that ROM first")

    renamed = ported = 0
    skipped: list[str] = []
    new_names: dict[Path, dict[str, str]] = {}
    all_names: list[str] = []
    delinks: list[tuple[Path, str, list[dict]]] = []
    for ref_symbols_path in sorted(ref_root.rglob("symbols.txt")):
        module = ref_symbols_path.parent
        dst_module = dst_root / module.relative_to(ref_root)
        ref = load_symbols(ref_symbols_path)
        dst = load_symbols(dst_module / "symbols.txt")

        # Only symbol runs with the same shape are paired: anything else is version-specific and keeps its own name
        names: dict[str, str] = {}
        addrs: dict[int, int] = {}
        matcher = difflib.SequenceMatcher(None, [shape(s) for s in ref], [shape(s) for s in dst], autojunk=False)
        for tag, i1, i2, j1, j2 in matcher.get_opcodes():
            if tag != "equal":
                continue
            for r, d in zip(ref[i1:i2], dst[j1:j2]):
                names[d[0]] = r[0]
                addrs[r[3]] = d[3]
                if size(r) is not None and size(d) is not None:
                    addrs[r[3] + size(r)] = d[3] + size(d)
        # A version-specific symbol can carry the name that a moved symbol takes over
        taken = {r for d, r in names.items() if d != r}
        for s in dst:
            if s[0] not in names and s[0] in taken:
                names[s[0]] = f"{s[0]}_{args.version}"
        new_names[dst_module] = names
        all_names += [names.get(s[0], s[0]) for s in dst]

        header, ref_files = parse_delinks(module / "delinks.txt")
        dst_header, _ = parse_delinks(dst_module / "delinks.txt")
        files = []
        for entry in ref_files:
            if all(start in addrs and end in addrs for _, start, end in entry["sections"]):
                entry["sections"] = [[name, addrs[start], addrs[end]] for name, start, end in entry["sections"]]
                files.append(entry)
            else:
                skipped.append(entry["name"])
        ported += len(files)
        delinks.append((dst_module / "delinks.txt", dst_header, files))

    duplicates = sorted({n for n in all_names if all_names.count(n) > 1})
    if duplicates:
        sys.exit(f"Renaming would create duplicate symbols, symbols.txt left unchanged: {', '.join(duplicates[:10])}")
    for path, header, files in delinks:
        write_delinks(path, header, files)
    for dst_module, names in new_names.items():
        path = dst_module / "symbols.txt"
        lines = []
        for line in path.read_text().splitlines():
            name = line.split(" ", 1)[0]
            if names.get(name, name) != name:
                line = names[name] + line[len(name):]
                renamed += 1
            lines.append(line)
        path.write_text("\n".join(lines) + "\n")

    print(f"{ported} file entries ported, {renamed} symbols renamed")
    for name in skipped:
        print(f"Skipped {name}: its sections don't map to {args.version} symbols, add it by hand")


if __name__ == "__main__":
    main()
