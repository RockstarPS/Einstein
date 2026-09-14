export MCU_PLUS_SDK_PATH?=$(abspath ../../..)
include $(MCU_PLUS_SDK_PATH)/imports.mak

#QNX_IFS_PATH=${DEVNEXT_WORKSPACE_PATH}/programs/reference/einstein4.0/ti-am62x/out/IMG_QNX/${PROJECT_VAR}/${CMAKE_BUILD_TYPE}/IMG_BUILD/images
#PSDK_QNX_PREBUILT_IMAGES=${DEVNEXT_WORKSPACE_PATH}/programs/reference/einstein4.0/ti-am62x/gp-build/qnx/prebuilt_e4_run0/images/prebuilt

#Input qnx binaries
ATF_BIN_NAME=bl31.bin
OPTEE_BIN_NAME=bl32.bin
QNX_BIN_NAME=ifs-primary.bin
FDT_BIN_NAME=psdk_linux_9.2_k3-am62p5-sk-am62pxx-evm.dtb

#QNX image load address
ATF_LOAD_ADDR=0x9e780000
OPTEE_LOAD_ADDR=0x9e800000
QNX_LOAD_ADDR=0x80080000

ifdef FDT_BIN_NAME
FDT_LOAD_ADDR=0x82000000
endif

#Output appimage name
QNX_BOOTIMAGE_NAME=qnx.appimage

#a53ss0-0 core Id for app image
BOOTIMAGE_CORE_ID_a53ss0-0 = 0
