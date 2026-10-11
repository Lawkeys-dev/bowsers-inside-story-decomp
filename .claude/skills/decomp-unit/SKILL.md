---
name: decomp-unit
description: Fast decompilation pass on one unit (module/overlay) of Bowser's Inside Story. A Sonnet orchestrator runs up to 8 Haiku decomp-worker agents in parallel, one function each, verifies every result and completes only the functions that match at 100%. Use when the user asks to decompile a unit or module, e.g. "/decomp-unit ov004" or "Lance une session de décompilation sur ov001".
argument-hint: <unit, e.g. ov004>
model: claude-sonnet-5-5
---

# Decompile a unit

You orchestrate a fast pass on the unit given in `$ARGUMENTS` (`ov004`, `main`...). The pass is meant to be quick and to catch
the easy functions: Haiku `decomp-worker` agents decompile, one function each, and you verify their work. You don't
decompile anything yourself. Hard functions are left with a `// TODO` for `/decomp-function`, which the user runs later.

**Never invoke `/decomp-function`** (or the `decomp-function` skill), and never launch an agent with another model than
Haiku: a function that fails here gets a TODO, nothing more.

Read `.claude/decomp-review.md` first: it describes how to verify a report, write a retry prompt and leave a TODO.
All commands run from the repository root through `./dev.sh` (see `CLAUDE.md`). Answer the user in their language.

## 1. Prepare (alone, before any agent starts)

1. `./dev.sh ninja` must succeed. If it fails, stop and report: the pass can't start on a broken build.
2. `./dev.sh python tools/decomp.py todo <unit>` lists the functions:
   - `todo`: not started. Take them all, **smallest first**. If there are more than 40, take the 40 smallest and say so in the
     final report.
   - `in progress`: skip them. A previous pass left them with a `// TODO`: they are for `/decomp-function`.
   - `complete`: skip.
   If nothing is left to do, tell the user (and list the `in progress` functions for `/decomp-function`), then stop.
3. Create the source files of all selected functions in one call (it updates `delinks.txt` and delinks the original code):
   `./dev.sh python tools/decomp.py new <func1> <func2> ...`
   Each function gets its own file `src/<unit>/<function>.cpp`, so that agents never share a file.
4. Note `git status --short`: the agents may only modify the files of their own function.

Agents never run `ninja`, `new` or `complete`: only you do, and only when no agent is running.

## 2. Dispatch (8 Haiku agents at most at the same time)

Launch the agents with the Agent tool, `subagent_type: "decomp-worker"`, without `model` (the agent runs on Haiku 5.5), one
function each. Start the first 8 in a single message. Each time one finishes, verify it, then launch the retry or the next
function of the queue, so that 8 agents at most run at once.

Each function gets **2 attempts** at most, both on Haiku with a `diff` budget of 25 runs:

1. First attempt:
   ```
   Function: <function>
   Source file: <source file>
   Size: 0x<size> bytes
   Attempt 1 of 2. Diff budget: 25 runs.
   ```
2. If it's rejected: one retry with the optimized retry prompt of `.claude/decomp-review.md` (`Attempt 2 of 2`).
3. If the retry is rejected too: leave a TODO (`.claude/decomp-review.md`) and move on. Don't try it a third time.

## 3. Complete (after the last agent has finished)

1. `./dev.sh python tools/decomp.py complete <file1> <file2> ...` with the files of all accepted functions, in one call
   (one full rebuild). It reverifies every function, marks the files complete and rebuilds the game.
2. If the full build fails, it reverts them all: complete the files one by one to find the culprit, and turn that function
   into a failure (note the build error in its `// TODO`).
3. `./dev.sh ninja` must succeed at the end.

## 4. Report

A table of every function of the pass: name, size, result (✅ 100% match, completed / ❌ best %), attempt that matched. Then
the functions completed over the total of the unit, what was learned about the unit (structs, purpose of the code) from the
agents' notes, and the list of failed functions to give to `/decomp-function <function>`. Don't commit: offer to.
