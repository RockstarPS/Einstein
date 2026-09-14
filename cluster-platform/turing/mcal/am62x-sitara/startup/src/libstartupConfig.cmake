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
cmake_minimum_required (VERSION 3.14)

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_vectors_nortos_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_handlers_nortos_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_handlers_nortos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_exception_handlers_nortos_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_exception_handlers_nortos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_vim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/boot_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/boot_armv7r.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/MpuP_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/MpuP_armv7r.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/PmuP_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/PmuP_armv7r.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/CpuId_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/CpuId_armv7r.c  
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/CacheP_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/CacheP_armv7r.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/UtilsP_armv7r_asm.S
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}

)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    GenMcal
    PlatformStubs
)

# Add target specific definitions
target_compile_definitions(${MODULE_NAME}
    PRIVATE
    -DSOC_AM62PX
    -DOS_NORTOS
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Nov-2023  | NCHELLAP   |  PE4TI29141-713  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------

