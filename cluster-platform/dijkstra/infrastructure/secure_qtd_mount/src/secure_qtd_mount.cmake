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
cmake_minimum_required (VERSION 3.14)

# Create Binary
add_executable(${BINARY_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

if(SUPPORT_AB_PARTITION)
    target_compile_definitions(${BINARY_NAME}
        PRIVATE
        SUPPORT_AB
    )
endif(SUPPORT_AB_PARTITION)

if(BUILD_SOC_PLATFORM STREQUAL SAM_EXYNOS)
    target_compile_definitions(${BINARY_NAME}
        PRIVATE
        SAM_EXYNOS
        CONFIG_SOC_EXYNOSAUTO9_EVT1
        SYSTEM_PATH_BIN_QNX6FS="/sbin/mkqnx6fs"
        SYSTEM_PATH_BIN_DOSFS="/sbin/mkdosfs"
    )
elseif(BUILD_SOC_PLATFORM STREQUAL TI_AM62P)
    if(${BUILD_OS} STREQUAL linux)
        target_compile_definitions(${BINARY_NAME}
            PRIVATE
            TI_AM62P
            SYSTEM_PATH_BIN_EXT4FS="/sbin/mkfs.ext4"
            SYSTEM_PATH_BIN_DOSFS="/sbin/mkfs.vfat"
        )
    else()
        #QNX7.0/7.1/8.0
        target_compile_definitions(${BINARY_NAME}
            PRIVATE
            TI_AM62P
            SYSTEM_PATH_BIN_QNX6FS="/system/sbin/mkqnx6fs"
            SYSTEM_PATH_BIN_DOSFS="/system/sbin/mkdosfs"
        )
    endif()
elseif(BUILD_SOC_PLATFORM STREQUAL QCOM_GEN3)
    target_compile_definitions(${BINARY_NAME}
        PRIVATE
        QCOM_GEN3
        SYSTEM_PATH_BIN_QNX6FS="/sbin/mkqnx6fs"
        SYSTEM_PATH_BIN_DOSFS="/sbin/mkdosfs"
    )
else()
    target_compile_definitions(${BINARY_NAME}
        PRIVATE
        NXP_MX8
        SYSTEM_PATH_BIN_QNX6FS="/system/sbin/mkqnx6fs"
        SYSTEM_PATH_BIN_DOSFS="/system/sbin/mkdosfs"
    )
endif()

if(BUILD_SOC_PLATFORM STREQUAL TI_AM62P)
    if(${BUILD_OS} STREQUAL linux)
        # Add dependency libraries
        target_add_dependencies(${BINARY_NAME}
            PUBLIC
            dk_logger
            metadata
        )
    else()
        #QNX7.0/7.1/8.0
        # Add dependency libraries
        target_add_dependencies(${BINARY_NAME}
            PUBLIC
            dk_logger
        )
    endif()
else()
    # Add dependency libraries
    target_add_dependencies(${BINARY_NAME}
        PUBLIC
        dk_logger
    )
endif()

if(${BUILD_OS} STREQUAL linux)
    target_link_libraries(${BINARY_NAME} PRIVATE
	    json-c
    )
else()
    #QNX 7.0/7.1/8.0
    target_link_libraries(${BINARY_NAME} PRIVATE
	    slog2
	    json
    )
endif()

if(BUILD_SOC_PLATFORM STREQUAL SAM_EXYNOS)
elseif(BUILD_SOC_PLATFORM STREQUAL TI_AM62P)
elseif(BUILD_SOC_PLATFORM STREQUAL QCOM_GEN3)
else()
    #i.MX8
    if(${BUILD_OS} STREQUAL QNX710)
        target_include_directories(${BINARY_NAME} PRIVATE
            ${BSP_DIR}/qnx71-bsp/src/hardware/support/sc-imx8/public
            ${BSP_DIR}/qnx71-bsp/src/lib/hw_vendor/nxp/imx8/sci/public/
            ${CMAKE_CURRENT_SOURCE_DIR}
        )
    elseif(${BUILD_OS} STREQUAL QNX700)
        target_include_directories(${BINARY_NAME} PRIVATE
            ${BSP_DIR}/qnx7-bsp/src/hardware/support/sc-imx8/public
            ${BSP_DIR}/qnx7-bsp/src/lib/hw_vendor/nxp/imx8/sci/public/
            ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endif()

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 08/02/2021  | NKHAN2   |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------