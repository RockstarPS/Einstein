

INC_PATH_1 = .
INC_PATH_2 = ../../include
INC_PATH_3 = ../../vmf/03_code/public
INC_PATH_4 = ../../vmf_config
INC_PATH_5 = ../../vmf_trace/03_code/public
INC_PATH_6 = ../../nw_config/03_code/public

LIB_PATH_1 = ../../rel/$(PROJECT)/libs

MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3) -I$(INC_PATH_4) -I$(INC_PATH_5) -I$(INC_PATH_6)
MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lpthread -lrt

CC_FLAGS = -c  -D_GNU_SOURCE -O0
CC_FLAGS += -DVMF_TRACE
CL_FLAGS = # 


OBJ_PATH = ../../rel/$(PROJECT)/obj/VmfPing
BIN_PATH = ../../rel/$(PROJECT)/bin


# User switches (TRUE / FALSE)
USE_PRINT_BUILD_TIME = TRUE

# Compiler for local Linux
CC                   = gcc
NETWORK_CONFIG_DIR   = ../../nw_os_config_linux
DEBUG_C_FLAG         = -ggdb
SHARED_C_FLAG        = -shared
OBJS_ADDITIONAL		 = #
SRCS_ADDITIONAL		 = #

ifeq ($(USE_PRINT_BUILD_TIME),TRUE)
	CC_FLAGS += -DPRINT_BUILD_TIME
endif


ifeq ($(PROJECT),LINUX_X86)
	CC=gcc
	NETWORK_CONFIG_DIR			=../../nw_os_config_linux
endif

ifeq ($(PROJECT),LINUX_X86_GCOV)
	CC=gcc
	NETWORK_CONFIG_DIR			=../../nw_os_config_linux
	GCOV=-fprofile-arcs -ftest-coverage -DVMF_GCOV
endif

ifeq ($(PROJECT),R013)
	# CrossCompiler for R0-13 ARM!
	CC=arm-none-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux
endif

ifeq ($(PROJECT),EAGLE)
	# CrossCompiler for EAGLE ARM!
	CC=arm-fsl-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux
endif

ifeq ($(PROJECT),EAGLE_UPDATE)
	# CrossCompiler for EAGLE Update ARM!
	CC=arm-oe-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux
endif

ifeq ($(PROJECT),QNX_X86)
	# CrossCompiler for QNX x86!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),QNX_700_X86_64)
	# CrossCompiler for QNX 700 x86_64!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V gcc_ntox86_64
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),QNX_700_ARMV7)
	# CrossCompiler for QNX 700 armv7!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V gcc_ntoarmv7le
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),QNX_660_ARMV7)
	# CrossCompiler for QNX 700 armv7!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V gcc_ntoarmv7le
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),QNX_700_AARCH64)
	# CrossCompiler for QNX 700 aarch64!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V gcc_ntoaarch64le
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),LINUX_AARCH64)
	# CrossCompiler for Linux aarch64!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lpthread -lrt
	CC=aarch64-linux-gnu-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux
endif

ifeq ($(PROJECT),DC15)
	# CrossCompiler for DC1.5 (QNX ARM)!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V 4.4.2,gcc_ntoarmle
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),EINSTEIN)
	# CrossCompiler for DC1.5 (QNX ARM)!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V 4.4.2,gcc_ntoarmle
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

ifeq ($(PROJECT),WINDOWS_X86)
    NETWORK_CONFIG_DIR			= ../../nw_os_config_windows
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

ifeq ($(PROJECT),LINUX_ARM_HF)
	CC=arm-linux-gnueabihf-gcc-4.6
    NETWORK_CONFIG_DIR			=../../nw_os_config_linux
endif

ifeq ($(PROJECT),D544)
	# CrossCompiler for Ford D544 Cluster (QNX ARM)!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V gcc_ntoarmv7le
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx
endif

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

MY_INCS += -I$(NETWORK_CONFIG_DIR)/03_code/public
CC_FLAGS += $(MY_INCS) $(GCOV) $(DEBUG_C_FLAG) $(SHARED_C_FLAG)


ifeq ($(AUTOMATED_BENCHMARK),TRUE)
	CC_FLAGS += -DAUTOMATED_BENCHMARK
endif


ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: prepare create_time_header $(BIN_PATH)/vmf_sender $(BIN_PATH)/vmf_listener $(BIN_PATH)/vmf_ping
	$(ECHO) "VMF Ping: all done!"


$(BIN_PATH)/vmf_sender: $(OBJ_PATH)/sender.o $(OBJS_ADDITIONAL) 
	$(CC) $(OBJ_PATH)/sender.o $(OBJS_ADDITIONAL) $(CL_FLAGS) $(MY_LIBS) $(GCOV) -o $@
	$(ECHO) "VMF ping sender finished!"

	
$(BIN_PATH)/vmf_listener: $(OBJ_PATH)/listener.o $(OBJS_ADDITIONAL) 
	$(CC) $(OBJ_PATH)/listener.o $(OBJS_ADDITIONAL) $(CL_FLAGS) $(MY_LIBS) $(GCOV) -o $@
	$(ECHO) "VMF ping listener finished!"


$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -Wp,-MD,$(@:.o=.p) -o $@ $<

$(OBJ_PATH)/%.o: $(SRCS_ADDITIONAL)/%.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -Wp,-MD,$(@:.o=.p) -o $@ $<


ifeq ($(PROJECT),INTEGRITY)     # Integrity image
$(BIN_PATH)/vmf_ping:
	$(CI)  $(INTEGRITY_BSP) $(CI_FLAGS) $(CI_INT_FILE) -o $@ 
	$(ECHO) "VMF Ping Image build."

else
$(BIN_PATH)/vmf_ping:

endif


ifeq ($(USE_PRINT_BUILD_TIME),TRUE)
create_time_header:
	python ../../scripts/create_time_header.py

else
create_time_header:

endif

prepare:
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)


clean:
	rm -f $(BIN_PATH)/vmf_*
	rm -f $(OBJ_PATH)/*
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)
	$(ECHO) "Clean done!"

