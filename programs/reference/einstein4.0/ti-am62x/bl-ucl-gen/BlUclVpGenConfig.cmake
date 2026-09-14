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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vp/UclInstCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg/vp/UclCfg.c
   
	)

# Add target include directories
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vp
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg/vp
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/VIP
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Abstraction/Debug/Null
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Abstraction/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Abstraction/Os/ASR/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/InterfaceLayer/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Abstraction/Phy/MailboxASR/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Adapters/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/DataLayer/UclDL/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/DataLayer/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/InterfaceLayer/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/InterfaceLayer/UclILRouter/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/InterfaceLayer/UclILSched/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/InterfaceLayer/UclILStream/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/System/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/System/UclSysDL/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/System/UclSys/
    ${CMAKE_SOURCE_DIR}/bl-build/stubs/
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    UclMailboxASRPhy  
    UclSysDL
    UclDL 
    UclCommon
    UclAsrDebug
    UclAsrOs  
    
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
