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


if(BUILD_SOC_PLATFORM MATCHES QCOM_GEN3)
    # Create Library
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/qcom/qcom_sys_shutdown.c
    )

    # Add dependency libraries
    target_include_directories(${MODULE_NAME} 
    	PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/public/
        ${QC_HLOS_QNX_DIR}/apps/qnx_ap/AMSS/platform/utilities/pwroff/public/amss/core
   	)

    target_link_directories(${MODULE_NAME}
        PUBLIC
        ${QC_HLOS_QNX_DIR}/apps/qnx_ap/AMSS/platform
        ${QC_HLOS_QNX_DIR}/apps/qnx_ap/AMSS/platform/utilities/pwroff/aarch64/a-le/
        ${QC_HLOS_QNX_DIR}/apps/qnx_ap/AMSS/platform/qal/clients/pmic_client/aarch64/so-le/
    )

    # Add system libraries
    target_link_libraries(${MODULE_NAME}
        PUBLIC
        libshutdown.a
        libpwroff.a
        libpmic_clientS.a
    )
elseif (BUILD_SOC_PLATFORM MATCHES VMWARE)
    # Create Library
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vmware/vmware_sys_shutdown.c
    )

    # Add dependency libraries
    target_include_directories(${MODULE_NAME} 
    	PUBLIC 
    	${CMAKE_CURRENT_SOURCE_DIR}/public/
   	)

    # Add system libraries
    target_link_libraries(${MODULE_NAME}
        PUBLIC
    )
elseif (CMAKE_SYSTEM_NAME MATCHES Linux)

    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
     ${CMAKE_CURRENT_SOURCE_DIR}/src/am62x/linux_sys_shutdown.c
      )
   # Add dependency libraries
    target_include_directories(${MODULE_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/public/
        ${CMAKE_BINARY_DIR}/install/usr/include
        )
       # Add system libraries
    target_link_libraries(${MODULE_NAME}
        PUBLIC
        #PRIVATE
        systemd
        rt        
	#libshutdown.a
    )
else()
    # Create Library
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/imx8/qnx_sys_shutdown.c
    )

    # Add dependency libraries
    target_include_directories(${MODULE_NAME} 
    	PUBLIC 
    	${CMAKE_CURRENT_SOURCE_DIR}/public/
   	)

    # Add system libraries
    target_link_libraries(${MODULE_NAME}
        INTERFACE
        ${MODULE_NAME}_libshutdown
    )
    add_library(${MODULE_NAME}_libshutdown STATIC IMPORTED)

    set_target_properties(${MODULE_NAME}_libshutdown
    PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/aarch64le/usr/lib/libshutdown.a
    )
endif ()

# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 2/7/2020    |  DRAJ5   |  NA       			| Created initial file
# 14/9/2023   |  VKUMARA |  HYU30644-15582              | Linked libshutdown.a as Prebuilt library
# 28/6/2024   |  dpanneer|  PE4TI29141-3781             | Added the linux AM62X compile part
# 22/07/2025  | PKRISH12 |  TFDCX32348-98686 	| Added linux system dbus library for dbus based power off/reboot. 
#-------------------------------------------------------------------------------------------------------------------
