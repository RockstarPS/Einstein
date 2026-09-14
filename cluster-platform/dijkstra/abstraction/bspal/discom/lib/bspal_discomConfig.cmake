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

# Create Library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CDiscom_DK_BSPAL.c
)

# Add dependency libraries
target_include_directories(${MODULE_NAME} 
                           PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/public
                           ${BUILD_ROOT_DIR}/dk.lib.logger/src/logger/
                           ${CMAKE_BINARY_DIR}/install/usr/include
)

# Add system libraries
target_link_libraries(${MODULE_NAME}
    PUBLIC
    slog2
    screen
    img
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
      PUBLIC
      dk_logger
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 09/02/2022  | SKOPPISE |  1567226  | Created initial file
#-------------------------------------------------------------------------------------------------------------------
