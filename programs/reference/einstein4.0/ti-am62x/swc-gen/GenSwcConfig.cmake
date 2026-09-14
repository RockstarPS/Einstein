#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2020] Visteon Corporation
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
if(DISPLAY_VAR STREQUAL VIP_CONTROLLED_DISPLAY)
    set(ecupowerm_files             ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/VIP_Early_HMI/src/EcuPowerM_Cfg.c)
    set(ecupowerm_header_paths      ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/VIP_Early_HMI/include)
    set(ecuappm_files               ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/VIP_Early_HMI/src/EcuAppM_Cfg.c)
    set(ecuappm_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/VIP_Early_HMI/include)
    set(ecubatterym_files           ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/src/EcuBatteryM_Cfg.c)
    set(ecubatterym_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/include)
elseif(DISPLAY_VAR STREQUAL GIP_CONTROLLED_DISPLAY)
    set(ecupowerm_files             ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/src/EcuPowerM_Cfg.c)
    set(ecupowerm_header_paths      ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/include)
    set(ecuappm_files               ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/src/EcuAppM_Cfg.c)
    set(ecuappm_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/include)
    set(ecubatterym_files           ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/src/EcuBatteryM_Cfg.c)
    set(ecubatterym_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/GIP_HMI/include)
endif()   
if(PMIC_VAR STREQUAL PMIC_CONTROLLED_A1)
    set(pmiccdd_files               ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A1/PmicCdd_Cfg.c)
    set(pmiccdd_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A1)
elseif(PMIC_VAR STREQUAL PMIC_CONTROLLED_A0)
    set(pmiccdd_files               ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A0/PmicCdd_Cfg.c)
    set(pmiccdd_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A0)
else()
    message(STATUS "PMICCDD is set to A1!")
    set(pmiccdd_files               ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A1/PmicCdd_Cfg.c)
    set(pmiccdd_header_paths        ${CMAKE_CURRENT_SOURCE_DIR}/gen/PmicCdd/A1)
endif()

if(DEFINED RTCCDD_ENABLE)
    set(rtccddmgr_files      ${CMAKE_CURRENT_SOURCE_DIR}/gen/RtcMgrCdd_Cfg.c)
    set(rtccdddrv_files      ${CMAKE_CURRENT_SOURCE_DIR}/gen/RtcDrvCdd_Cfg.c)
     list(APPEND RTCCDD_DEPENDENCIES
        RtcCdd
    )
endif()

add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${ecupowerm_files}
    ${ecuappm_files}
    ${ecubatterym_files}
    ${pmiccdd_files}
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/IoExp_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/CDD_BswFit_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/CDD_McuFit_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/gen/CDD_Backlight_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/gen/DisplayCdd_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/gen/EcuWakeupM_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/gen/CDD_FitManager_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-callouts/EcuPowerM_Callouts.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Mgrdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Memdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Tracediagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Commdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Cybersecdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Ethernetdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Ioctrlrd_pwm_diagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Ioctrlrd_dio_diagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Ioctrlrd_analog_diagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Iocalibdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Displaycontroldiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Oscdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg/Resetsleepdiagcdd_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/LedDrv_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/TmExt_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Ecc_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Pok_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Dcc_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Ppu_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_FlsIntegrity_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Soc_Periodic_ReadBack_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/SafeNvM_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsCtrl.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsCtrlNwControllerApp.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsGtw.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsMdl.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsCtrl_cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdlsafe/ComAbsMdlSafe.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsMdl_RxCfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdlsafe/ComAbsMdlSafe_RxCfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdlsafe/ComAbsMdlSafe_TxCfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsMdl_TxCfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl/ComAbsNm.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/RstM_Cfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/gen/FltM_Cfg.c
)

target_compile_definitions(${MODULE_NAME}
    PUBLIC
    ${FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS}
)
message(STATUS "Applying FLTM same-Fault reset-loop HW test definition to target ${MODULE_NAME}")

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gen
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/gen
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-gen/lib_include
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/MeetCfg
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/platform-callouts
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdl
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/comabsmdlsafe
    ${ecupowerm_header_paths}
    ${ecuappm_header_paths}
    ${ecubatterym_header_paths}
    ${pmiccdd_header_paths}
)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    PlatformStubs
    GenBsw
    GenMcal
    EcuBatteryM
    EcuWakeupM
    meetcdd
    SafeNvM
    FltMExt
    EcuAppM
    EcuAppMCallOuts
    DmnMgr
    CfgDmnMgr
    Pmic-Tps65224
    backlight
    Pwm
    Adc
    FltM
    LedDrv
    RstM
    EcuPowerM
    Display
    TmExt
    McuSdk
    ${RTCCDD_DEPENDENCIES}
    CDDFitManager
	CDDBswFit
	CDDMcuFit    
    Dlt
    Dem
    ComMExt

)
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User     |   Task              |   Description
#-------------------------------------------------------------------------------------------------------------------
#  1/31/2024  | NCHELLAP   |  PE4TI29141-1205    | Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  7/28/2025  | abasavar   |  PE4TI29141-9512    | Updated CMake to have a proper splict for vip-hmi and gip-hmi
#-------------------------------------------------------------------------------------------------------------------
