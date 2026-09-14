#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# 
#
#
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
message(STATUS "BL open")

set(HSM_APP_PATH                    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app)

SET (SYSCONFIG_HOME $ENV{SYSCONFIG_HOME})
set (SW_VERSION 0x0A010021)

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

# Install paths configurations
set (CMAKE_CPU_FAMILY             ti)
set (CMAKE_SYSTEM_FAMILY          ti)
set (CMAKE_SYSTEM_CPU             cortexr5)
set (CMAKE_SYSTEM_PROCESSOR       arm)
set (DISPCDD_VAR "PLATFORM_4_0")
set (CMAKE_CPU_FAMILY_SERIES      am62p)

# Set paths to search for *Config.cmake files
add_search_paths(
    INCLUDE
    # Platform paths
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-build
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-app/bl
    ${CMAKE_SOURCE_DIR}/cluster-platform/software-update/fbl/autosar/update-cdd
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/mcal
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-mcal-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-bsw-gen
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-update-client
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-ucl-gen
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vIpc-driver/r5
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-shutdown/r5
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-cryptoApplication/r5
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/vHsmCryptoJobHandler/r5
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-cryptodriver
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/vHsmSWCrypto
)

# Add binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/dummy.c	
)

# target_compile_options(${BINARY_NAME} PUBLIC
add_compile_options(
    -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16 -mthumb -Wall -g -Wno-gnu-variable-sized-type-not-at-end -Wno-unused-function
    -march=armv7-r
    -fno-stack-protector 
    -c -O0 -mlittle-endian -std=c99 -MD -fno-rtti -fdata-sections -fcommon -ffunction-sections -flto -finline-functions -munaligned-access
	-Wno-incompatible-pointer-types
)

target_compile_definitions(${BINARY_NAME}
    PUBLIC
    AUTOSAR_431
    BUILD_MCU0_0
    BUILD_MCU
    SOC_AM62PX
    SOC_AM62P
    # AUTOSAR_ETH_ENABLE
    PMIC_WDG_DISABLE
)

# Set extencion for the generated binary
#set_target_properties(${BINARY_NAME} PROPERTIES SUFFIX ".elf")
set_target_properties(${BINARY_NAME} PROPERTIES SUFFIX ".out")
message(STATUS "BL open")
# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PUBLIC
	BlApps
	BlUclVpGen
	FblGenMcal
    FblPlatformStubs
	
)


# Add linker file
target_link_options(${BINARY_NAME} PRIVATE
	-Wl,--ram_model -Wl,--no_demangle -Wl,--diag_wrap=on -Wl,--reread_libs -Wl,--diag_warning -Wl,--extract-dwo -Wl,--zero_init=ON -Wl,--mapfile_contents=all -Wl,
    ${CMAKE_CURRENT_SOURCE_DIR}/tgt/linker_r5.lds
)

#Generate HsFs
set(ECHO_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_BL/EINSTIEN4.0_BL.appimage.${DEVICE_TYPE}")

# Find any Python version
find_package(Python COMPONENTS Interpreter REQUIRED)

add_custom_target(GenerateHsFs ALL
    # Convert ELF to RPRC with SW_VERSION
    COMMAND ${SYSCONFIG_HOME}/nodejs/node ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/out2rprc/elf2rprc.js
            ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_BL/EINSTIEN4.0_BL.out ${SW_VERSION} >> ${CMAKE_CURRENT_BINARY_DIR}/bootimage_temp_out.txt
    # Generate the Multi-core Image (standard, non-XIP)
    COMMAND ${SYSCONFIG_HOME}/nodejs/node ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/multicoreImageGen/multicoreImageGen.js --devID 55 --out EINSTIEN4.0_BL.appimage EINSTIEN4.0_BL.rprc@5 >> ${CMAKE_CURRENT_BINARY_DIR}/bootimage_temp_out.txt
    # Sign the generated image with SW_VERSION used as the key version
    COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/HS_FS_Signing_Boot_10_1/signing/appimage_x509_cert_gen.py --bin EINSTIEN4.0_BL.appimage --authtype 0 --loadaddr 83200000 --key ${SIGNING_KEY} --output ${ECHO_OUTPUT} --keyversion 1.5
    # Clean up temporary files
    COMMAND ${CMAKE_COMMAND} -E remove EINSTIEN4.0_BL.appimage
    COMMAND ${CMAKE_COMMAND} -E remove EINSTIEN4.0_BL.rprc
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_BL/bootimage_temp_out.txt
    # Print Success Message
    COMMAND ${CMAKE_COMMAND} -E echo "Standard Boot Image generated successfully: ${CMAKE_CURRENT_BINARY_DIR}/EINSTIEN4.0_BL/EINSTIEN4.0_BL.appimage.${DEVICE_TYPE}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_dependencies(GenerateHsFs ${BINARY_NAME})

# Set klocwork platform streams 
set(USERNAME                   vsoci)
set(PASSWORD                   ChiPD008_123)
set(KLOCWORK_SERVER            https://kw.group4.visteon.com:8443)
set(KLOCWORK_PROJECT_NAME      VC_DI_E4.0-VIP_MY25_EP29141)
set(KLOCWORK_STREAM            VC_DI_E4.0-VIP_MY25_EP29141_INT)
# Include klocwork script
include(${CMAKE_CURRENT_SOURCE_DIR}/klocwork.cmake)
#-------------------------------------------------------------------------------------------------------------------
#    Date           |   User        |       Task        |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28-Nov-2023  | NCHELLAP   |  PE4TI29141-713  |  Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------

