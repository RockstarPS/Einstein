cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_TEMPL_CXX_FLAGS}")

include_directories(
     ${CMAKE_CURRENT_SOURCE_DIR}/../inc
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.vsomeip.qnx7-aarch64.Dbg/External/include
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/inc/     
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/infra.comm.vmf/rel/qnx700_aarch64/include
     ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.OsalWrapper.OsalWrapperC++/
	 ${CMAKE_CURRENT_SOURCE_DIR}/../../../../cdc.vruntime.src.health/
)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.boost.qnx7-aarch64.Dbg/External/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.vsomeip.qnx7-aarch64.Dbg/External/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/infra.comm.vmf/rel/qnx700_aarch64/libs
)

add_executable(srvgw_vsomeip_gac
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/srvgw_main.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/srvgw_core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/dk_gw_cmsgvmf.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/src/msg_ids.cpp
   	${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.src.someip.msgcfg.GAC/VmfSomeipMsgConfig/MsgConfig/src/msg_cache_ids.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede/dk_runtime2_deserializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../fpf.bin.External.dk.infra.comm/External/dk.runtime.core/src/runtime2/sede/dk_runtime2_serializer.cpp
)

target_link_libraries(srvgw_vsomeip_gac -lvmf_client -lmq -lvsomeip -lc -lsocket
					   traceosalcpp ScHealthClient)  








