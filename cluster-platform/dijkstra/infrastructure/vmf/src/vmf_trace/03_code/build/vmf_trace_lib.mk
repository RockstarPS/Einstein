#--------------------------------------------------------------
# Makefile for VMF_TRACE_LIB
#--------------------------------------------------------------
.PHONY: vmf_trace_lib_obj_dir vmf_trace_lib vmf_trace_lib_clean

VMF_TRACE_LIB_PUBLIC_INC 	= -I$(VMF_TRACE_LIB_DIR)/03_code/public

ifeq ($(VMF_TRACE),YES)
VMF_TRACE_LIB_PROTECTED_INC 	= -I$(VMF_TRACE_LIB_DIR)/03_code/protected
VMF_TRACE_LIB_OBJ_DIR		= $(OBJ_PATH)/vmf_trace_lib

ifeq ($(os),windows)
VMF_TRACE_LIB_SO     = $(ARMLE_LIB_DIR)/libvmf_trace.dll
VMF_TRACE_LIB_IMPORT = $(ARMLE_LIB_DIR)/libvmf_trace.lib
VMF_TRACE_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_trace_static.lib
VMF_TRACE_LIB        = $(VMF_TRACE_LIB_SO) $(VMF_TRACE_LIB_A) $(VMF_TRACE_LIB_IMPORT)
else ifeq ($(os),integrity)
VMF_TRACE_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_trace.a
VMF_TRACE_LIB        = $(VMF_TRACE_LIB_A)
else
VMF_TRACE_LIB_SO     = $(ARMLE_LIB_DIR)/libvmf_trace.so
VMF_TRACE_LIB_A      = $(ARMLE_LIB_DIR)/libvmf_trace.a
VMF_TRACE_LIB        = $(VMF_TRACE_LIB_SO) $(VMF_TRACE_LIB_A)
endif

VMF_TRACE_LIB_OBJS =                               \
	$(VMF_TRACE_LIB_OBJ_DIR)/nw_vmf_trace.o

vmf_trace_lib: vmf_trace_lib_obj_dir $(VMF_TRACE_LIB)
	@echo "VMF trace lib created"
	@echo "+------------------------------------------------------------+"

vmf_trace_lib_clean: nw_config_clean
	$(RM) $(VMF_TRACE_LIB_OBJ_DIR)
	$(RM) $(VMF_TRACE_LIB)
	
vmf_trace_lib_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_TRACE_LIB_OBJ_DIR)

$(VMF_TRACE_LIB_SO): $(VMF_TRACE_LIB_OBJS)
#ifeq ($(os),windows)
	$(MAKE_ECHO)$(LINK.c) -L $(ARMLE_LIB_DIR) $(NW_CONFIG_OBJS) $(VMF_TRACE_LIB_OBJS) $(GCOV) $(VMF_IPC_OBJS) $(SYS_LIBS) -lvmf_client $(SHARED) -Wl,-h$(notdir $@) -o $@
#else
#	$(MAKE_ECHO)$(LINK.c) -L $(ARMLE_LIB_DIR) $(NW_CONFIG_OBJS) $(VMF_TRACE_LIB_OBJS) $(GCOV)                 $(SYS_LIBS) -lvmf_client $(SHARED) -Wl,-h$(notdir $@) -o $@
#endif

$(VMF_TRACE_LIB_A): $(VMF_TRACE_LIB_OBJS)
ifeq ($(os),integrity)
	$(MAKE_ECHO)$(AR)        $(VMF_IPC_OBJS) $(NW_CONFIG_OBJS) $(VMF_TRACE_LIB_OBJS) $(INTEGRITY_BSP) -o $@
else
	$(MAKE_ECHO)$(AR) rcs $@ $(VMF_IPC_OBJS) $(NW_CONFIG_OBJS) $(VMF_TRACE_LIB_OBJS)
endif

$(VMF_TRACE_LIB_IMPORT): $(VMF_TRACE_LIB_OBJS)
	$(MAKE_ECHO)$(DLLTOOL) -d $(VMF_TRACE_LIB_DIR)/03_code/build/nw_vmf_trace_lib.def -l $(VMF_TRACE_LIB_IMPORT) 


$(VMF_TRACE_LIB_OBJS): $(VMF_TRACE_LIB_DIR)/03_code/build/vmf_trace_lib.mk

#--------------------------------------------------------------
#          		vmf-trace-Lib  Rules
#--------------------------------------------------------------
$(VMF_TRACE_LIB_OBJ_DIR)/%.o: $(VMF_TRACE_LIB_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(SO_FPIC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(GCOV) $(SHARED)  -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

endif
-include $(VMF_TRACE_LIB_OBJS:.o=.d)
