#!/usr/bin/env bash
# Runs the deserialize(bool_t&) functional test against BOTH the original and
# the fixed production source, on the host. No board, no SDK, no VectorCAST.
#
#   usage: bash run_ft_deserialize_bool.sh [path-to-repo]
#
# Reconstructs the ORIGINAL by putting the stray '*' back on the bare
# 'mPosition++;' inside deserialize(bool_t&). Aborts if that reconstruction
# changes nothing, because then both halves would compile identical source and
# the comparison would be meaningless.
set -euo pipefail

REPO=${1:-${REPO:-$HOME/WORKSPACE/VerifyBoostRepo}}
REPO=${REPO%/}
SERDES=$REPO/cluster-platform/dijkstra/libraries/runtime/src/runtime/serdes
FT=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/ft_deserialize_bool.cpp
WORK=${WORK:-/tmp/ft-bool}
CXX=${CXX:-g++}

[ -f "$SERDES/dk_runtime_deserializer.cpp" ] || { echo "ERROR: not a repo: $REPO"; exit 1; }
[ -f "$FT" ] || { echo "ERROR: ft_deserialize_bool.cpp not found next to this script"; exit 1; }
rm -rf "$WORK"; mkdir -p "$WORK"

SRC=$SERDES/dk_runtime_deserializer.cpp
echo "repo   : $REPO"
echo -n "endings: "; grep -q $'\r' "$SRC" && echo "CRLF" || echo "LF"

# ---- the fixed source must actually contain the fix ------------------------
if ! awk '/deserialize *\( *bool_t *&/{f=1} f && /^[[:space:]]*mPosition\+\+;[[:space:]]*\r?$/{found=1}
          f && /^\}/{exit} END{exit !found}' "$SRC"; then
    echo
    echo "ERROR: deserialize(bool_t&) does not contain a bare 'mPosition++;'."
    echo "       The fix is not applied in this repo, so there is nothing to verify."
    echo "       Current body:"
    awk '/deserialize *\( *bool_t *&/{f=1} f{printf "         %4d  %s\n", NR, $0} f && /^\}/{exit}' "$SRC"
    exit 1
fi

# ---- reconstruct the original ---------------------------------------------
cp -r "$SERDES" "$WORK/orig"
ORIG=$WORK/orig/dk_runtime_deserializer.cpp
awk '
    /deserialize *\( *bool_t *&/           { infn = 1 }
    infn && !done && /^[[:space:]]*mPosition\+\+;[[:space:]]*\r?$/ {
        sub(/mPosition\+\+;/, "*mPosition++;"); done = 1
    }
    infn && /^\}/                          { infn = 0 }
                                           { print }
' "$SRC" > "$ORIG.tmp"
mv "$ORIG.tmp" "$ORIG"

# ---- HARD ASSERTION: the two sources must differ --------------------------
if cmp -s "$SRC" "$ORIG"; then
    echo
    echo "ERROR: could not reconstruct the original - the two sources are identical."
    echo "       Refusing to run, because the result would prove nothing."
    exit 1
fi
echo
echo "reconstruction OK - the one line that differs:"
{ diff "$ORIG" "$SRC" || true; } | sed "s/^/    /"

# ---- build and run both ---------------------------------------------------
run() {   # run <label> <include-and-source-dir>
    local label=$1 dir=$2
    "$CXX" -O2 -Wall -I"$dir" "$FT" "$dir/dk_runtime_deserializer.cpp" -o "$WORK/ft_$label" 2>&1 \
        | grep -v 'mPosition++' || true
    echo "---------------- $label ----------------"
    "$WORK/ft_$label" | tee "$WORK/out_$label.txt"
    echo
}
run original "$WORK/orig"
run fixed    "$SERDES"

# ---- verdict --------------------------------------------------------------
echo "=========================================================="
if cmp -s "$WORK/out_original.txt" "$WORK/out_fixed.txt"; then
    if grep -q 'FAILED' "$WORK/out_fixed.txt"; then
        echo "  Outputs match, but assertions FAILED in both. Investigate."
        exit 1
    fi
    echo "  FUNCTIONALLY IDENTICAL - all assertions passed in both builds,"
    echo "  and the two runs produced byte-identical output."
    echo "  Compared: $WORK/out_original.txt"
    echo "            $WORK/out_fixed.txt"
else
    echo "  *** BEHAVIOUR DIFFERS - the fix changes observable behaviour. ***"
    { diff "$WORK/out_original.txt" "$WORK/out_fixed.txt" || true; } | sed "s/^/  /"
    exit 1
fi
echo "=========================================================="
