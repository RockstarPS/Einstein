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
    ${DK_WDG_PROXY_PATH}/main.c
    ${DK_WDG_PROXY_PATH}/wdg_proxy_linux.c
    ${DK_WDG_PROXY_PATH}/wdg_proxy_comm_if.c
)

# Add directories
target_include_directories(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}	
    ${DK_WDG_PROXY_PATH}
)

# Add system libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
    systemd
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    vmf_client
    dk_logger
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}/wdg_test_FT"
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 05/14/2019  | SSATHYAP |  N/A  	 | Removed dependency on prebuilt library 
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
