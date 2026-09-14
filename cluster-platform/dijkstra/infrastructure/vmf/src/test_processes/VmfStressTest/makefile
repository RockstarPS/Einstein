CC_FLAGS = -c  -D_GNU_SOURCE -O0
STRESS_TEST = TRUE

OBJ_PATH = ../../rel/$(PROJECT)/obj/VmfStressTest
BIN_PATH = ../../rel/$(PROJECT)/bin

# Compiler for local Linux
CC                   = gcc

ifeq ($(PROJECT),LINUX_X86)
	CC=gcc
endif

ifeq ($(PROJECT),LINUX_X86_GCOV)
	CC=gcc
endif

ifeq ($(PROJECT),R013)
	# CrossCompiler for R0-13 ARM!
	CC=arm-none-linux-gnueabi-gcc
endif

ifeq ($(PROJECT),EAGLE)
	# CrossCompiler for EAGLE ARM!
	CC=arm-fsl-linux-gnueabi-gcc
endif

ifeq ($(PROJECT),EAGLE_UPDATE)
	# CrossCompiler for EAGLE Update ARM!
	CC=arm-oe-linux-gnueabi-gcc
endif

ifeq ($(PROJECT),QNX_X86)
	# CrossCompiler for QNX x86!
	CC=qcc
endif

ifeq ($(PROJECT),QNX_700_X86_64)
	# CrossCompiler for QNX 700 x86_64!
	CC=qcc -V gcc_ntox86_64
endif

ifeq ($(PROJECT),QNX_700_ARMV7)
	# CrossCompiler for QNX 700 armv7!
	CC=qcc -V gcc_ntoarmv7le
endif

ifeq ($(PROJECT),QNX_660_ARMV7)
	# CrossCompiler for QNX 700 armv7!
	CC=qcc -V gcc_ntoarmv7le
endif

ifeq ($(PROJECT),QNX_700_AARCH64)
	# CrossCompiler for QNX 700 aarch64!
	CC=qcc -V gcc_ntoaarch64le
endif

ifeq ($(PROJECT),LINUX_AARCH64)
	# CrossCompiler for Linux aarch64!
	CC=aarch64-linux-gnu-gcc
endif

ifeq ($(PROJECT),DC15)
	# CrossCompiler for DC1.5 (QNX ARM)!
	CC=qcc -V 4.4.2,gcc_ntoarmle
endif

ifeq ($(PROJECT),EINSTEIN)
	# CrossCompiler for DC1.5 (QNX ARM)!
	CC=qcc -V 4.4.2,gcc_ntoarmle
endif

ifeq ($(STRESS_TEST),FALSE)
ifeq ($(PROJECT),WINDOWS_X86)
 #   NETWORK_CONFIG_DIR			= ../../nw_os_config_windows
    PTHREAD_WIN_INC_PATH        = ../../nw_os_config_windows/pthread_w32/include
    MY_INCS += -I$(PTHREAD_WIN_INC_PATH)
	CC=i686-w64-mingw32-gcc
	AR=i686-w64-mingw32-gcc-ar
	DLLTOOL=dlltool -C
    os=windows
	CC_FLAGS += -DHAVE_STRUCT_TIMESPEC -DWIN32
    MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace
    MY_LIBS += -L../../nw_os_config_windows/pthread_w32/libs -lpthreadVC2 -lws2_32
    SO_FPIC =
    BIN_FPIC =
endif

ifeq ($(PROJECT),WINDOWS_X86_64)
    NETWORK_CONFIG_DIR			= ../../nw_os_config_windows_64
	CC=x86_64-w64-mingw32-gcc -v
	AR=x86_64-w64-mingw32-gcc-ar
	DLLTOOL=dlltool -C
	os=windows
	SYS_LIBS = -lws2_32
	SO_FPIC =
	BIN_FPIC =	
	CC_FLAGS += -DHAVE_STRUCT_TIMESPEC -DWINDOWS_X86_64
    MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace
    SO_FPIC =
    BIN_FPIC =
endif
endif

ifeq ($(PROJECT),LINUX_ARM_HF)
	CC=arm-linux-gnueabihf-gcc-4.6
endif

ifeq ($(PROJECT),D544)
	# CrossCompiler for Ford D544 Cluster (QNX ARM)!
	CC=qcc -V gcc_ntoarmv7le
endif

ifeq ($(STRESS_TEST),FALSE)
ifeq ($(PROJECT),INTEGRITY)
ifeq ($(HOST),WINDOWS)
INTEGRITY_BSP = -bsp=devtree-cortex-a15 -os_dir=C:/ghs/int1124-P2
CI=C:/ghs/int1124-P2/multi/bin/win32/intex
CC=C:/ghs/comp_201416/ccintarm 
CI_FLAGS  = -integrity_version 11.2.4 -alt_tools_path C:/ghs/comp_201416
else
INTEGRITY_BSP = -bsp=devtree-cortex-a15 -os_dir=/opt/ghs/ghs.int1124-P2
CC=/opt/ghs/ghs.comp_201416_linux/ccintarm
CI=/opt/ghs/ghs.int1124-P2/multi/bin/linux86/intex 
CI_FLAGS  = -integrity_version 11.2.4 -alt_tools_path /opt/ghs/ghs.comp_201416_linux
endif
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lposix -lshm_client -lsocket -livfs
	#MY_LIBS = -L$(LIB_PATH_1) -lvmf_client             -lposix -lshm_client -lsocket -livfs
	NETWORK_CONFIG_DIR			= ../../nw_os_config_integrity
	DEBUG_C_FLAG = -G 
	SHARED_C_FLAG=#
	OBJS_ADDITIONAL = $(OBJ_PATH)/shm_area.o
	SRCS_ADDITIONAL = $(NETWORK_CONFIG_DIR)/03_code/src
	
	CC_FLAGS += $(INTEGRITY_BSP)
	CC_FLAGS += -gnu99 --unknown_pragma_silent -D__MISRA_20_9=0 -D__MISRA_124=0 -D__CHECK_API_ERROR=0
	CL_FLAGS = $(INTEGRITY_BSP)
	CI_FLAGS += -gstack_options -intexoption -no_shared_libs -intexoption -no_shared_libs_quiet -intexoption -allocate_initialized_together 
	CI_INT_FILE = -intfile vmf_ping.int
endif
endif

ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"

all: prepare $(BIN_PATH)/Vmf_StressTest
	$(ECHO) "VMF Stress Test: all done!"

$(BIN_PATH)/Vmf_StressTest: $(OBJ_PATH)/vmf_stress_test.o 
	$(CC) $(OBJ_PATH)/vmf_stress_test.o -o $@
	$(ECHO) "VMF stress test finished!"

$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)-shared -Wp,-MD,$(@:.o=.p) -o $@ $<	
	
prepare:
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)

clean:
	rm -f $(BIN_PATH)/vmf_*
	rm -f $(OBJ_PATH)/*
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)
	$(ECHO) "Clean done!"

