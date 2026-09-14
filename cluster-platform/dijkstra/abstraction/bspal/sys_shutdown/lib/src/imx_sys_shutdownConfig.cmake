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

# Create Library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/imx8/imx_sys_shutdown.c
)

# Add dependency libraries
if(${BUILD_OS} STREQUAL QNX710)
target_include_directories(${MODULE_NAME} 
	PRIVATE
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/imx8/qnx71-bsp/src/hardware/support/sc-imx8/public/sys
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/imx8/qnx71-bsp/src/lib/hw_vendor/nxp/imx8/sci/public
)
elseif(${BUILD_OS} STREQUAL QNX700)
target_include_directories(${MODULE_NAME} 
	PRIVATE
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/imx8/qnx7-bsp/src/hardware/support/sc-imx8/public/sys
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/imx8/qnx7-bsp/src/lib/hw_vendor/nxp/imx8/sci/public
)
endif()
# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2/7/2020    |  DRAJ5   |  NA   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
