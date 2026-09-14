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

# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resmgr/CDisplay_RM.c
)

# Add dependency libraries
target_include_directories(${BINARY_NAME} 
							PRIVATE 
							${CMAKE_CURRENT_SOURCE_DIR}/src/resmgr
)

if(VBUILD_QNX_MAJOR_VERSION STREQUAL 7)
# Add system libraries
	target_link_libraries(${BINARY_NAME}
		PRIVATE
		login
	)
elseif(VBUILD_QNX_MAJOR_VERSION STREQUAL 8)
	# Add system libraries
	target_link_libraries(${BINARY_NAME}
		PRIVATE
		secpol
	)
else()
	message(FATAL_ERROR "ERROR - QNX Major Version (${VBUILD_QNX_MAJOR_VERSION}). Valid values are: 7, 8")
endif()

target_compile_definitions(${BINARY_NAME}
	PRIVATE
		VBUILD_QNX_MAJOR_VERSION=${VBUILD_QNX_MAJOR_VERSION}
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
	PUBLIC
	resmgr_display_intf
	resmgr_display_devctl
	dk_logger
)

if(NOT BSP_DISPLAY_TEST_DISABLED)
# Add test binaries
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FT/display_rm_test.cmake
)
endif()

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2/7/2020    | RCHALLA1  |  NA   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
