ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

define PINFO
PINFO DESCRIPTION=J7 video encoder lib
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

NAME = timmenc
INSTALLDIR = usr/lib

#Add extra include path
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/driver/encoder \
                $(PSDK_QNX_PATH)/qnx/codec/img/driver/decoder \
                $(PSDK_QNX_PATH)/qnx/codec/img/driver/common \
                $(PSDK_QNX_PATH)/qnx/codec/img \
                $(PSDK_QNX_PATH)/qnx/codec/img/osal/inc \
                $(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include

#for pdk
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/pdk/packages

EXTRA_SRCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/driver/encoder \
                $(PSDK_QNX_PATH)/qnx/codec/img/driver/common \
                $(PSDK_QNX_PATH)/qnx/codec/img/osal/src/qnx \
                $(PSDK_QNX_PATH)/qnx/codec/img/timmlib/encoder

CCFLAGS=-DOSAL_QNX -DSOC_J721E -DQNX_OS
#for debug purpose
#CCFLAGS+=-DDEBUG_ENCODER_DRIVER


include $(MKFILES_ROOT)/qtargets.mk
