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
if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
	set(BOARD_VAR e4_a1)
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
	set(BOARD_VAR e4_a0)
endif()

# Add custom target to build BSP when it is not compiled
add_custom_command(
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/prebuilt_${BOARD_VAR}/         ${CMAKE_BINARY_DIR}/install/
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/prebuilt_common/               ${CMAKE_BINARY_DIR}/install/
	COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/install/BSP_Installed
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	USES_TERMINAL
	OUTPUT ${CMAKE_BINARY_DIR}/install/BSP_Installed
	COMMENT "Building Linux BSP"
)

add_custom_target(build_linuxbsp ALL DEPENDS ${CMAKE_BINARY_DIR}/install/BSP_Installed)

# Add a target to clean all BSP
add_custom_target(clean_linuxbsp
	COMMENT "Cleaning Linux BSP" VERBATIM
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/${BOARD_VAR}/${CMAKE_BUILD_TYPE}
	COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/OPTEE
	USES_TERMINAL
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  07/07/2023  | MMK      |    N/A    | Created initial file from P33 program
#-------------------------------------------------------------------------------------------------------------------
