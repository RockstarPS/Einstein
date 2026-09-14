############# MAKEFILE FOR VMF trace client unit test ###################
### platform:   windows
### compiler:   mingw32-gcc
### linker:     mingw32-gcc
### unit test:  hwut
######################################################################

.SECONDARY: OBJ_LIST

### PROJECT
EXE = test_main.exe
OBJ_DIR = obj
DUT_DIR = ../../06_code/src
SRC_DIR = .
STB_DIR = stubs
MY_HWUT_PATH=$(subst \,/, $(HWUT_PATH))#
MY_MINGW_PATH=$(subst \,/, $(MINGW_PATH))#
ERROR_LOG = error.txt


INCS = \
	-I$(STB_DIR) \
	-I../../06_code/protected \
	-I../../06_code/public \
    -I../../../vmf/03_code/protected \
    -I../../../vmf/03_code/public \
    -I../../../vmf_posix/03_code/protected \
    -I../../../vmf_rem_client/06_code/protected \
    -I../../../vmf_rem_client/06_code/public \
    -I../../../vmf_trace/06_code/public \
	-I$(MY_HWUT_PATH)/support/C/ \
	-I$(MY_MINGW_PATH)/include


OBJS = $(OBJ_DIR)/test_main.o \
		$(OBJ_DIR)/test__nw_vmf_rem_util.o \
		$(OBJ_DIR)/test__nw_vmf_rem_server_rpc.o \
		$(OBJ_DIR)/test__nw_vmf_rem_server_connector.o \
		$(OBJ_DIR)/nw_vmf_rem_server_connector.o \
		$(OBJ_DIR)/nw_vmf_rem_server_rpc.o \
		$(OBJ_DIR)/nw_vmf_rem_util.o \
		$(OBJ_DIR)/vmf_rem_stubs.o \
		$(OBJ_DIR)/pthread.o


### COMPILER AND LINKER
CC              = $(MY_MINGW_PATH)/bin/mingw32-gcc.exe
CFLAGS          = -DVMF_REM -DVMF_REM_SERVER_UNIT_TEST -DVMF_REM_DEBUG -Wall -ggdb -c $(INCS) -DUNIT_TEST -fprofile-arcs -ftest-coverage #

LFLAGS          =

#OUT_TOOL        = cat
OUT_TOOL        = type
ERROR_LOG       = error.txt
FILE_LIST       = filelist.txt
MKDIR           = mkdir
#RM              = rm -f
RM              = del /F /Q
#RMDIR           = rmdir
ECHO            = @echo
ECHO_MAKE       = @
ECHO_COMPILING  = $(ECHO) "Compiling " $<
ECHO_LINKING    = $(ECHO) "Linking..."
ECHO_FINISHED   = $(ECHO) "*** $(EXE) is made... ***"

# main rules

all: remove_file_list remove_error_log exec

clean: remove_file_list remove_error_log remove_objs remove_exe

files:
	$(ECHO)
	$(OUT_TOOL) $(FILE_LIST)

$(EXE): all

hwut-info:
	$(ECHO) $(EXE)

hwut-gcov-info:
	$(ECHO) \
	nw_vmf_rem_server_connector.c \
	nw_vmf_rem_server_rpc.c \
	nw_vmf_rem_util.c

hwut-gcov-obj:
	$(ECHO) $(OBJ_DIR)

# sub rules

remove_file_list:
	$(RM) $(FILE_LIST)

remove_error_log:
	$(RM) $(ERROR_LOG)


remove_objs:
	$(RM) $(OBJ_DIR)\*.*

remove_exe:
	$(RM) $(EXE)

exec:  $(OBJS)
	$(ECHO_MAKE)$(CC) $(LFLAGS) $(OBJS) -lgcov -o $(EXE) 2>>$(ERROR_LOG)
	$(ECHO_LINKING)
	$(ECHO_FINISHED)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(ECHO_COMPILING)
	$(ECHO_MAKE)$(CC) $(CFLAGS) -o $@ $< 2>>$(ERROR_LOG)
	$(ECHO) $< >>$(FILE_LIST)

$(OBJ_DIR)/%.o: $(STB_DIR)/%.c
	$(ECHO_COMPILING)
	$(ECHO_MAKE)$(CC) $(CFLAGS) -o $@ $< 2>>$(ERROR_LOG)
	$(ECHO) $< >>$(FILE_LIST)

$(OBJ_DIR)/%.o: $(DUT_DIR)/%.c
	$(ECHO_COMPILING)
	$(ECHO_MAKE)$(CC) $(CFLAGS) -o $@ $< 2>>$(ERROR_LOG)
	$(ECHO) $< >>$(FILE_LIST)
