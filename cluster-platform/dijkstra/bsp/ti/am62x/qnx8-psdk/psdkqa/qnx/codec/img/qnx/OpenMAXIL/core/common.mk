ifndef QCONFIG
QCONFIG=qconfig.mk
endif

include $(QCONFIG)
NAME=omxcore_j7

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/khronos/openmaxil
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility

include $(MKFILES_ROOT)/qmacros.mk

INSTALLDIR=usr/lib
define PINFO
PINFO DESCRIPTION=OMX IL Core
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CCFLAGS += -D$(SOC_UPPER)

include $(MKFILES_ROOT)/qtargets.mk

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/
  LIBS += omxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)S.a
endif

