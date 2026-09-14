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

# Set library information variables
set(DK_LOGGER_VERSION_MAJOR       0)
set(DK_LOGGER_VERSION_MINOR       8)
set(DK_LOGGER_VERSION_PATCH_LEVEL 0)

set(DK_LOGGER_VERSION ${DK_LOGGER_VERSION_MAJOR}.${DK_LOGGER_VERSION_MINOR}.${DK_LOGGER_VERSION_PATCH_LEVEL})

if(DK_UPDATE_BUILDINFO)
set(DK_LOGGER_BUILD_USER $ENV{USERNAME})
string(TIMESTAMP DK_LOGGER_BUILD_TIMESTAMP "%Y-%m-%d %H:%M")
cmake_host_system_information(RESULT DK_LOGGER_BUILD_HOSTNAME QUERY HOSTNAME)
else()
set(DK_LOGGER_BUILD_USER "NA")
string(TIMESTAMP DK_LOGGER_BUILD_TIMESTAMP "0000-00-00 00:00")
set(DK_LOGGER_BUILD_HOSTNAME "NA")
endif()

# Generate configuration file using variables
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dk_logger_version.h.in ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/logger/dk_logger_version.h @ONLY)

# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/dk_logger_impl.cpp
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/logger
    ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/logger
)

# Add dependency libraries
if(CMAKE_SYSTEM_NAME MATCHES Windows)
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    unistd_wrapper.a
)
endif()

# Add dependency libraries
if (DK_DLT_ENABLED)
	target_add_dependencies(${MODULE_NAME}
		PUBLIC
		dlt_wrapper
	)
	# Add system libraries
	target_link_libraries(${MODULE_NAME}
		PRIVATE
		dlt_s
	)
endif(DK_DLT_ENABLED)

# Add system libraries
if (DK_SLOG2_ENABLED)
    target_link_libraries(${MODULE_NAME}
        PUBLIC
        slog2
    )
endif(DK_SLOG2_ENABLED)

# Set module version
set_target_properties(${MODULE_NAME}
    PROPERTIES 
    VERSION ${DK_LOGGER_VERSION}
    SOVERSION ${DK_LOGGER_VERSION_MAJOR}
)

# Set API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/dk_logger_impl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/dk_logger.h
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/logger
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 07/14/2020  | DRAJ5    |  962331   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020 | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------

