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
add_executable(${BINARY_NAME} dummy_executable.c)

# Add dependency libraries
if(CMAKE_SYSTEM_NAME MATCHES Linux)
target_add_dependencies(${BINARY_NAME}
	PUBLIC
	bspal_dio
)
endif()

if(CMAKE_SYSTEM_NAME MATCHES QNX)
target_add_dependencies(${BINARY_NAME}
	PUBLIC
	resmgr_dio_devctl
	bspal_dio
)
endif()

if(BSPAL_DIO_TESTS)
# Add test binaries
binary_scripts(
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test01/dio_set_pin.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test02/dio_set_pin0.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test03/read_pin_value1.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test04/read_pin_value0.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test05/set_dir_out.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test06/set_dir_in.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test07/read_dir_in.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/c_client/test08/read_dir_out.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/test/FT/cxx_client/test01/main_cpp.cmake
)
endif()

