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

if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
    set(BOARD_VAR e4_a1)
    set(EXTRA_DEFINES "-DBOOT_MODE_XSPI")
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
    set(BOARD_VAR e4_a0)
    set(EXTRA_DEFINES "-DBOOT_MODE_SPI")
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1_QNX)
    set(BOARD_VAR e4_a1)
    set(OS_VAR_DEFINE "DEFINES_release+=-DQNX_OS" "DEFINES_debug+=-DQNX_OS")
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0_QNX)
    set(BOARD_VAR e4_a0)
    set(OS_VAR_DEFINE "DEFINES_release+=-DQNX_OS" "DEFINES_debug+=-DQNX_OS")
endif()

# Check if production_mode environment variable is defined
if(DEFINED ENV{PRODUCTION_MODE})
    if("$ENV{PRODUCTION_MODE}" STREQUAL "ON")
        message(STATUS "======= PRODUCTION_MODE IS SET ========")
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HS =====")
        set(DEVICE_TYPE "hs")
        set(SIGNING_KEY "app_degenerateKey_Prod.pem")
    else()
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HSFS =====")
        set(DEVICE_TYPE "hs_fs")
        set(SIGNING_KEY "app_degenerateKey.pem")
    endif()
else()
    message(STATUS "==== PRODUCTION_MODE OFF. COMPILING FOR DEVICE_TYPE HSFS =====")
    set(DEVICE_TYPE "hs_fs")
    set(SIGNING_KEY "app_degenerateKey.pem")
endif()
# Export DEVICE_TYPE to environment for Makefiles
set(ENV{DEVICE_TYPE} ${DEVICE_TYPE})

# Set variables used by the support scripts
set(MCU_SDK_DIR         ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/mcu-sdk)
set(PROJECT_DM_DIR      ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/dm-firmware)
set(YOCTO_BINS          ${CMAKE_SOURCE_DIR}/$ENV{ARTI_OUTPUT_PATH}/$ENV{ARTI_PATTERN}/Jenkins_Images)
set(SECMGR_SOURCE_DIR   ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib)
set(DM_MODULES_DIR      ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/dm)

# Add custom target to build BSP when it is not compiled

file(GLOB BOARD_PATCHES
    "${PROJECT_DM_DIR}/patches/*.patch"
)
set(APPLY_PATCHES "")
foreach(PF ${BOARD_PATCHES})
    list(APPEND APPLY_PATCHES COMMAND patch -d ${MCU_SDK_DIR}/ -p1 --input=${PF})
endforeach()

add_custom_command (
    COMMENT "Starting to Build DM FW "
    COMMAND git clean -fdx  ${MCU_SDK_DIR}
    COMMAND git restore  ${MCU_SDK_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/visteon_imports.mak ${MCU_SDK_DIR}/imports.mak
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/ddr_Config/board_ddrReginit.h ${MCU_SDK_DIR}/source/drivers/ddr/v1/soc/am62px/board_ddrReginit.h
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/security_key/${SIGNING_KEY}  ${MCU_SDK_DIR}/tools/boot/signing/app_degenerateKey.pem
    ${APPLY_PATCHES}
    COMMAND touch ${CMAKE_BINARY_DIR}/install/patches_done

    WORKING_DIRECTORY ${MCU_SDK_DIR}
    USES_TERMINAL
    OUTPUT ${CMAKE_BINARY_DIR}/install/patches_done
    COMMENT "Applying BOARD_VAR Specific Patches"
)

add_custom_command(
    COMMENT "Starting to Build DM FW "
    COMMAND make -j -s -f ${MCU_SDK_DIR}/makefile libs
    COMMAND touch ${CMAKE_BINARY_DIR}/install/libs_Installed

    WORKING_DIRECTORY ${MCU_SDK_DIR}
    USES_TERMINAL
    DEPENDS ${CMAKE_BINARY_DIR}/install/patches_done
    OUTPUT ${CMAKE_BINARY_DIR}/install/libs_Installed
    COMMENT "Build LIB Modules"
)

# Add custom target to build BSP when it is not compiled

add_custom_command(	
    COMMENT "Starting to Build DM FW "

    #Copy DM sub-modules
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_DM_DIR}/sbl_e4_common_utils
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${DM_MODULES_DIR}/sblutil/src ${PROJECT_DM_DIR}/sbl_e4_common_utils
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${DM_MODULES_DIR}/vdm-wdg/src ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${DM_MODULES_DIR}/vdm-dlt/src ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/install
    COMMAND make -e  VARIANT=${BOARD_VAR} DEVICE_TYPE=${DEVICE_TYPE} EXTRA_DEFINES=${EXTRA_DEFINES} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -j -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/ti-arm-clang all
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/ti-arm-clang/sbl_ospi_stage1.release.${DEVICE_TYPE}.tiimage ${CMAKE_BINARY_DIR}/install
    COMMAND make -e  VARIANT=${BOARD_VAR} DEVICE_TYPE=${DEVICE_TYPE} EXTRA_DEFINES=${EXTRA_DEFINES} ${OS_VAR_DEFINE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -j -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/ti-arm-clang all
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/ti-arm-clang/sbl_ospi_stage2.release.appimage.${DEVICE_TYPE} ${CMAKE_BINARY_DIR}/install
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -j -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage1/ti-arm-clang all
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage1/ti-arm-clang/sbl_emmc_stage1.release.${DEVICE_TYPE}.tiimage ${CMAKE_BINARY_DIR}/install
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} ${OS_VAR_DEFINE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -j -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage2/ti-arm-clang all
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage2/ti-arm-clang/sbl_emmc_stage2.release.appimage.${DEVICE_TYPE} ${CMAKE_BINARY_DIR}/install

    # Linux app Gen

    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/install/DM_Installed

    WORKING_DIRECTORY ${PROJECT_DM_DIR}
    USES_TERMINAL
    DEPENDS ${CMAKE_BINARY_DIR}/install/libs_Installed
    OUTPUT ${CMAKE_BINARY_DIR}/install/DM_Installed
    COMMENT "Building DM FW"
)

add_custom_target(build_dm ALL DEPENDS ${CMAKE_BINARY_DIR}/install/DM_Installed)

# Add a target to clean all BSP
add_custom_target(clean_dm
    COMMENT "Cleaning DM FW" VERBATIM

    #Clean DM sub-modules
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PROJECT_DM_DIR}/sbl_e4_common_utils/
    COMMAND ${CMAKE_COMMAND} -E rm -f ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/wd.h
    COMMAND ${CMAKE_COMMAND} -E rm -f ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/wd.c
    COMMAND ${CMAKE_COMMAND} -E rm -f ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/dlt.h
    COMMAND ${CMAKE_COMMAND} -E rm -f ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/dlt.c
    
    COMMAND cd ${PROJECT_DM_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/visteon_imports.mak ${MCU_SDK_DIR}/imports.mak
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/ti-arm-clang clean
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage1/ti-arm-clang scrub
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/ti-arm-clang clean
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SblOspi/sbl_ospi_stage2/ti-arm-clang scrub
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage1/ti-arm-clang clean
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage1/ti-arm-clang scrub
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage2/ti-arm-clang clean
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} -s -C ${PROJECT_DM_DIR}/SbleMMC/sbl_emmc_stage2/ti-arm-clang scrub

    COMMAND cd ${MCU_SDK_DIR}
    COMMAND make -s -f ${MCU_SDK_DIR}/makefile libs-clean
    COMMAND make -s -f ${MCU_SDK_DIR}/makefile libs-scrub
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${MCU_SDK_DIR}/${BOARD_VAR}/install/patches_done
    COMMAND git clean -fdx  ${MCU_SDK_DIR}
    COMMAND git restore  ${MCU_SDK_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/install
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_BINARY_DIR}/CMakeCache.txt
    
    WORKING_DIRECTORY ${PROJECT_DM_DIR}
    USES_TERMINAL
)



#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  03/05/2024  | MMK      |    N/A    | Updated to SDK 9.2
#  27/07/2023  | MMK      |    N/A    | Created initial DM build file
#-------------------------------------------------------------------------------------------------------------------
