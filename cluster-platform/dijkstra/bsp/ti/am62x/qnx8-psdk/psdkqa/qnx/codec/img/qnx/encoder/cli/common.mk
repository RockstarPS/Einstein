ifndef QCONFIG
QCONFIG=qconfig.mk
endif

include $(QCONFIG)

NAME=vxe_enc-cli

EXTRA_INCVPATH += $(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include \
                  $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/driver \
                  $(PSDK_QNX_PATH)/qnx/codec/img/osal/inc

include $(MKFILES_ROOT)/qmacros.mk

INSTALLDIR=usr/lib

define PINFO
PINFO DESCRIPTION = TI-J721e encode resource manager client library
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

CCFLAGS=-DOSAL_QNX -DSOC_J721E -DQNX_OS

include $(MKFILES_ROOT)/qtargets.mk
