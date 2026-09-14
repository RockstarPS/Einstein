cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_TEMPL_CXX_FLAGS}")

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../inc
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.vsomeip.qnx7-aarch64.Dbg/External/include
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/inc/     
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/infra.comm.vmf/rel/qnx700_aarch64/include
)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.boost.qnx7-aarch64.Dbg/External/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.vsomeip.qnx7-aarch64.Dbg/External/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/infra.comm.vmf/rel/qnx700_aarch64/libs
)
  
add_executable(vmf_msg_sender_receiver
	${CMAKE_CURRENT_SOURCE_DIR}/../src/uclstub_helper.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../src/uclstub_msgdb_parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../src/uclstub_msg_sender.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../src/uclstub_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/src/msg_ids.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/src/msg_maps.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/dk_runtime2_cmsgvmf.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede/dk_runtime2_deserializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede/dk_runtime2_serializer.cpp    
)

target_link_libraries(vmf_msg_sender_receiver -lvmf_client -lmq -lvsomeip -lc -lsocket)    
