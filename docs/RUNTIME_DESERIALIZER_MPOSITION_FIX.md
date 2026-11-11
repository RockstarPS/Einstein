# `deserialize(bool_t&)` — removing the stray dereference

**File:** `cluster-platform/dijkstra/libraries/runtime/src/runtime/serdes/dk_runtime_deserializer.cpp`
**Line:** 74, inside `dk::runtime::core::Deserializer::deserialize ( bool_t &value )`
**Scope:** one character. No API change, no behaviour change.
**Verification:** host functional test, 31 assertions, byte-identical output before and after.

```diff
-        *mPosition++;
+        mPosition++;
```

---

## 1. What `mPosition` is

A message arrives from another process as raw bytes. `Deserializer` decodes them
back into typed values, and `mPosition` is its **reading cursor** — a
`std::vector<byte_t>::iterator` declared at `dk_runtime_deserializer.hpp:71`.

```
box:      0     1     2     3
        +-----+-----+-----+-----+
mData   | 01  | 7E  | 00  | 2A  |
        +-----+-----+-----+-----+
           ^
       mPosition        "the next byte not yet consumed"
```

Two values travel together: `mPosition` (where the cursor is) and `mRemaining`
(how many bytes are still unread).

## 2. When this code runs

**Not only at construction.** Every place `mPosition` is touched in the file:

| Line(s) | Situation | Effect on the cursor |
|---|---|---|
| 27, 35, 43 | construction — a message object is created | placed at byte 0 |
| 65 | reading a bool | reads, does not move |
| **74** | reading a bool | **moves forward 1** |
| 92 | reading a uint8 | moves forward 1 |
| 114-115 | reading a uint16 | moves forward 2 |
| 143-149 | reading a uint32 | moves forward 4 |
| 178-185 | reading a uint64 / double | moves forward 8 |
| 325-326, 343-344 | reading a byte array | moves forward N |
| 386 | `reset()` — object reused for the next message | back to byte 0 |

`MsgDeserializer` (`dk_runtime_msgserdes.h`) derives from `Deserializer`, so any
IPC message carrying a `bool` field reaches line 74. It is live, repeatedly
executed code — once per field, per message, for the life of the system.

## 3. Why the change has no functional effect

Three distinct operations, easily confused:

| Expression | Meaning |
|---|---|
| `*mPosition` | read the byte at the cursor; do not move |
| `mPosition++` | move the cursor forward one; do not read |
| `*mPosition++` | parses as `*(mPosition++)` — **move**, then read the byte the cursor just left |

Post-increment binds tighter than dereference, so **the increment happens in both
forms.** That is the crux: the cursor advance was never at risk.

The function, as it was:

```cpp
if ( 1U > mRemaining )            // line 58: nothing left -> bail out
    ret = false;
else
{
    if ( 0x01U == *mPosition )    // line 65: READ the byte -> true / false
        value = true;
    else
        value = false;

    *mPosition++;                 // line 74: MOVE ... and read again, discarded
    mRemaining--;
}
```

Trace on a buffer whose first byte is `0x01`:

| Step | Line | Action | Cursor after | Result stored? |
|---|---|---|---|---|
| 1 | 58 | `mRemaining` non-zero, continue | 0 | — |
| 2 | 65 | read byte 0 → `0x01` → `value = true` | 0 | yes, into `value` |
| 3 | 74 | move cursor | 1 | — |
| 4 | 74 | read byte 0 again | 1 | **no — discarded** |

Step 4 is the stray `*`. There is no `=` on line 74 and no variable receives the
value; the byte was already read correctly at step 2. The change deletes step 4
and nothing else.

Contrast the overload at line 92, where the `*` does real work:

```cpp
        value = *mPosition++;          // reads AND advances
```

That asymmetry is why line 74 reads as a typo rather than an idiom.

### Could the extra read have been unsafe?

No. The dangerous case would be reading past the end of the buffer. Step 4 reads
the byte the cursor *left*, not the new one, and line 58 already guaranteed that
byte exists. So the old code was wasteful, never incorrect. **This is a cleanup,
not a bug fix — no field issue was being chased.**

## 4. Why the change is worth making

| Reason | Strength |
|---|---|
| Removes a `-Wunused-result` warning from the GCC 15.2.0 cross compiler | main reason — see the caveat below |
| Removes a Klocwork "useless expression" finding (Klocwork runs in this build: `gp_program.cmake:228-233`) | holds on every toolchain |
| States the intent — line 74's job is to advance, not to read | readability |

### Caveat: the warning is toolchain-specific

`*mPosition++` does **not** warn on every compiler. Measured on GCC 13.3.0 with
`-Wall -Wextra -Wunused-value -Wpedantic`: **zero diagnostics.**

The reason is that `*` on a `std::vector<byte_t>::iterator` is a member function
call (`__normal_iterator::operator*`), and GCC does not warn about discarding a
function's return value unless that function is `[[nodiscard]]`. In GCC 13's
libstdc++ it is not (`bits/stl_iterator.h:1096`):

```cpp
      _GLIBCXX20_CONSTEXPR
      reference
      operator*() const _GLIBCXX_NOEXCEPT      // no nodiscard
```

Newer libstdc++ releases added `[[nodiscard]]` to those operators, which is what
makes the SDK's **GCC 15.2.0** emit the warning. Mechanism reproduced in
isolation:

```
warning: ignoring return value of 'unsigned char& It::operator*() const',
         declared with attribute 'nodiscard' [-Wunused-result]
    8 | void f(It &it) { *it++; }
      |                     ^~
```

**Confirm against the actual build log before citing this reason:**

```bash
grep -n 'dk_runtime_deserializer' warnings.txt
```

If that shows a `-Wunused-result` on line 74, the justification holds. If it
shows nothing, the warning came from elsewhere and the reason needs rechecking.

## 5. Verification

Two independent methods. Both live in
`docs/verification/runtime-deserializer-mposition/`.

### 5.1 Host functional test — the primary evidence

`ft_deserialize_bool.cpp` + `run_ft_deserialize_bool.sh`. Compiles the **real
production source file** twice — once with the stray `*` reconstructed, once
without — and runs both. No board, no SDK, no VectorCAST, about five seconds.

```bash
cd docs/verification/runtime-deserializer-mposition
bash run_ft_deserialize_bool.sh /path/to/repo
```

Every case asserts four observable effects: the **return code**, the
**out-parameter**, **`mPosition`**, and **`mRemaining`**.

| Case | Payload | What it proves |
|---|---|---|
| FT-01 | `01` | returns true, `value=true`, cursor +1, remaining 0 |
| FT-02 | `00` | returns true, `value=false`, cursor +1 |
| FT-03 | `FF` | non-`0x01` is false (the `== 0x01U` rule) |
| FT-04 | *(empty)* | returns false, `value` untouched, cursor **not** moved |
| FT-05 | `01 00 01` | cursor goes 1 → 2 → 3 across three calls |
| FT-06 | `01 7E` | the next field still reads `0x7E` — payload intact |

FT-05 and FT-06 are the load-bearing cases: they are what fails if the cursor
stalls or double-advances. The out-parameter is seeded with the *opposite* of the
expected value, so an untouched `value` cannot accidentally look correct.

**Result:**

```
reconstruction OK - the one line that differs:
    74c74
    <         *mPosition++;
    ---
    >         mPosition++;

---------------- original ----------------
=== PASSED (0 check failures) ===
---------------- fixed ----------------
=== PASSED (0 check failures) ===

==========================================================
  FUNCTIONALLY IDENTICAL - all assertions passed in both builds,
  and the two runs produced byte-identical output.
==========================================================
```

31 assertions each side; the two console transcripts are byte-identical under
`cmp`.

### 5.2 Cross object-code comparison — supporting evidence

`verify_object_code.sh`. Uses the **real aarch64 cross compiler and the real
build flags** by replaying ninja's own recorded compile command, so it needs a
clean build with the fix applied first. It then recompiles that one translation
unit with the original source and compares the objects.

```bash
bash verify_object_code.sh        # REPO=... OUT=... to override paths
```

It covers both objects (`dk_runtime` and `dk_runtime_s`), and falls back to
`objdump` disassembly if the raw bytes differ only in metadata.

### 5.3 Diagnostic helper

`diag_bool_fn.sh` is read-only. It prints the line endings, whether the file has
a local modification, the whole function with line numbers, and every
`mPosition++` in the file. Run it first when working in an unfamiliar checkout.

## 6. Why target testing is not required

1. The removed `*` had no consumer — line 74 is a bare statement.
2. The cursor advances identically in both forms (post-increment, §3).
3. The compiler discards the dead read anyway — identical object code at `-O2`.
4. Identical `.o` → identical `libdk_runtime.so.0.11.0` → identical bytes on the board.
5. A target test can only observe the binary's behaviour, and there is no change to observe.

A secondary point: `deserialize(bool_t&)` runs only when a message carries a
`bool` field, so a `systemctl start`/`stop` smoke run may never execute line 74.
A green target run would therefore be weak evidence even if the change *had*
mattered. The host functional test exercises the path directly, which is why it
is the stronger instrument here.

## 7. Gap in the existing VectorCAST suite

`cluster-platform/dijkstra/libraries/runtime/src/test/UT/runtimedeserializer/`
already has three cases on this function — `01_Empty_buffer`, `02_Value_false`,
`03_Value_true` — but each asserts **only the return value**:

```
TEST.EXPECTED:...deserialize(bool_t&)bool.return:true
```

None checks `value`, `mPosition` or `mRemaining`. The suite therefore passes
identically before and after, and **is not evidence about this change.** Saying
"the unit tests pass" is true but says nothing.

To close the gap inside VectorCAST, add `TEST.EXPECTED` lines for `mPosition`
and `mRemaining` to cases 02 and 03 — the same assertions as FT-01/FT-02. Not
done here; raised for the architect to decide.

## 8. Trial cases and problems hit

Recorded because each one cost time and the mistakes are repeatable.

### 8.1 The first runner passed while proving nothing

v1 of the script reconstructed the original with:

```bash
sed -i 's/^\([[:space:]]*\)mPosition++;$/\1*mPosition++;/' "$ORIG"
```

On the first real run it silently failed — both halves compiled **identical
source**, both printed `PASSED`, and the result looked like a clean pass. The
only clue was the script's own grep echoing `74:        mPosition++;` with no
`*`.

Two causes:

- **`$` anchor vs CRLF.** With Windows line endings the line content ends in
  `\r`, so `mPosition++;$` never matches. Likely in a tree that also carries
  `.bat` test harnesses.
- **Line-number assumption.** The pattern was fine but fragile, and the script
  trusted it without checking.

**Fixes in v2:**

- `awk` instead of `sed`, matching `/^[[:space:]]*mPosition\+\+;[[:space:]]*\r?$/`
  — CRLF-tolerant, verified against a deliberately CRLF-converted tree.
- The function is located by pattern (`/deserialize *\( *bool_t *&/`), not by
  line number.
- **A hard `cmp` assertion** that the reconstructed original differs from the
  fixed source. If it does not, the script aborts:
  `ERROR: could not reconstruct the original - the result would prove nothing.`
- A second guard that aborts if the fix is not applied at all, printing the
  current function body.
- The reconstructed diff is printed before building, so the operator can see
  with their own eyes that the two halves differ.

**Lesson: a verification script that can pass without verifying anything is
worse than no script.** Both failure modes now exit non-zero.

### 8.2 `set -o pipefail` killed the script on a successful diff

```bash
diff "$ORIG" "$SRC" | sed 's/^/    /'
```

`diff` returns 1 when files differ — which is the *expected* case here. Under
`set -euo pipefail` that aborted the script immediately after printing the
reconstruction diff, with exit code 1 and no test output at all. Fixed by
wrapping both diffs: `{ diff a b || true; } | sed ...`.

### 8.3 ninja's compile commands are relative to the build directory

The object-code script replays `ninja -t commands` output. Those commands use
`-o` paths relative to the build directory, so running them from the repo root
writes the object to the wrong place and compares stale files. The recompile must
be wrapped: `( cd "$OUT" && eval "$CMD" )`.

Also: this translation unit is compiled **twice** (into `dk_runtime` and
`dk_runtime_s`), so the script resolves and compares both objects rather than
taking `head -1`.

### 8.4 Warning attribution was initially wrong

The `-Wunused-result` on line 74 was first attributed to the line generically.
Testing on GCC 13 produced **no warning at all**, which forced a proper
root-cause: the diagnostic depends on `[[nodiscard]]` in the libstdc++ shipped
with the compiler, and only newer releases carry it on `__normal_iterator`.
See §4. The practical consequence is the `grep warnings.txt` check — the
justification must be confirmed against the real build log, not assumed.

### 8.5 A line-number claim made from a stale reading

While comparing two checkouts, the second `*mPosition++` was stated to be at
line 86 in one tree and 92 in another, and the two files were called different
versions. A direct `grep -n` showed **both at 92** — the files matched. The
earlier figure came from eyeballing a `sed -n '50,95p'` range instead of
grepping. Minor, but it sent the diagnosis briefly down the wrong path.

### 8.6 Environment resets lost uncommitted work twice

The working tree was cleaned by container rebuilds mid-task, discarding the
one-line edit and the scratchpad scripts. Everything here was recreated from the
conversation. **Uncommitted work in an ephemeral environment is not storage** —
which is the reason these scripts now live in the repository rather than in
`/tmp`.

## 9. Status

| Item | State |
|---|---|
| `docs/RUNTIME_DESERIALIZER_MPOSITION_FIX.md` (this file) | committed |
| `docs/verification/runtime-deserializer-mposition/*` (4 files) | committed |
| **The one-line source fix at line 74** | **NOT committed** — awaiting approval |
| VectorCAST assertions for `mPosition` / `mRemaining` | not done — architect decision |
| Target validation | not required (§6) |

Because the fix is not committed, `run_ft_deserialize_bool.sh` run against a
clean checkout of this branch will **abort by design**:

```
ERROR: deserialize(bool_t&) does not contain a bare 'mPosition++;'.
       The fix is not applied in this repo, so there is nothing to verify.
```

That is the intended behaviour. Apply the one-line change to a working tree
first, then run it.

### Why these files are not under `test/FT/`

`cluster-platform/dijkstra/libraries/runtime/src/test/FT/` holds the four
on-target test applications wired into the cross build
(`build_dk_runtime.cmake:42-45`). These scripts are host-side, build with the
host `g++`, and must not be picked up by that build — so they live under `docs/`
beside the document that explains them. Moving them into the test tree is
reasonable if the architect prefers it; they would need a directory the cross
build does not glob.
