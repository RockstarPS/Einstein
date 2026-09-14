export QNX_SDP_VERSION ?= 800
ifeq ($(QNX_SDP_VERSION), 800)
export QNX_BASE ?= $(HOME)/qnx800
export QNX_CROSS_COMPILER_TOOL ?= aarch64-unknown-nto-qnx8.0.0-
export QNX_TARGET ?= $(QNX_BASE)/target/qnx
export MAKEFLAGS=-I$(QNX_BASE)/target/qnx/usr/include
else
export QNX_BASE ?= $(HOME)/qnx710
export QNX_CROSS_COMPILER_TOOL ?= aarch64-unknown-nto-qnx7.1.0-
export QNX_TARGET ?= $(QNX_BASE)/target/qnx7
export MAKEFLAGS=-I$(QNX_BASE)/target/qnx7/usr/include
endif

export PSDK_QNX_PATH ?= $(abspath ..)
export PDK_QNX_PATH ?= $(PSDK_QNX_PATH)/pdk
export QNX_HOST ?= $(QNX_BASE)/host/linux/x86_64
export QNX_BOOT_PATH ?= $(PSDK_QNX_PATH)/bootfs
export QNX_FS_PATH ?= $(PSDK_QNX_PATH)/qnxfs
export QNX_AUX_FS_PATH ?= $(PSDK_QNX_PATH)/rootfs
export PATH=$(QNX_HOST)/usr/bin:$(shell printenv PATH)
export LINUX_FS_BOOT_PATH ?= $(PSDK_QNX_PATH)/../bootfs
export VISION_APPS_PATH ?= $(abspath ../../vision_apps)
export QNX_ARCH=aarch64le

## Added for building SBL
export PSDK_RTOS_PATH ?= $(abspath ../..)
export PDK_PATH ?= $(PSDK_RTOS_PATH)/pdk
ifeq ($(SOC),am62a)
export MCU_PLUS_PATH=~/ti/mcu_plus_sdk_am62ax_10_00_00_14
else ifeq ($(SOC),am62x)
export MCU_PLUS_PATH=~/ti/mcu_plus_sdk_am62x_10_00_00_14
else ifeq ($(SOC),am62px)
export MCU_PLUS_PATH=~/ti/mcu_plus_sdk_am62px_10_00_00_14
endif
export GCC_LINUX_ARM_ROOT ?= $(PSDK_RTOS_PATH)/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu
export ETHFW_PATH ?= $(PSDK_RTOS_PATH)/ethfw
