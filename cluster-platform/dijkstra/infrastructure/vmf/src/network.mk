#**********************************************************************
#***  Network subsystem makefile                                    ***
#**********************************************************************
#***  JLR instrument cluster MY2010                                 ***
#**********************************************************************
.PHONY: network_ss network_libs vmf_exec network_exec network_clean

#-----------------------------------------------------------------------
#   Default Configuration 
#-----------------------------------------------------------------------

# Compiler switch to add profiling data
#QNX_PROFILE_MOST =-p
QNX_PROFILE_MOST =

EXTERNAL_MOST=NO

# Network power management
SS_PM=

# INIC reset support
#	If PORTMAN is enabled no need to define ENABLE_INIC_RESET
USE_PORTMAN=YES

# VMF spy option
CC_FLAGS += -DVMF_SPY

#CC_FLAGS += -DENABLE_OSAL_ASYNC


ifneq ($(VMF_MI),NO)
VMF_TARDIS=YES
endif

# Print build time to console
USE_PRINT_BUILD_TIME = YES
ifeq ($(USE_PRINT_BUILD_TIME),YES)
CC_FLAGS += -DVMF_PRINT_BUILD_TIME
endif


#-----------------------------------------------------------------------
# Network directory settings
#-----------------------------------------------------------------------
VMF_SERVER_DIR				= $(NETWORK_VOB)/vmf
VMF_CONFIG_DIR				= $(NETWORK_VOB)/vmf_config
VMF_LIB_DIR				= $(NETWORK_VOB)/vmf
VMF_MI_DIR				= $(NETWORK_VOB)/vmf_mi

# setup up IPC
ifeq ($(VMF_IPC),SOCK_UDP)
# UDP Socket IPC
VMF_IPC_DIR                 = $(NETWORK_VOB)/vmf_ipc_udp
CC_FLAGS += -DSOCK_UDP
else ifeq ($(VMF_IPC),SOCK_DOMAIN)
# DOMAIN Socket IPC
VMF_IPC_DIR                 = $(NETWORK_VOB)/vmf_ipc_socket
CC_FLAGS += -DSOCK_DOMAIN
else ifeq ($(VMF_IPC),SHM)
# Shared Memory IPC
VMF_IPC_DIR                 = $(NETWORK_VOB)/vmf_ipc_shm
else ifeq ($(VMF_IPC),MQ)
# Message queue IPC
VMF_IPC_DIR                 = $(NETWORK_VOB)/vmf_ipc_mq
ifneq ($(PROJECT),INTEGRITY)
CC_FLAGS += -DENABLE_OSAL_ASYNC
endif
else
# default = DOMAIN Socket IPCS
VMF_IPC_DIR                 = $(NETWORK_VOB)/vmf_ipc_socket
endif


VMF_TRACE_LIB_DIR			= $(NETWORK_VOB)/vmf_trace
VMF_TRACE_SVR_DIR			= $(NETWORK_VOB)/vmf_trace
ifeq ($(VMF_TRACE),YES)
VMF_REM=YES
endif

ifeq ($(VMF_REM),YES)
VMF_REM_SERVER_DIR			= $(NETWORK_VOB)/vmf_rem_server
VMF_REM_CLIENT_DIR			= $(NETWORK_VOB)/vmf_rem_client
endif

ifeq ($(VMF_SQL),YES)
VMF_SQL_SERVER_DIR			= $(NETWORK_VOB)/vmf_sql
endif

VMF_EXTS_DIR   			    = $(NETWORK_VOB)/vmf_extensions


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

# local linux 64bit
ifeq ($(PROJECT),LINUX_X86_64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DLINUX_X86_64
endif

# local linux
ifeq ($(PROJECT),LINUX_X86_GCOV)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
GCOV=-fprofile-arcs -ftest-coverage -DVMF_GCOV
CC_FLAGS += -DLINUX_X86_GCOV
endif

# Windows compiled with mingw cross compiler 
ifeq ($(PROJECT),WINDOWS_X86)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_windows
CC_FLAGS += -DWINDOWS_X86
	ifeq ($(HOST),WINDOWS)
        # Workaround for MinGW re-defintion of timespec
        # CC_FLAGS += -DHAVE_STRUCT_TIMESPEC -DNEED_STRUCT_I_TIMERSPEC -DWIN32
	    CC_FLAGS += -DHAVE_STRUCT_TIMESPEC -DWIN32
	else
        CC_FLAGS += -DNEED_STRUCT_I_TIMERSPEC
	endif
endif

ifeq ($(PROJECT),WINDOWS_X86_64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_windows_64
CC_FLAGS += -DWINDOWS_X86_64
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

# QNX 7.0.0 x86_64!
ifeq ($(PROJECT),QNX_700_X86_64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_700_X86_64
endif

# QNX 7.0.0 aarch64!
ifeq ($(PROJECT),QNX_700_AARCH64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_700_AARCH64
endif

# QNX 7.1.0 aarch64!
ifeq ($(PROJECT),QNX_710_AARCH64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_710_AARCH64
endif

# QNX 7.0.0 armv7!
ifeq ($(PROJECT),QNX_700_ARMV7)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_700_ARMV7
endif

# QNX 6.6.0 armv7!
ifeq ($(PROJECT),QNX_660_ARMV7)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DQNX_660_ARMV7
endif

# arm linux 64bit
ifeq ($(PROJECT),LINUX_AARCH64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DLINUX_AARCH64
endif

# Nissan DC1.5 (QNX ARM)!
ifeq ($(PROJECT),DC15)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DDC15
endif

# Einstein / X351 Cluster (QNX ARM)!
ifeq ($(PROJECT),EINSTEIN)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DEINSTEIN
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

# Ford D544 (QNX ARM)!
ifeq ($(PROJECT),D544)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DD544
endif

# PSA P2D3 (QNX ARM)!
ifeq ($(PROJECT),P2D3)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_qnx
CC_FLAGS += -DP2D3
endif

# Linux ARM_HF
ifeq ($(PROJECT),LINUX_ARM_HF)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DLINUX_ARM_HF
endif

# Windows compiled with mingw cross compiler 
ifeq ($(PROJECT),INNO_WINDOWS)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_windows

	ifneq ($(HOST),WINDOWS)
        # Workaround for MinGW re-defintion of timespec
        CC_FLAGS += -DNEED_STRUCT_I_TIMERSPEC
	endif

CC_FLAGS += -DINNO_WINDOWS 
endif

# Windows compiled with mingw cross compiler (64bit!)
ifeq ($(PROJECT),INNO_WINDOWS_64)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_windows_64
CC_FLAGS += -DINNO_WINDOWS_64 
endif

# Linux INNO_ARM_HF
ifeq ($(PROJECT),INNO_ARM_HF)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DINNO_ARM_HF
endif

# Linux INNO_ARM
ifeq ($(PROJECT),INNO_ARM)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DINNO_ARM
endif

# RasPi
ifeq ($(PROJECT),RASPI)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DRASPI
endif

# U321 ARM!
ifeq ($(PROJECT),U321)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_linux
CC_FLAGS += -DU321
endif

# Integrity RTOS
ifeq ($(PROJECT),INTEGRITY)
NETWORK_CONFIG_DIR			= $(NETWORK_VOB)/nw_os_config_integrity
ifeq ($(HOST),WINDOWS)
INTEGRITY_BSP			    = -bsp=devtree-cortex-a15 -os_dir=C:/ghs/int1124-P2
CI_FLAGS  = -integrity_version 11.2.4 -alt_tools_path C:/ghs/comp_201416
else
INTEGRITY_BSP			    = -bsp=devtree-cortex-a15 -os_dir=/opt/ghs/ghs.int1124-P2
CI_FLAGS  = -integrity_version 11.2.4 -alt_tools_path /opt/ghs/ghs.comp_201416_linux
endif
CC_FLAGS += -DINTEGRITY $(INTEGRITY_BSP) -gnu99 --unknown_pragma_silent 
CC_FLAGS += -D__MISRA_20_9=0 -D__MISRA_124=0 -D__CHECK_API_ERROR=0     #suppress warnings from BSP!
CI_FLAGS += -gstack_options -intexoption -no_shared_libs -intexoption -no_shared_libs_quiet -intexoption -allocate_initialized_together 
CI_INT_FILE = -intfile $(NETWORK_CONFIG_DIR)/vmf.int
endif

#-----------------------------------------------------------------------
# Network Component Makefiles
#-----------------------------------------------------------------------
include $(VMF_SERVER_DIR)/03_code/build/nw_vmf_server.mk
include $(VMF_LIB_DIR)/03_code/build/nw_vmf_lib.mk
include $(VMF_IPC_DIR)/03_code/build/nw_vmf_ipc.mk
include $(NETWORK_CONFIG_DIR)/03_code/build/nw_os_config.mk
include $(VMF_TRACE_LIB_DIR)/03_code/build/vmf_trace_lib.mk

ifeq ($(VMF_REM),YES)
include $(VMF_REM_SERVER_DIR)/03_code/build/vmf_rem_server.mk
endif

ifeq ($(VMF_TRACE),YES)
include $(VMF_TRACE_SVR_DIR)/03_code/build/vmf_trace_svr.mk
endif

ifeq ($(VMF_MI),YES)
include $(VMF_MI_DIR)/03_code/build/vmf_mi.mk
endif

ifeq ($(VMF_SQL),YES)
VMF_SQL_SERVER_DIR			= $(NETWORK_VOB)/vmf_sql
include $(VMF_SQL_SERVER_DIR)/03_code/build/vmf_sql_server.mk
endif

ifneq ($(VMF_EXTS),NO)
include $(VMF_EXTS_DIR)/03_code/build/vmf_extension_starter.mk
CC_FLAGS += -DVMF_EXTS
endif

#-----------------------------------------------------------------------
# Network public and protected includes
#-----------------------------------------------------------------------
NETWORK_PUBLIC_INC =             \
	$(VMF_SERVER_PUBLIC_INC) \
	$(VMF_LIB_PUBLIC_INC)    \
	$(NW_CONFIG_PUBLIC_INC)  \
	$(VMF_TRACE_LIB_PUBLIC_INC) \
    $(VMF_TRACE_SVR_PUBLIC_INC) \
	$(VMF_SQL_SERVER_PUBLIC_INC) \
    $(VMF_EXTS_INC)         
	
NETWORK_PUBLIC_INC += -I$(VMF_CONFIG_DIR)

ifeq ($(VMF_MI),YES)
	NETWORK_PUBLIC_INC += $(VMF_MI_PUBLIC_INC)
endif

ifeq ($(VMF_REM),YES)
	NETWORK_PUBLIC_INC += $(VMF_REM_SERVER_PUBLIC_INC)
endif


NETWORK_PROTECTED_INC = \
	$(VMF_SERVER_PROTECTED_INC) \
	$(VMF_LIB_PROTECTED_INC) \
	$(VMF_IPC_PROTECTED_INC)
	

ifeq ($(VMF_MI),YES)
	NETWORK_PROTECTED_INC += $(VMF_MI_PROTECTED_INC)
endif

ifeq ($(VMF_REM),YES)
	NETWORK_PROTECTED_INC += $(VMF_REM_SERVER_PROTECTED_INC)
endif

ifeq ($(VMF_TRACE),YES)
	NETWORK_PROTECTED_INC += $(VMF_TRACE_LIB_PROTECTED_INC)
endif


#-----------------------------------------------------------------------
# Network QAC
#-----------------------------------------------------------------------
NETWORK_QAC_ANALYSE_SOURCE_FILE =
NETWORK_QAC_GENERATE_ANNOTATED_SOURCE_CODE 	=


#-----------------------------------------------------------------------
# Build rules
#-----------------------------------------------------------------------
network_libs:  vmf_create_time_header echo_network_libs nw_config vmf_ipc vmf_lib vmf_trace_lib

network_libs_clean: vmf_lib_clean vmf_trace_lib_clean

network_exec: network_libs vmf_extensions vmf_exec 

network_clean: network_libs_clean vmf_clean vmf_trace_svr_clean vmf_mi_clean vmf_exts_clean

vmf_exec: echo_vmf  vmf_lib vmf_trace_svr vmf_mi $(ARMLE_BIN_DIR)/vmf



#------------------------------------------------------------------------------------------------------------------------------------
# VMF
#------------------------------------------------------------------------------------------------------------------------------------
$(ARMLE_BIN_DIR)/vmf: nw_config vmf_rem_server vmf_server vmf_ipc  $(ARMLE_BIN_DIR)/vmf_sql
ifeq ($(os),qnx)
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) $(VMF_EXTS_OBJS) -L $(ARMLE_LIB_DIR) -L $(PLATFROM_QNX_TARGET)/qnx6/armle/lib -lsocket -lmq -o $@
else ifeq ($(os),windows)
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) $(VMF_EXTS_OBJS) -L $(ARMLE_LIB_DIR) $(SYS_LIBS) -o $@.exe
else ifeq ($(os),integrity)
	##$(MAKE_ECHO)$(CL) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) $(VMF_EXTS_OBJS) -L $(ARMLE_LIB_DIR) $(SYS_LIBS) $(INTEGRITY_BSP) $(CL_FLAGS) -o $@.elf
	$(MAKE_ECHO)$(CL)  $(NW_CONFIG_OBJS) $(NW_CONFIG_SHM_OBJS) $(VMF_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) $(SYS_LIBS)  $(INTEGRITY_BSP)  -o $@.elf
	$(MAKE_ECHO)$(CL)  $(NW_CONFIG_SHM_OBJS) -lshm_manager $(INTEGRITY_BSP)  -o $(ARMLE_BIN_DIR)/vmf_shm_mgr.elf
	$(MAKE_ECHO)$(CI)  $(INTEGRITY_BSP) $(CI_FLAGS) $(CI_INT_FILE) -o $@ 
else
	$(MAKE_ECHO)$(CC) $(STATIC) $(NW_CONFIG_OBJS) $(VMF_SERVER_OBJS) $(VMF_REM_SERVER_OBJS) $(VMF_IPC_OBJS) $(VMF_TRACE_SERVER_OBJS) $(VMF_TRACE_LIB_OBJS) $(VMF_MI_OBJS) $(VMF_EXTS_OBJS) $(GCOV) -L $(ARMLE_LIB_DIR)   -lpthread -lrt -ldl -o $@
endif
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "vmf executables are made"
	$(ECHO) " "
	$(ECHO) " "


vmf_clean: nw_config_clean vmf_lib_clean vmf_server_clean vmf_ipc_clean vmf_rem_server_clean vmf_sql_clean



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
# DISABLE SYSINFO
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
# Target Logging (currently VMF Trace only!)
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_TARGET_LOGGING),YES)
CC_FLAGS += -DVMF_TARGET_LOGGING
endif


#------------------------------------------------------------------------------------------------------------------------------------
# Target Logging (USB-logging)
#------------------------------------------------------------------------------------------------------------------------------------
ifeq ($(VMF_FILE_LOGGING),YES)
CC_FLAGS += -DVMF_FILE_LOGGING
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
# VMF Print Build Time to console
#------------------------------------------------------------------------------------------------------------------------------------
vmf_create_time_header:
	python scripts/create_time_header.py vmf_config



#------------------------------------------------------------------------------------------------------------------------------------
# VMF EXTENSIONS (VMF_EXTS)
#------------------------------------------------------------------------------------------------------------------------------------
ifneq ($(VMF_EXTS),NO)
vmf_extensions:
vmf_exts_clean:
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
	$(ECHO) "SQL server made"
	$(ECHO) " "
	$(ECHO) " "

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


echo_vmf:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "VMF"

echo_inic_flashing_exec:
	$(ECHO) "+------------------------------------------------------------+"
	$(ECHO) "INIC FLASHING"
