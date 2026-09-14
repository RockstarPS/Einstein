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

set(DK_BSPAL_DISPLAY_VERSION_MAJOR 0)
set(DK_BSPAL_DISPLAY_VERSION_MINOR 11)
set(DK_BSPAL_DISPLAY_VERSION_PATCH_LEVEL 0)
set(DK_BSPAL_DISPLAY_VERSION ${DK_BSPAL_DISPLAY_VERSION_MAJOR}.${DK_BSPAL_DISPLAY_VERSION_MINOR}.${DK_BSPAL_DISPLAY_VERSION_PATCH_LEVEL})
set(DK_BSPAL_DISPLAY_BUILD_USER $ENV{USERNAME})
string(TIMESTAMP DK_BSPAL_DISPLAY_BUILD_TIMESTAMP "%Y-%m-%d %H:%M")
cmake_host_system_information(RESULT DK_BSPAL_DISPLAY_BUILD_HOSTNAME QUERY HOSTNAME)


if(CMAKE_SYSTEM_NAME MATCHES Linux)
        # Create Library
        add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
                ${CMAKE_CURRENT_SOURCE_DIR}/src/dk_bspal_display.c
                )

	# Add dependency libraries
        target_include_directories(${MODULE_NAME}
               PUBLIC
               ${CMAKE_CURRENT_SOURCE_DIR}/public
               ${BUILD_ROOT_DIR}/dk.lib.logger/src/logger/
               )

        # Add system libraries
        target_link_libraries(${MODULE_NAME}
                PUBLIC
		#slog2
                )

        # Add dependency libraries
        target_add_dependencies(${MODULE_NAME}
                PUBLIC
		#display #Not been used
                dk_logger
                )

        target_compile_definitions(${MODULE_NAME}
                PUBLIC
                _DEFAULT_SOURCE
                )
	add_definitions(-DLINUX_PLATFORM)
endif()



if(CMAKE_SYSTEM_NAME MATCHES QNX)

# Create Library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dk_bspal_display.c
)

# Add dependency libraries
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    ${BUILD_ROOT_DIR}/dk.lib.logger/src/logger/
)

# Add system libraries
target_link_libraries(${MODULE_NAME}
    PUBLIC
    slog2
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
        PUBLIC
        resmgr_display_devctl
        dk_logger
)
add_definitions(-DQNX_PLATFORM)

endif()




set_target_properties(${MODULE_NAME} 
						PROPERTIES 
						VERSION ${DK_BSPAL_DISPLAY_VERSION} 
						SOVERSION ${DK_BSPAL_DISPLAY_VERSION_MAJOR} 
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task            |   Description
#-------------------------------------------------------------------------------------------------------------------
# 2/7/2020    | RBABU9   |  NA               | Created initial file
# 11/08/2024  | dpanneer |  PE4TI29141-72    | Added for E4 Platform linux board 
# 03/10/2024  | ssomasu1 |  TFDCX32348-42310 | Common BSPAL code for QNX & linux
#-------------------------------------------------------------------------------------------------------------------
