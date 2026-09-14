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

set(VBUILD_SKIP_TARGET_CHECKS True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Install paths configurations
set(CMAKE_INSTALL_PREFIX        ${CMAKE_BINARY_DIR}/install)
set(CMAKE_INSTALL_BINDIR        usr/bin)
set(CMAKE_INSTALL_LIBDIR        usr/lib)
set(CMAKE_INSTALL_INCLUDEDIR    usr/include)

include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

#-------------------------------------------------------------------------------

FetchContent_Declare(imx8_dio
    GIT_REPOSITORY "https://bsp-os.git.visteon.com/platform/bsp-os/dijkstra/bsp/imx8/dio.git"
    GIT_TAG "rel-20240422-1.1.9"
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(imx8_dio)
if(NOT imx8_dio_POPULATED)
    FetchContent_Populate(imx8_dio)
endif()

#-------------------------------------------------------------------------------

FetchContent_Declare(dk_logger_repo
    GIT_REPOSITORY "https://bsp-os.git.visteon.com/platform/bsp-os/dijkstra/libraries/logger.git"
    GIT_TAG "rel-20240618-0.8.7"
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(dk_logger_repo)
if(NOT dk_logger_repo_POPULATED)
    FetchContent_Populate(dk_logger_repo)
endif()

#-------------------------------------------------------------------------------

FetchContent_Declare(clang_format_proj
    GIT_REPOSITORY "https://bsp-os.git.visteon.com/platform/bsp-os/dijkstra/tools/clang-tools/clangd-example-proj.git"
    GIT_TAG "clang-format-proj"
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(clang_format_proj)
if(NOT clang_format_proj_POPULATED)
    FetchContent_Populate(clang_format_proj)
    file(COPY ${clang_format_proj_SOURCE_DIR}/.clang-format DESTINATION ${CMAKE_SOURCE_DIR})
    file(COPY ${clang_format_proj_SOURCE_DIR}/.vscode DESTINATION ${CMAKE_SOURCE_DIR})
endif()

#-------------------------------------------------------------------------------

FetchContent_Declare(clang_tidy_proj
    GIT_REPOSITORY "https://bsp-os.git.visteon.com/platform/bsp-os/dijkstra/tools/clang-tools/clangd-example-proj.git"
    GIT_TAG "feature/clang-example-proj"
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(clang_tidy_proj)
if(NOT clang_tidy_proj_POPULATED)
    FetchContent_Populate(clang_tidy_proj)
    file(COPY ${clang_tidy_proj_SOURCE_DIR}/.clang-tidy DESTINATION ${CMAKE_SOURCE_DIR})
endif()

#-------------------------------------------------------------------------------

# Options configuration
option(DK_SLOG2_ENABLED "Set to ON/OFF to enable/disable dk_logger slog2 Integration" ON)
set(DK_BSPAL_I2C_FT_TESTS ON CACHE BOOL "Set to OFF to disable tests" FORCE)

# Set paths to search for *Config.cmake files
add_search_paths(
    INCLUDE
        ${CMAKE_SOURCE_DIR}/dio
        ${imx8_dio_SOURCE_DIR}
        ${dk_logger_repo_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/i2c
)

# Add binary scripts
binary_scripts(
    ${CMAKE_SOURCE_DIR}/dio/build_dio_bspal.cmake
    ${CMAKE_SOURCE_DIR}/i2c/build_dk_bspal_i2c.cmake
)

add_custom_target(clang_tools_target
    COMMAND bash ${CMAKE_SOURCE_DIR}/clang-config/get-compile-commands.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_dependencies(bspal_dio clang_tools_target)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
