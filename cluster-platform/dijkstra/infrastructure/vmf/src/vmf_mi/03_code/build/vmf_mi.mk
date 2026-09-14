#--------------------------------------------------------------
# Makefile for VMF_TRACE_SERVER
#--------------------------------------------------------------
.PHONY: vmf_mi vmf_mi_clean vmf_mi_obj_dir

VMF_MI_OBJDIR		= $(OBJ_PATH)/vmf_mi
VMF_MI_PUBLIC_INC 	= -I$(VMF_MI_DIR)/03_code/public
VMF_MI_PROTECTED_INC 	= -I$(VMF_MI_DIR)/03_code/protected


VMF_MI_OBJS =                              \
	$(VMF_MI_OBJDIR)/nw_vmf_mi_dtype_file.o   \
	$(VMF_MI_OBJDIR)/nw_vmf_mi_dtype_tcp.o   \
	$(VMF_MI_OBJDIR)/nw_vmf_mi_main.o
#	$(VMF_MI_OBJDIR)/lzrw3-a.o

ifneq ($(os),integrity)
	VMF_MI_OBJS += $(VMF_MI_OBJDIR)/vmqport_control.o
endif


vmf_mi: vmf_mi_obj_dir $(VMF_MI_OBJS)

vmf_mi_clean:
	$(RM) $(VMF_MI_OBJDIR) $(VMF_MI_OBJS)

vmf_mi_obj_dir:
	$(MAKE_ECHO)mkdir -p $(VMF_MI_OBJDIR)


$(VMF_MI_OBJS): $(VMF_MI_DIR)/03_code/build/vmf_mi.mk

#--------------------------------------------------------------
#          		vmf-trace-Svr  Rules
#--------------------------------------------------------------
$(VMF_MI_OBJDIR)/%.o: $(VMF_MI_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)


-include $(VMF_MI_OBJS:.o=.d)
