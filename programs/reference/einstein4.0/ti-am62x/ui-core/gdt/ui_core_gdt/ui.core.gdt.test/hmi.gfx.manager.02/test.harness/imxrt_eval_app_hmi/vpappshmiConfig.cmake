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
	${CMAKE_CURRENT_SOURCE_DIR}/src/HmiSpecific.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/hmi_gfx02_image_data.c	
	${CMAKE_CURRENT_SOURCE_DIR}/autogen/Default_Font.c
	${CMAKE_CURRENT_SOURCE_DIR}/autogen/hmi_gfx_mgr02_clut_table.c
	${CMAKE_CURRENT_SOURCE_DIR}/autogen/hmi_gfx_mgr02_font.c
	${CMAKE_CURRENT_SOURCE_DIR}/autogen/New_fonts_1.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/osal/turing/gdtcdd
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/ice_apple/ui.core.iceapple/view.manager.02/src
	${CMAKE_CURRENT_SOURCE_DIR}/cfg	
	${CMAKE_CURRENT_SOURCE_DIR}/cfg/iceapple	
	${CMAKE_CURRENT_SOURCE_DIR}/autogen
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/hmi.gfx.manager.02/src/
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/osal/turing/gdtcdd/
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/osal/turing/gdtctrl/
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/hmi.gfx.manager.02/amber_mem/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../programs/vw/my2022/fpkb8/bsw-gen/Appl/GenData/Components/	
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../programs/vw/my2022/fpkb8/bsw-gen/Appl/GenData
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../programs/vw/my2022/fpkb8/bsw-gen/bsw/os
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/turing/vautosar/sys/mos/src/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../programs/vw/my2022/fpkb8/vp-build/stubs/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/02_driver/basic_graphics/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/05_util/utgraphic/include
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/05_util/hw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/05_util/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/05_util/compat/basic_graphics/include	
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/drivers/traveo2/05_util/utwarp/include	
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cluster-platform/gui/gdt/ui.core.gdt/osal/turing/gdtcdd
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    PlatformStubs
    Dio
    EcuM
    EcuMExt
    GenBsw
    GenMcal
    IoHwAbExt
    NvM
    PpuDrv
    FlsTst
    RamTst
    HsmIpcCm7
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
