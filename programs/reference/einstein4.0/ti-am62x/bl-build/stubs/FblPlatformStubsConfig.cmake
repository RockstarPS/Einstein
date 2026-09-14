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
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux/CddIpcAppRProcLinux.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux/IpcTrace.c
    #${CMAKE_CURRENT_SOURCE_DIR}/main.c
    #${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/BswM/src/BswM_ComMStub.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/src/CanIf.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/src/CanIf_Cbk.c
    #${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Rte/src/Rte_Stubs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/McuApp_Startup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/DioApp.c
    #${CMAKE_CURRENT_SOURCE_DIR}/NvM_Test.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/src/app_utils.c
    #${CMAKE_CURRENT_SOURCE_DIR}/utils/src/app_utils_eth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/EepromTest.c
	${CMAKE_CURRENT_SOURCE_DIR}/BlUclGen_Stubs/src/BlUclGenStub.c
    #${CMAKE_CURRENT_SOURCE_DIR}/DssTestApp/dss_display_test.c
    #${CMAKE_CURRENT_SOURCE_DIR}/DssTestApp/dss_display_pattern.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanStub/src/CanStub.c
    #${CMAKE_CURRENT_SOURCE_DIR}/LinStub/src/LinStub.c
    #${CMAKE_CURRENT_SOURCE_DIR}/EcuAppMStub/SleepManager.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Det/src/Det.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/AsrGnrl/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/BswM/inc
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Dem/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Det/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Rte/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/MemMap/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanStub/inc
	${CMAKE_CURRENT_SOURCE_DIR}/BlUclGen_Stubs/inc
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/System/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/Common/
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/DataLayer/Common/
    ${CMAKE_CURRENT_SOURCE_DIR}/LinStub/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/EcuAppMStub
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    Can
    FblGenMcal
    Dio
    FblGenBsw
    GenSwc
    I2cDrv
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Nov-2023  | NCHELLAP   |  PE4TI29141-713  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
