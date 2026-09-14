### COMMON CONFIG ###
CFLAGS ?=
MAKE_JOBS ?= 1

###############################################################################
# TI SDK CONFIGURATION
#
# CI / DevNext provides TI_HOME as the final SDK root path.
# When TI_HOME is set, do NOT interpret, version-scan, or re-discover the SDK.
#
# Conan fallback exists only for local development convenience.
# Conan cache layout is unstable with Conan 2.x and must NOT be relied on in CI.
###############################################################################

ifeq ($(TI_HOME),)

    # TI_HOME not set → local development fallback path

    ifeq ($(CONAN_HOME),)
        CONAN_HOME ?= $(HOME)
    else
        # : intentional empty else branch
    endif

    TI_SDK_DIR_BASE ?= $(CONAN_HOME)/.conan/data/ti-sdk

    # Auto-detect latest TI SDK version from Conan cache (Conan 1.x layout)
    TI_SDK_VERSION ?= $(shell ls -1 $(TI_SDK_DIR_BASE) 2>/dev/null | sort -Vr | head -n 1)

    # Sanity check: version must exist in Conan cache
    ifeq ($(TI_SDK_VERSION),)
        $(error "TI SDK not found in Conan cache. Please set TI_HOME to SDK root or install ti-sdk via Conan.")
    else
        # Locate ti_sdk inside Conan package tree
        TI_SDK_BASE ?= $(shell find $(TI_SDK_DIR_BASE)/$(TI_SDK_VERSION)/visteon/stable/package -type d -name "ti_sdk" 2>/dev/null | head -n 1)

        # Final validation for Conan path
        ifeq ($(TI_SDK_BASE),)
            $(error "Failed to locate ti_sdk directory in Conan cache.")
        else
            export TI_SDK_PATH ?= $(TI_SDK_BASE)
        endif
    endif

else

    # TI_HOME is set, use it directly as SDK root (CI / DevNext path)
    # No version scanning, no subfolder logic
    export TI_SDK_PATH ?= $(TI_HOME)

endif

# Final global sanity check (applies to both CI and local dev paths)
ifeq ($(TI_SDK_PATH),)
    $(error "TI_SDK_PATH is empty. SDK resolution failed.")
endif

###############################################################################
# Common build configuration for OP-TEE Security Library
###############################################################################

export OPTEE_SECMGR_PATH ?= $(CURDIR)

# Compiler and linker flags
export CFLAGS  += -I$(TI_SDK_PATH)/sysroots/aarch64-oe-linux/usr/include/uuid
export LDFLAGS += -L$(TI_SDK_PATH)/sysroots/aarch64-oe-linux/usr/lib/aarch64-oe-linux/11.4.0
export SYSROOT_PATH ?= $(TI_SDK_PATH)

# SDK sysroot paths
SDK_PATH_TARGET ?= $(TI_SDK_PATH)/sysroots/aarch64-oe-linux
SDK_PATH_HOST   ?= $(TI_SDK_PATH)/sysroots/x86_64-arago-linux

# Source and prebuilt directories
OPTEEOS_PREBUILT_DIR      ?= $(OPTEE_SECMGR_PATH)/Prebuilt_OS/arm-plat-k3/export-ta_arm64
OPTEECLIENT_PREBUILT_DIR  ?= $(OPTEE_SECMGR_PATH)/Prebuilt_client
SECURITY_MANAGER_SRC      ?= $(OPTEE_SECMGR_PATH)/SecurityManager

# OP-TEE development exports
export TA_DEV_KIT_DIR ?= $(OPTEEOS_PREBUILT_DIR)
export TEEC_EXPORT    ?= $(OPTEECLIENT_PREBUILT_DIR)/out/export/usr

# Toolchain configuration
ARCH ?= arm64
CROSS_COMPILE ?= $(SDK_PATH_HOST)/usr/bin/aarch64-oe-linux/aarch64-oe-linux-

export CROSS_COMPILE
export CC = $(CROSS_COMPILE)gcc --sysroot=$(SDK_PATH_TARGET)

# Build targets and parallelism
MAKE_ALL_TARGETS ?= optee-securitylib
MAKE_JOBS ?= 16
