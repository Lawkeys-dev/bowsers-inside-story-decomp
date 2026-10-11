# Reviewing decomp-worker attempts

Shared by the `/decomp-unit` and `/decomp-function` orchestrators. **A function is done only when your own `diff` run prints
`100.00%  MATCH`.** An agent's report is a claim, never a proof.

## Verify a report

When a `decomp-worker` agent returns:

1. Run `./dev.sh python tools/decomp.py diff <function>` yourself.
2. `100.00%  MATCH` printed: review the source file.
   - It respects `CLAUDE.md`: `extern "C"` with the original name, placeholder structs with offset comments, natural code
     (no inline assembly, no `#pragma`, no gratuitous `goto` or pointer tricks).
   - `git status --short` shows no change outside this function's files. Revert any other change with `git checkout -- <path>`
     (or delete the new file) and reject the attempt.

   If both are fine, **accept** the function. Otherwise reject it with the precise reason.
3. No match (whatever the agent claims): reject it. If a previous attempt had a better percentage, restore its code in the
   file, so that the next attempt starts from the best one.

## Optimized retry prompt

A retry must not start from scratch nor repeat what already failed. Before writing it, run `diff` yourself, read the
assembly with `info` and the current source file, then give the agent:

```
Function: <function>
Source file: <source file> (it holds the best attempt so far: start from it, don't rewrite it from scratch)
Size: 0x<size> bytes
Attempt <n> of <max>. Diff budget: <budget> runs.
Best result so far: <percent>%

What still differs (from your own diff):
- <each group of `!!` lines: the original instructions, the compiled ones, and what C construct produces the original>

Already tried, don't repeat:
- <every change reported in the NOTES of all previous attempts and why it failed>

Try, in this order:
1. <your most likely fix for the first difference, concrete: "declare `count` before `ptr`", "make `unk54` a `u16`",
   "nest the second `if` in the first one"...>
2. <...>

What is known: <struct layout, purpose of the function and of its callees, from the previous NOTES>
```

Pick the hints from the differences: register-only differences call for declaration order, local types or temporaries;
missing or extra instructions for a different expression or control flow; a different load size for a field type
(see "Matching techniques" in `CLAUDE.md` and "Reading the assembly" in `.claude/agents/decomp-worker.md`).

## Leave a TODO

When a function fails for good, the file keeps the best attempt and, above the function, a `// TODO:` comment with the best
percentage and what still differs (write it yourself if the agent didn't). It stays not complete: the original code is
linked, the build stays green.
