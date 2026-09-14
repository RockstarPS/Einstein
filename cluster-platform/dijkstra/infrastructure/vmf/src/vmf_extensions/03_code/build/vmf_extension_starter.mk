#--------------------------------------------------------------
# Makefile for VMF_EXTENSION_STARTER
#--------------------------------------------------------------
.PHONY: vmf_exts

VMF_EXTS_OBJDIR	= $(OBJ_PATH)/vmf_exts
VMF_EXTS_INC 	= -I$(VMF_EXTS_DIR)/03_code/src


VMF_EXTS_OBJS = $(VMF_EXTS_OBJDIR)/vmf_extension_starter.o   

vmf_extensions: vmf_exts_obj_dir $(VMF_EXTS_OBJS)

vmf_exts_clean:
	$(MAKE_ECHO)$(RM) $(VMF_EXTS_OBJDIR) $(VMF_EXTS_OBJS)

vmf_exts_obj_dir:
	mkdir -p $(VMF_EXTS_OBJDIR)


$(VMF_EXTS_OBJS): $(VMF_EXTS_DIR)/03_code/build/vmf_extension_starter.mk

#--------------------------------------------------------------
#          		build  Rules
#--------------------------------------------------------------
$(VMF_EXTS_OBJDIR)/%.o: $(VMF_EXTS_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) $(NETWORK_PROTECTED_INC) $(NETWORK_PUBLIC_INC) $(CCINC) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)


-include $(VMF_EXTS_OBJS:.o=.d)
