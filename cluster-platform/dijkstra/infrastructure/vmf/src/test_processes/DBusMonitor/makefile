
INC_PATH_1 = /usr/include
INC_PATH_2 = /usr/include/dbus-1.0
INC_PATH_3 = /usr/include/glib-2.0
INC_PATH_4 = /usr/lib/glib-2.0/include
INC_PATH_5 = /usr/lib/dbus-1.0/include
LIB_PATH_1 = /usr/lib


ifeq ($(VMF_TRACE), YES)
    INC_PATH_VMF_1 = ../../vmf_trace/03_code/public
    INC_PATH_VMF_2 = ../../include
    INC_PATH_VMF_3 = ../../vmf/03_code/public
    INC_PATH_VMF_4 = ../../vmf_config
    INC_PATH_VMF_5 = ../../nw_config/03_code/public
    LIB_PATH_VMF = ../../libs
    LIBS_VMF = -lvmf_client -lvmf_trace
    OPTIONS_VMF = -DVMF_TRACE
else
    INC_PATH_VMF_1 = 
    INC_PATH_VMF_2 = 
    INC_PATH_VMF_3 = 
    INC_PATH_VMF_4 =
    INC_PATH_VMF_5 =
    LIB_PATH_VMF =
    LIBS_VMF =
    OPTIONS_VMF =
endif

  

MY_INCS = -I$(INC_PATH_1) -I$(INC_PATH_2) -I$(INC_PATH_3) -I$(INC_PATH_4) -I$(INC_PATH_5) -I$(INC_PATH_VMF_1) -I$(INC_PATH_VMF_2) -I$(INC_PATH_VMF_3) -I$(INC_PATH_VMF_4) -I$(INC_PATH_VMF_5)
MY_LIBS = -L$(LIB_PATH_1) -L$(LIB_PATH_VMF) -lglib-2.0 -ldbus-1 -ldbus-glib-1 $(LIBS_VMF)


OBJ_PATH = obj
BIN_PATH = bin



CC=gcc
CC_FLAGS = -c $(MY_INCS) $(OPTIONS_VMF) -D_GNU_SOURCE -O2 -ggdb -Wall -Werror-implicit-function-declaration


ECHO = @echo
ECHO_COMPILING  = @echo "Compiling"


all: $(BIN_PATH)/dbus_moni
	$(ECHO) "All done!"


$(BIN_PATH)/dbus_moni: $(OBJ_PATH)/listener.o $(OBJ_PATH)/dbus-print-message.o
	$(CC) $(OBJ_PATH)/listener.o $(OBJ_PATH)/dbus-print-message.o $(MY_LIBS) -o $@
	$(ECHO) "DBus Monitor finished!"




$(OBJ_PATH)/%.o: %.c
	$(ECHO_COMPILING) $<
	$(CC) $(CC_FLAGS)  -shared -Wp,-MD,$(@:.o=.p) -o $@ $<


clean:
	rm -f $(BIN_PATH)/*
	rm -f $(OBJ_PATH)/*
	rm -f $(ERROR_LOG)
	$(ECHO) "Clean done!"

