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

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/CodeGen/Mdl_SafetyAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CodeGen/Mdl_SafetyAdapter_RxCfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/CodeGen/Mdl_SafetyAdapter_TxCfg.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/CodeGen
	#${CMAKE_SOURCE_DIR}/programs/toyota/my2026/7xxd/rte
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    rte
    PUBLIC
	GenBsw
	PlatformStubs
)


#====================================================================================================================================
#**      CDSID         Date         Traceability              Description
#**==================================================================================================================================
#**     cbhaskar     28-oct-2020      1105994             initial file creation for Program specific cfgs
#**==================================================================================================================================
