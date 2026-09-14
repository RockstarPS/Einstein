#--------------------------------------------------------------
# Makefile for VMF_LIB
#--------------------------------------------------------------
.PHONY: vmf_lib_obj_dir vmf_lib vmf_lib_clean

VMF_LIB_OBJ_DIR		= $(VMF_SERVER_OBJ_DIR)
VMF_LIB_PUBLIC_INC 	= -I$(VMF_LIB_DIR)/03_code/public
VMF_LIB_PROTECTED_INC	= -I$(VMF_LIB_DIR)/03_code/protected
VMF_LIB_PREBUILT_DIR	= $(VMF_LIB_DIR)/03_code/prebuilt

ifeq ($(os),windows)
VMF_LIB_SO     = $(ARMLE_LIB_DIR)/libvmf_client.dll
VMF_LIB_IMPORT = $(ARMLE_LIB_DIR)/libvmf_client.lib
VMF_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_client_static.lib
VMF_LIB        = $(VMF_LIB_SO) $(VMF_LIB_IMPORT) $(VMF_LIB_A)
else ifeq ($(os),integrity)
VMF_LIB_SO     = $(ARMLE_LIB_DIR)/libvmf_client.so
VMF_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_client.a
VMF_LIB        = $(VMF_LIB_A)
else
VMF_LIB_SO     = $(ARMLE_LIB_DIR)/libvmf_client.so
VMF_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_client.a
VMF_LIB        = $(VMF_LIB_SO) $(VMF_LIB_A)
endif

VMF_LIB_OBJS =						\
	$(VMF_LIB_OBJ_DIR)/nw_vmf_client.o		\
	$(VMF_LIB_OBJ_DIR)/nw_vmf_collector.o		\
	$(VMF_LIB_OBJ_DIR)/nw_vmf_timer.o		\
	$(VMF_SERVER_OBJ_DIR)/nw_vmf_debug.o            \
	$(VMF_LIB_OBJ_DIR)/nw_vmf_client_uties.o

vmf_lib:  vmf_lib_obj_dir vmf_ipc_obj_dir $(VMF_LIB)
	@echo "VMF client lib created"
	@echo "+------------------------------------------------------------+"

vmf_lib_clean: nw_config_clean
	$(RM) $(VMF_LIB_OBJ_DIR)
	$(RM) $(VMF_LIB)

vmf_lib_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_LIB_OBJ_DIR)

$(VMF_LIB_SO): $(VMF_LIB_OBJS)
	$(MAKE_ECHO)$(LINK.c) -L $(ARMLE_LIB_DIR) $(VMF_IPC_OBJS) $(NW_CONFIG_OBJS) $(VMF_LIB_OBJS) $(SYS_LIBS) $(GCOV) $(SHARED) -Wl,-h$(notdir $@) -o $@

$(VMF_LIB_A): $(VMF_LIB_OBJS)
ifeq ($(os),integrity)
	$(MAKE_ECHO)$(AR)  $(VMF_IPC_OBJS) $(NW_CONFIG_OBJS) $(VMF_LIB_OBJS) $(INTEGRITY_BSP) -o $@
else
	$(MAKE_ECHO)$(AR) rcs $@ $(VMF_IPC_OBJS) $(NW_CONFIG_OBJS) $(VMF_LIB_OBJS)
endif



$(VMF_LIB_IMPORT): $(VMF_LIB_OBJS)
	$(MAKE_ECHO)$(DLLTOOL) -d $(VMF_SERVER_DIR)/03_code/build/nw_vmf_client_lib.def -l $(VMF_LIB_IMPORT)


$(VMF_LIB_OBJS): $(VMF_LIB_DIR)/03_code/build/nw_vmf_lib.mk

#--------------------------------------------------------------
#			vmf-Lib  Rules
#--------------------------------------------------------------
$(VMF_LIB_OBJ_DIR)/%.o: $(VMF_LIB_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(SO_FPIC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(GCOV) $(SHARED) -fno-strict-aliasing -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

#--------------------------------------------------------------
#			ipc Rules
#--------------------------------------------------------------
$(VMF_IPC_OBJ_DIR)/%.o: $(VMF_IPC_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(SO_FPIC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(OTF_ENABLE) -fno-strict-aliasing $(SHARED) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

-include $(VMF_LIB_OBJS:.o=.d)
