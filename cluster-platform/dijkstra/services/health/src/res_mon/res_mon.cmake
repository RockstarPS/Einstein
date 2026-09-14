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
    ${CMAKE_CURRENT_SOURCE_DIR}/debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_comm_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_ddr_mx8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_dlt_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_extract_package.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_package.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_procfs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/res_mon_qcom.c
)

# Add directories
target_include_directories(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/dlt/include/dlt
)

# Add system libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
    mq
    slog2
    dlt_s
    login
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    dlt_wrapper
    vmf_client
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 05/14/2019  | DRAJ5    |  N/A      | dlt_s added as dependancy library 
#-------------------------------------------------------------------------------------------------------------------
# 05/14/2019  | SSATHYAP |  N/A      | Removed dependency on prebuilt library 
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
