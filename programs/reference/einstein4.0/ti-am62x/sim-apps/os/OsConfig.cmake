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

set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/x86/OsSim.c
								 ${CMAKE_CURRENT_SOURCE_DIR}/x86/OsSimulationInclude.c
								 ${CMAKE_CURRENT_SOURCE_DIR}/x86/WinEventHandler.c
								 ${CMAKE_CURRENT_SOURCE_DIR}/x86/WinTimer.c
								 ${CMAKE_CURRENT_SOURCE_DIR}/x86/WinAbstraction.c
								 ${CMAKE_CURRENT_SOURCE_DIR}/x86/OsSimTasks.c
)
set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/x86)

set (MOS_PATH ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/mos/src)

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${MOS_PATH}/src/OsAlarm.c
    ${MOS_PATH}/src/OsApi.c
    ${MOS_PATH}/src/OsApplication.c
    ${MOS_PATH}/src/OsCore.c
    ${MOS_PATH}/src/OsCounter.c
    ${MOS_PATH}/src/OsError.c
    ${MOS_PATH}/src/OsEvent.c
    ${MOS_PATH}/src/OsMain.c
    ${MOS_PATH}/src/OsMemProtection.c
    ${MOS_PATH}/src/OsMessage.c
    ${MOS_PATH}/src/OsMetrics.c
    ${MOS_PATH}/src/OsSched.c
	${MOS_PATH}/src/OsRes.c
    ${MOS_PATH}/src/OsScheduleTable.c
    ${MOS_PATH}/src/OsStart.c
    ${MOS_PATH}/src/OsTask.c
    ${MOS_PATH}/src/OsTime.c
    ${MOS_PATH}/src/OsTrap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/x86/OsHalCpu.c
    ${processor_files}
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${MOS_PATH}/includes
    ${processor_header_paths}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    # Os
	#Main
    #PRIVATE
    #PlatformStubs
    #GenMcal
    #AssertLib
	#Startup
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
