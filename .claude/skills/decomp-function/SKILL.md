---
name: decomp-function
description: Deep decompilation of ONE hard function of Bowser's Inside Story, usually one left with a TODO by /decomp-unit. Opus orchestrates up to 3 Sonnet decomp-worker attempts, then takes over itself for up to 3 tries with everything learned. Only run when the user types /decomp-function <function>.
argument-hint: <function, e.g. func_ov001_02069ac8>
model: claude-opus-5-5
disable-model-invocation: true
---

# Decompile one hard function

You take on the function given in `$ARGUMENTS`, usually one that `/decomp-unit` left with a `// TODO`. First Sonnet
`decomp-worker` agents attempt it, one after the other, and you verify their work. If they all fail, you take over yourself
with everything they learned. **The function is done only when your own `diff` run prints `100.00%  MATCH`.**

Read `.claude/decomp-review.md` first: it describes how to verify a report, write a retry prompt and leave a TODO.
All commands run from the repository root through `./dev.sh` (see `CLAUDE.md`). Answer the user in their language.

## 1. Prepare

1. `./dev.sh ninja` must succeed. If it fails, stop and report.
2. `./dev.sh python tools/decomp.py info <function>` gives its unit, size, assembly and source file:
   - `complete`: tell the user it's already done and stop.
   - no source file yet: `./dev.sh python tools/decomp.py new <function>`.
   - a source file with other functions in it: work in that file, but only change this function (and the structs it
     needs). `complete` will require every function of the file to match.
3. Run `diff` once: note the starting percentage and read the `// TODO` left by a previous pass, if any.
4. Note `git status --short`: only this function's files may change.

## 2. Sonnet attempts (3 at most, one at a time)

Launch the Agent tool with `subagent_type: "decomp-worker"` and `model: "sonnet"` (Sonnet 5.5), one agent at a time:

- Attempt 1: if the file only holds the stub, use the first attempt prompt:
  ```
  Function: <function>
  Source file: <source file>
  Size: 0x<size> bytes
  Attempt 1 of 3. Diff budget: 40 runs.
  ```
  If it holds a previous attempt with a `// TODO`, use the optimized retry prompt of `.claude/decomp-review.md` from the
  start, with what the TODO says.
- Attempts 2 and 3: the optimized retry prompt, with everything every previous attempt tried.

Verify each report as `.claude/decomp-review.md` describes. Accepted: go to step 4.

## 3. Your own tries (3 at most)

After 3 rejected Sonnet attempts, decompile it yourself, starting from the best attempt in the file and from everything the
agents' NOTES and your own diffs taught you. Follow the same rules as the agents (`.claude/agents/decomp-worker.md`): only
this function's file, natural code, no inline assembly or `#pragma`.

A **try** is one hypothesis about what the original source looked like (a different control flow, a different struct
layout, a different expression of the same computation...), refined with 20 `diff` runs at most. Write the hypothesis down
before each try. After 3 tries without a match, leave a TODO (`.claude/decomp-review.md`) that sums up the hypotheses that
failed, so that the next person doesn't repeat them.

## 4. Complete

If the function matches: `./dev.sh python tools/decomp.py complete <source file>`. If the full build fails, it reverts:
treat it as a failure and note the build error in the TODO. `./dev.sh ninja` must succeed at the end.

## 5. Report

The result (✅ 100% match, completed / ❌ best %), who matched it (Sonnet attempt n, or your try n), the starting and final
percentages, what made the difference (or the hypotheses that failed), and what was learned about the structs and the
purpose of the function. Don't commit: offer to.
