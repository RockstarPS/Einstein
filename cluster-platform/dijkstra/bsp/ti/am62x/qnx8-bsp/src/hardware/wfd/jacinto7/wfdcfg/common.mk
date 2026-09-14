ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

ALL_DEPENDENCIES=$(PROJECT_ROOT)/Makefile
INSTALLDIR=/dev/null
PUBLIC_INCVPATH=$(PROJECT_ROOT)/public

include $(MKFILES_ROOT)/qmacros.mk
include $(MKFILES_ROOT)/qtargets.mk
