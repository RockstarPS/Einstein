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
add_executable(${BINARY_NAME} dummy_executable.c)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
     PUBLIC
     bspal_sigunit
)

# Add test binaries
if(BSPAL_SIGUNIT_TESTS)
binary_scripts(
     ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/linux/ti_misr/misr_ti_test_linux.cmake
)
endif()
endif()

if(CMAKE_SYSTEM_NAME MATCHES QNX)
# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
     PUBLIC
     resmgr_sigunit_devctl
     bspal_sigunit
)

# Add test binaries
if(BSPAL_SIGUNIT_TESTS)
binary_scripts(
     ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/sigunit_test.cmake
     ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/qnx/ti_misr/misr_ti_test_qnx.cmake
)
endif()

endif( )
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 26JUN/2024  | VARVIND  |  TFDCX32348-29453  | Created initial file
# 21OCT2024   | PKRISH12 |  TFDCX32348-50216 | Sigunit BSPAL changes.
#-------------------------------------------------------------------------------------------------------------------
