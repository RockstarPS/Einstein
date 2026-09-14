#
#   Copyright (c) 2023, Texas Instruments Incorporated
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#   *  Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   *  Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
#   *  Neither the name of Texas Instruments Incorporated nor the names of
#      its contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

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

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/khronos/openmaxil \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/public/khronos/openmaxil

# Add On lIbraries (AOI) was depricated and support was removed in SDP 8.0.
# Logs will be handled via SLOG.
# LIBS += aoi
LIBS += screen

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += omxcore_j7$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += omxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += slog2
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)S.a
endif

include $(MKFILES_ROOT)/qtargets.mk
