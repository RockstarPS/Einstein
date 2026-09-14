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

# Add Version file
set(UCL_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include(${UCL_ROOT_PATH}/Ucl_Version.cmake)

# Add source files for the library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfProxy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfInterface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
    ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/ucl
)

# Common UCL dependencies
set(UCL_PRIVATE_DEPENDS 
    UclAdapterCommon
    UclAlCommon
    UclCommon.a
    UclDL.a
    UclILCommon
	UclILRouter.a
	UclILSched.a
    UclSysCommon
	UclSys.a
    vmf_client
)

if(UCL_TRANSPORT_SPI)
    set(UCL_PRIVATE_DEPENDS 
        ${UCL_PRIVATE_DEPENDS}
        UclALPhySpiQnx.a
    )
endif()

# Add target dependencies
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    ${UCL_PRIVATE_DEPENDS}
)

# Add API header files
target_add_api_headers(${MODULE_NAME}
    HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfConfig.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfInterface.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UclVmfProxy.hpp
)

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ucl
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  04/10/2020  | MDELAFU1 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
