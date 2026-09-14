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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dk_bspal_deserializer.c
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
# Add dependency libraries
target_include_directories(${MODULE_NAME} 
    PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/public
	${BSPAL_DESERIALIZER_INCLUDEDIR}
)


# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
      PUBLIC
      dk_logger
)

add_definitions(-DLINUX_PLATFORM)
endif( )


# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 
# 17DEC2024   | SSOMASU1 |  TFDCX32348-59708 |  BSPAL library development
#-------------------------------------------------------------------------------------------------------------------
