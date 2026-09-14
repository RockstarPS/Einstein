ifeq ($(SOC),$(filter $(SOC), am64x am62x am62a am62px))
PACKAGE_SRCS_COMMON += src/ip/eqep/V0_2
PACKAGE_SRCS_COMMON += cslr_eqep.h csl_eqep.h src/ip/eqep/src_files_eqep.mk
SRCDIR += src/ip/eqep/V0_2/priv
SRCS_COMMON += csl_eqep.c
endif