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

# Use library CMakeLists.txt
if(NOT TARGET dlt)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR}/dlt)
endif()

add_library(${MODULE_NAME} INTERFACE)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/dlt
    ${CMAKE_BINARY_DIR}/dlt/include/dlt
)

if(MODULE_STATIC_SHARED STREQUAL "STATIC_LIBRARY")
    # Add system libraries
    target_link_libraries(${BINARY_NAME}
        PRIVATE
        dlt_s
    )
else()
    # Add system libraries
    target_link_libraries(${BINARY_NAME}
        PRIVATE
        dlt
    )
endif()

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  07/15/2020  | DRAJ5    |    N/A    | INTERFACE added
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020  | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
