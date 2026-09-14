#--------------------------------------------------------------
# Makefile for vmf server
#--------------------------------------------------------------
.PHONY: vmf_server_obj_dir vmf_server vmf_server_clean

VMF_SERVER_OBJ_DIR		  = $(OBJ_PATH)/vmf
#VMF_SERVER_PUBLIC_INC 		= -I$(VMF_SERVER_DIR)/03_code/public
#VMF_SERVER_PROTECTED_INC 	= -I$(VMF_SERVER_DIR)/03_code/protected
VMF_SERVER_PROTECTED_INC  = -I$(VMF_SERVER_DIR)/03_code/include

VMF_SERVER_OBJS =                                               \
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_server.o                   \
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_router.o                   \
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_routing_db-core.o          \
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_routing_db-events.o        \
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_routing_db-memory.o        \
    $(VMF_SERVER_OBJ_DIR)/vmf_ipc.o



vmf_server_clean:
	$(RM) $(VMF_SERVER_OBJ_DIR) $(VMF_SERVER_OBJS)

vmf_server: vmf_server_obj_dir $(VMF_SERVER_OBJS)

vmf_server_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_SERVER_OBJ_DIR)

$(VMF_SERVER_OBJS): $(VMF_SERVER_DIR)/03_code/build/nw_vmf_server.mk

#--------------------------------------------------------------
#		VMF Rules
#--------------------------------------------------------------

$(VMF_SERVER_OBJ_DIR)/%.o: $(VMF_SERVER_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(OTF_ENABLE) $(SYS_LIBS) -fno-strict-aliasing -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

-include $(VMF_SERVER_OBJS:.o=.d)
