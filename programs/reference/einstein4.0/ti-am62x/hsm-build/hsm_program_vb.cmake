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

set(BOOKSHELF_PATH                  ${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm)
set(HSM_CFG_PATH                    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-cfg)
set(HSM_APP_PATH                    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app)

if(CMAKE_BUILD_TYPE STREQUAL debug )
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g --opt_for_speed=0 -O4 -pdr -pdew -pds=230 -pds=1463 --gen_func_subsections=on -me --display_error_number --diag_warning=255 --diag_wrap=off --common=off --unaligned_access=off")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")
else()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --symdebug:none --opt_for_speed=0 -O4 -pdr -pdew -pds=230 -pds=1463 --gen_func_subsections=on -me --display_error_number --diag_warning=255 --diag_wrap=off --common=off --unaligned_access=off")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --symdebug:none")
endif()

# Check if production_mode environment variable is defined
if(DEFINED ENV{PRODUCTION_MODE})
    if("$ENV{PRODUCTION_MODE}" STREQUAL "ON")
        message(STATUS "======= PRODUCTION_MODE IS SET ========")
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HS =====")
        set(DEVICE_TYPE "hs")
    else()
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HSFS =====")
        set(DEVICE_TYPE "hs_fs")
    endif()
else()
    message(STATUS "==== PRODUCTION_MODE OFF. COMPILING FOR DEVICE_TYPE HSFS =====")
    set(DEVICE_TYPE "hs_fs")
endif()

# Export DEVICE_TYPE to environment for Makefiles
set(ENV{DEVICE_TYPE} ${DEVICE_TYPE})

set(HSM_SIGN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Hsm_sign)
set(MAKEFILE_PATH ${HSM_SIGN_PATH}/HSMAppimageGen)

SET(SYSCONFIG_HOME $ENV{SYSCONFIG_HOME})
message("HSM sys ${SYSCONFIG_HOME}")

add_search_paths(
    INCLUDE
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/ti
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/app
    ${BOOKSHELF_PATH}/vhsm-cryptoApplication/m4
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-app/vHsmCryptoJobHandler/m4
    ${BOOKSHELF_PATH}/vIpc-driver/m4
    ${BOOKSHELF_PATH}/vhsm-timer
    ${BOOKSHELF_PATH}/vhsm-crypt
    ${BOOKSHELF_PATH}/vhsm-otpdrv
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-cfg
    ${BOOKSHELF_PATH}/vhsm-shutdown/m4
    ${BOOKSHELF_PATH}/vhsm-keystore
    ${BOOKSHELF_PATH}/vhsm-fw
    ${BOOKSHELF_PATH}/vhsm-wdg
    ${BOOKSHELF_PATH}/vdlt-hsm/m4
)

binary_script(${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-build/Hsmbinary.cmake  Hsmbinary)

add_custom_command(
    COMMAND ${CMAKE_C_COMPILER} -O0 --run_linker --disable_auto_rts --unused_section_elimination=on Hsmbinary.o ${COMPILER_PATH}/lib/libc.a ${CMAKE_CURRENT_SOURCE_DIR}/linkercmd/hsm_map.ld -m Hsmbinary.map -o hsm.elf
    COMMAND ${COMPILER_PATH}/bin/armstrip -pdew -p -o=hsm.stripped.elf hsm.elf
    COMMAND ${CMAKE_C_COMPILER} -I${COMPILER_PATH}/include -I${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/hsm-cfg ${CMAKE_CURRENT_SOURCE_DIR}/linkercmd/hsm_demo_bin.cmd.S --preproc_with_comment --output_file=hsm_bin.cmd
    COMMAND ${COMPILER_PATH}/bin/armhex -b --byte --image --zero --memwidth=8 --linkerfill -fill 0x00000000 -pdew --issue_remarks -q hsm_bin.cmd -map=hsm.bin.map -o hsm.bin hsm.elf
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary
    OUTPUT 
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.elf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.stripped.elf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm_bin.cmd
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.bin
    DEPENDS Hsmbinary.o
    COMMENT "== Generating HSM ELF file =="
)
add_custom_target(GenElf ALL 
    DEPENDS 
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.elf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.stripped.elf
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm_bin.cmd
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binaries/Hsmbinary/hsm.bin
)


add_custom_command(
    TARGET GenElf
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env DEVICE_TYPE=${DEVICE_TYPE} CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY} HSM_SIGN_PATH=${HSM_SIGN_PATH} SYSCONFIG_PATH=${SYSCONFIG_HOME} make -s -f ${MAKEFILE_PATH}/makefile 
    COMMENT "Generating HSM ${DEVICE_TYPE} Image"
)
# Set klocwork platform streams 
set(USERNAME                   vsoci)
set(PASSWORD                   ChiPD008_123)
set(KLOCWORK_SERVER            https://kw.group4.visteon.com:8443)
set(KLOCWORK_PROJECT_NAME      VC_DI_EINSTEIN_HSM)
set(KLOCWORK_STREAM            VC_DI_E4.0_HSM_EP29141_INT)

# Include klocwork script
include(${CMAKE_CURRENT_SOURCE_DIR}/klocwork.cmake)
#-------------------------------------------------------------------------------------------------------------------
#    Date     |     User    |   Task           |   Description
#-------------------------------------------------------------------------------------------------------------------
#  28/08/2024 |    KJOHN    |  PE4TI29141-3287 |  HSM Build Base
#-------------------------------------------------------------------------------------------------------------------
#  29/08/2024 |    KJOHN    |  PE4TI29141-4403 |  HSM HS_FS Image
#-------------------------------------------------------------------------------------------------------------------
#  02/09/2024 |    KJOHN    |  PE4TI29141-4415 |  HSM 128KB Image
#-------------------------------------------------------------------------------------------------------------------