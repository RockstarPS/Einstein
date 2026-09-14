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

# Files to be linked into the static library

add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/metadata.c
	${CMAKE_CURRENT_SOURCE_DIR}/lib/metadata_hw.c
	${CMAKE_CURRENT_SOURCE_DIR}/lib/shared_mutex.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/public
	${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/metadata
	${CMAKE_BINARY_DIR}/install/usr/include
)

if(DK_LIB_METADATA_SWAP16)
    target_compile_definitions(${MODULE_NAME}
        PUBLIC
        METADATA_SWAP16
    )
endif()

if(DK_LIB_METADATA_NOR)
    target_compile_definitions(${MODULE_NAME}
        PUBLIC
        METADATA_NOR
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    target_compile_definitions(${MODULE_NAME} 
        PUBLIC
        DEBUG
        DEBUG_SYSLOG
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES QNX)
    target_compile_definitions(${MODULE_NAME} 
        PUBLIC
        DEBUG
        DEBUG_SLOG2
    )

endif()

# Set API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/public/metadata.h
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/metadata
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2021/07/11  |KSHANMU4  |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
