#--------------------------------------------------------------
# Makefile for gw
#--------------------------------------------------------------
PHONY: vmf_rem_server_obj_dir vmf_rem_server_clean

VMF_REM_SERVER_OBJ_DIR			= $(OBJ_PATH)/vmf_rem_server
VMF_REM_SERVER_PUBLIC_INC		= -I$(VMF_REM_SERVER_DIR)/06_code/public
VMF_REM_SERVER_PROTECTED_INC	= -I$(VMF_REM_SERVER_DIR)/06_code/protected
VMF_REM_CLIENT_PROTECTED_INC	= -I$(VMF_REM_CLIENT_DIR)/06_code/protected

VMF_REM_SERVER_OBJS = \
	$(VMF_REM_SERVER_OBJ_DIR)/nw_vmf_rem_server_connector.o\
	$(VMF_REM_SERVER_OBJ_DIR)/nw_vmf_rem_server_rpc.o 

vmf_rem_server: vmf_rem_server_obj_dir $(VMF_REM_SERVER_OBJS)

vmf_rem_server_clean:
	$(RM) $(VMF_REM_SERVER_OBJ_DIR)  $(VMF_REM_SERVER_OBJS)

vmf_rem_server_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_REM_SERVER_OBJ_DIR)

$(VMF_REM_SERVER_OBJS): $(VMF_REM_SERVER_DIR)/06_code/build/vmf_rem_server.mk

#--------------------------------------------------------------
#						VMF remote server Rules
#--------------------------------------------------------------

$(VMF_REM_SERVER_OBJ_DIR)/%.o: $(VMF_REM_SERVER_DIR)/06_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(VMF_REM_SERVER_PROTECTED_INC) $(VMF_REM_SERVER_PUBLIC_INC) $(CCINC)  $(OTF_ENABLE) -shared -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)


-include $(VMF_REM_SERVER_OBJS:.o=.d)
