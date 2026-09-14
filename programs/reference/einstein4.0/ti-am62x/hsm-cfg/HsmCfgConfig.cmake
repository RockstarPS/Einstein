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

add_library(${MODULE_NAME} ${MODULE_STATIC}
    ${CMAKE_CURRENT_SOURCE_DIR}/vHsmFWCfg.c
)

target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    HsmCare
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |     User    |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28/08/2024 |    KJOHN    |  PE4TI29141-3287 |  HSM Build Base
#-------------------------------------------------------------------------------------------------------------------