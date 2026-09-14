ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

SUFFIXES := .build .ifs

BUILD_TEMPLATE = $(CURDIR)/../../Templates_build_sdp800
INSTALL=../install
BOARD=am62p-evm

export BSP_TARGET_EXTRA=$(CURDIR)/target-extra
# Always specify PSDK_QNX_PATH as path to PSDKQA: this backup path is for internal builds only
export PSDK_QNX_PATH?=../src/hardware/support/ti/am62p/psdkqa

.PHONY: all clean

all: ifs-$(BOARD).raw

clean:
	$(RM_HOST) *.raw *.sym

ifs-$(BOARD).raw: $(BOARD).build
	$(HOST_MKIFS) -r$(INSTALL) $(MKIFSFLAGS) $^ $@

-include $(BUILD_TEMPLATE)/template.mk
