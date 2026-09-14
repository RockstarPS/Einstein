ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

include $(MKFILES_ROOT)/qmacros.mk

EXTRA_INCVPATH+=$(PROJECT_ROOT)/../../public

IS_DEBUG_BUILD:=$(filter g, $(VARIANT_LIST))
DBG_LIBSUFFIX := $(if $(IS_DEBUG_BUILD),_g)
DBG_DIRSUFFIX := $(if $(IS_DEBUG_BUILD),-debug)

CCFLAGS += $(if $(IS_DEBUG_BUILD), -O0)
CCFLAGS += $(PLATFORM_CCFLAGS)

# You can change the NAME line to rename the .so file, but don't change
# SONAME_DLL--the WFD driver is linked against a specific SONAME.
SONAME_DLL=$(IMAGE_PREF_SO)wfdcfg$(IMAGE_SUFF_SO).0
NAME=$(IMAGE_PREF_SO)wfdcfg-$(PROJECT)

INSTALLDIR:=usr/lib/graphics/am62p$(DBG_DIRSUFFIX)

DESC=Returns a list of display timings and extensions for the TI AM62XX EVM board.

define PINFO
PINFO DESCRIPTION = "$(DESC)"
endef

INSTALL_ROOT_nto = $(PROJECT_ROOT)/../../../../../../install
USE_INSTALL_ROOT=1

include $(MKFILES_ROOT)/qtargets.mk
