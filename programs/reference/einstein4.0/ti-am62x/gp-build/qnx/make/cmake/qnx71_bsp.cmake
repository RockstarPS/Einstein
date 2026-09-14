#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2020] Visteon Corporation
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

# Set variables used by the support scripts
set(BSP_DIR         ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x)
set(PROJECT_BSP_DIR ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/qnx71-bsp)

# Generate images for EINSTEIN4.0_EVK
if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
    set(BOARD_VAR e4_run0)
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
    set(BOARD_VAR e4_run0)
endif()

# Add custom target to build BSP when it is not compiled
add_custom_command(
    COMMENT "Building QNX BSP"
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BSP_DIR}/qnx71-bsp/install
    COMMAND cp -fr ${PROJECT_BSP_DIR}/src/hardware/startup/boards/am62p/${BOARD_VAR} ${BSP_DIR}/qnx71-bsp/src/hardware/startup/boards/
    COMMAND cp -fr ${PROJECT_BSP_DIR}/src/hardware/wfd ${BSP_DIR}/qnx71-bsp/src/hardware/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/qnx/prebuilt_common/ ${CMAKE_BINARY_DIR}/install/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/qnx/prebuilt_${BOARD_VAR}/ ${CMAKE_BINARY_DIR}/install/
    COMMAND make all
    COMMAND ${CMAKE_COMMAND} -E touch ${BSP_DIR}/qnx71-bsp/install/BSP_Installed
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${BSP_DIR}/qnx71-bsp/install ${CMAKE_BINARY_DIR}/install
    WORKING_DIRECTORY ${BSP_DIR}/qnx71-bsp
    USES_TERMINAL
    OUTPUT ${BSP_DIR}/qnx71-bsp/install/BSP_Installed
    )
add_custom_target(build_qnxbsp DEPENDS ${BSP_DIR}/qnx71-bsp/install/BSP_Installed)

# Add a target to clean all BSP
add_custom_target(clean_qnxbsp
    COMMENT "Cleaning QNX BSP" VERBATIM
    WORKING_DIRECTORY ${BSP_DIR}/qnx71-bsp
    COMMAND make clean
    COMMAND git clean -xdf
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BSP_DIR}/install
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BSP_DIR}/qnx71-bsp/src/hardware/startup/boards/${BOARD_VAR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/install/
    USES_TERMINAL
    )

#add_dependencies(clean_bsp build_bsp)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  29/03/2024  | NSUBRAM2 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
