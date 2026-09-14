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

set (CMAKE_SIGCDD_CORE ${CMAKE_CURRENT_SOURCE_DIR}/../../ui-core/functional_safety/sigcdd/ui.core.sigcdd)

# Files to be Linked into the static Library
add_library(${MODULE_NAME} STATIC
    ${CMAKE_SIGCDD_CORE}/SigCdd/src/SigCdd.c
    ${CMAKE_SIGCDD_CORE}/SigMgrCdd/src/SigMgrCdd.c
    ${CMAKE_SIGCDD_CORE}/SigIfCdd/src/SigIfCdd.c
)

# Add Compile macro definitions
target_compile_definitions (${MODULE_NAME}
    PUBLIC
    GFX_USE_TIDSS_DRIVER
)

# Directories with header files to be shared
target_include_directories (${MODULE_NAME}
    PUBLIC
    ${CMAKE_SIGCDD_CORE}/SigCdd/src/
    ${CMAKE_SIGCDD_CORE}/SigIfCdd/src/
    ${CMAKE_SIGCDD_CORE}/SigMgrCdd/src/
    ${CMAKE_CURRENT_SOURCE_DIR}/sigcdd-cfg/
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

# Add dependency Libraries
target_add_dependencies (${MODULE_NAME}
    PRIVATE
    GenBsw
    CmpLib
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |       Task       |                            Description
#-------------------------------------------------------------------------------------------------------------------
#  22/08/2024 | PCHUKLEV | BMIC29130-35031  | Created initial file
#-------------------------------------------------------------------------------------------------------------------
