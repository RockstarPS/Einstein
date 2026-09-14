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

# Add Version file
set(UCL_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/..)
include(${UCL_ROOT_PATH}/Ucl_Version.cmake)

# Create library target
if((${BUILD_OS} STREQUAL QNX710) OR (${BUILD_OS} STREQUAL QNX700))
	add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
	${CMAKE_CURRENT_SOURCE_DIR}/UclBufferPool.c
	${CMAKE_CURRENT_SOURCE_DIR}/UclCmnRingBuffer.c
	${CMAKE_CURRENT_SOURCE_DIR}/UclCmnSerialize.c
	${CMAKE_CURRENT_SOURCE_DIR}/UclVmfMsgQueue.c
	${CMAKE_CURRENT_SOURCE_DIR}/UclCrc.c
)
elseif(${BUILD_OS} STREQUAL linux)
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/UclBufferPool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnRingBuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnSerialize.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfMsgQueue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCrc.c
)
else()
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/UclBufferPool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnRingBuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnSerialize.c
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCrc.c
)
endif()

# Add target include directories
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
	UclDL
    UclSysCommon
    PRIVATE
    UclAlCommon
)

# Add API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Ucl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Ucl_Types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UclBufferPool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnRingBuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UclCmnSerialize.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfMsgQueue.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UclBufferPool.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UclBlockingQueue.hpp
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ucl
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/11/2022  | SSHANKA8 |  1607549  | Updated for ASR build to not include UclVmfMsgQueue
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
