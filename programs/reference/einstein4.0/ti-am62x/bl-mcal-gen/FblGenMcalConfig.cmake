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
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Can_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Can_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Cdd_IpcCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Gpt_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Gpt_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Dio_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Dio_Lcfg.c
	${CMAKE_CURRENT_SOURCE_DIR}/PortDrvCfg/Port_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/output/src/Fls_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/output/src/Fls_PBcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/output/src/Eth_PBcfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/output/src/EthTrcv_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Mcu_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Mcu_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Spi_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Spi_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Spi_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Wdg_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Wdg_Lcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/output/src/Wdg_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_board_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_board_open_close.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_dpl_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_drivers_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_drivers_open_close.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_pinmux_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl/ti_power_clock_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/I2cCfg/I2c_Cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/I2cCfg/I2c_Irq.c
    #${CMAKE_CURRENT_SOURCE_DIR}/DssCfg/Dss_IrqCfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/SciDrvCfg/SciDrv_Cfg.c
    #${CMAKE_CURRENT_SOURCE_DIR}/LinCfg/Lin_Cfg.c
)

target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/output/include
    ${CMAKE_CURRENT_SOURCE_DIR}/SysconfigGeneratedDpl
    ${CMAKE_CURRENT_SOURCE_DIR}/I2cCfg
    ${CMAKE_CURRENT_SOURCE_DIR}/DssCfg
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs
	${CMAKE_CURRENT_SOURCE_DIR}/PortDrvCfg/
    #${CMAKE_CURRENT_SOURCE_DIR}/LinCfg
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    FblGenBsw
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  08-Sep-2023  | NCHELLAP   |  PE4TI29141-267  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
