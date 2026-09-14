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


#set(MY_MODULE_DEPS "")
 
 
if(CMAKE_CPU_FAMILY_SERIES STREQUAL "am62p")
    list(APPEND MY_MODULE_DEPS McuSdk)
endif()

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RstM.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RstM_Irq.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inc
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    GenMcal
    PlatformStubs
    GenBsw
    ${MY_MODULE_DEPS}
    GenSwc
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task            |   Description
#-------------------------------------------------------------------------------------------------------------------
#  27-Aug-2024  | NCHELLAP   |  PE4TI29141-4360  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
