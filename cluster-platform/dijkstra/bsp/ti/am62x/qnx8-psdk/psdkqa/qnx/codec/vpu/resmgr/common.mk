#
#   Copyright (c) 2022, Texas Instruments Incorporated
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

NAME = ti-vpu-codec-mgr
INSTALLDIR = bin
USEFILE=$(PROJECT_ROOT)/$(NAME).use

define PINFO
PINFO DESCRIPTION=TI VPU Codec Resource Manager
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CCOPTS += -D$(SOC_UPPER) -DQNX_RES_MGR -DQNX_OS
CCOPTS += -fPIC

#Add extra include path
EXTRA_INCVPATH += $(PDK_INSTALL_PATH)
EXTRA_INCVPATH += $(PROJECT_ROOT)/inc
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/public
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/encoder
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/decoder
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/helper
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/common
EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/

#Add source path
EXTRA_SRCVPATH +=$(PROJECT_ROOT)/src

LIBS = c

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += ti-pdk$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-sciclient$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += sharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/sciclient.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.csl.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.osal.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/ti.board.aa72fg
  LIBS += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX)S.a
endif

include $(MKFILES_ROOT)/qtargets.mk
