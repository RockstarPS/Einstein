ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

NAME=omxil_video_enc
INSTALLDIR=usr/bin

define PINFO
PINFO DESCRIPTION = OpenMAX IL Test - Video Encode
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CXXFLAGS += -D$(SOC_UPPER)
CXXFLAGS+=-DAO_LOGLVL=AO_LOG_DEBUG2

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/khronos/openmaxil \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/public/khronos/openmaxil

# Add On lIbraries (AOI) was depricated and support was removed in SDP 8.0.
# Logs will be handled via SLOG.
# LIBS += aoi
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

include $(MKFILES_ROOT)/qtargets.mk
