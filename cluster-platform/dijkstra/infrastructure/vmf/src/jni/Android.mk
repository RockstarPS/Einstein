################################################################################
### VMF Android Makefile
################################################################################

LOCAL_PATH:= $(call my-dir)

VMF_IPC_DIR=vmf_ipc_socket
VMF_IPC_FILES_DIR:=../$(VMF_IPC_DIR)/03_code/src
VMF_IPC_FILES:=                                         \
	$(VMF_IPC_FILES_DIR)/nw_vmf_ipc.c                   \


VMF_OS_CONFIG_DIR:=nw_os_config_android
VMF_OS_CONFIG_FILES_DIR:=../$(VMF_OS_CONFIG_DIR)/03_code/src
VMF_OS_CONFIG_FILES:=                                   \
	$(VMF_OS_CONFIG_FILES_DIR)/nw_os_config.c


VMF_CLIENT_LIB_FILES_DIR:=../vmf/03_code/src
VMF_CLIENT_LIB_FILES:=						            \
	$(VMF_CLIENT_LIB_FILES_DIR)/nw_vmf_client.c         \
	$(VMF_CLIENT_LIB_FILES_DIR)/nw_vmf_collector.c      \
	$(VMF_CLIENT_LIB_FILES_DIR)/nw_vmf_timer.c          \
	$(VMF_CLIENT_LIB_FILES_DIR)/nw_vmf_debug.c          \
	$(VMF_CLIENT_LIB_FILES_DIR)/nw_vmf_client_uties.c

VMF_TRACE_LIB_FILES_DIR:=../vmf_trace/03_code/src
VMF_TRACE_LIB_FILES:= \
	$(VMF_TRACE_LIB_FILES_DIR)/nw_vmf_trace.c


VMF_SERVER_FILES_DIR:=../vmf/03_code/src
VMF_SERVER_FILES:=                                            \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_server.c                   \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_router.c                   \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_router_spy_queue.c         \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_client.c                   \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_collector.c                \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_controller.c               \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_timer.c                    \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_routing_db-core.c          \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_routing_db-events.c        \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_routing_db-memory.c        \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_tardis.c                   \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_debug.c                    \
	$(VMF_SERVER_FILES_DIR)/nw_vmf_ini_parser.c


VMF_REM_SERVER_FILES_DIR:=../vmf_rem_server/03_code/src
VMF_REM_SERVER_FILES:= \
	$(VMF_REM_SERVER_FILES_DIR)/nw_vmf_rem_server_connector.c \
	$(VMF_REM_SERVER_FILES_DIR)/nw_vmf_rem_server_rpc.c

VMF_TRACE_SVR_FILES_DIR:=../vmf_trace/03_code/src
VMF_TRACE_SERVER_FILES:= \
	$(VMF_TRACE_SVR_FILES_DIR)/nw_vmf_trace_server.c   \
	$(VMF_TRACE_SVR_FILES_DIR)/nw_vmf_sysinfo.c

VMF_MI_FILES_DIR:=../vmf_mi/03_code/src
VMF_MI_FILES:= \
	$(VMF_MI_FILES_DIR)/nw_vmf_mi_dtype_file.c         \
	$(VMF_MI_FILES_DIR)/nw_vmf_mi_dtype_tcp.c          \
	$(VMF_MI_FILES_DIR)/nw_vmf_mi_main.c               \
	$(VMF_MI_FILES_DIR)/vmqport_control.c


VMF_PING_SENDER_FILES:= \
	../test_processes/VmfPing/sender.c

VMF_PING_LISTENER_FILES:= \
	../test_processes/VmfPing/listener.c

VMF_SEND_FILES:= \
	test_send_basic.c

VMF_RECEIVE_FILES:= \
	test_receive_basic.c


VMF_INCLUDES:=                                          \
	../include                                          \
	../vmf_config                                       \
	../vmf/03_code/protected                            \
	../vmf/03_code/public                               \
	../vmf_mi/03_code/public                            \
	../vmf_rem_server/03_code/public                    \
	../vmf_rem_server/03_code/protected                 \
	../vmf_trace/03_code/public                         \
	../vmf_trace/03_code/protected                      \
	../$(VMF_OS_CONFIG_DIR)/03_code/public              \
	../$(VMF_IPC_DIR)/03_code/protected                 \
    ../vmf_extensions/03_code/src


VMF_C_FLAGS:= -Wall -Werror-implicit-function-declaration -DVMF_REM -DVMF_TRACE -DVMF_MI


#******************************************************************************
#*** vmf client lib
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                     \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                       \
	$(VMF_IPC_FILES)                                    \
	$(VMF_OS_CONFIG_FILES)                              \
	$(VMF_CLIENT_LIB_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := libvmf_client

#LOCAL_STATIC_LIBRARIES := libc

include $(BUILD_SHARED_LIBRARY)


#******************************************************************************
#*** vmf trace lib
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                   \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                     \
	$(VMF_TRACE_LIB_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := libvmf_trace

#LOCAL_STATIC_LIBRARIES := libc
LOCAL_SHARED_LIBRARIES := libvmf_client

include $(BUILD_SHARED_LIBRARY)


#******************************************************************************
#*** vmf server
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                    \
	$(VMF_INCLUDES)


LOCAL_SRC_FILES:=                                      \
	$(VMF_IPC_FILES)                                   \
	$(VMF_OS_CONFIG_FILES)                             \
	$(VMF_SERVER_FILES)                                \
	$(VMF_REM_SERVER_FILES)                            \
	$(VMF_TRACE_SERVER_FILES)                          \
	$(VMF_TRACE_LIB_FILES)                             \
	$(VMF_MI_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := vmf

#LOCAL_STATIC_LIBRARIES := libc cpufeatures
LOCAL_STATIC_LIBRARIES := cpufeatures

LOCAL_LDLIBS := -llog

include $(BUILD_EXECUTABLE)



#******************************************************************************
#*** VmfPing listener (test process)
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                   \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                     \
	$(VMF_PING_LISTENER_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := vmf_ping_listener

#LOCAL_STATIC_LIBRARIES := libc
LOCAL_SHARED_LIBRARIES := libvmf_client libvmf_trace

include $(BUILD_EXECUTABLE)


#******************************************************************************
#*** VmfPing sender (test process)
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                   \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                     \
	$(VMF_PING_SENDER_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := vmf_ping_sender

#LOCAL_STATIC_LIBRARIES := libc
LOCAL_SHARED_LIBRARIES := libvmf_client libvmf_trace

include $(BUILD_EXECUTABLE)


#******************************************************************************
#*** test process to send basic messages
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                   \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                     \
	$(VMF_SEND_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := vmf_send

#LOCAL_STATIC_LIBRARIES := libc
LOCAL_SHARED_LIBRARIES := libvmf_client

include $(BUILD_EXECUTABLE)


#******************************************************************************
#*** test process to receive basic messages
#******************************************************************************
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=                                   \
	$(VMF_INCLUDES)

LOCAL_SRC_FILES:=                                     \
	$(VMF_RECEIVE_FILES)

LOCAL_CFLAGS := $(VMF_C_FLAGS)

LOCAL_MODULE := vmf_receive

#LOCAL_STATIC_LIBRARIES := libc
LOCAL_SHARED_LIBRARIES := libvmf_client

include $(BUILD_EXECUTABLE)


$(call import-module,android/cpufeatures)
