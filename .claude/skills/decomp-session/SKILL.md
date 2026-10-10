---
name: decomp-session
description: Runs a decompilation session on one module (overlay) of Bowser's Inside Story. Orchestrates up to 5 decomp-function agents in parallel, verifies every result itself and only completes the functions that match at 100%. Use when the user asks to start a decompilation session on a module, e.g. "Lance une session de décompilation sur ov001".
argument-hint: <module, e.g. ov001>
model: claude-sonnet-5-5
---

# Decompilation session

You are the orchestrator of a decompilation session on the module given in the request or in `$ARGUMENTS` (`ov001`, `main`...).
You don't decompile anything yourself: `decomp-function` agents do, one function each, and you verify their work.
**A function is done only when your own `diff` run prints `100.00%  MATCH`.** An agent's report is a claim, never a proof.

All commands run from the repository root through `./dev.sh` (see `CLAUDE.md`). Answer the user in their language.

## 1. Prepare (alone, before any agent starts)

1. `./dev.sh ninja` must succeed. If it fails, stop and report: the session can't start on a broken build.
2. `./dev.sh python tools/decomp.py todo <module>` lists the functions:
   - `todo`: not started. Take them all, **smallest first**. If there are more than 20, take the 20 smallest and say so in the
     final report.
   - `in progress`: a previous attempt left a source file with a `// TODO`. Add them to the queue; the agent continues
     from the existing file.
   - `complete`: skip.
   If nothing is left, tell the user the module is done and stop.
3. Create the source files of all `todo` functions in one call (it updates `delinks.txt` and delinks the original code):
   `./dev.sh python tools/decomp.py new <func1> <func2> ...`
   Each function gets its own file `src/<module>/<function>.cpp`, so that agents never share a file.
4. Note `git status --short`: the agents may only modify the files of their own function.

Agents must never run `ninja`, `new` or `complete`: only you do, and only when no agent is running (steps 1, 3 and 4 here).

## 2. Dispatch (5 agents at most at the same time)

Launch the agents with the Agent tool, `subagent_type: "decomp-function"`, one function each. Start the first 5 in a single
message. Each time one finishes, verify it (step 3), then launch the next attempt or the next function of the queue, so that
5 at most run at once (all models together).

Each function gets **4 attempts** at most, one after the other, until one is accepted:

| Attempt | Model | Agent tool `model` | `diff` runs | Prompt |
|---|---|---|---|---|
| 1 | Haiku 5.5 | (agent default) | 25 | first attempt |
| 2 | Haiku 5.5 | (agent default) | 25 | optimized retry |
| 3 | Sonnet 5.5 | `"sonnet"` | 40 | optimized retry |
| 4 | Sonnet 5.5 | `"sonnet"` | 40 | optimized retry |

Prompt of the first attempt:

```
Function: <function>
Source file: <source file>
Size: 0x<size> bytes
Attempt 1 of 4. Diff budget: 25 runs.
```

### Optimized retry prompt (attempts 2 to 4)

A retry must not start from scratch nor repeat what already failed. Before writing it, run `diff` yourself, read the
assembly with `info` and the current source file, then give the agent:

```
Function: <function>
Source file: <source file> (it holds the best attempt so far: start from it, don't rewrite it from scratch)
Size: 0x<size> bytes
Attempt <n> of 4. Diff budget: <25 or 40> runs.
Best result so far: <percent>%

What still differs (from your own diff):
- <each group of `!!` lines: the original instructions, the compiled ones, and what C construct produces the original>

Already tried, don't repeat:
- <every change reported in the NOTES of the previous attempts and why it failed>

Try, in this order:
1. <your most likely fix for the first difference, concrete: "declare `count` before `ptr`", "make `unk54` a `u16`",
   "nest the second `if` in the first one"...>
2. <...>

What is known: <struct layout, purpose of the function and of its callees, from the previous NOTES>
```

Pick the hints from the differences: register-only differences call for declaration order, local types or temporaries;
missing or extra instructions for a different expression or control flow; a different load size for a field type
(see "Matching techniques" in `CLAUDE.md` and "Reading the assembly" in `.claude/agents/decomp-function.md`). For the
Sonnet attempts, also list everything both Haiku attempts tried.

## 3. Verify every report

When an agent returns:

1. Run `./dev.sh python tools/decomp.py diff <function>` yourself.
2. `100.00%  MATCH` printed: review the source file.
   - It respects `CLAUDE.md`: `extern "C"` with the original name, placeholder structs with offset comments, natural code
     (no inline assembly, no `#pragma`, no gratuitous `goto` or pointer tricks).
   - `git status --short` shows no change outside this function's files. Revert any other change with `git checkout -- <path>`
     (or delete the new file) and reject the attempt.
   If both are fine, **accept** the function. Otherwise reject it with the precise reason.
3. No match (whatever the agent claims): reject it. If the previous attempt had a better percentage, restore its code
   in the file first, so that the next attempt starts from the best one. Launch the next attempt (table above) with an
   optimized retry prompt.
4. After the 4th rejected attempt, the function **fails**: make sure the file holds the best attempt and, above the function,
   a `// TODO:` comment with its best percentage and what still differs (write it yourself if the agent didn't). It stays not
   complete: the original code is linked, the build stays green. Move on to the next function of the queue.

## 4. Complete (after the last agent has finished)

1. `./dev.sh python tools/decomp.py complete <file1> <file2> ...` with the files of all accepted functions, in one call
   (one full rebuild). It reverifies every function, marks the files complete and rebuilds the game.
2. If the full build fails, it reverts them all: complete the files one by one to find the culprit, and turn that function
   into a failure (note the build error in its `// TODO`).
3. `./dev.sh ninja` must succeed at the end.

## 5. Report

A table of every function of the session: name, size, result (✅ 100% match, completed / ❌ best %), the attempt and model that matched or the number of failed attempts. Then the
functions completed over the total of the module, what was learned about the module (structs, purpose of the code) from
the agents' notes, and the next step for the failures. Don't commit: offer to.
