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

# Add files depending on the CMAKE_SYSTEM_PROCESSOR
if(CMAKE_SYSTEM_CPU STREQUAL cortexm7)
    set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/cortexm7/OsAsm.arm)
    set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/cortexm7)
    set(compiler_files           ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS/OsHal_Compiler.c)
    set(compiler_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS)
elseif( (CMAKE_SYSTEM_CPU STREQUAL cortexm4f) AND (CMAKE_SYSTEM_FAMILY STREQUAL tv2) )
#Check if traveo2 is configured
    set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU}/OsAsm.arm)
    set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU})
    set(compiler_files           ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS/OsHal_Compiler.c)
    set(compiler_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS)
elseif( (CMAKE_SYSTEM_CPU STREQUAL cortexr5) AND (CMAKE_SYSTEM_FAMILY STREQUAL ti) )
#Check if ti is configured
    set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU}/OsAsm.S)
    set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU})
    set(compiler_files           ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/CLANG/OsHal_Compiler.c)
    set(compiler_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/CLANG)
elseif( (CMAKE_SYSTEM_CPU STREQUAL cortexm0plus) AND (CMAKE_SYSTEM_FAMILY STREQUAL ti) )
#Check if ti-mspm0p is configured
    set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU}/OsAsm.S)
    set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU})
    set(compiler_files           ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/CLANG/OsHal_Compiler.c)
    set(compiler_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/CLANG)
else()
    set(processor_files          ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU}/OsAsm.arm)
    set(processor_header_paths   ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU})
    set(compiler_files           ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS/OsHal_Compiler.c)
    set(compiler_header_paths    ${CMAKE_CURRENT_SOURCE_DIR}/hal/compiler/GHS)
endif()

if(CMAKE_CPU_FAMILY STREQUAL tv2)
    set(controller_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/tv2/OsHal_CpuDerivative.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/tv2/${CMAKE_CPU_FAMILY_SERIES}/OsHal_CpuDerivative_Int.c
       )
    set(controller_header_paths
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/tv2
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/tv2/${CMAKE_CPU_FAMILY_SERIES}
        )
elseif(CMAKE_CPU_FAMILY STREQUAL imx)
    set(controller_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/imx/${CMAKE_CPU_FAMILY_SERIES}/OsHal_CpuDerivative.c
        )
    set(controller_header_paths
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/imx/${CMAKE_CPU_FAMILY_SERIES}
        )
elseif(CMAKE_CPU_FAMILY STREQUAL ti)
    set(controller_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/ti/${CMAKE_CPU_FAMILY_SERIES}/OsHal_CpuDerivative.c
        )
    set(controller_header_paths
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/ti/${CMAKE_CPU_FAMILY_SERIES}
        )
else()
    set(controller_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/${CMAKE_CPU_FAMILY_SERIES}/OsHal_CpuDerivative.c
        )
    set(controller_header_paths
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/${CMAKE_CPU_FAMILY_SERIES}
        )
endif()

#Add files depending on the Core used whether cortex R or cortex M
if(CMAKE_SYSTEM_CPU STREQUAL cortexr5)
    set(common_derivative_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/OsHal_CpuDerivative_CortexR_Common.c
        )
else()
    set(common_derivative_files
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/cpu/OsHal_CpuDerivative_CortexM_Common.c
        )
endif()


# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsAlarm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsApi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsApplication.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsCore.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsCounter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsError.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsEvent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsMain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsMemProtection.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsMessage.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsMetrics.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsSched.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/OsRes.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsScheduleTable.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsStart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsTask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsTime.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OsTrap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/core/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_CPU}/OsHal_CpuCore.c
    ${processor_files}
    ${controller_files}
    ${common_derivative_files}
    ${compiler_files}
)

#Add target compile definition
if((CMAKE_SYSTEM_FAMILY STREQUAL tv2) OR (CMAKE_SYSTEM_FAMILY STREQUAL imx8) OR ((CMAKE_SYSTEM_CPU STREQUAL cortexr5) AND (CMAKE_SYSTEM_FAMILY STREQUAL ti)))
target_compile_definitions(${MODULE_NAME}
    PUBLIC
    -DOS_PRIVILEGE_USER_ENABLE
)
endif()

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/mcal/traveo2/startup/hdr/rev_a
    ${CMAKE_SOURCE_DIR}/cluster-platform/turing/mcal/traveo2/startup/hdr/rev_a/ip
    ${processor_header_paths}
    ${controller_header_paths}
    ${compiler_header_paths}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
    GenBsw
    #Main
    PRIVATE
    PlatformStubs
    GenMcal
    AssertLib
    #Startup
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
