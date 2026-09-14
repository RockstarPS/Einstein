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
if(DISPLAY_VAR STREQUAL VIP_CONTROLLED_DISPLAY)
    set(ecuappm_callouts_files             ${CMAKE_CURRENT_SOURCE_DIR}/VIP_Early_HMI/src/EcuAppM_Callouts.c)
    set(ecuappm_callouts_header_paths      ${CMAKE_CURRENT_SOURCE_DIR}/VIP_Early_HMI/include)
elseif(DISPLAY_VAR STREQUAL GIP_CONTROLLED_DISPLAY)
    set(ecuappm_callouts_files             ${CMAKE_CURRENT_SOURCE_DIR}/GIP_HMI/src/EcuAppM_Callouts.c)
    set(ecuappm_callouts_header_paths      ${CMAKE_CURRENT_SOURCE_DIR}/GIP_HMI/include)
endif()

add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${ecuappm_callouts_files}
)

target_include_directories(${MODULE_NAME}
    PUBLIC
    ${ecuappm_callouts_header_paths}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    PlatformStubs
    GenSwc
    EcuPowerM
    Display

)  
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 10/07/2023    akappa                  Initial version of ECUAPPM module
#-------------------------------------------------------------------------------------------------------------------
