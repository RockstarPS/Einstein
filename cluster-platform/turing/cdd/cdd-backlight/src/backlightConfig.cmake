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

# Create library target with specified files

if(BACKLIGHTCDD_VAR STREQUAL LP8867)
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Backlightcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/BacklightCdd_ErrorHandler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CDD_Backlight.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib_src/LP8867/BacklightDrvCdd.c
	)
elseif(BACKLIGHTCDD_VAR STREQUAL MAX20446B)
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
	${CMAKE_CURRENT_SOURCE_DIR}/src/Backlightcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/BacklightCdd_ErrorHandler.c
   ${CMAKE_CURRENT_SOURCE_DIR}/src/CDD_Backlight.c
	${CMAKE_CURRENT_SOURCE_DIR}/lib_src/MAX20446/BacklightDrvCdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/lib_src/MAX20446/BacklightDrvCdd_I2C.c
	${CMAKE_CURRENT_SOURCE_DIR}/lib_src/MAX20446/BacklightDrvCdd_I2C_MAX20446.c
	)
else()
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
 	${CMAKE_CURRENT_SOURCE_DIR}/src/Backlightcdd.c
 	${CMAKE_CURRENT_SOURCE_DIR}/src/BacklightCdd_ErrorHandler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CDD_Backlight.c
    )
endif()




# Directories with header files to be shared
if(BACKLIGHTCDD_VAR STREQUAL LP8867)
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/lib_include/LP8867
    )
elseif(BACKLIGHTCDD_VAR STREQUAL MAX20446B)
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/lib_include/MAX20446
    )
else()
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)
endif()
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    Common
    CmpLib
    GenSwc
    GenBsw
    Dio
    Pwm
    PlatformStubs
	GenMcal
	I2cDrv
    EcuPowerM
)

 
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  07/21/2020  | RGHOAEL |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------

