

INC_PATH_1 = .
INC_PATH_2 = ../../include
INC_PATH_3 = ../../vmf/03_code/public
INC_PATH_4 = ../../vmf_config
INC_PATH_5 = ../../vmf_trace/03_code/public
INC_PATH_6 = ../../nw_config/03_code/public

LIB_PATH_1 = ../../libs/$(ARCH)


MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3) -I$(INC_PATH_4) -I$(INC_PATH_5) -I$(INC_PATH_6)
MY_LIBS = -L$(LIB_PATH_1) -lvmf_trace -lvmf_client -lpthread -lrt


OBJ_PATH = obj
BIN_PATH = bin


# Compiler for local Linux
CC=gcc

ifeq ($(ARCH),arm)
	# CrossCompiler for R0-13 ARM!
	CC=arm-none-linux-gnueabi-gcc
endif

CC_FLAGS = -c $(MY_INCS) -DVMF_TRACE -D_GNU_SOURCE -O2 -ggdb -Wall -Werror-implicit-function-declaration


ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: $(BIN_PATH)/vmf_trace_weird
	$(ECHO) "VMF Trace Weird: all done!"


$(BIN_PATH)/vmf_trace_weird: pathes $(OBJ_PATH)/main.o
	$(CC) $(OBJ_PATH)/main.o $(MY_LIBS) -o $@


$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -shared -Wp,-MD,$(@:.o=.p) -o $@ $<


pathes:
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	$(ECHO) "Clean done!"

