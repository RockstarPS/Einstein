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
        ${CMAKE_CURRENT_SOURCE_DIR}/src/resmgr/CSigUnit_RM.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ti-am62p/CSigUnit_HwIf.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ti-am62p/CSigUnit_HwInit.c
)

# Add directories
target_include_directories(${BINARY_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resmgr
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ti-am62p
)

# Add system libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PUBLIC
    resmgr_sigunit_devctl
    dk_logger
)

# Add test binaries
#binary_scripts(
#    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dio_test.cmake
#)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 06/01/2021  | KGEETHA |       | Created initial file
#-------------------------------------------------------------------------------------------------------------------
