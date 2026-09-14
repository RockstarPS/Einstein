

ifeq ($(STATIC),YES)
	MY_STATIC=-static -pthread
else
	MY_STATIC=#
endif

INC_PATH_1 = .
INC_PATH_2 = ../../include
INC_PATH_3 = ../../vmf/03_code/public
INC_PATH_4 = ../../vmf_config
INC_PATH_5 = ../../vmf_trace/03_code/public
INC_PATH_6 = ../../nw_config/03_code/public

LIB_PATH_1 = ../../libs/$(PROJECT)


MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3) -I$(INC_PATH_4) -I$(INC_PATH_5) -I$(INC_PATH_6)
MY_LIBS = -L$(LIB_PATH_1) $(MY_STATIC) -lvmf_client -lpthread -lrt


OBJ_PATH = obj
BIN_PATH = bin



# Compiler for local Linux
CC=gcc
NETWORK_CONFIG_DIR			=../../nw_os_config_linux/03_code/public

ifeq ($(PROJECT),LINUX_X86)
	CC=gcc
	NETWORK_CONFIG_DIR			=../../nw_os_config_linux/03_code/public
endif

ifeq ($(PROJECT),R013)
	# CrossCompiler for R0-13 ARM!
	CC=arm-none-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux/03_code/public
endif

ifeq ($(PROJECT),EAGLE)
	# CrossCompiler for EAGLE ARM!
	CC=arm-fsl-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux/03_code/public
endif

ifeq ($(PROJECT),EAGLE_UPDATE)
	# CrossCompiler for EAGLE Update ARM!
	CC=arm-oe-linux-gnueabi-gcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_linux/03_code/public
endif

ifeq ($(PROJECT),QNX_X86)
	# CrossCompiler for QNX x86!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lmq
	CC=qcc
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx/03_code/public
endif

ifeq ($(PROJECT),DC15)
	# CrossCompiler for DC1.5 (QNX ARM)!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lmq
	CC=qcc -V 4.4.2,gcc_ntoarmle
	NETWORK_CONFIG_DIR			= ../../nw_os_config_qnx/03_code/public
endif

ifeq ($(PROJECT),WINDOWS_X86)
    NETWORK_CONFIG_DIR			= ../../nw_os_config_windows/03_code/public
    PTHREAD_WIN_INC_PATH        = ../../nw_os_config_windows/pthread_w32/include
    MY_INCS += -I$(PTHREAD_WIN_INC_PATH)
	CC=i586-mingw32msvc-gcc -v
    AR=i586-mingw32msvc-ar
    DLLTOOL=i586-mingw32msvc-dlltool -C
    os=windows
    MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -L../../nw_os_config_windows/pthread_w32/libs -lpthreadVC2 -lws2_32
    SO_FPIC =
    BIN_FPIC =
endif

ifeq ($(PROJECT),OPENSYN)
	# CrossCompiler for OpenSynergy Linux on ARM!
	CC=arm-unknown-linux-gnueabi-gcc
endif

ifeq ($(PROJECT),LINUX_ARM_HF)
	CC=arm-linux-gnueabihf-gcc-4.6
    NETWORK_CONFIG_DIR			=../../nw_os_config_linux/03_code/public
endif


MY_INCS += -I$(NETWORK_CONFIG_DIR)


CC_FLAGS = -c $(MY_INCS) $(OPTIONS_VMF) -D_GNU_SOURCE -O0 -ggdb


ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: $(BIN_PATH)/vmf_echo


$(BIN_PATH)/vmf_echo: $(OBJ_PATH)/echo_basic.o
	$(CC) $(OBJ_PATH)/echo_basic.o $(MY_LIBS) -o $@
	$(ECHO) "VMF echo process finished!"



$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -shared -Wp,-MD,$(@:.o=.p) -o $@ $<


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)
	$(ECHO) "Clean done!"

