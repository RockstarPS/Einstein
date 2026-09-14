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

# Create Dummy Executable to generate all the OSAL libraries
add_executable(${BINARY_NAME} dummy_executable.c)



# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    INTERFACE
    dk_wdg_client
    dk_wdg_client.a
)

# Add test binaries
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/wdg_proxy/wdg_proxy.cmake
) 

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
if(DK_HEALTH_TESTS)
    set(DK_WDG_PROXY_PATH      ${PROJ_ROOT_PATH}/cluster-platform/dijkstra/services/health/src/wdg_proxy)
    binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_13/test_13.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_12/test_12.cmake  
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_11/test_11.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_10/test_10.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_09/test_09.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_08/test_08.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_07/test_07.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_06/test_06.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_05/test_05.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_04/test_04.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_03/test_03.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_02/test_02.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT/test_01/test_01.cmake
    ) 	
endif()
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
if(DK_HEALTH_TESTS)
    set(DK_WDG_PROXY_PATH      ${PROJ_ROOT_PATH}/cluster-platform/dijkstra/services/health/src/wdg_proxy)
    binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_01/test_01.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_02/test_02.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_03/test_03.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_04/test_04.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_05/test_05.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_06/test_06.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_07/test_07.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_08/test_08.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_09/test_09.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_10/test_10.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_11/test_11.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_12/test_12.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_13/test_13.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_14/test_14.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_15/test_15.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_16/test_16.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_17/test_17.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_18/test_18.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_19/test_19.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/test_20/test_20.cmake
    )

    # Specify the source directory containing script files
    set(SCRIPT_FILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../test/wdg_test/FT_Linux/scripts)

    # Use file(GLOB ...) to get a list of all configuration files
    file(GLOB SCRIPT_FILES ${SCRIPT_FILES_DIR}/*.*)

    # Install the script files
    install( FILES ${SCRIPT_FILES} DESTINATION "${CMAKE_INSTALL_BINDIR}/wdg_test_FT" )
endif()
endif()


if(DK_HEALTH_CFG_GEN)
    add_custom_target(wdg_proxy_cfg_gen
        COMMAND python3 gen.py ${DK_HEALTH_CFG_GEN_INPUT} ${CMAKE_BINARY_DIR}/install/usr/include/wdg_proxy_cfg.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../wdg_proxy_cfg_gen
    )
    add_dependencies(${BINARY_NAME} wdg_proxy_cfg_gen)
endif()
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
