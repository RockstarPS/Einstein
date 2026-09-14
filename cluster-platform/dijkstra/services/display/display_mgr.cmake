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

target_sources(${BINARY_NAME}
    PRIVATE
        ${GP_RTE_DIR}/gip/src/applications/display_mgr/main.cpp
        ${GP_RTE_DIR}/gip/src/applications/display_mgr/display_mgr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/display_manager_component.cpp
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    GenRuntime
    dk_logger
    dk_runtime
    bspal_display
)

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
target_link_libraries(${BINARY_NAME}
    PRIVATE
    ham
    mq
    slog2
    vmf_client
)
endif()

if(DK_DISPLAY_GAMMA_RGB)
target_compile_definitions(${BINARY_NAME} PRIVATE DISPLAY_GAMMA_RGB)
endif()


target_include_directories(${BINARY_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${GP_RTE_DIR}/gip/src/applications/display_mgr
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2020/07/27  | ASUNDAR6 |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
