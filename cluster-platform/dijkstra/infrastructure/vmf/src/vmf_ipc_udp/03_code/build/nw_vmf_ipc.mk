#--------------------------------------------------------------
# Makefile for vmf process
#--------------------------------------------------------------
.PHONY: vmf_posix_obj_dir vmf_posix vmf_posix_clean

VMF_IPC_OBJ_DIR		    = $(VMF_SERVER_OBJ_DIR)
VMF_IPC_PUBLIC_INC 	    = -I$(VMF_IPC_DIR)/03_code/public
VMF_IPC_PROTECTED_INC 	= -I$(VMF_IPC_DIR)/03_code/protected

VMF_IPC_OBJS =                                \
	$(VMF_IPC_OBJ_DIR)/nw_vmf_ipc.o 


vmf_ipc_clean:
	$(RM) $(VMF_IPC_OBJ_DIR) $(VMF_IPC_OBJS)

vmf_ipc: vmf_ipc_obj_dir vmf_ipc_prebuilt $(VMF_IPC_OBJS)

vmf_ipc_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_IPC_OBJ_DIR)

vmf_ipc_prebuilt:
#	@echo "Copy mq executable"
#	$(CP) $(QNX_TARGET)/$(TARGET)/sbin/mq $(ARMLE_BIN_DIR)
#	@echo "Copy libmq"
#	$(CP) $(QNX_TARGET)/$(TARGET)/usr/lib/libmq.so.1 $(ARMLE_LIB_DIR)

#	$(CP) $(VMF_IPC_PREBUILT_DIR)/mq $(ARMLE_BIN_DIR)
#	$(CP) $(VMF_IPC_PREBUILT_DIR)/libmq.* $(ARMLE_LIB_DIR)


$(VMF_IPC_OBJS): $(VMF_IPC_DIR)/03_code/build/nw_vmf_ipc.mk

#--------------------------------------------------------------
#          		VMF_POSIX  Rules
#--------------------------------------------------------------

$(VMF_IPC_OBJ_DIR)/%.o: $(VMF_IPC_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(BIN_FPIC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(OTF_ENABLE) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

-include $(VMF_IPC_OBJS:.o=.d)
