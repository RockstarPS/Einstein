ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

SUFFIXES := .build .ifs .raw

BUILD_TEMPLATE = $(CURDIR)/../../Templates_build
INSTALL=../install
BOARD=am62x-evm

export BSP_TARGET_EXTRA=$(CURDIR)/target-extra
# Always specify PSDK_QNX_PATH as path to PSDKQA: this backup path is for internal builds only
export PSDK_QNX_PATH?=../src/hardware/support/ti/am62x/psdkqa

.PHONY: all clean

# For TI build
all: ifs-am62x-evm.raw ifs-am62x-evm-ti.raw

clean:
	$(RM_HOST) *.raw *.sym

ifs-am62x-evm.raw: am62x-evm.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

ifs-am62x-evm-ti.raw: am62x-evm-ti.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

-include $(BUILD_TEMPLATE)/template.mk
