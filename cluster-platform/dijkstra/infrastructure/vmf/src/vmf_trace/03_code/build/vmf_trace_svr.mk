#--------------------------------------------------------------
# Makefile for VMF_TRACE_SERVER
#--------------------------------------------------------------
.PHONY: vmf_trace_svr_obj_dir vmf_trace_svr vmf_trace_svr_clean

VMF_TRACE_SVR_OBJ_DIR			= $(OBJ_PATH)/vmf_trace
VMF_TRACE_SVR_PUBLIC_INC 		= -I$(VMF_TRACE_SVR_DIR)/03_code/public 
VMF_TRACE_SVR_PUBLIC_INC   	   += -I$(VMF_TRACE_SVR_DIR)/03_code/target_logging/include
VMF_TRACE_SVR_PUBLIC_INC       += -I$(VMF_TRACE_SVR_DIR)/03_code/dlt/include 
VMF_TRACE_SVR_PROTECTED_INC 	= -I$(VMF_TRACE_SVR_DIR)/03_code/protected 


VMF_TRACE_SERVER_OBJS =                              \
	$(VMF_TRACE_SVR_OBJ_DIR)/nw_vmf_trace_server.o   \
	$(VMF_TRACE_SVR_OBJ_DIR)/nw_vmf_sysinfo.o

ifeq ($(VMF_TARGET_LOGGING),YES)
VMF_TRACE_SERVER_OBJS += $(VMF_TRACE_SVR_OBJ_DIR)/nw_vmf_target_log.o
endif

ifeq ($(DLT_GW),YES)
VMF_TRACE_SERVER_OBJS += $(VMF_TRACE_SVR_OBJ_DIR)/nw_vmf_trace_dlt_gw.o
endif

vmf_trace_svr: vmf_trace_svr_obj_dir $(VMF_TRACE_SERVER_OBJS)

vmf_trace_svr_clean:
	$(RM) $(VMF_TRACE_SVR_OBJ_DIR) $(VMF_TRACE_SERVER_OBJS)

vmf_trace_svr_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_TRACE_SVR_OBJ_DIR)


$(VMF_TRACE_SERVER_OBJS): $(VMF_TRACE_SVR_DIR)/03_code/build/vmf_trace_svr.mk

#--------------------------------------------------------------
#          		vmf-trace-Svr  Rules
#--------------------------------------------------------------
$(VMF_TRACE_SVR_OBJ_DIR)/%.o: $(VMF_TRACE_SVR_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(VMF_TRACE_SVR_PROTECTED_INC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(SYS_LIBS) $(GCOV) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

#--------------------------------------------------------------
#          		vmf-target-logging  Rules
#--------------------------------------------------------------
$(VMF_TRACE_SVR_OBJ_DIR)/%.o: $(VMF_TRACE_SVR_DIR)/03_code/target_logging/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(VMF_TRACE_SVR_PROTECTED_INC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(SYS_LIBS) $(GCOV) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)


#--------------------------------------------------------------
#          		vmf-trace-dlt-gw  Rules
#--------------------------------------------------------------
$(VMF_TRACE_SVR_OBJ_DIR)/%.o: $(VMF_TRACE_SVR_DIR)/03_code/dlt/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(VMF_TRACE_SVR_PROTECTED_INC) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(SYS_LIBS) $(GCOV) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)


-include $(VMF_TRACE_SERVER_OBJS:.o=.d)
