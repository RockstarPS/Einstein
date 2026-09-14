

VMF_PATH = ../vmf_devel
PROJECT = WINDOWS_X86

VMF_INC_PATH = $(VMF_PATH)/$(PROJECT)/include
VMF_LIB_PATH = $(VMF_PATH)/$(PROJECT)/libs


MY_INCS = -I$(VMF_INC_PATH)
MY_LIBS = -L$(VMF_LIB_PATH) -lvmf_client -lvmf_trace 


OBJ_PATH = obj
BIN_PATH = bin

BIN = $(BIN_PATH)/b515_vmf_ardu_gw.exe

OBJS = $(OBJ_PATH)/b515_vmf_ardu_gw.o \
       $(OBJ_PATH)/getopt.o \
       $(OBJ_PATH)/P32_BaseFunc.o \
       $(OBJ_PATH)/P32_DabCtrl.o \
       $(OBJ_PATH)/P32_DmbApi.o \
       $(OBJ_PATH)/P32_Rf_Api.o \
       $(OBJ_PATH)/P32_Rf_PNx3030x.o \
       $(OBJ_PATH)/P32_SendQHandler.o \
       $(OBJ_PATH)/stub_fkts.o


CC_FLAGS = -c $(MY_INCS) -DVMF_TRACE -O0 -ggdb


# Default Compiler
CC=gcc -v


# Compiler for 32 bit Windows
ifeq ($(PROJECT),WINDOWS_X86)
	ifeq ($(HOST),WIN)
		MY_LIBS += -lpthreadVC2 -lws2_32
		CC=mingw32-gcc
		os=windows
	else
		CC=i586-mingw32msvc-gcc -v
		AR=i586-mingw32msvc-ar
		DLLTOOL=i586-mingw32msvc-dlltool -C
		os=windows
		MY_LIBS += -lpthreadVC2 -lws2_32
		SO_FPIC =
		BIN_FPIC =
	endif
endif

ifeq ($(PROJECT),LINUX_X86)
	CC=i586-mingw32msvc-gcc -v
    MY_LIBS+=lpthread
endif




ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: create_path $(BIN)
	$(ECHO) "B515 Ardu VMF ARDU GW done!"


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


