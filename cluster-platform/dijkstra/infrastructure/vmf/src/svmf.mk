#**********************************************************************
#***  Network subsystem makefile                                    ***
#**********************************************************************
#***  JLR instrument cluster MY2010                                 ***
#**********************************************************************
.PHONY: network_ss network_libs vmf_exec network_exec network_clean

#-----------------------------------------------------------------------
#   Default Configuration
#-----------------------------------------------------------------------


EXTERNAL_MOST=NO

# Network power management
SS_PM=

# INIC reset support
#	If PORTMAN is enabled no need to define ENABLE_INIC_RESET
USE_PORTMAN=YES

# VMF spy option
CC_FLAGS += -DVMF_SPY

#CC_FLAGS += -DENABLE_OSAL_ASYNC


#-----------------------------------------------------------------------
# Network directory settings
#-----------------------------------------------------------------------
VMF_SERVER_DIR				= $(NETWORK_VOB)/svmf
VMF_CONFIG_DIR				= $(NETWORK_VOB)/svmf_config
VMF_LIB_DIR				= $(NETWORK_VOB)/vmf
VMF_MI_DIR				= $(NETWORK_VOB)/vmf_mi


#-----------------------------------------------------------------------
# select nw_os_config dir
#-----------------------------------------------------------------------

#default
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux

# local linux
ifeq ($(PROJECT),LINUX_X86)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DLINUX_X86
endif

# Windows compiled with mingw cross compiler
ifeq ($(PROJECT),WINDOWS_X86)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_windows
CC_FLAGS += -DWINDOWS_X86
endif


# R0-13 ARM!
ifeq ($(PROJECT),R013)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DR013
endif

# EAGLE ARM!
ifeq ($(PROJECT),EAGLE)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DEAGLE
endif

# QNX x86!
ifeq ($(PROJECT),QNX_X86)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_X86
endif

# Nissan DC1.5 (QNX ARM)!
ifeq ($(PROJECT),DC15)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DDC15
endif

# EAGLE Update ARM!
ifeq ($(PROJECT),EAGLE_UPDATE)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DEAGLE_UPDATE
endif

# OpenSynergy Linux on ARM!
ifeq ($(PROJECT),OPENSYN)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_opensyn_linux
CC_FLAGS += -DOPENSYN
endif


#-----------------------------------------------------------------------
# Network Component Makefiles
#-----------------------------------------------------------------------
include $(VMF_SERVER_DIR)/03_code/build/nw_vmf_server.mk
include $(NETWORK_CONFIG_DIR)/03_code/build/nw_os_config.mk


#-----------------------------------------------------------------------
# Network public and protected includes
#-----------------------------------------------------------------------
NETWORK_PUBLIC_INC = \
    -I$(VMF_CONFIG_DIR) \
	$(NW_CONFIG_PUBLIC_INC)

NETWORK_PROTECTED_INC = \
	$(VMF_SERVER_PROTECTED_INC) \
	$(VMF_IPC_PROTECTED_INC)


#-----------------------------------------------------------------------
# Network QAC
#-----------------------------------------------------------------------
NETWORK_QAC_ANALYSE_SOURCE_FILE =
NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE 	=


#-----------------------------------------------------------------------
# Build rules
#-----------------------------------------------------------------------
network_libs: echo_network_libs nw_config vmf_ipc vmf_lib vmf_trace_lib

network_libs_clean: vmf_lib_clean vmf_trace_lib_clean

network_exec: network_libs vmf_exec

network_clean: network_libs_clean vmf_clean vmf_trace_svr_clean vmf_mi_clean

vmf_exec: echo_vmf vmf_lib vmf_trace_svr vmf_mi $(ARMLE_BIN_DIR)/vmf

### network_ss: network_libs network_exec


svmf_exec: echo_svmf $(ARMLE_BIN_DIR)/svmf




#------------------------------------------------------------------------------------------------------------------------------------
# VMF
#------------------------------------------------------------------------------------------------------------------------------------
$(ARMLE_BIN_DIR)/svmf: nw_config $(ARMLE_BIN_DIR)/vmf_rem_server vmf_server
ifeq ($(os),qnx)
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) -L $(ARMLE_LIB_DIR) -L $(PLATFROM_QNX_TARGET)/qnx6/armle/lib -lsocket -lmq -o $@
else ifeq ($(os),windows)
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) -L $(ARMLE_LIB_DIR)  $(SYS_LIBS) -o $@.exe
else
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) -L $(ARMLE_LIB_DIR)  -lpthread -lrt -ldl -o $@
endif
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "vmf executables are made"


#OLD: svmf_clean: nw_config_clean vmf_lib_clean vmf_server_clean vmf_ipc_clean vmf_rem_server_clean vmf_sql_clean

svmf_clean: vmf_server_clean



#------------------------------------------------------------------------------------------------------------------------------------
# DO not use SOCKETS
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(NO_SOCKETS),YES)
CC_FLAGS += -DNO_SOCKETS
endif

#------------------------------------------------------------------------------------------------------------------------------------
# VMF TARDIS
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_TARDIS),YES)
CC_FLAGS += -DVMF_TARDIS
endif

#------------------------------------------------------------------------------------------------------------------------------------
# VMF TARDIS
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_SYSINFO),NO)
CC_FLAGS += -DDISABLE_SYSINFO
endif

#------------------------------------------------------------------------------------------------------------------------------------
# DLT gateway
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(DLT_GW),YES)
CC_FLAGS += -DDLT_GW
endif

#------------------------------------------------------------------------------------------------------------------------------------
# VMF Remote Server
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_REM),YES)
CC_FLAGS += -DVMF_REM
$(ARMLE_BIN_DIR)/vmf_rem_server: vmf_rem_server
#	@echo "vmf remote server objects made"
else
$(ARMLE_BIN_DIR)/vmf_rem_server:
vmf_rem_server_clean:
endif

#------------------------------------------------------------------------------------------------------------------------------------
# VMF TRACE
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_TRACE),YES)
CC_FLAGS += -DVMF_TRACE
else
vmf_trace_lib:
vmf_trace_lib_clean:
vmf_trace_svr:
vmf_trace_svr_clean:
endif


#$(ARMLE_BIN_DIR)/profiler:


#------------------------------------------------------------------------------------------------------------------------------------
# VMF MI
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_MI),YES)
CC_FLAGS += -DVMF_MI
else
vmf_mi:
vmf_mi_clean:
endif


#------------------------------------------------------------------------------------------------------------------------------------
# VMF SQL
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_SQL),YES)
 $(ARMLE_BIN_DIR)/vmf_sql: vmf_sql_server
ifeq ($(os),qnx)
	$(MAKE_ECHO)$(CC) $(VMF_SQL_SERVER_OBJS) -L $(ARMLE_LIB_DIR) -L $(PLATFROM_QNX_TARGET)/qnx6/armle/lib -lsocket -lmq -lvmf_client -lvmf_trace -o $@
else ifeq ($(os),windows)
	$(MAKE_ECHO)$(CC) $(VMF_SQL_SERVER_OBJS) -L $(ARMLE_LIB_DIR) -L $(PLATFROM_QNX_TARGET)/qnx6/armle/lib $(SYS_LIBS) -lvmf_client -lvmf_trace -o $@.exe
else
	$(MAKE_ECHO)$(CC) $(VMF_SQL_SERVER_OBJS) -L $(ARMLE_LIB_DIR) -L $(PLATFROM_QNX_TARGET)/qnx6/armle/lib -lpthread -lvmf_client -lvmf_trace -lrt -lpthread -ldl -o $@
endif
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "vmf executables are made"

vmf_sql_clean:        vmf_sql_server_clean
else

 $(ARMLE_BIN_DIR)/vmf_sql:
vmf_sql_clean:

endif



echo_network_libs:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "Network libraries"


echo_network_exec:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "Network"


echo_svmf:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "| SMALL VMF !!!                                              |"
	$(ECHO) "+------------------------------------------------------------+"


echo_vmf:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "VMF"

echo_inic_flashing_exec:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "INIC FLASHING"
