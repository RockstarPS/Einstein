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

# Set library information variables
set(DK_RUNTIME_VERSION_MAJOR 0)
set(DK_RUNTIME_VERSION_MINOR 11)
set(DK_RUNTIME_VERSION_PATCH_LEVEL 0)

set(DK_RUNTIME_VERSION ${DK_RUNTIME_VERSION_MAJOR}.${DK_RUNTIME_VERSION_MINOR}.${DK_RUNTIME_VERSION_PATCH_LEVEL})
if(DK_UPDATE_BUILDINFO)
set(DK_RUNTIME_BUILD_USER $ENV{USERNAME})
string(TIMESTAMP DK_RUNTIME_BUILD_TIMESTAMP "%Y-%m-%d %H:%M")
cmake_host_system_information(RESULT DK_RUNTIME_BUILD_HOSTNAME QUERY HOSTNAME)
else()
set(DK_RUNTIME_BUILD_USER "NA")
string(TIMESTAMP DK_RUNTIME_BUILD_TIMESTAMP "0000-00-00 00:00")
set(DK_RUNTIME_BUILD_HOSTNAME "NA")
endif()
# relevant configuration options are DK_VMF_ENABLED, DK_CDC_WATCHDOG_ENABLED and DK_HAM_WATCHDOG_ENABLED

# Generate configuration file using variables
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dk_runtime_version.h.in ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/runtime/dk_runtime_version.h @ONLY)

# Files to be linked into the shared library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_application.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_component.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_container.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_parserif.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_ipcmsgif.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_wdgif.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_thread_pool.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_msgcmn.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_deserializer.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_serializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/ini/ConvertUTF.c 
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/ini
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes
    ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/runtime
)

#Windows Specific Settings
if(CMAKE_SYSTEM_NAME MATCHES Windows)
target_add_dependencies(${MODULE_NAME}
   pthreads4w.a
)

target_link_options(${MODULE_NAME}
	PUBLIC
	/SAFESEH:NO
)
endif()


# Add dependency libraries
if(DK_HAM_WATCHDOG_ENABLED OR DK_SD_WATCHDOG_ENABLED )
    target_add_dependencies(${MODULE_NAME}
        PRIVATE
        dk_logger
        PUBLIC
        osal
        vmf_client
        dk_wdg_client
    )
else()
    target_add_dependencies(${MODULE_NAME}
        PRIVATE
        dk_logger
        PUBLIC
        osal
        vmf_client
    )
endif()

# Set module version
set_target_properties(${MODULE_NAME}
    PROPERTIES 
    VERSION ${DK_RUNTIME_VERSION}
    SOVERSION ${DK_RUNTIME_VERSION_MAJOR}
)

# Set API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_component.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_container.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_parserif.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_ipcmsgif.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_wdgif.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_fifoserdes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_msgserdes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_msgcmn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_thread_decl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/dk_runtime_thread_pool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_deserializer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_serializer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_byte_order.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/serdes/dk_runtime_primitive_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/ini/ConvertUTF.h
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/ini/SimpleIni.h
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/runtime
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020  | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
