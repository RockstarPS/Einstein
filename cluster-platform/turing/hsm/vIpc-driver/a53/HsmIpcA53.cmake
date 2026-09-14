#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2024] Visteon Corporation
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

# Files to be linked into the static library
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmIpcMain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmIpcHostManager.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmCryptoJobHandler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmCryptoManager.c
)

target_include_directories(${BINARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public
)


# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    dk_logger
    #McuSdk
    #PlatformStubs
    #HsmCare
    #HsmCfg
)

# Set API header files
#target_add_api_headers(${MODULE_NAME}
 #   HEADERS
 #   ${CMAKE_CURRENT_SOURCE_DIR}/public/vHsmIpc.h
 #   ${CMAKE_CURRENT_SOURCE_DIR}/public/vHsmIpcSram.h
#)

# Install the library
#install(TARGETS ${MODULE_NAME}
   # ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/HsmIpcA53
#)
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


# EOF
