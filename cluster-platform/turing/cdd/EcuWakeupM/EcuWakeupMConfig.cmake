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

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EcuWakeupM.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EcuWakeupM_ErrorHandler.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/SchM_EcuWakeupM.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_src/EcuWakeupM_LowlevelDrv_Gpt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_src/EcuWakeupM_LowlevelDrv_Icu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_src/EcuWakeupM_LowlevelDrv_Port.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_include
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    Common
    PlatformStubs
    GenMcal
	GenSwc
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  9/04/2020  | RMITEV   |  1037227  | Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
