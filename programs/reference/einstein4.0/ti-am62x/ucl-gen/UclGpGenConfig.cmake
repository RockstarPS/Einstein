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
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_RxMsgDb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_TxMsgDb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_VmfAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_VmfAdapter.cpp
)

# Add target include directories
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/System/UclSysDL
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Abstraction/Debug/Console
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Adapters/VMF
)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    UclCommon
    UclDL
    UclAdapterCommon
    UclILCommon
    UclSys
    UclALDebugDLT
    GenRuntime
)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    UclCommon
    UclDL
    UclAdapterCommon
    UclILCommon
    UclSys
    UclQnxDebug
    GenRuntime
)
endif()
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 11/06/2020  | NKHAN2   |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
