

VMF_PATH = ../vmf_devel
PROJECT = WINDOWS_X86

VMF_INC_PATH = $(VMF_PATH)/$(PROJECT)/include
VMF_LIB_PATH = $(VMF_PATH)/$(PROJECT)/libs


MY_INCS = -I$(VMF_INC_PATH)
MY_LIBS = -L$(VMF_LIB_PATH) -lvmf_client -lvmf_trace 


OBJ_PATH = obj
BIN_PATH = bin

BIN = $(BIN_PATH)/saturn_vmf_com_gw.exe

OBJS = $(OBJ_PATH)/saturn_vmf_com_gw.o \
       $(OBJ_PATH)/getopt.o


CC_FLAGS = -c $(MY_INCS) -DVMF_TRACE -O0 -ggdb


# Default Compiler
CC=i586-mingw32msvc-gcc -v


# Compiler for 32 bit Windows
ifeq ($(PROJECT),WINDOWS_X86)
	CC=i586-mingw32msvc-gcc -v
    MY_LIBS+=-lpthreadVC2
endif

ifeq ($(PROJECT),LINUX_X86)
	CC=gcc
    MY_LIBS+=lpthread
endif




ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: create_path $(BIN)
	$(ECHO) "D3CoS VMF COM GW done!"


$(BIN): $(OBJS)
	$(CC) $(OBJS) $(MY_LIBS) -o $@


$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS) -o $@ $<


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	$(ECHO) "Clean done!"

create_path:
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)


