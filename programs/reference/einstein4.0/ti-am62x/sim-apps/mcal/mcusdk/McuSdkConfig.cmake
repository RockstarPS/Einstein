#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2024] Visteon Corporation
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
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_pm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_rm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_rm_irq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_procboot.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_firewall.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/sciclient_lpm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/csl_sec_proxy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/soc/am62px/sciclient_irq_rm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/soc/am62px/sciclient_fmwSecureProxyMap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/soc/am62px/sciclient_soc_priv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/common/AddrTranslateP.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/common/DebugP_log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/common/QueueP_nortos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/nortos/dpl/r5/HwiP_armv7r_asm.S
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/pinmux/am62px/pinmux.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/soc/am62px/soc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/common/dss_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/common/dss_evtMgr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/dctrl/dss_dctrlApi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/dctrl/dss_dctrlGraph.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/disp/dss_dispApi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/disp/dss_dispPriv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/soc/am62px/dss_soc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/soc/am62px/dss_soc_graph.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/hw_include/V3/csl_dssCommon.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/hw_include/V3/csl_dssVideoPipe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/hw_include/V3/csl_dssVideoPort.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/dss/v0/hw_include/V3/csl_dssOverlay.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/fvid2/v0/fvid2_utils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/fvid2/v0/fvid2_drvMgr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/fvid2/v0/fvid2_graph.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1/mcasp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1/mcasp_dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1/soc/am62px/mcasp_soc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/soc/am62px/sdl_esm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/v0/sdl_ip_esm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/soc/am62px/sdl_esm_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/sdl_esm_priv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dpl/sdl_dpl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/rti/v0/sdl_rti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/rti/v0/sdl_ip_rti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/rti/v0/soc/am62px/sdl_soc_rti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/soc/am62px/sdl_ecc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/V0/sdl_ip_ecc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/r5/v0/sdl_ecc_r5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/r5/v0/sdl_r5_utils.S
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/sdl_ecc_utils.S
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dcc/v0/sdl_dcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dcc/v0/soc/am62px/sdl_soc_dcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/soc/am62px/sdl_soc_pok.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/sdl_ip_pok_defs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/sdl_ip_pok.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/sdl_pok.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_ch.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_flow.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_ring_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_ring_lcdma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_rm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/udma_utils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/csl_bcdma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/csl_intaggr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/csl_lcdma_ringacc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/csl_pktdma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/soc/am62px/udma_rmcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/soc/am62px/udma_soc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/soc/udma_rmcfg_common.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1/mcasp_drv_configs
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/mcasp/v1/soc/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/hw_include
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/hw_include/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/pinmux/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/dpl
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/sciclient/include/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/soc/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/v0
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/esm/soc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dpl
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/soc/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/v0
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/ecc/soc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dcc/v0
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dcc/v0/soc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/dcc/v0/soc/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/include
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/r5/v0
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/soc/am62px
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1/soc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl/pok/v1
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/include
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/soc
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/soc/am62px
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/bcdma
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/lcdma_ringacc
	${CMAKE_CURRENT_SOURCE_DIR}/drivers/udma/v0/hw_include/pktdma
)

# Add target specific definitions
target_compile_definitions(${MODULE_NAME}
    PRIVATE
    -DSOC_AM62PX
    -DMCU_R5
    -DR5F_CORE
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Aug-2024  | NCHELLAP   |  PE4TI29141-4365  |  MCAL v10.0 Update
#-------------------------------------------------------------------------------------------------------------------
