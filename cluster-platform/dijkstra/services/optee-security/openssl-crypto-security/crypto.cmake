#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2021] Visteon Corporation
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
cmake_minimum_required(VERSION 3.14)

# Add the OpenSSL package
find_package(OpenSSL REQUIRED)

# Define the executable and library names
set(BINARY_NAME armcrypto)
set(LIBRARY_NAME armcryptoextension)

# Specify the source files
set(SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/SecurityCryptoHandler.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto_main.c
)

# Checking if source files exist
foreach(SOURCE_FILE ${SOURCE_FILES})
    if(NOT EXISTS ${SOURCE_FILE})
        message(WARNING "Source file ${SOURCE_FILE} does not exist!")
    endif()
endforeach()

# Create the executable
add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_include_directories(${BINARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link OpenSSL libraries to the executable
target_link_libraries(${BINARY_NAME} OpenSSL::Crypto)

# Install the executable
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Create a shared library from the same source files
add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link OpenSSL libraries to the shared library
target_link_libraries(${LIBRARY_NAME} OpenSSL::Crypto)

# Install the shared library
install(TARGETS ${LIBRARY_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 28/01/2025  | pkarnada   |     | Created initial file
#-------------------------------------------------------------------------------------------------------------------


