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
cmake_minimum_required (VERSION 3.14)

# Create Binary
add_executable(${BINARY_NAME})

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
target_sources(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/network_packet_filter_qnx.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager_component.cpp
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/meet-hw-imx8/src/enet_reg_readwrite/ethernet_register_read_write.cpp
	$<$<BOOL:${NETWORK_MGR_PHY_TC812}>:${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager_enet_register.cpp>
	$<$<BOOL:${NETWORK_MGR_PHY_TJA1101}>:${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager_tja1101.cpp>
    ${GP_RTE_DIR}/gip/src/applications/network_mgr/main.cpp
    ${GP_RTE_DIR}/gip/src/applications/network_mgr/network_mgr.cpp
	)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
target_sources(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/network_packet_filter_linux.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/network_manager_component.cpp
    ${GP_RTE_DIR}/gip/src/applications/network_mgr/main.cpp
    ${GP_RTE_DIR}/gip/src/applications/network_mgr/network_mgr.cpp
	)
endif()

	if(NETWORK_MGR_PHY_TC812)
	target_compile_definitions(${BINARY_NAME} PRIVATE ENET_PHY_TC812 )
	endif()
	
	if(NETWORK_MGR_PHY_TJA1101)
	target_compile_definitions(${BINARY_NAME} PRIVATE ENET_PHY_TJA1101 )
	endif()
	
	# COMPILER flag to mask IOCTL socket call in network manager. (Temporary fix)
	if(${BUILD_OS} STREQUAL QNX710)
	add_compile_definitions(${BINARY_NAME} PRIVATE QNX_710_IOCTL_SOCKET_DEPRECATION)
	endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
target_include_directories(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
	${GP_RTE_DIR}/gip/src/applications/network_mgr
	${GP_RTE_DIR}/gip/src/common 
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/tools/nxp/ethernet/lib/public/
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/meet-hw-imx8/src/include/
	)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
target_include_directories(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
	${GP_RTE_DIR}/gip/src/applications/network_mgr
	${GP_RTE_DIR}/gip/src/common
	)
endif()

# Add dependency libraries
if(NETWORK_MGR_PHY_TC812)
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    GenRuntime
    dk_logger
    dk_runtime
	ethernet_phy_read_write
)
else()
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    GenRuntime
    dk_logger
    dk_runtime
)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
target_link_libraries(${BINARY_NAME}
    PRIVATE
    rt
    vmf_client
    c
)
else()
target_link_libraries(${BINARY_NAME}
    PRIVATE
    mq
    slog2
    vmf_client
    socket
)
endif()


if(DK_NETWORK_MGR_TESTS)
binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/src/network_test.cmake
)
endif()

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2021/07/27  | RKRISHN8 |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
