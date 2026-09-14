set -x
cp out/qnx/release/compile_commands.json compile_commands.json
sed -i 's+bin/qcc -Vgcc_ntoaarch64le+bin/ntoaarch64-gcc+g' compile_commands.json
sed -i 's+bin/q\+\+ -Vgcc_ntoaarch64le+bin/ntoaarch64-g\+\++g' compile_commands.json
sed -i 's+-NDEBUG++g' compile_commands.json
qcc -Vgcc_ntoaarch64le -dM -xc /dev/null -c -v -E 1> ~/qcc.inc
pkill clang
exit 0
