#!/usr/bin/env bash
# Confirms that removing the stray '*' from *mPosition++ in
# dk_runtime_deserializer.cpp changes no generated code, using the REAL
# cross compiler and the REAL build flags.
#
# PRE-REQUISITE: a CLEAN BUILD has already been done WITH the fix applied.
# This script does not build the tree; it recompiles one translation unit
# using ninja's own recorded compile command.
#
#   usage: bash verify_object_code.sh
#     REPO=... OUT=... OBJDUMP=... override the defaults
set -euo pipefail

REPO=${REPO:-$HOME/WORKSPACE/VerifyBoostRepo}
OUT=${OUT:-$REPO/programs/reference/einstein4.0/ti-am62x/out/GP_LINUX/EINSTEIN_4_0_A0/release}
SRC=cluster-platform/dijkstra/libraries/runtime/src/runtime/serdes/dk_runtime_deserializer.cpp
OBJDUMP=${OBJDUMP:-aarch64-oe-linux-objdump}
WORK=${WORK:-/tmp/mposition-check}

mkdir -p "$WORK"
cd "$REPO"

# --- sanity -----------------------------------------------------------------
[ -f "$OUT/build.ninja" ] || { echo "no build.ninja under $OUT - clean build first"; exit 1; }
git diff --quiet -- "$SRC" && { echo "$SRC has no local change - nothing to verify"; exit 1; }

# --- every object built from this source (expect 2: dk_runtime, dk_runtime_s)
mapfile -t OBJS < <(find "$OUT" -name 'dk_runtime_deserializer.cpp.o' | sort)
[ "${#OBJS[@]}" -gt 0 ] || { echo "no objects found - was the clean build successful?"; exit 1; }
echo "objects: ${#OBJS[@]}"
printf '  %s\n' "${OBJS[@]}"

# --- ninja's exact compile lines --------------------------------------------
ALL=$WORK/all-commands.txt
ninja -C "$OUT" -t commands > "$ALL"

save() { local tag=$1 i
         for i in "${!OBJS[@]}"; do cp "${OBJS[$i]}" "$WORK/$tag.$i.o"; done; }

recompile() { local O REL CMD
  for O in "${OBJS[@]}"; do
    REL=${O#"$OUT"/}
    CMD=$(grep -F -- "$REL" "$ALL" | grep -- ' -c ' | head -1)
    [ -n "$CMD" ] || { echo "no compile command recorded for $REL"; exit 1; }
    # MUST run from the build dir: ninja's object paths are relative to it.
    ( cd "$OUT" && eval "$CMD" )
  done; }

# --- fixed objects come from your clean build -------------------------------
save fixed

# --- original: path-limited stash, so other local changes are untouched -----
git stash push -- "$SRC" >/dev/null
trap 'git stash list | grep -q . && git stash pop >/dev/null 2>&1 || true' EXIT
recompile
save orig
git stash pop >/dev/null
trap - EXIT

# --- leave the tree matching the fixed source -------------------------------
recompile

# --- compare -----------------------------------------------------------------
rc=0
for i in "${!OBJS[@]}"; do
  echo
  echo "=== ${OBJS[$i]}"
  if cmp -s "$WORK/orig.$i.o" "$WORK/fixed.$i.o"; then
    echo "    BYTE-IDENTICAL"
  else
    echo "    bytes differ - falling back to disassembly"
    if ! command -v "$OBJDUMP" >/dev/null; then
      echo "    $OBJDUMP not on PATH; set OBJDUMP=<cross objdump> and re-run"; rc=1; continue
    fi
    for t in orig fixed; do
      "$OBJDUMP" -d --no-show-raw-insn "$WORK/$t.$i.o" | tail -n +3 > "$WORK/$t.$i.asm"
    done
    if diff -u "$WORK/orig.$i.asm" "$WORK/fixed.$i.asm"; then
      echo "    ASSEMBLY IDENTICAL (object metadata only)"
    else
      echo "    *** CODE DIFFERS - investigate above ***"; rc=1
    fi
  fi
done
echo
exit $rc
