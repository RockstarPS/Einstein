ifdef PSDK_QNX_PATH
# Error if PSDK_QNX_PATH is provided but doesn't exist
ifeq ("$(wildcard $(PSDK_QNX_PATH))","")
$(error TI PSDKQA ($(PSDK_QNX_PATH)): path not found)
endif

$(info TI PSDKQA ($(PSDK_QNX_PATH)): driver will be built with DMA support!)
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/pdk/packages
EXTRA_INCVPATH += $(PSDK_QNX_PATH)

# Eventually all devices will use these libs once TI PSDK 8.1 is released
EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/so.le
EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/so.le
EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld/aarch64/so.le
EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/so.le
LIBS+=ti-pdk
LIBS+=ti-sciclient
LIBS+=ti-udmalld
LIBS+=tiudma-usr
else
$(warning TI PSDKQA not found: driver will be built without DMA support!)
endif
