

INC_PATH_1 = .
INC_PATH_2 = ../../include
INC_PATH_3 = ../../vmf/03_code/public
INC_PATH_4 = ../../vmf_config
INC_PATH_5 = ../../vmf_trace/03_code/public
INC_PATH_6 = ../../nw_config/03_code/public

LIB_PATH_1 = ../../libs/$(PROJECT)


MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3) -I$(INC_PATH_4) -I$(INC_PATH_5) -I$(INC_PATH_6)
MY_LIBS = -L$(LIB_PATH_1) -lvmf_client -lvmf_trace -lpthread -lrt


OBJ_PATH = obj
BIN_PATH = bin


# Compiler for local Linux
CC=gcc
NETWORK_CONFIG_DIR			=../../nw_os_config_linux/03_code/public
GCOV=-fprofile-arcs -ftest-coverage -DVMF_GCOV

MY_INCS += -I$(NETWORK_CONFIG_DIR)
CC_FLAGS = -c $(MY_INCS) $(GCOV) -DVMF_TRACE -D_GNU_SOURCE -O0 -ggdb

ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"

all: $(BIN_PATH)/vmf_gcov


$(BIN_PATH)/vmf_gcov: $(OBJ_PATH)/listener.o
	$(CC) $(OBJ_PATH)/listener.o $(MY_LIBS) $(GCOV) -o $@
	$(ECHO) "VMF GCOV finished!"


$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -shared -Wp,-MD,$(@:.o=.p) -o $@ $<


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	mkdir -p $(BIN_PATH)
	mkdir -p $(OBJ_PATH)
	$(ECHO) "Clean done!"

