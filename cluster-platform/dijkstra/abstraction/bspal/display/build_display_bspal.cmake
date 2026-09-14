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
add_executable(${BINARY_NAME} dummy_executable.c)

# Add dependency libraries
if(CMAKE_SYSTEM_NAME MATCHES Linux)
target_add_dependencies(${BINARY_NAME}
        PUBLIC
	#display
        bspal_display
	
)
endif()

if(CMAKE_SYSTEM_NAME MATCHES QNX)
target_add_dependencies(${BINARY_NAME}
	PUBLIC
	resmgr_display_devctl
	bspal_display
)
endif() 


if(CMAKE_SYSTEM_NAME MATCHES QNX)

if(BSPAL_DISPLAY_TESTS)
# Add test binaries
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test01/display_power_on.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test02/display_power_off.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test03/display_pwr_on_neg.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test04/display_pwr_off_neg.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test05/display_state_read.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test06/display_state_on_neg.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test07/display_state_off.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test08/display_set_get_power.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/cxx_client/test/display_state.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test09/display_set_get_gamma_rgb.cmake
)
endif()

endif()


if(CMAKE_SYSTEM_NAME MATCHES Linux)

if(BSPAL_DISPLAY_TESTS)
# Add test binaries
binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test01/display_power_on.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test02/display_power_off.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test05/display_state_read.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test07/display_state_off.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test08/display_set_get_power.cmake
)
endif()

endif()

#-------------------------------------------------------------------------------------------------------------------
#    Date       |   User   |   Task            |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 08/07/2020    | RBABU9   |  NA               | Created initial file
# 12/08/2024    | dpanneer | PE4TI29141-4275   | Added display modules for E4 platform linux board
#-------------------------------------------------------------------------------------------------------------------
