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

# Select service profile default based on current platform family.
if(NOT DEFINED FLTM_SERVICE_PROFILE)
    if(CMAKE_CPU_FAMILY STREQUAL "ti")
        set(FLTM_SERVICE_PROFILE E4)
    elseif(CMAKE_CPU_FAMILY STREQUAL "tv2")
        set(FLTM_SERVICE_PROFILE TV2)
    else()
        message(FATAL_ERROR "Unsupported CMAKE_CPU_FAMILY for FltM service profile selection: ${CMAKE_CPU_FAMILY}")
    endif()
endif()

# Select SoC profile default explicitly so service-profile selection and SoC
# source selection can evolve independently.
if(NOT DEFINED FLTM_SOC_PROFILE)
    if(CMAKE_CPU_FAMILY STREQUAL "ti")
        set(FLTM_SOC_PROFILE TI)
    else()
        message(FATAL_ERROR "Unsupported CMAKE_CPU_FAMILY for FltM SoC profile selection: ${CMAKE_CPU_FAMILY}")
    endif()
endif()

if(FLTM_SOC_PROFILE STREQUAL "TI")
    set(controller_files
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_Irq.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_Dcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_Ecc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_Pok.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_Ppu.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_FlsIntegrity.c
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src/FltM_Soc_PeriodicReadBack.c
       )
    set(controller_header_paths
        ${CMAKE_CURRENT_SOURCE_DIR}/fltm_soc/ti/src
        )
else()
    message(FATAL_ERROR "Unsupported FLTM_SOC_PROFILE='${FLTM_SOC_PROFILE}'. Supported values: TI")
endif()

if(FLTM_SERVICE_PROFILE STREQUAL "E4")
    set(fltm_service_file
        ${CMAKE_CURRENT_SOURCE_DIR}/FltM_Service_E4.c
       )
elseif(FLTM_SERVICE_PROFILE STREQUAL "TV2")
    set(fltm_service_file
        ${CMAKE_CURRENT_SOURCE_DIR}/FltM_Service_Tv2.c
       )
else()
    message(FATAL_ERROR "Unsupported FLTM_SERVICE_PROFILE: ${FLTM_SERVICE_PROFILE}")
endif()


# Create library target with specified files
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/FltM.c
    ${fltm_service_file}
	${controller_files}

)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${controller_header_paths}
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
	PRIVATE
	GenBsw
	GenSwc
	McuSdk
)


#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  26/02/2025 | sdv      |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
