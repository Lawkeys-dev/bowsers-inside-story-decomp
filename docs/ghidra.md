# Ghidra setup

[Ghidra](https://github.com/NationalSecurityAgency/ghidra) gives a C-like starting point for each function.
The [`dsd-ghidra`](https://github.com/AetiasHax/dsd-ghidra) extension loads DS ROMs and syncs function boundaries and names
with the `dsd` config in `config/`. It runs natively on macOS (Apple Silicon), no container needed.

> [!IMPORTANT]
> `dsd-ghidra` v0.7.0 is built for **Ghidra 11.2.1** exactly. Other Ghidra versions refuse to install it.

## Install

1. Install a Java 21 JDK:
   ```shell
   brew install --cask temurin@21
   ```
2. Download [Ghidra 11.2.1](https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.2.1_build/ghidra_11.2.1_PUBLIC_20241105.zip)
   and unzip it, for example in `~/Applications/`. On macOS, remove the quarantine flag so that the decompiler binaries can run:
   ```shell
   xattr -dr com.apple.quarantine ~/Applications/ghidra_11.2.1_PUBLIC
   ```
3. Start Ghidra with `~/Applications/ghidra_11.2.1_PUBLIC/ghidraRun`.
4. Download the [latest `dsd-ghidra` release](https://github.com/AetiasHax/dsd-ghidra/releases/latest) (`.zip`, don't unzip it).
5. In Ghidra: **File → Install Extensions**, click **+**, select the `.zip`, press **OK**, then restart Ghidra.

## Load the game

1. Create a project: **File → New Project → Non-Shared Project**, outside of this repository (e.g. `~/ghidra-projects/bis`).
2. **File → Import File…** (or drag and drop) and select `extract/baserom_bis_usa.nds`. In the import dialog, the format must be
   **dsd-ghidra-loader** with language `ARM:LE:32:v5t`. If it shows "Raw Binary", the extension isn't installed.
3. When asked "Which CPU program do you want to load?", choose **ARM9** (the game code; ARM7 is the sound/Wi-Fi CPU).
4. Double-click the imported program to open it. **When Ghidra offers to analyze it, answer No.** The `dsd` sync gives more
   accurate function boundaries.
5. **Window → Script Manager**, search for `SyncDsd`, and run it (double-click). Select `config/usa/arm9/config.yaml` in this
   repository. Tick the "In Tool" checkbox to add the script to the toolbar.
6. Save the program (<kbd>Cmd</kbd>+<kbd>S</kbd>).

Run the sync again whenever `config/` changes (new symbol names, new delinked files).

## Tips

- Functions are named after `config/usa/arm9/**/symbols.txt`: `func_ov122_0206d978` is in overlay 122 at `0x0206d978`.
- Rename functions, structs and fields in Ghidra freely, but the source of truth is the code in `src/` and the `dsd` config.
- Class names found in the game data use AlphaDream's `cl` prefix (`clMenuLinkList`, `clMenuSpriteBuffer`…).
