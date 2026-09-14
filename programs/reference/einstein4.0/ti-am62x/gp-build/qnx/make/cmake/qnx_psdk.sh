#!/bin/bash

# Exit immediately if any command fails
set -e

export QNX_SDP_VERSION=800
export PROFILE=release
export BOARD=am62px_evm
export SOC=am62px
export BOARD_TYPE=sk

action="${1}"

PROJECT_BSP_DIR="${DEVNEXT_WORKSPACE_PATH}/programs/reference/einstein4.0/ti-am62x/qnx8-bsp"
BSP_DIR="${DEVNEXT_WORKSPACE_PATH}/cluster-platform/dijkstra/bsp/ti/am62x"

cp -v "${PROJECT_BSP_DIR}/psdk/psdkqa/qnx/makefile" "${BSP_DIR}/qnx8-psdk/psdkqa/qnx/makefile"
cp -v "${PROJECT_BSP_DIR}/psdk/psdkqa/qnx/scripts/qnx_fs_create_qnx800.mk" "${BSP_DIR}/qnx8-psdk/psdkqa/qnx/scripts/qnx_fs_create_qnx800.mk"

cd "${BSP_DIR}/qnx8-psdk/psdkqa/qnx"

if [ "${action}" == "build" ]; then
    echo "Building QNX PSDK"
    make all
    make qnx_fs_create
elif [ "${action}" == "clean" ]; then
    echo "Cleaning QNX PSDK"
    make clean
else
    echo "Invalid action. Usage: $0 [build|clean]"
    exit 1
fi
