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
cmake_minimum_required (VERSION 3.14...3.14)

set(HSMCARE_HSM   ${MCAL_FOLDER}/hsm)
set(HSMCARE_OSAL  ${MCAL_FOLDER}/osal)
set(HSMCARE_TISCI ${MCAL_FOLDER}/tisci)


# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/arch/irq-arm.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/arch/irq-arm-asm.S
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/common/osal_clock_user.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/common/secure_core.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/common/tisci_secure.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/common/tisci.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/common/trace.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ia_lib/dmsc_ia_config.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ia_lib/dmsc_ia.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/psilcfg/psilcfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/psilcfg/psilcfg_soc_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ra_lib/comm_memory_soc_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ra_lib/ring_acel_config_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ra_lib/ring_acel_soc_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ra_lib/comm_memory.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ra_lib/ring_accelerator.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/rat/rat.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/dmsc_tx_routing_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/sec_proxy_config_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/sec_proxy_soc_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/sec_proxy_minimal.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/secure_proxy_init.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/secure_proxy_routing_description.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy/secure_proxy_transfer.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/trace/trace-buffer.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/trace/trace.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/aes/aes_kdf.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/aes/aes.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/core/hs_security_init.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/common/udmap_soc_data.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/common/udmap_pkt_descr.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/common/udmap.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma/pktdma_ring_soc_data.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma/sec_dma_bootcfg.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma/sec_dma_soc_data.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma/pktdma_ring.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma/sec_pktdma.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/keystore/keystore.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/pka_firmware_utilites.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_sec_ctx_bootcfg.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_soc_data.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/eip29t2_firmware.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_aes_keyinv.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_crypto.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_pka.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_pkt_descr.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_rng.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul_sec_ctx.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul/sa2ul.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hsm_core/hsm.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/lib/hsm_data.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/core/common_funcs.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/core/socmem.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/firewall/cred.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/firewall/masters.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/firewall/cred_bootcfg.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/firewall/firewall_conf.c 
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/security/firewall/masters_bootcfg.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/utils/ioremap.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/utils/itoa.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/utils/map.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/utils/strncpy.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/common/osal_clock.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/common/osal_halt.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/common/osal_hwi.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/common/startup_nortos.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/src/clock.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/src/hwi.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/src/semaphore.c
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/src/task.c
     ${CMAKE_CURRENT_SOURCE_DIR}/Intr/src/Interrupt_handler.c
     ${CMAKE_CURRENT_SOURCE_DIR}/app/src/entry.S
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/ospi/ospi.c
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/flash/flash.c
     ${CMAKE_CURRENT_SOURCE_DIR}/FlsDrv/src/Fls.c
     ${CMAKE_CURRENT_SOURCE_DIR}/mpu/vHsmMPU.c
     ${CMAKE_CURRENT_SOURCE_DIR}/Intr/src/vHsmFaulthandling.S

)
target_include_directories(${MODULE_NAME}
    PUBLIC
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/arch
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/sec_proxy
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/drivers/uart
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/common
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/dma/pktdma
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/hs/sa2ul
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/common
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/common/lib
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/drivers
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/hs
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/hsm_core
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/lib
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/msg
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/osal
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/security
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/security/config/am62px
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/soc
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/tisci
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/tisci/security
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/tisci_provider
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/utils
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/include
     ${CMAKE_CURRENT_SOURCE_DIR}/osal/nortos/include
     ${CMAKE_CURRENT_SOURCE_DIR}/tisci/inc
     ${CMAKE_CURRENT_SOURCE_DIR}/tisci/inc/rm
     ${CMAKE_CURRENT_SOURCE_DIR}/tisci/inc/security
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/src/lib
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/tests/hs/security
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/tests/include
     ${CMAKE_CURRENT_SOURCE_DIR}/hsm/include/common/types
     ${CMAKE_CURRENT_SOURCE_DIR}/app/src
     ${CMAKE_CURRENT_SOURCE_DIR}/mpu
     ${CMAKE_CURRENT_SOURCE_DIR}/FlsDrv/public
    
)


# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    HsmCfg
)

# EOF
