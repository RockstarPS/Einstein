cmake_minimum_required(VERSION 2.8)

add_executable(${BINARY_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/uclstub_helper.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/uclstub_msgdb_parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/uclstub_msg_sender.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/uclstub_main.cpp        
        ${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/dk_runtime2_cmsgvmf.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede/dk_runtime2_deserializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede/dk_runtime2_serializer.cpp	
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/src/msg_ids.cpp
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/src/msg_maps.cpp 
)

include_directories(${BINARY_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2
	${CMAKE_CURRENT_SOURCE_DIR}/../../vsomeip/vsomeip/vsomeip/QNX/interface
	${CMAKE_CURRENT_SOURCE_DIR}/../../../infrastructure/vmf/bin/qnx700_aarch64/include
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/inc
)

target_link_libraries(${BINARY_NAME}
	PUBLIC
	vmf_client
	-lmq
        vsomeip	
        -lc
        socket
)

# Install the binary
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}

)
