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
#----------------------------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.14)

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
	${CMAKE_CURRENT_SOURCE_DIR}/cfg/DmnMgr_Cfg.c
)

# Add target include directories
target_include_directories(${MODULE_NAME}
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/cfg	
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE	
	Common
	GenBsw
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  5/29/2020  | DMURUGE@ |           | Created initial file
#  04/08/2021 | CBHASKAR |  1299140  | Moved cfg files to programs group
#  04/03/2023 | PSURESH3 | JLR3C29298-18568 | Domain Manager Integration
#  08/06/2023 | SGOVIND9 | JLR3C29298-25445 | Pre-Build Integration
#-------------------------------------------------------------------------------------------------------------------
