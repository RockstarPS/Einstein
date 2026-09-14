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

# Create Binary
add_executable(${BINARY_NAME}     
  ${CMAKE_CURRENT_SOURCE_DIR}/src/boot_kpi_logger.c
)

# Add target include directories
target_include_directories(${BINARY_NAME}
  PUBLIC
  ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/img-build/boot_kpi
  ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/tools/kpi/boot-kpi/ti_am62x/include/
)

target_compile_definitions(${BINARY_NAME}
    PUBLIC
    BOOT_KPI_LOG_EN
)