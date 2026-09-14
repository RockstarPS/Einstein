#---------------------------------------------------------------------------------------------------------------------
#
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

if(DEFINED PROJECT_VAR)
   if(PROJECT_VAR STREQUAL "EINSTIEN_4_0_VIP_HMI")
       set(DISPLAY_VAR "VIP_CONTROLLED_DISPLAY")
    elseif(PROJECT_VAR STREQUAL "EINSTIEN_4_0_GIP_HMI")
       set(DISPLAY_VAR "GIP_CONTROLLED_DISPLAY")
   else()
       set(DISPLAY_VAR "GIP_CONTROLLED_DISPLAY")
   endif()
   if(PROJECT_VAR STREQUAL "EINSTEIN_4_0_A1")
        set(PMIC_VAR "PMIC_CONTROLLED_A1")
        set(FLTMEXT_VAR "FLTMEXT_CONTROLLED_A1")
    elseif(PROJECT_VAR STREQUAL "EINSTEIN_4_0_A0")
        set(PMIC_VAR "PMIC_CONTROLLED_A0")
        set(FLTMEXT_VAR "FLTMEXT_CONTROLLED_A0")
    else()
        set(PMIC_VAR "PMIC_CONTROLLED_A1")
        set(FLTMEXT_VAR "FLTMEXT_CONTROLLED_A1")
        message(STATUS "Using default A1 configuration!")
    endif()
else()
   message(FATAL_ERROR "PROJECT_VAR is not set!")
endif()

set(HSM_APP_PATH                    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app)
# Check if production_mode environment variable is defined
if(DEFINED ENV{PRODUCTION_MODE})
    if("$ENV{PRODUCTION_MODE}" STREQUAL "ON")
        message(STATUS "======= PRODUCTION_MODE IS SET ========")
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HS =====")
        set(DEVICE_TYPE "hs")
        set(SIGNING_KEY ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/signing/app_degenerateKey_Prod.pem)
    else()
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HSFS =====")
        set(DEVICE_TYPE "hs_fs")
        set(SIGNING_KEY ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/signing/app_degenerateKey.pem)
    endif()
else()
    message(STATUS "==== PRODUCTION_MODE OFF. COMPILING FOR DEVICE_TYPE HSFS =====")
    set(DEVICE_TYPE "hs_fs")
    set(SIGNING_KEY ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/signing/app_degenerateKey.pem)
endif()
# Export DEVICE_TYPE to environment for Makefiles
set(ENV{DEVICE_TYPE} ${DEVICE_TYPE})

# Configure search paths, compile definitions, and dependencies based on DISPLAY_VAR
if(DISPLAY_VAR STREQUAL "VIP_CONTROLLED_DISPLAY")
   set(hmi_search_paths
       ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ehmi-app
       ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ui-core
   )
   set(hmi_compile_definition "EHMI_ENABLE")
   set(hmi_dependencies
       SwcDispMonSf
       SigCdd
       ehmiapp
       gdt
       iceapple
   )
endif()

SET(SYSCONFIG_HOME $ENV{SYSCONFIG_HOME})
set(SW_VERSION 0x0A010021)

option(VP_ENABLE_KPI_IMAGE_PADDING "Pad the generated VP boot image to a KPI target size" OFF)
set(VP_KPI_IMAGE_TARGET_SIZE "4188000" CACHE STRING "Approximate target size in bytes for KPI-padded VP boot image")
set(VP_KPI_IMAGE_PAD_MAX_END_ADDR "0x82A00000" CACHE STRING "Exclusive upper DDR code address reserved for KPI image padding")
set(VP_KPI_IMAGE_PAD_FILL_BYTE "0xA5" CACHE STRING "Fill byte used for KPI RPRC padding")
set(VP_KPI_IMAGE_WARNING_MARGIN "262144" CACHE STRING "Warn when the remaining KPI padding budget drops below this number of bytes")
# Bench-only FltM same-Fault reset-loop HW test profile.
# Keep STD_OFF for normal delivery and before committing.
set(FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS
    FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE=STD_OFF
)
list(GET FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS 0 FLTM_SAME_FAULT_HW_TEST_ENABLE_MESSAGE)
string(REPLACE "FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE=" "" FLTM_SAME_FAULT_HW_TEST_ENABLE_MESSAGE "${FLTM_SAME_FAULT_HW_TEST_ENABLE_MESSAGE}")
message(STATUS "FLTM same-Fault reset-loop HW test enable: ${FLTM_SAME_FAULT_HW_TEST_ENABLE_MESSAGE}")

# Install paths configurations
set (CMAKE_CPU_FAMILY             ti)
set (CMAKE_SYSTEM_FAMILY             ti)
set (CMAKE_SYSTEM_CPU             cortexr5)
set (CMAKE_SYSTEM_PROCESSOR             arm)
set (CMAKE_CPU_FAMILY_SERIES      am62p)
set (DISPCDD_VAR "AM62X")
set (BACKLIGHTCDD_VAR LP8867)
# set (RTCCDD_VAR "RA8804CE")
# set (RTCCDD_ENABLE ON)
#set (AUTOSAR_ETH_ENABLE ON)

# Set paths to search for *Config.cmake files
add_search_paths(
    INCLUDE
    # Platform paths
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/vp-build
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/mcal
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/swccore/swc-core-dmnmgr
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/mcal-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bsw-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/swc-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ecumext
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/dltext
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/fltmext
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/nvmext
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ecuappm-callouts
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ucl-gen
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-cryptoApplication/r5
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/vHsmCryptoJobHandler/r5
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-shutdown/r5
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vIpc-driver/r5
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/di-apps
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-cryptodriver
    ${hmi_search_paths}
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/commext
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/update-client
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/wdgmext
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/xf-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/vHsmSWCrypto
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vdlt-hsm/r5

)

# Explicit CMake-side control for flash-integrity post-build processing.
# Keep this OFF for targets that do not need checksum artifact generation.
option(VP_FLASH_INTEGRITY_POSTBUILD_ENABLE "Enable flash integrity checksum post-build processing" ON)

# Add binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/dummy.c
)



# target_compile_options(${BINARY_NAME} PUBLIC
add_compile_options(
    -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16 -mthumb -Wall -g -Wno-gnu-variable-sized-type-not-at-end -Wno-unused-function
    -march=armv7-r
    -fno-stack-protector
    -c -Os -mlittle-endian -std=c99 -MD -fno-rtti -fdata-sections -fcommon -ffunction-sections -flto -finline-functions -munaligned-access
	-Wno-incompatible-pointer-types
)

target_compile_definitions(${BINARY_NAME}
    PUBLIC
    AUTOSAR_431
    BUILD_MCU0_0
    BUILD_MCU
    SOC_AM62PX
    SOC_AM62P
    VIP_UART_TEST
    BOOT_KPI_LOG_EN
    _FS_FAULT_INJECTION_TEST_ENABLE_
    # RTCCDD_ENABLE
    ${hmi_compile_definition}
    LED_DRV_ENABLE
    ${FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_COMPILE_DEFINITIONS}
    #AUTOSAR_ETH_ENABLE
    #PMIC_LW_TEST_ENABLE
)

if(VP_FLASH_INTEGRITY_POSTBUILD_ENABLE)
    target_compile_definitions(${BINARY_NAME} PUBLIC VP_FLASH_INTEGRITY_POSTBUILD_ENABLE=1)
else()
    target_compile_definitions(${BINARY_NAME} PUBLIC VP_FLASH_INTEGRITY_POSTBUILD_ENABLE=0)
endif()


# Set extencion for the generated binary
set_target_properties(${BINARY_NAME} PROPERTIES SUFFIX ".out")

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PUBLIC
    DiApps
    GenMcal
    PlatformStubs
    SciDrv
    Lin
    EcuWakeupM
    LedDrv
    CDDFitManager
    ${hmi_dependencies}
)

# Add linker file
target_link_options(${BINARY_NAME} PRIVATE
    -Wl,--ram_model -Wl,--no_demangle -Wl,--diag_wrap=on -Wl,--reread_libs -Wl,--diag_warning -Wl,--extract-dwo -Wl,--zero_init=ON -Wl,--mapfile_contents=all -Wl,
    ${CMAKE_CURRENT_SOURCE_DIR}/tgt/linker_r5.lds
)
#Generate HsFs
set(ECHO_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP/EINSTIEN4.0_VP.appimage.${DEVICE_TYPE}")

# Find any Python version
find_package(Python COMPONENTS Interpreter REQUIRED)


set(VP_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP)
set(OUT_PATH ${VP_BUILD_DIR}/EINSTIEN4.0_VP.out)
set(RPRC_PATH ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP.rprc)
set(SREC_PATH ${VP_BUILD_DIR}/EINSTIEN4.0_VP.srec)
set(CODE_REGION_SREC ${VP_BUILD_DIR}/EINSTIEN4.0_VP_CODE_REGION.srec)
set(CHECKSUM_SREC ${VP_BUILD_DIR}/EINSTIEN4.0_VP_CHECKSUM.srec)
set(CHECKSUM_BIN ${VP_BUILD_DIR}/EINSTIEN4.0_VP_CHECKSUM.bin)
set(CHECKSUM_BYTES_BIN ${VP_BUILD_DIR}/CHECKSUM_BYTES.bin)
set(CODE_REGION_BIN ${VP_BUILD_DIR}/CODE_REGION.bin)
set(CHECKSUM_ADDR 0x82600000)

set(KPI_RPRC_PAD_COMMAND)

if(VP_ENABLE_KPI_IMAGE_PADDING)
    set(KPI_RPRC_PAD_COMMAND
        COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/rprc_kpi_pad.py
                ${RPRC_PATH}
                --target-size ${VP_KPI_IMAGE_TARGET_SIZE}
                --pad-max-end-addr ${VP_KPI_IMAGE_PAD_MAX_END_ADDR}
                --pad-fill-byte ${VP_KPI_IMAGE_PAD_FILL_BYTE}
                --warn-remaining-pad-bytes ${VP_KPI_IMAGE_WARNING_MARGIN}
                >> ${CMAKE_CURRENT_BINARY_DIR}/bootimage_temp_out.txt
    )
endif()

set(HSFS_DEPENDS ${OUT_PATH})

if(VP_FLASH_INTEGRITY_POSTBUILD_ENABLE)
    message(STATUS "Flash integrity post-build enabled: checksum post-build step will run.")

add_custom_command(
    OUTPUT ${SREC_PATH} ${CODE_REGION_SREC} ${CHECKSUM_SREC} ${CHECKSUM_BIN} ${CHECKSUM_BYTES_BIN} ${CODE_REGION_BIN}
    COMMAND bash ${CMAKE_CURRENT_LIST_DIR}/process_elf_sections.sh
            ${OUT_PATH}
            ${CHECKSUM_ADDR}
            ${SREC_PATH}
            ${CODE_REGION_SREC}
            ${CHECKSUM_SREC}
            ${CHECKSUM_BIN}
            ${CHECKSUM_BYTES_BIN}
            ${CODE_REGION_BIN}
    DEPENDS ${OUT_PATH}
    COMMENT "Processing ELF sections, generating artifacts"
)
    list(APPEND HSFS_DEPENDS
         ${SREC_PATH}
         ${CODE_REGION_SREC}
         ${CHECKSUM_SREC}
         ${CHECKSUM_BIN}
         ${CHECKSUM_BYTES_BIN}
         ${CODE_REGION_BIN})
else()
    message(STATUS "Flash integrity post-build disabled: skipping checksum post-build step.")
endif()

add_custom_target(GenerateHsFs ALL
    DEPENDS ${HSFS_DEPENDS}
    # Convert ELF to RPRC with SW_VERSION
    COMMAND ${SYSCONFIG_HOME}/nodejs/node ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/out2rprc/elf2rprc.js
            ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP/EINSTIEN4.0_VP.out ${SW_VERSION} >> ${CMAKE_CURRENT_BINARY_DIR}/bootimage_temp_out.txt
    ${KPI_RPRC_PAD_COMMAND}
    # Generate the Multi-core Image (standard, non-XIP)
    COMMAND ${SYSCONFIG_HOME}/nodejs/node ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/multicoreImageGen/multicoreImageGen.js --devID 55 --out EINSTIEN4.0_VP.appimage EINSTIEN4.0_VP.rprc@5 >> ${CMAKE_CURRENT_BINARY_DIR}/bootimage_temp_out.txt
    # Sign the generated image with SW_VERSION used as the key version
    COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/signing/appimage_x509_cert_gen.py --bin EINSTIEN4.0_VP.appimage --authtype 0 --loadaddr 83200000 --key ${SIGNING_KEY} --output ${ECHO_OUTPUT} --keyversion 1.5
    # Clean up temporary files
    COMMAND ${CMAKE_COMMAND} -E remove EINSTIEN4.0_VP.appimage
    COMMAND ${CMAKE_COMMAND} -E remove EINSTIEN4.0_VP.rprc
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP/bootimage_temp_out.txt
    # COMMAND ${CMAKE_COMMAND} -E remove ${SREC_PATH}
    # COMMAND ${CMAKE_COMMAND} -E remove ${CODE_REGION_SREC}
    # COMMAND ${CMAKE_COMMAND} -E remove ${CHECKSUM_SREC}
    # COMMAND ${CMAKE_COMMAND} -E remove ${CHECKSUM_BIN}
    # COMMAND ${CMAKE_COMMAND} -E remove ${CHECKSUM_BYTES_BIN}
    # Print Success Message
    COMMAND ${CMAKE_COMMAND} -E echo "Standard Boot Image generated successfully: ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_VP/EINSTIEN4.0_VP.appimage.${DEVICE_TYPE}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)


add_dependencies(GenerateHsFs ${BINARY_NAME})
#######################################################
# Set klocwork platform streams 
set(USERNAME                   vsoci)
set(PASSWORD                   ChiPD008_123)
set(KLOCWORK_SERVER            https://kw.group4.visteon.com:8443)
set(KLOCWORK_PROJECT_NAME      VC_DI_E4.0-VIP_MY25_EP29141/VC_DI_EINSTEIN4.0_TI-REF_INT)

# Include klocwork script
include(${CMAKE_CURRENT_SOURCE_DIR}/klocwork.cmake)


#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User       |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Nov-2023  | NCHELLAP   |  PE4TI29141-713  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
