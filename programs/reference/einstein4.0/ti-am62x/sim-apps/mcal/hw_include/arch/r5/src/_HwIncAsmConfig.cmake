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

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/lld_arm_r5.asm
)

# Apply assembler-specific compile flags ONLY to the .asm file
# Assembler option is selected based on https://sir.ext.ti.com/jira/browse/EXT_EP-10877
# -Wno-unused-command-line-argument - Supressing warning only in this file based on https://sir.ext.ti.com/jira/browse/EXT_EP-12044
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/lld_arm_r5.asm
    PROPERTIES
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/startup
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Aug-2024  | NCHELLAP   |  PE4TI29141-4365  |  MCAL v10.0 Update
#-------------------------------------------------------------------------------------------------------------------

