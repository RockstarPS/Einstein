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
cmake_minimum_required (VERSION 3.14)

# Files to be linked into the shared library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/wdg_client/wdg_client.cpp
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/wdg_client
)

# Set API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/wdg_client/wdg_client.h
)

target_add_dependencies(${MODULE_NAME}
    PUBLIC
    dk_logger
)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
# Add system libraries
target_link_libraries(${MODULE_NAME}
    PUBLIC
    systemd
)
else()
# Add system libraries
target_link_libraries(${MODULE_NAME}
    PUBLIC
    ham  
)
endif()

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/wdg_client
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020  | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
