################################################################################
# Makefile for creating VMF standalone
################################################################################


################################################################################
# Path structure
################################################################################
NETWORK_VOB = .

ARMLE_LIB_DIR=rel/$(PROJECT)/libs
ARMLE_BIN_DIR=rel/$(PROJECT)/bin

IDIR = $(NETWORK_VOB)/include
OBJ_PATH    = $(subst \,/,$(CURDIR)/rel/$(PROJECT)/obj)

################################################################################
# Compiler
################################################################################

# default
#CC=invalid  # Don't set! Could be available via environment!
CL=invalid
CI=invalid
os=linux
project = $(PROJECT)
SO_FPIC = -fPIC
BIN_FPIC = -fPIC
CC_FLAG_DEBUG = -ggdb
SHARED = -shared

# Compiler for 32 bit Windows
ifeq ($(PROJECT),WINDOWS_X86)
    ifeq ($(HOST),WINDOWS)
		# MinGW32 Compiler
        SYS_LIBS = -L$(NETWORK_CONFIG_DIR)/pthread_w32/libs -lpthreadVC2 -lws2_32
		CC=i686-w64-mingw32-gcc
		AR=i686-w64-mingw32-gcc-ar
		DLLTOOL=dlltool -C
        os=windows
        SO_FPIC =
        BIN_FPIC =
    else
        CC=i586-mingw32msvc-gcc -v
        AR=i586-mingw32msvc-ar
        DLLTOOL=i586-mingw32msvc-dlltool -C
        os=windows
        SYS_LIBS = -L$(NETWORK_CONFIG_DIR)/pthread_w32/libs -lpthreadVC2 -lws2_32
        SO_FPIC =
        BIN_FPIC =
    endif
endif

ifeq ($(PROJECT),WINDOWS_X86_64)
	CC=x86_64-w64-mingw32-gcc -v
	AR=x86_64-w64-mingw32-gcc-ar
	DLLTOOL=dlltool -C
	os=windows
	SYS_LIBS = -lws2_32
	SO_FPIC =
	BIN_FPIC =
endif

# Compiler for local Linux
ifeq ($(PROJECT),LINUX_X86)
	CC=gcc
endif

# Compiler for local Linux on 64bit machine
ifeq ($(PROJECT),LINUX_X86_64)
	CC=gcc
	
	# Linux Mint PC --> Innovation Fraunhofer Renderer PC
	#CC=gcc-4.4		
endif

# Compiler for local Linux
ifeq ($(PROJECT),LINUX_X86_GCOV)
	CC=gcc
endif

# Compiler for ARM HF (hard float)
ifeq ($(PROJECT),LINUX_ARM_HF)
	# Ubuntu
	CC=arm-linux-gnueabihf-gcc-4.6
	# Mint PC
	#CC=arm-linux-gnueabihf-gcc-4.8
endif

# CrossCompiler for R0-13 ARM!
ifeq ($(PROJECT),R013)
	CC=arm-none-linux-gnueabi-gcc
endif

# CrossCompiler for EAGLE ARM!
ifeq ($(PROJECT),EAGLE)
	CC=arm-fsl-linux-gnueabi-gcc
endif

# CrossCompiler for EAGLE Update ARM!
# jmerkle 2016-07-07: 
#     With introduction of U321 (compiler with same name!), EAGLE_UPDATE is hardfloat!
ifeq ($(PROJECT),EAGLE_UPDATE)
	CC=arm-oe-linux-gnueabi-gcc
endif

# CrossCompiler for QNX x86!
ifeq ($(PROJECT),QNX_X86)
	AR=ntox86-ar
	CC=qcc -V gcc_ntox86
 	os=qnx
endif

# CrossCompiler for QNX x86!
ifeq ($(PROJECT),QNX_700_X86_64)
	AR=ntox86_64-ar
	CC=qcc -V gcc_ntox86_64
 	os=qnx
endif

ifeq ($(PROJECT),QNX_660_ARMV7)
	AR=ntoarmv7-ar
	CC=qcc -V gcc_ntoarmv7le
 	os=qnx
endif

# CrossCompiler for QNX7 aarch64!
ifeq ($(PROJECT),QNX_700_AARCH64)
	AR=ntoaarch64-ar
	CC=qcc -V gcc_ntoaarch64le
 	os=qnx
endif

# CrossCompiler for QNX710 aarch64!
ifeq ($(PROJECT),QNX_710_AARCH64)
	AR=ntoaarch64-ar
	CC=qcc -V gcc_ntoaarch64le
 	os=qnx
endif

# CrossCompiler for QNX7 armv7!
ifeq ($(PROJECT),QNX_700_ARMV7)
	AR=ntoarmv7-ar
	CC=qcc -V gcc_ntoarmv7le
 	os=qnx
endif

# CrossCompiler for Linux aarch64!
ifeq ($(PROJECT),LINUX_AARCH64)
	CC=aarch64-linux-gnu-gcc
	AR=aarch64-linux-gnu-ar
endif

# CrossCompiler for Nissan DC1.5 (QNX ARM) !
ifeq ($(PROJECT),DC15)
	AR = ntoarm-ar
	CC=qcc  -V 4.4.2,gcc_ntoarmle
 	os=qnx
endif

# CrossCompiler for Einstein / X351 Cluster (QNX ARM) !
ifeq ($(PROJECT),EINSTEIN)
	AR = ntoarm-ar
	CC=qcc  -V 4.4.2,gcc_ntoarmle
 	os=qnx
endif

# CrossCompiler for OpenSynergy Linux on ARM!
ifeq ($(PROJECT),OPENSYN)
    STATIC=-static -pthread
	CC=arm-unknown-linux-gnueabi-gcc
endif

# CrossCompiler for Ford D544 Cluster (QNX ARM) !
ifeq ($(PROJECT),D544)
	ifeq ($(HOST),WINDOWS)
		AR=ntoarmv7-ar
		CC=qcc -V gcc_ntoarmv7le
		os=qnx
	else
		AR=ntoarm-ar
		CC=qcc -V gcc_ntoarmv7le
		os=qnx
	endif
endif

# CrossCompiler for PSA P2D3 Cluster (QNX ARM)!
ifeq ($(PROJECT),P2D3)
	ifeq ($(HOST),WINDOWS)
		AR=ntoarmv7-ar
		CC=qcc -V gcc_ntoarmv7le
		os=qnx
	else
		AR=ntoarm-ar
		CC=qcc -V gcc_ntoarmv7le
		os=qnx
	endif
endif

# Compiler for INNO ARM 
ifeq ($(PROJECT),INNO_ARM)
	CC=arm-linux-gnueabi-gcc
	AR=arm-linux-gnueabi-ar
endif

# Compiler for INNO ARM HF (hard float)
ifeq ($(PROJECT),INNO_ARM_HF)
	CC=arm-linux-gnueabihf-gcc-4.6
endif

# Compiler for INNO_WINDOWS (32 bit)
ifeq ($(PROJECT),INNO_WINDOWS)
	CC=i586-mingw32msvc-gcc -v
	AR=i586-mingw32msvc-ar
	DLLTOOL=i586-mingw32msvc-dlltool -C
	os=windows
	SYS_LIBS = -L$(NETWORK_CONFIG_DIR)/pthread_w32/libs -lpthreadVC2 -lws2_32
	SO_FPIC =
	BIN_FPIC =
endif

# Compiler for INNO_WINDOWS_64 (64 bit)
ifeq ($(PROJECT),INNO_WINDOWS_64)
	CC=x86_64-w64-mingw32-gcc -v
	AR=x86_64-w64-mingw32-ar
	DLLTOOL=x86_64-w64-mingw32-dlltool -C
	os=windows
	SYS_LIBS = -lws2_32
	SO_FPIC =
	BIN_FPIC =
endif

# Compiler for RasPi
ifeq ($(PROJECT),RASPI)
	CC=gcc
endif

# CrossCompiler for U321 ARM!
ifeq ($(PROJECT),U321)
	#set by environment script which is executed in build.sh!
    #CC=arm-oe-linux-gnueabi-gcc
endif

# CrossCompiler for Integrity RTOS
ifeq ($(PROJECT),INTEGRITY)
	ifeq ($(HOST),WINDOWS)
		CC=C:/ghs/comp_201416/ccintarm
		CL=C:/ghs/comp_201416/ccintarm
		AR=C:/ghs/comp_201416/ccintarm -archive
		CI=C:/ghs/int1124-P2/multi/bin/win32/intex 
	else
		CC=/opt/ghs/ghs.comp_201416_linux/ccintarm
		CL=/opt/ghs/ghs.comp_201416_linux/ccintarm
		AR=/opt/ghs/ghs.comp_201416_linux/ccintarm -archive
		CI=/opt/ghs/ghs.int1124-P2/multi/bin/linux86/intex 
	endif
	
	os=integrity
	CC_FLAG_DEBUG = -G
	SYS_LIBS = -lposix -lshm_client -lsocket -livfs -lnet
	SHARED=#
endif


# Compiler for Visteon components
QCC_COMPILER = $(MAKE_ECHO)$(CC) -c  $(CC_FLAGS)


################################################################################
# Tools
################################################################################
RM=rm -rf
MKDIR=mkdir -p
ECHO=@echo
ECHO_COMPILING=@echo "Compiling $<"
ECHO_LINKING=@echo "Linking..."


################################################################################
# Flags and options
################################################################################
CC_FLAGS =-I$(IDIR) -O0 $(CC_FLAG_DEBUG) -D_GNU_SOURCE  -Wall -Werror-implicit-function-declaration


################################################################################
# help output
################################################################################
.PHONY: help

ifdef PROJECT

help:
	@$(ECHO)
	@$(ECHO) make PROJECT=$(PROJECT)
	@$(ECHO)
	@$(ECHO) "    os        = $(os)"
	@$(ECHO) "    os-config = $(NETWORK_CONFIG_DIR)"
	@$(ECHO) "    CC        = $(CC)"
	@$(ECHO) "    CC_FLAGS  = $(CC_FLAGS)"
	@$(ECHO) "    AR        = $(AR)"
	@$(ECHO) "    DLLTOOL   = $(DLLTOOL)"
	@$(ECHO) "    SYS_LIBS  = $(SYS_LIBS)"
	@$(ECHO) "    SO_FPIC   = $(SO_FPIC)"
	@$(ECHO) "    BIN_FPIC  = $(BIN_FPIC)"
	@$(ECHO)


else

help:
	@$(ECHO)
	@$(ECHO) Variants that can be built are:
	@$(ECHO) make PROJECT=WINDOWS_X86
	@$(ECHO) make PROJECT=LINUX_X86
	@$(ECHO) make PROJECT=QNX_X86
	@$(ECHO) make PROJECT=QNX_660_ARMV7
	@$(ECHO) make PROJECT=QNX_700_X86_64
	@$(ECHO) make PROJECT=QNX_700_AARCH64
	@$(ECHO) make PROJECT=QNX_700_ARMV7
	@$(ECHO) make PROJECT=DC15
	@$(ECHO) make PROJECT=R013
	@$(ECHO) make PROJECT=EAGLE
	@$(ECHO) make PROJECT=EAGLE_UPDATE
	@$(ECHO) make PROJECT=OPENSYN
	@$(ECHO) make PROJECT=EINSTEIN
	@$(ECHO) make PROJECT=LINUX_ARM_HF
	@$(ECHO) make PROJECT=D544
	@$(ECHO) make PROJECT=RASPI
	@$(ECHO) make PROJECT=U321
	@$(ECHO) make PROJECT=INTEGRITY
	@$(ECHO)
	@$(ECHO) "Try for more info: make help PROJECT=<project>"
	@$(ECHO)

endif

ifeq ($(SMALL_VMF),YES)
include $(NETWORK_VOB)/svmf.mk
else
include $(NETWORK_VOB)/network.mk
endif
