#---------------------------------------------------------------------------------------------------------------------
# VISTEON CORPORATION CONFIDENTIAL - x86 MinGW-GCC Configuration Extract
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
# Extracted x86/MinGW-GCC specific configuration from vp_platform.cmake
# This file contains all relevant settings for x86 processor with MinGW-GCC toolchain
#---------------------------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.14)

# Build all libraries as STATIC by default
#set(BUILD_SHARED_LIBS OFF)

set(VBUILD_SKIP_TARGET_CHECKS TRUE)

#======================================= MICRO PART CONFIGURATIONS =========================================================================
set(OEM 		"reference")
set(MODEL_YEAR 	"einstein4.0")
set(PROGRAM  	"ti-am62x")
set(DISPLAY_VAR "VIP_CONTROLLED_DISPLAY")
set(DISPCDD_VAR                     "PLATFORM_4_0")

#======================================= PATH CONFIGURATIONS ==============================================================================
set(PROGRAM_FOLDER             				${CMAKE_SOURCE_DIR}/programs/${OEM}/${MODEL_YEAR}/${PROGRAM})
set(MCAL_FOLDER             				${CMAKE_SOURCE_DIR}/cluster-platform/turing/mcal)
set(CDD_FOLDER			 				    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd)

# x86-specific processor configuration (from original if block)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL x86)
	set (MCALS     							${PROGRAM_FOLDER}/sim-apps/mcal)
	set (MCAL_GEN  							" ")
	set (SIM_APPS  							${PROGRAM_FOLDER}/sim-apps/sim)
	set (SIM_OS    							${PROGRAM_FOLDER}/sim-apps/os)
	set (SIMULATION_STUBS     				Sim)
    set (EXCLUDE_COMP  						${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem
                                            ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/mos/src
                                            ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/SNvM
                                            ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/NvM
                                            ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/Ea
                                            ${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/Memif
											${MCAL_FOLDER}/am62x-sitara
											${MCAL_FOLDER}/ti/am62p-pkgv11-010103

		)
	set(MINGW_GCC TRUE)
	set(VBUILD_DEFAULT_LIBS_STATIC 1)
# Prevent MinGW ld from opening too many files
    set_property(GLOBAL PROPERTY JOB_POOLS single_job=1)
    set(CMAKE_JOB_POOL_LINK single_job)
 
else()
	message(FATAL_ERROR "This configuration is specifically for x86 processor with MinGW-GCC toolchain")
endif()

#======================================= SEARCH PATHS CONFIGURATION ========================================================================
add_search_paths(
    INCLUDE
    # Platform paths
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/swccore/swc-core-dmnmgr
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl
    ${MCALS}
	${SIM_APPS}
	${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs
    ${PROGRAM_FOLDER}/bsw-gen
	${PROGRAM_FOLDER}/swc-gen
    ${PROGRAM_FOLDER}/ecumext
    ${PROGRAM_FOLDER}/nvmext
	# ${PROGRAM_FOLDER}/fltmext
	${PROGRAM_FOLDER}/dltext
	${PROGRAM_FOLDER}/commext
	${PROGRAM_FOLDER}/wdgmext
	${PROGRAM_FOLDER}/ecuappm-callouts
	${PROGRAM_FOLDER}/ucl
	${PROGRAM_FOLDER}/ucl-gen
	${PROGRAM_FOLDER}/hsm-app/vHsmCryptoJobHandler/r5
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-shutdown/r5
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vIpc-driver/r5
	${PROGRAM_FOLDER}/di-apps
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vhsm-cryptodriver
	${PROGRAM_FOLDER}/update-client
	${PROGRAM_FOLDER}/xf-gen
	${PROGRAM_FOLDER}/hsm-app/vHsmSWCrypto
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/hsm/vdlt-hsm/r5
    ${SIM_OS}
    EXCLUDE
    ${EXCLUDE_COMP}
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd/EcuPowerM
)

#======================================= x86 EXECUTABLE CONFIGURATION =======================================================================
# x86 MinGW-GCC Executable configuration
set(COMPILERFLAGS -m32 -c -std=c99 -DWIN_32 -DDYNAMIC_XLDRIVER_DLL -fpermissive)

set(BUILD_SHARED_LIBS FALSE CACHE STRING "Library type: STATIC or SHARED" FORCE)

add_executable(${BINARY_NAME}
	${SIM_APPS}/src/Simmain.c
)

# Set Windows executable extension
set_target_properties(${BINARY_NAME} PROPERTIES SUFFIX ".exe")

# x86-specific compile definitions
target_compile_definitions(${BINARY_NAME}
	PUBLIC
	VCONST=const
	AUTOSAR_431
    BUILD_MCU0_0
    BUILD_MCU
    SOC_AM62PX
    SOC_AM62P
	SIMULATION_BUILD
	__ILP32__
	OS_PRIVILEGE_USER_ENABLE
	-DBUILD_SHARED_LIBS=OFF
)

# Apply compiler flags
target_compile_options(${BINARY_NAME}
	PUBLIC
	${COMPILERFLAGS}
)

#======================================= x86 INCLUDE DIRECTORIES =============================================================================
target_include_directories(${BINARY_NAME}
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/stubs/Bsw_Stubs/AsrGnrl/inc
	${CMAKE_CURRENT_SOURCE_DIR}/stubs/Bsw_Stubs/Det/inc
	${CMAKE_CURRENT_SOURCE_DIR}/stubs/Bsw_Stubs/MemMap/inc
	${CMAKE_CURRENT_SOURCE_DIR}/stubs/Bsw_Stubs/Rte/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs
	${CMAKE_CURRENT_SOURCE_DIR}/includes
	${PROGRAM_FOLDER}/bsw-gen/Project/Appl/GenData
	${PROGRAM_FOLDER}/bsw-gen/Project/Appl/GenData/Components
	${PROGRAM_FOLDER}/bsw-gen/bsw/os
	${PROGRAM_FOLDER}/bsw-gen/bsw/bswm
	${PROGRAM_FOLDER}/bsw-gen/bsw/NvM
	${PROGRAM_FOLDER}/bsw-gen/bsw/crc
	${PROGRAM_FOLDER}/bsw-gen/bsw/ecum
	${PROGRAM_FOLDER}/bsw-gen/bsw/com
	${PROGRAM_FOLDER}/bsw-gen/bsw/commext
	${PROGRAM_FOLDER}/bsw-gen/bsw/diag
	${PROGRAM_FOLDER}/bsw-gen/bsw/amd
	${PROGRAM_FOLDER}/bsw-gen/bsw/det
	${PROGRAM_FOLDER}/bsw-gen/bsw/dlt
	${PROGRAM_FOLDER}/bsw-gen/private
	${PROGRAM_FOLDER}/swc-gen/gen
	${PROGRAM_FOLDER}/nvmext/src
	${PROGRAM_FOLDER}/mcal-gen/DssCfg
	${PROGRAM_FOLDER}/mcal-gen/I2cCfg
	${PROGRAM_FOLDER}/mcal-gen/IcuCfg
	${PROGRAM_FOLDER}/mcal-gen/LinCfg
	${PROGRAM_FOLDER}/mcal-gen/output/include
	${PROGRAM_FOLDER}/mcal-gen/PortDrvCfg/VIP_Early_HMI
	${PROGRAM_FOLDER}/mcal-gen/PwmCfg
	${PROGRAM_FOLDER}/mcal-gen/SciDrvCfg
	${PROGRAM_FOLDER}/mcal-gen/SysconfigGeneratedDpl/
	${PROGRAM_FOLDER}/ecumext/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/mos/src/includes
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/mos/src/hal/compiler/CLANG
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/ecum/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/bswm/src/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/crc/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/amd/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/diag/dem/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/diag/dcm/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanIf/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanNm/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanSM/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanTp/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanTrcv/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/Com/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/ComM/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/IpduM/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/Nm/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/PduR/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/SecOC/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/services/Xcp/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/Ea/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/Fee/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/Memif/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/NvM/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/mem/src/SNvM/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/e2e/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/e2exf/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/det/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/sys/dlt/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/sys/wdgm/src/WdgIf/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/sys/wdgm/src/WdgM/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw/tmext/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw/iohwab/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw/EcuAppM/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/bsw/EcuAppM/include
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib/memlib/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib/assertlib/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/lib/cmplib/src/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/swccore/swc-core-dmnmgr/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd/fltm/src/fltm_soc/ti/src
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd/fltm/src
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/fltmext/src/src
	${MCALS}
	${MCALS}/hw_include
	${MCALS}/hw_include/soc/j722s/src
	${MCALS}/hw_include/am62px
	${MCALS}/hw_include/arch/r5
	${MCALS}/mcusdk
	${MCALS}/mcusdk/drivers/hw_include
	${MCALS}/mcusdk/drivers/sciclient/include/tisci/am62px
	${MCALS}/mcusdk/drivers/fvid2
	${MCALS}/mcusdk/drivers/pinmux/am62px
	${MCALS}/mcusdk/sdl
	${MCALS}/mcusdk/sdl/esm/soc/am62px
	${MCALS}/mcusdk/drivers/soc/am62px
	${MCALS}/board/flash/inc
	${MCALS}/Can
	${MCALS}/Can/src
	${MCALS}/Can/include
	${MCALS}/CddIpc/ipc_baremetal_hw
	${MCALS}/CddIpc/ipc_baremetal_hw/include
	${MCALS}/CddIpc/ipc_baremetal_hw/src
	${MCALS}/CddIpc
	${MCALS}/CddIpc/src
	${MCALS}/CddIpc/include
	${MCALS}/Dio
	${MCALS}/Dio/src
	${MCALS}/Dio/include
	${MCALS}/Dio/dio_hw/V0
	${MCALS}/Eth
	${MCALS}/EthTrcv
	${MCALS}/Fls
	${MCALS}/Fls/src
	${MCALS}/Fls/include
	${MCALS}/Gpt
	${MCALS}/Gpt/src
	${MCALS}/Gpt/include
	${MCALS}/i2cdrv
	${MCALS}/i2cdrv/src/src
	${MCALS}/icudrv
	${MCALS}/icudrv/src/src
	${MCALS}/include
	${MCALS}/lin
	${MCALS}/lin/src/src
	${MCALS}/Mcu
	${MCALS}/Mcu/include
	${MCALS}/portdrv
	${MCALS}/portdrv/src/src
	${MCALS}/Pwm
	${MCALS}/Pwm/include
	${MCALS}/Pwm/src
	${MCALS}/scidrv/src/src
	${MCALS}/Spi
	${MCALS}/Spi/src
	${MCALS}/Spi/include
	${MCALS}/Wdg
	${MCALS}/Wdg/src
	${MCALS}/Wdg/include
	${MCALS}/startup
	# ${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd/EcuPowerM/include
	# ${CMAKE_SOURCE_DIR}/cluster-platform/turing/cdd/EcuPowerM/src
	${SIM_OS}
	${SIM_OS}/x86
	${SIM_APPS}/src
	${SIM_APPS}/EcuPowerM/include
	${SIM_APPS}/EcuPowerM/src
)

#======================================= BINARY DEPENDENCIES =================================================================================
target_add_dependencies(${BINARY_NAME}
    PRIVATE
	${SIMULATION_STUBS}
	DiApps
	NvMExt
	PlatformStubs
)
