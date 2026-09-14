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

if(FLTMEXT_VAR STREQUAL FLTMEXT_CONTROLLED_A0)
    set(fltmext_files               ${CMAKE_CURRENT_SOURCE_DIR}/A0/src/src/FltMExt.c)
    set(fltmext_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/A0/src/src)
elseif(FLTMEXT_VAR STREQUAL FLTMEXT_CONTROLLED_A1)
    set(fltmext_files               ${CMAKE_CURRENT_SOURCE_DIR}/A1/src/src/FltMExt.c)
    set(fltmext_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/A1/src/src)
else()
    message(STATUS "FLTMEXT_VAR is set to A1!")
    set(fltmext_files               ${CMAKE_CURRENT_SOURCE_DIR}/A1/src/src/FltMExt.c)
    set(fltmext_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/A1/src/src)
endif()

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${fltmext_files}
)

if(NOT DEFINED FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS)
    message(FATAL_ERROR "FLTM same-Fault reset-loop HW test definition must be provided by vp_platform.cmake")
endif()

target_compile_definitions(${MODULE_NAME}
    PUBLIC
    ${FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS}
)
message(STATUS "Applying FLTM same-Fault reset-loop HW test definition to target ${MODULE_NAME}")

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${fltmext_header_paths}

)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    GenBsw
    GenMcal
    FltM
    RstM

)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  1/23/2024  | NCHELLAP |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
