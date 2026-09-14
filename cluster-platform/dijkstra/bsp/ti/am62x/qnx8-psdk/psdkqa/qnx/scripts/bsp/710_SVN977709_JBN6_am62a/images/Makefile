ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs
SUFFIXES := .build .ifs .raw

BUILD_TEMPLATE = $(CURDIR)/../../Templates_build
INSTALL=../install
BOARD=am62a-evm

export BSP_TARGET_EXTRA=$(CURDIR)/target-extra
# Always specify PSDK_QNX_PATH as path to PSDKQA: this backup path is for internal builds only
export PSDK_QNX_PATH?=../src/hardware/support/ti/am62a/psdkqa

.PHONY: all clean
.NOTPARALLEL:

# For TI build
all: ifs-am62a-evm.raw ifs-am62a-evm-ti.raw

clean:
	$(RM_HOST) *.raw *.sym

ifs-$(BOARD).raw: $(BOARD).build
	$(HOST_MKIFS) -r$(INSTALL) $(MKIFSFLAGS) $^ $@

ifs-$(BOARD)-ti.raw: $(BOARD)-ti.build
	$(HOST_MKIFS) -v -r$(INSTALL) $(MKIFSFLAGS) $^ $@

-include $(BUILD_TEMPLATE)/template.mk
