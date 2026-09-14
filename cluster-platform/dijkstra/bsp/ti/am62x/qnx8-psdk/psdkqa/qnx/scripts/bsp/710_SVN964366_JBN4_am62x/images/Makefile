ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

SUFFIXES := .build .ifs .raw

export BSP_TARGET_EXTRA=$(CURDIR)/target-extra

.PHONY: all clean
.NOTPARALLEL:

# For TI build
#all: ifs-am62x-evm.raw
all: ifs-am62x-evm.raw ifs-am62x-evm-ti.raw

clean:
	$(RM_HOST) *.raw *.sym

ifs-am62x-evm.raw: am62x-evm.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

ifs-am62x-evm-ti.raw: am62x-evm-ti.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

-include $(BUILD_TEMPLATE)/template.mk
