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

# Set system architecture
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
string(TOLOWER "${BUILD_OS}_${CMAKE_SYSTEM_PROCESSOR}_VS" system_arch)
else()
string(TOLOWER "${BUILD_OS}_${CMAKE_SYSTEM_PROCESSOR}" system_arch)
endif()

# Create Dummy Executable to generate all the OSAL libraries
add_executable(${BINARY_NAME} dummy_executable.c)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    INTERFACE
    vmf_client
    vmf_client.a
    vmf_trace
    vmf_trace.a
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
