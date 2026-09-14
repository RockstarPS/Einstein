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

# Create Dummy Executable to generate all the OSAL libraries
add_executable(${BINARY_NAME}     
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_VmfAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_VmfAdapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_RxMsgDb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP/UclGen_TxMsgDb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gp/UclInstCfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg/gp/UclCfg.c
)

# Add target include directories
target_include_directories(${BINARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/adapter/GIP
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg/gp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gp
)

target_compile_definitions(${BINARY_NAME}
    PUBLIC
    UCL_DEBUG_ON	
)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    GenRuntime
    dlt_wrapper
    UclAdapterCommon
    UclDL.a
    UclILCommon
    UclILRouter.a
    UclILSched.a
    UclPosixOs.a
    UclALDebugDLT.a
    UclMailboxLinuxPhy.a
    UclSys.a
    ucl_vmf
    vmf_client
)

# Add dependency libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
    pthread
    dlt
)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    GenRuntime
    UclAdapterCommon
    UclDL.a
    UclILCommon
    UclILRouter.a
    UclILSched.a
    UclPosixOs.a
    UclQnxDebug.a
    UclMailboxLinuxPhy.a
    UclSys.a
    ucl_vmf
    vmf_client
)

# Add dependency libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
    slog2
    mq
    login
)
endif()

if(MAILBOX_TEST)
    binary_scripts(
        ${CMAKE_CURRENT_SOURCE_DIR}/mailbox-test/MailboxGip.cmake
)
endif()

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ucl
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
