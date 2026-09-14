ifndef QCONFIG
QCONFIG=qconfig.mk
endif
#CCFLAGS += -O0 -g
#CCFLAGS+=-DAO_LOGLVL=AO_LOG_DEBUG2
include $(QCONFIG)

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/khronos/openmaxil \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/public/khronos/openmaxil

NAME=omxil_video_dec
INSTALLDIR=usr/bin

define PINFO
PINFO DESCRIPTION = OpenMAX IL Test - Video Decode
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

include $(MKFILES_ROOT)/qtargets.mk

LIBS += screen

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += omxcore_j7$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += omxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += slog2
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)S.a
endif