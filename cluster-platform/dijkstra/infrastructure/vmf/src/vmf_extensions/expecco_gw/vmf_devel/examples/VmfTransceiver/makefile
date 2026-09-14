
OBJ_PATH = obj
BIN_PATH = bin

ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"

# Compiler for local Linux
CC=gcc

ifeq ($(PROJECT),LINUX_X86)
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
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc
endif

ifeq ($(PROJECT),DC15)
	# CrossCompiler for DC1.5 (QNX ARM)!
	MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lsocket -lmq
	CC=qcc -V 4.4.2,gcc_ntoarmle
endif

ifeq ($(PROJECT),WINDOWS_X86)
#    NETWORK_CONFIG_DIR			= ../../nw_os_config_windows/03_code/public
#    PTHREAD_WIN_INC_PATH        = ../../nw_os_config_windows/pthread_w32/include
    MY_INCS += -I$(PTHREAD_WIN_INC_PATH)
	CC=i586-mingw32msvc-gcc -v
    AR=i586-mingw32msvc-ar
    DLLTOOL=i586-mingw32msvc-dlltool -C
    os=windows
    MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace
    MY_LIBS += -L../../nw_os_config_windows/pthread_w32/libs -lpthreadVC2 -lws2_32
    SO_FPIC =
    BIN_FPIC =
endif

TARGET_PATH = ../../$(PROJECT)
INC_PATH_1 = .
INC_PATH_2 = ./include
INC_PATH_3 = $(TARGET_PATH)/include

LIB_PATH_1 =  $(TARGET_PATH)/libs

MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3)
MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lpthread -lrt
ifeq ($(PROJECT),WINDOWS_X86)
MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lpthreadVC2 
endif

CC_FLAGS = -c $(MY_INCS) $(OPTIONS_VMF) -DVMF_TRACE -D_GNU_SOURCE -O0 -ggdb

all: $(BIN_PATH)/vmf_transceiver       
	 $(ECHO) "VMF transceiver: all done!" 


$(BIN_PATH)/vmf_transceiver: $(OBJ_PATH)/vmf_transceiver.o
	$(ECHO) $(CC)
	$(CC) $(OBJ_PATH)/vmf_transceiver.o $(MY_LIBS) -o $@
	$(ECHO) "VMF transceiver finished!"


$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -shared -Wp,-MD,$(@:.o=.p) -o $@ $<


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)
	$(ECHO) "Clean done!"

