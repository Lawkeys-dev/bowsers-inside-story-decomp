# Compiler

**Bowser's Inside Story was built with Metrowerks CodeWarrior for Nintendo DS 2.0, with `-O4,p`.**
The project uses `mwccarm` **2.0/sp1p5**.

## Evidence

### SDK version

The ARM9 build info of the USA ROM (`extract/usa/arm9/arm9.yaml`) has `sdk_version: 0x04027538`, i.e. **NitroSDK 4.2**
(release step 30008). NitroSDK 4.x shipped alongside CodeWarrior 2.0, while CodeWarrior 1.2 belongs to older SDKs
(Mario & Luigi: Partners in Time, 2005, uses 1.2/base).

### Language

The overlays contain C++ static initializers (`__sinit_*`) and class names such as `clMenuLinkList` or `clMenuSpriteBuffer`:
the game is written in **C++**, with AlphaDream's `cl` prefix for class names.

### Matching tests

Eight leaf functions from various overlays were decompiled by hand ([`compiler-probe.cpp`](compiler-probe.cpp)) and
compiled with every `mwccarm` version available (25 versions: 1.2, 2.0 and DSi) using
[`tools/probe_compilers.py`](../tools/probe_compilers.py):

| Function | 1.2 | 2.0 | DSi |
| -------- | --- | --- | --- |
| `func_ov122_0206d978` (comparisons) | 100% | 100% | 100% |
| `func_ov124_02078574` (2D loop) | 71.8–75.3% | **100%** | 77.6% |
| `func_ov118_020ebda8` (loop, multiply) | 44.4–52.7% | **100%** | 100% |
| `func_ov004_0208ac58` (combined conditions) | 91.2–95.4% | **100%** | 100% |
| `func_ov015_020a2b60` (division by constant) | 24.5–49.7% | 94.8% | 94.8% |
| `func_ov016_020af02c` (bit array) | 49.7–53.6% | 98.1% | 88.7% |
| `func_ov123_0207731c` (switch) | 100% | 100% | 100% |
| `func_ov086_020c9be0` (switch) | 100% | 100% | 100% |

- Only the **2.0** family matches every function that was fully decompiled.
- The two functions below 100% are source-level puzzles (load order, register swap): no 2.0 version or flag change moves them.
- `-O4,p` is confirmed: `-O4,s` drops to 65.9% and 93.5% on the last two functions. `-O3,p`, `-inline auto`,
  `-ipa file`, `-char unsigned` and `-enum int` change nothing on these functions.
- **The 2.0 service packs (base to sp2p4) produce identical code on every function tested.** 2.0/sp1p5 is used because it
  is the version of the [Phantom Hourglass](https://github.com/zeldaret/ph) decompilation and maps to the `mwcc_30_131`
  compiler on decomp.me. If a function ever matches with one service pack only, switch with
  `python tools/configure.py usa --mwcc-version <version>`.

## Reproducing

```shell
./dev.sh ninja                                                   # delinked objects are needed
./dev.sh python tools/probe_compilers.py docs/compiler-probe.cpp
./dev.sh python tools/probe_compilers.py docs/compiler-probe.cpp --versions 2.0/sp1p5 --extra-flags="-O4,s"
```
