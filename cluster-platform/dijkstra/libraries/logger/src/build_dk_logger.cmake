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

# Create Dummy Executable to generate all the OSAL libraries
add_executable(${BINARY_NAME} dummy_executable.c)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    INTERFACE
    dk_logger
    dk_logger.a
    )

if(CMAKE_SYSTEM_NAME MATCHES QNX)
    target_add_dependencies(${BINARY_NAME}
    INTERFACE
    dk_logger_gpp
    dk_logger_gpp.a
    )
endif(CMAKE_SYSTEM_NAME MATCHES QNX)

# Add test binaries
if(DK_LOGGER_TESTS)
    binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/CONSOLE/dk_logger_console_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/SLOG2/dk_logger_slog2_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/MULTI_THREAD/dk_logger_thread_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/FILE_S/dk_logger_file_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/DLT/dk_logger_dlt_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_c/MULTIPLE_CONTEXT/dk_logger_multicontext_c.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/CONSOLE/dk_logger_console_cpp.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/SLOG2/dk_logger_slog2_cpp.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/MULTI_THREAD/dk_logger_thread_cpp.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/FILE_S/dk_logger_file_cpp.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/DLT/dk_logger_dlt_cpp.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/dk_Logger_cxx/MULTIPLE_CONTEXT/dk_logger_multiplecontext_cpp.cmake
)
endif()
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 07/14/2020  |   DRAJ5  |  962331   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
