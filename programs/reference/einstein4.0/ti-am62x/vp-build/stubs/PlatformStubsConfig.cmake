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

#Add files depending on the Core used whether Ethernet or not
if(DEFINED AUTOSAR_ETH_ENABLE)
    set(ethernet_files
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/src/app_utils_eth.c
    )
endif()

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux/CddIpcAppRProcLinux.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux/IpcTrace.c
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/EccTest.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/BswM/src/BswM_ComMStub.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/src/CanIf.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/src/CanIf_Cbk.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Rte/src/Rte_Stubs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Os/src/Os_Stubs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/McuApp_Startup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/DioApp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/NvM_Test.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/src/app_utils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/EepromTest.c
    ${CMAKE_CURRENT_SOURCE_DIR}/DssTestApp/dss_display_test.c
    ${CMAKE_CURRENT_SOURCE_DIR}/DssTestApp/dss_display_pattern.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanStub/src/CanStub.c
    ${CMAKE_CURRENT_SOURCE_DIR}/LinStub/src/LinStub.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/systst/src/SysTst.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Chimes_Stub/Chimes_Stub.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Chimes_Stub/audio_sample.c
    ${ethernet_files}
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/AsrGnrl/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/BswM/inc
    # ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanIf/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Dem/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/Rte/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/MemMap/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/CddIpcRProcLinux
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/CanStub/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/LinStub/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/EcuAppMStub
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
    ${CMAKE_CURRENT_SOURCE_DIR}/Chimes_Stub
    ${CMAKE_CURRENT_SOURCE_DIR}/Bsw_Stubs/systst/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../cluster-platform/dijkstra/tools/kpi/boot-kpi/ti_am62x/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../img-build/boot_kpi
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    Can
    Lin
    GenMcal
    Dio
    GenBsw
    GenSwc
    Pmic-Tps65224
    I2cDrv
    SciDrv
    UclVpGen
    HsmIpcR5
    vHsmCryptoManagerR5
    LedDrv
    Pwm
	IcuDrv
    FltM
    RstM
    WdgM
    vhsm-cryptodriver
    CorTst
    RamTst
    TmExt
    FltMExt
    vHsmShutdownR5
    EcuMExt
    NvMExt
    Det
    vDLT_HSM
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Nov-2023  | NCHELLAP   |  PE4TI29141-713  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
