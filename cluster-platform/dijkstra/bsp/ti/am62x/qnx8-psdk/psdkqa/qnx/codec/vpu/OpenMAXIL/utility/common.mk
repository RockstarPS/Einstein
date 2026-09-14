ifndef QCONFIG
QCONFIG=qconfig.mk
endif

include $(QCONFIG)
NAME=omxil_j7_utility

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

LIBS+=slog2
