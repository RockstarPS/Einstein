#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2019] Visteon Corporation
# All Rights Reserved.
#
# NOTICE: This is an unpublished work of authorship, which contains trade secrets.
# Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
# its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
# or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
# in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
# under all copyright laws to protect this work as a published work, when appropriate.
# Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
# without the written authorization of Visteon Corporation.
#
#---------------------------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 2.8)


if(CMAKE_SYSTEM_NAME MATCHES QNX)
include_directories(${BINARY_NAME}
	PUBLIC
    	${CMAKE_CURRENT_SOURCE_DIR}/inc
    	${CMAKE_CURRENT_SOURCE_DIR}/../../vsomeip/interface	
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/inc		
)
elseif(CMAKE_SYSTEM_NAME MATCHES Linux)
include_directories(${BINARY_NAME}
	PUBLIC
    	${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vsomeip/interface
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/inc		
)
endif()

add_executable(${BINARY_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/srvgw_main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/srvgw_core.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/dk_gw_cmsgvmf.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede/dk_runtime2_deserializer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../runtime2/sede/dk_runtime2_serializer.cpp
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/src/msg_ids.cpp
	${SIP_GEN_DIR}/VmfSomeipMsgConfig/MsgConfig/src/msg_cache_ids.cpp	
)

if (DK_CDC_WATCHDOG_ENABLED)
target_compile_definitions(${BINARY_NAME} PRIVATE DK_CDC_WATCHDOG_ENABLED)
message("srvgw_vsomeip build : cdc watchdog enabled")
elseif (DK_HAM_WATCHDOG_ENABLED)
target_compile_definitions(${BINARY_NAME} PRIVATE DK_HAM_WATCHDOG_ENABLED)
message("srvgw_vsomeip build : ham watchdog enabled")
else()
message("srvgw_vsomeip build : watchdog disabled")
endif()


if (DK_DLT_ENABLED)
       target_compile_definitions(${BINARY_NAME} PRIVATE SOMEIPGW_DLT_LOGGER_ENABLED)
endif()


if(CMAKE_SYSTEM_NAME MATCHES QNX)

if (DK_CDC_WATCHDOG_ENABLED)
        target_add_dependencies(${BINARY_NAME}
                PUBLIC
                ScHealthClient    
        )
elseif (DK_HAM_WATCHDOG_ENABLED)
        target_add_dependencies(${BINARY_NAME}
                PUBLIC
                dk_wdg_client    
        )
endif()
elseif (CMAKE_SYSTEM_NAME MATCHES Linux)

endif()

if (DK_DLT_ENABLED)
        target_add_dependencies(${BINARY_NAME}
                PUBLIC
                dk_logger 
        )
else()
        target_add_dependencies(${BINARY_NAME}
                PUBLIC
                traceosalcpp  
        )
endif()


if(CMAKE_SYSTEM_NAME MATCHES QNX)
        target_link_libraries( ${BINARY_NAME}
                PRIVATE
                vmf_client 
                mq  
                c 
                socket
                vsomeip   
        )
elseif (CMAKE_SYSTEM_NAME MATCHES Linux)
        target_link_libraries( ${BINARY_NAME}
                PRIVATE
                vmf_client 
                rt  
                c 
                pthread
                vsomeip     
        )
endif()


if(CMAKE_SYSTEM_NAME MATCHES QNX)
 if (DK_CDC_WATCHDOG_ENABLED)
        target_link_libraries( ${BINARY_NAME}
                PRIVATE
                ScHealthClient
        )
 elseif (DK_HAM_WATCHDOG_ENABLED)
        target_link_libraries( ${BINARY_NAME}
                PRIVATE
                dk_wdg_client
        )
 endif()
endif()

if (DK_DLT_ENABLED)

else()
        target_link_libraries( ${BINARY_NAME}
                PRIVATE
                traceosalcpp     
        )
endif()


# Install the binary
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
