#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2024] Visteon Corporation
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
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dlt_gateway_component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dlt_gateway_tcp_server.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dlt_gateway_shm_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dlt_gateway_core_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dlt_gateway_payload_validate.cpp
    ${GP_RTE_DIR}/gip/src/applications/dlt_gateway/main.cpp
    ${GP_RTE_DIR}/gip/src/applications/dlt_gateway/dlt_gateway.cpp
)

# Add target include directories
target_include_directories(
    ${BINARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${GP_RTE_DIR}/gip/src/applications/dlt_gateway/
)

# Add dependency libraries
target_add_dependencies(
    ${BINARY_NAME}
    PUBLIC
    GenRuntime
    dk_logger
    dk_runtime
)
  
# Install the binary
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
      
#-----------------------------------------------------------------------------------------------------------------}
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  9/8/2020  | rkrishn8 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
