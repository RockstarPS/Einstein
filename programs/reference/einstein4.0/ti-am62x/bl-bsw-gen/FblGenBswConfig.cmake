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
# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    #${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Rte.c
    #${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Rte_SystemApplication_OsCore0.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/intvect.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/Os_Alarm_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os/intvect_asm.S
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
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvM_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/Ea_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/MemIf_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/EepDrv_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/MemAbstract.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvMExt_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/ecum/EcuM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgM/WdgM_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgIf/WdgIf_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/amd/Apm_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Adc_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_DIn_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_DOut_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/private/IoHwAb_Filter_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthIf_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthSM_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/TcpIp_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/SoAd_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/SoAd_PBcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/DoIP_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/ComM_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Eth_DrvInit.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/EthTest.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port/arch/sys_arch.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanIf_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanTp_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/PduR_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanSM_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/CanNm_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Com_Lcfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/DcmExt.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/Dcm_Cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag/Dem_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinIf_Par_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinNm_Par_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinSM_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinSm_PBCfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Lin_Tp_Par_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/LinTrcv_Par_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/IpduM_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Nm_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Xcp_Lcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/Xcp_Appl.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/csm/Csm_cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/cryif/CryIf_Cfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/PmicCdd/PmicCdd_Cfg.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData
    ${CMAKE_CURRENT_SOURCE_DIR}/Project/Appl/GenData/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/os
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/crc
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/ecum
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/amd
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgM
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/wdgm/WdgIf
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/e2exf
    ${CMAKE_CURRENT_SOURCE_DIR}/private
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/com
    ${CMAKE_CURRENT_SOURCE_DIR}/bsw/diag
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port
    #${CMAKE_CURRENT_SOURCE_DIR}/bsw/com/lwip_port/arch
	${CMAKE_CURRENT_SOURCE_DIR}/stubs
	#${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvMConfiguratorV2.5/res/Srec_Gen/mem/Fee/src
	#${CMAKE_CURRENT_SOURCE_DIR}/bsw/NvM/NvMConfiguratorV2.5/res/Srec_Gen/stubs
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/PmicCdd
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/csm
	${CMAKE_CURRENT_SOURCE_DIR}/bsw/cryif

)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    FblPlatformStubs
    HwInclude
	#Board
	BlUclVpGen
    Os
    Can
    CanIf
    CanSM
    CanTp
    #CanNm
    PduR
    ComM
	Com
    Wdg
    Mcu
    Spi
    CddIpc
    Gpt
	#Fls
	#Fee
    McuSdk
    MemLib
	#CmpLib
    AssertLib
    NvM
    MemIf
    Ea
    Crc
    Dem
    Dcm
	Csm
	CryIf
	vhsm-cryptodriver
	HsmIpcR5
	WdgM
	WdgIf
    I2cDrv
    EepDrv
	PortDrv
    EcuM
    #UpdateCdd
    blupdateclient
    libstartup
    PRIVATE
    FblGenMcal
	Pmic-Tps65224
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#               nchellap                           
#-------------------------------------------------------------------------------------------------------------------
