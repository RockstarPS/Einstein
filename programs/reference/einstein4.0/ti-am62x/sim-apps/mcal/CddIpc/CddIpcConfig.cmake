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


# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Cdd_Ipc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Cdd_IpcIrq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src/ipc_mp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src/ipc_utils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src/ipc_mailbox.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src/ipc_virtio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src/ipc_api.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/soc/V1/ipc_soc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/mailbox_hw/V0/priv/hw_mailbox.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/src
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/soc
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/soc/V1
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/mailbox_hw/V0
    ${CMAKE_CURRENT_SOURCE_DIR}/ipc_baremetal_hw/mailbox_hw/V0/V0_1
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    CddIpc
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Aug-2024  | NCHELLAP   |  PE4TI29141-4365  |  MCAL v10.0 Update
#-------------------------------------------------------------------------------------------------------------------
