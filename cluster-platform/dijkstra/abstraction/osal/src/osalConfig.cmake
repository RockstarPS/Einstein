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

# Especify version fo the library
set (OSAL_MAJOR_VERSION 0)
set (OSAL_MINOR_VERSION 1)
set (OSAL_PATCH_VERSION 1)
set (OSAL_VERSION ${OSAL_MAJOR_VERSION}.${OSAL_MINOR_VERSION}.${OSAL_PATCH_VERSION})

# Check the system type
set(system_type posix)

# Files to be linked into the shared library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalClock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalConfig.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalMutex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalMutexLock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalOsTimer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalProcess.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalRecursiveMutex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalSemaphore.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalSharedMemory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalThread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalTimer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalTimerMgr.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/DKOsalTrace.cpp 
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}
)

# Add dependency libraries
if(CMAKE_SYSTEM_NAME MATCHES Windows)
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    pthreads4w.a
    unistd_wrapper.a
)
endif()
# Add target definitions
target_compile_definitions(${MODULE_NAME}
    PUBLIC
    OSAL_VERSION=\"${OSAL_VERSION}\"
)

# Set module version
set_target_properties(${MODULE_NAME}
    PROPERTIES 
    VERSION ${OSAL_VERSION}
    SOVERSION ${OSAL_MAJOR_VERSION}
)

# Add all the header files found in ${system_type}
search_src_file(api_hdr_files
    INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_type}/*.h
)
target_add_api_headers(${MODULE_NAME} HEADERS ${api_hdr_files})

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/osal
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020  | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
