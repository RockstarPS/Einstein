# global domain cmake file for cmake based projects
#
# Precondition: Import/Source the global environment setup
# e.g. for QNX ${path2QNXInstallation}/sdp/qnxsdp-env.sh
# Careful: Sourcing the env may change the PATH variable!
#
# Author: Alexander Weimann, Robert Allmeroth
#

cmake_minimum_required(VERSION 3.5.1)

PROJECT( VmfSomeipGateway )


if (NOT BSW_OS)
    set (BSW_OS "linux")
endif ()

if (NOT BSW_ARCH)
    set (BSW_ARCH "x86")
endif ()

if (NOT BSW_PLATFORM)
    set (BSW_PLATFORM "dijkstra")
endif ()

if (${CMAKE_SYSTEM_NAME} STREQUAL "QNX")
    set (BSW_OS "qnx7")

    if (${BSW_ARCH} STREQUAL "gcc_ntox86")
        set (BSW_ARCH "x86")
    elseif (${BSW_ARCH} STREQUAL "gcc_ntoaarch64le")
         set (BSW_ARCH "aarch64")
    endif ()
endif ()

set (VARIANT "${BSW_OS}-${BSW_ARCH}")

if (DEBUG_MACRO)
    add_definitions (-DDEBUG)
endif ()

add_subdirectory ( ${CMAKE_CURRENT_SOURCE_DIR}/../Gateway/build ${CMAKE_CURRENT_BINARY_DIR}/Gateway)

