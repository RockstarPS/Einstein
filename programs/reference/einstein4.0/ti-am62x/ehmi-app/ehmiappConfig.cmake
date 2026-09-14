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

set(CMAKE_GDT_CORE          ${CMAKE_CURRENT_SOURCE_DIR}/../ui-core/gdt)
set(CMAKE_ICEAPPLE_CORE     ${CMAKE_CURRENT_SOURCE_DIR}/../ui-core/iceapple)
set(CMAKE_EHMI_APPS         ${CMAKE_CURRENT_SOURCE_DIR}/../ehmi-app/ehmi.ui)

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_EHMI_APPS}/gdt-autogen/hmi_gfx_mgr02_clut_table.c
    ${CMAKE_EHMI_APPS}/gdt-autogen/hmi_gfx_mgr02_font.c
    ${CMAKE_EHMI_APPS}/gdt-autogen/hmi_gfx_mgr02_vgfont.c
    ${CMAKE_EHMI_APPS}/gdt-autogen/Default_Font.c
    ${CMAKE_EHMI_APPS}/src/hmi_gfx02_image_data.c
    ${CMAKE_EHMI_APPS}/src/hmi_specific.c
)


# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_EHMI_APPS}/gdt-autogen
    ${CMAKE_EHMI_APPS}/language-autogen
    ${CMAKE_EHMI_APPS}/cfg
    ${CMAKE_EHMI_APPS}/include

    ${CMAKE_GDT_CORE}/ui_core_gdt/ui.core.gdt/hmi.gfx.manager.02/src/
    ${CMAKE_GDT_CORE}/ui_core_gdt/ui.core.gdt/osal/turing/
    ${CMAKE_GDT_CORE}/ui_core_gdt/ui.core.gdt/osal/turing/gdtctrl

    ${CMAKE_ICEAPPLE_CORE}/ui.core.iceapple/animation.core.02/src/
    ${CMAKE_ICEAPPLE_CORE}/ui.core.iceapple/language.core.01/src/
    ${CMAKE_ICEAPPLE_CORE}/ui.core.iceapple/view.manager.02/src/
)

target_add_dependencies(${MODULE_NAME}
    PUBLIC
    PlatformStubs
    gdt
    iceapple
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  10/7/2024  | mchoudha |  -   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
