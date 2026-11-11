#!/usr/bin/env bash
# Shows what deserialize(bool_t&) looks like in a given repo, and whether the
# file uses CRLF line endings. Read-only.
#   usage: bash diag_bool_fn.sh ~/WORKSPACE/EI26
set -euo pipefail
REPO=${1:?usage: bash diag_bool_fn.sh <repo-path>}
F=$REPO/cluster-platform/dijkstra/libraries/runtime/src/runtime/serdes/dk_runtime_deserializer.cpp
[ -f "$F" ] || { echo "not found: $F"; exit 1; }

echo "file : $F"
echo -n "line endings : "
if grep -q $'\r' "$F"; then echo "CRLF  (this is why the sed failed)"; else echo "LF"; fi
echo -n "git status   : "
( cd "$REPO" && git status --short -- "$F" | grep . || echo "clean (no local modification)" )
echo
echo "=== deserialize(bool_t&) as it exists in this repo ==="
awk '/deserialize *\( *bool_t *&/ {f=1} f {printf "%4d  %s\n", NR, $0} f && /^\}/ {exit}' "$F"
echo
echo "=== every mPosition++ in the file ==="
grep -n 'mPosition++' "$F"
