#*****************************************************************************
#                                                                            *
#              CONFIDENTIAL VISTEON CORPORATION                              *
#                                                                            *
# This is an unpublished work of authorship, which contains trade            *
# secrets, created in 2020. Visteon Corporation owns all rights to           *
# this work and intends to maintain it in confidence to preserve             *
# its trade secret status. Visteon Corporation reserves the right,           *
# under the copyright laws of the United States or those of any              *
# other country that may have jurisdiction, to protect this work             *
# as an unpublished work, in the event of an inadvertent or                  *
# deliberate unauthorized publication. Visteon Corporation also              *
# reserves its rights under all copyright laws to protect this               *
# work as a published work, when appropriate. Those having access            *
# to this work may not copy it, use it, modify it or disclose the            *
# information contained in it without the written authorization              *
# of Visteon Corporation.                                                    *
#                                                                            *
#*****************************************************************************/

cmake_minimum_required(VERSION 3.14)
project(optee_securitylib )

# Point to the directory with Makefile and imports.mak
set(OPTEE_MAKE_DIR "${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib")

# Find Make
find_program(MAKE_BIN make REQUIRED)

# Run cleanx
execute_process(
    COMMAND ${MAKE_BIN} -C ${OPTEE_MAKE_DIR} optee-securitylib_clean
    RESULT_VARIABLE CLEAN_RESULT
    OUTPUT_VARIABLE CLEAN_OUTPUT
    ERROR_VARIABLE CLEAN_ERROR
)
if(NOT CLEAN_RESULT EQUAL 0)
    message(FATAL_ERROR "Clean failed:\n${CLEAN_OUTPUT}\n${CLEAN_ERROR}")
else()
    message(STATUS "Clean success:\n${CLEAN_OUTPUT}")
endif()

# Run build
execute_process(
    COMMAND ${MAKE_BIN} -C ${OPTEE_MAKE_DIR} optee-securitylib
    RESULT_VARIABLE BUILD_RESULT
    OUTPUT_VARIABLE BUILD_OUTPUT
    ERROR_VARIABLE BUILD_ERROR
)
if(NOT BUILD_RESULT EQUAL 0)
    message(FATAL_ERROR "Build failed:\n${BUILD_OUTPUT}\n${BUILD_ERROR}")
else()
    message(STATUS "Build success:\n${BUILD_OUTPUT}")
endif()
