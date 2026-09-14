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

if(CMAKE_SYSTEM_NAME MATCHES QNX)
    target_add_dependencies(${BINARY_NAME}
    INTERFACE
    bspal_sys_shutdown
    imx_sys_shutdown
   )
elseif(CMAKE_SYSTEM_NAME MATCHES Linux)
	target_add_dependencies(${BINARY_NAME}
       	#INTERFACE
	PUBLIC
	bspal_sys_shutdown
	#linux_sys_shutdown
)
endif()

if(DK_SHUTDOWN_TESTS)
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test_01/dk_shutdown_c1.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test_02/dk_shutdown_c2.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/cxx_client/test_01/dk_shutdown_cxx1.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/cxx_client/test_02/dk_shutdown_cxx2.cmake
 )
 endif()
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task             |  Description
#-------------------------------------------------------------------------------------------------------------------
# 08/20/2020  |   DRAJ5  |                    | Created initial file
# 28/06/2024  | dpanneer | PE4TI29141-3781    | Added for linux 
#-------------------------------------------------------------------------------------------------------------------
