#--------------------------------------------------------------
# Makefile for vmf server
#--------------------------------------------------------------
.PHONY: vmf_trace_svr vmf_trace_cli

VMF_TRACE_TEST_OBJ_DIR		    = $(OBJ_PATH)/vmf_trace
VMF_TRACE_TEST_PROTECTED_INC 	= -I$(VMF_TRACE_LIB_DIR)/04_test/protected

VMF_TRACE_TEST_SVR_OBJS =                                       \
	$(VMF_TRACE_TEST_OBJ_DIR)/vmf_trace_svr.o


VMF_TRACE_TEST_CLI_OBJS =                                       \
	$(VMF_TRACE_TEST_OBJ_DIR)/vmf_trace_cli.o


vmf_trace_test_clean:
	$(RM) $(VMF_TRACE_TEST_OBJ_DIR) $(VMF_TRACE_TEST_OBJS)

vmf_trace_test_svr: vmf_trace_test_obj_dir $(VMF_TRACE_TEST_SVR_OBJS)
vmf_trace_test_cli: vmf_trace_test_obj_dir $(VMF_TRACE_TEST_CLI_OBJS)

vmf_trace_svr_clean: $(RM) $(VMF_TRACE_TEST_SVR_OBJS)
vmf_trace_cli_clean: $(RM) $(VMF_TRACE_TEST_CLI_OBJS)

vmf_trace_test_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_TRACE_TEST_OBJ_DIR)

$(VMF_TRACE_TEST_OBJS): $(VMF_TRACE_LIB_DIR)/04_test/build/vmf_trace_test.mk

#--------------------------------------------------------------
#          		VMF-Trace Test  Rules
#--------------------------------------------------------------

$(VMF_TRACE_TEST_OBJ_DIR)/%.o: $(VMF_TRACE_LIB_DIR)/04_test/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) $(OTF_ENABLE) -shared -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

-include $(VMF_TRACE_TEST_SVR_OBJS:.o=.d)
-include $(VMF_TRACE_TEST_CLI_OBJS:.o=.d)

