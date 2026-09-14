ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

define PINFO
PINFO DESCRIPTION=J7 video encoder cli unit test app
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

NAME = enc_cli_ut
INSTALLDIR = usr/bin

#Add extra include path
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli

LIBS = c

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += vxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX)S.a
endif

include $(MKFILES_ROOT)/qtargets.mk
