#--------------------------------------------------------------
# Makefile for nw config.
#--------------------------------------------------------------

NW_CONFIG_OBJ_DIR           = $(OBJ_PATH)/nw_config
NW_CONFIG_PUBLIC_INC        = -I$(NETWORK_CONFIG_DIR)/03_code/public

NW_CONFIG_OBJS = $(NW_CONFIG_OBJ_DIR)/nw_os_config.o


nw_config_clean:
	$(RM) $(NW_CONFIG_OBJ_DIR) $(NW_CONFIG_OBJS)

nw_config: nw_config_obj_dir $(NW_CONFIG_OBJS)

nw_config_obj_dir:
	$(MAKE_ECHO)mkdir -p $(NW_CONFIG_OBJ_DIR)

$(NW_CONFIG_OBJS): $(NETWORK_CONFIG_DIR)/03_code/build/nw_os_config.mk



#--------------------------------------------------------------
#	Compile rules
#--------------------------------------------------------------

$(NW_CONFIG_OBJ_DIR)/%.o: $(NETWORK_CONFIG_DIR)/03_code/src/%.c
	$(ECHO_COMPILING)
	$(QCC_COMPILER) -fPIC $(NETWORK_PUBLIC_INC) $(CCINC) $(OTF_ENABLE) -Wp,-MD,$(@:.o=.p) -o $@ $<
	$(FIXDEP)
	$(ECHO_QACING)
	$(NETWORK_QAC_ANALYSE_SOURCE_FILE)
	$(NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE)

-include $(NW_CONFIG_OBJS:.o=.d)
