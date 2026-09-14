#---------------------------------------------------------------------------------------------------------------------
#
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

# variable for lwip port path
set(LWIP_PORT_INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port"
    "${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port/arch"
    CACHE STRING "Path for LWIP port include directories"
)


#Add files depending on the Core used whether Ethernet or not
if(DEFINED AUTOSAR_ETH_ENABLE)
    set(ethernet_files
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthIf_Lcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthSM_Lcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/TcpIp_Lcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/SoAd_Lcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/SoAd_PBcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/DoIP_Lcfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Eth_DrvInit.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthTest.c
    )
endif()

if(CMAKE_SYSTEM_PROCESSOR STREQUAL x86)
set (OS_GEN_FILES       )
else()
set (OS_GEN_FILES               ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/intvect.c
                                ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/intvect_asm.S
    )   
endif()

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Rte.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Rte_OsApplication_NonTrusted.c
	${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Rte_OsApplication_Trusted.c
    ${OS_GEN_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_Alarm_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_Application_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_Core_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_CountersLcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_HooksCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_IsrLcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_MpuLcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_ResourceCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_Task_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_TrustedServiceCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_ScheduleTable_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/OsStacks_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/cryif/CryIf_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/csm/Csm_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/Ea_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/MemIf_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/EepDrv_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/MemAbstract.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvMExt_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/ecum/EcuM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgM/WdgM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgIf/WdgIf_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/amd/Apm_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Adc_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_DIn_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_DOut_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Pwm_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Filter_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/ComM_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port/arch/sys_arch.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanIf_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanTp_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanTrcv_Tja1040_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanTrcv_Tja1145ATK_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanTrcv_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/PduR_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanSM_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanNm_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Com_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Com_Callout.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/e2exf/E2EXf_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/ComXf_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/commext/ComMExt_Cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/DcmExt.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/Dcm_Cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/Dem_Cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/Dem_Ext.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinIf_Par_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinNm_Par_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinSM_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinSm_PBCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Lin_Tp_Par_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinTrcv_Par_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/IpduM_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Nm_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Xcp_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Xcp_Appl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/dlt/Dlt_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/dlt/Dlt_Comm_Com.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/dltext/DltExt_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/bswm/BswM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/det/Det_Cfg.c
    ${ethernet_files}
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/cryif
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/csm
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/crc
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/ecum
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/amd
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgM
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgIf
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/e2exf
    ${CMAKE_CURRENT_SOURCE_DIR}/private
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port/arch
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/dlt
   # ${CMAKE_CURRENT_SOURCE_DIR}/bsw/dltext
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/commext
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/bswm
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/det
)

# Conditionally add Ethernet-related dependencies
if(DEFINED AUTOSAR_ETH_ENABLE)
    list(APPEND ETH_DEPENDENCIES
        Eth
        EthTrcv
        EthIf
        EthSM
        TcpIp
        SoAd
        DoIP
    )
endif()

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    PlatformStubs
    HwInclude
    HwIncAsm
    Os
    Can
    CanIf
    CanSM
    CanTp
    CanTrcv
    CanNm
    PduR
    PortDrv
    ComM
    LinIf
    LinNm
    LinSM
    LinTp
    LinTrcv
    Com
    ${ETH_DEPENDENCIES}
      #IpduM
    Nm
    Xcp
    Wdg
    Mcu
    Spi
    CddIpc
    Gpt
    McuSdk
    MemLib
    CddIpc
    CmpLib
    AssertLib
    NvM
    MemIf
    Ea
    Crc
    Chcksumlib
    Dem
    Dcm
    Dlt
    DltExt
    ioexp_ads7138
    I2cDrv
    Lin
    EepDrv
    BswM
    EcuM
    EcuMExt
    WdgM
    WdgIf
    IoHwAb
    MathLib
    Amd
    EcuAppM
    EcuAppMCallOuts
    NvMExt
    DmnMgr
    libstartup
    ComXfgen
    E2EXfgen
    ComXf
    E2exf
    PRIVATE
    GenMcal
    SciDrv
    Pmic-Tps65224
    Csm
    CryIf
    vhsm-cryptodriver
    ComMExt
	updateclient
    WdgMExt
    Det
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#               nchellap
#-------------------------------------------------------------------------------------------------------------------
