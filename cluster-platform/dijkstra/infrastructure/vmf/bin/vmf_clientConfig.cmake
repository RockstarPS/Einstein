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

# Set system architecture
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
	string(TOLOWER "${BUILD_OS}_${CMAKE_SYSTEM_PROCESSOR}_VS" system_arch)
else()
	string(TOLOWER "${BUILD_OS}_${CMAKE_SYSTEM_PROCESSOR}" system_arch)
endif()

# Create library target
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED} IMPORTED)

# Specify the precompiled library to use
if(MODULE_STATIC_SHARED STREQUAL STATIC)
    if(CMAKE_SYSTEM_NAME STREQUAL Windows)
        set(static_suffix _static)
    endif()
    set_target_properties(${MODULE_NAME} PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${static_suffix}${CMAKE_STATIC_LIBRARY_SUFFIX}
    )
    # Install the library
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${static_suffix}${CMAKE_STATIC_LIBRARY_SUFFIX} DESTINATION ${CMAKE_INSTALL_LIBDIR})
else()
    set_target_properties(${MODULE_NAME} PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${CMAKE_SHARED_LIBRARY_SUFFIX}
    )
    if(CMAKE_SYSTEM_NAME STREQUAL Windows)
        set_target_properties(${MODULE_NAME} PROPERTIES
            IMPORTED_IMPLIB ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${CMAKE_STATIC_LIBRARY_SUFFIX}
        )
        # Install the library
        install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${CMAKE_STATIC_LIBRARY_SUFFIX}
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/dll
        )
        install(FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${CMAKE_SHARED_LIBRARY_SUFFIX}
            DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    else()
        # Install the library
        install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/libvmf_client${CMAKE_SHARED_LIBRARY_SUFFIX} DESTINATION ${CMAKE_INSTALL_BINDIR})
    endif()
endif()

# Add directories
target_include_directories(${MODULE_NAME}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/include
)

# Add all the header files found in ${system_arch}
search_src_file(api_hdr_files
    INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/*.h
)
target_add_api_headers(${MODULE_NAME} HEADERS ${api_hdr_files})

# Copy header files to install folder
file(COPY ${PUBLIC_HEADER} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/vmf)

# Copy binaries to install folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/bin/vmf${CMAKE_EXECUTABLE_SUFFIX}
          ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/bin/vmf_listener${CMAKE_EXECUTABLE_SUFFIX}
          ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/bin/vmf_sender${CMAKE_EXECUTABLE_SUFFIX}
     DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}
)

# Install DLLs
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    install(FILES 
        ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/bin/libgcc_s_dw2-1.dll 
        ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/bin/libwinpthread-1.dll 
        ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/pthreadGC2.dll 
        ${CMAKE_CURRENT_SOURCE_DIR}/${system_arch}/libs/pthreadVC2.dll 
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endif()

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 11/22/2019  | MDELAFU1 |  677597   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
