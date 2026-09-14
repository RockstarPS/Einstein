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
if(DISPCDD_VAR STREQUAL IMXRT)
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayMgrCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayIfCdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/ImxRT/DisplayDrvCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ImxRT/DisplayI2CDrvCdd.c 	
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/ImxRT
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
	PRIVATE
	Common
	GenSwc
	GenBsw
	GenMcal
	PlatformStubs
	CmpLib
	Rte
	I2c
)

elseif(DISPCDD_VAR STREQUAL TRAVEO2)

add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayMgrCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayIfCdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Traveo2/DisplayDrvCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Traveo2/DisplayI2CDrvCdd.c 	
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Traveo2
)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
	PRIVATE
	Common
	GenSwc
	GenBsw
	GenMcal
	PlatformStubs
	CmpLib
	I2cDrv
	#SDLInterface
	#Rte
)

elseif(DISPCDD_VAR STREQUAL AM62X)
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayMgrCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DisplayIfCdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Am62x/DisplayDrvCdd.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Am62x/
)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
	PRIVATE
	Common
	GenSwc
	GenBsw
	GenMcal
	PlatformStubs
	CmpLib
)
endif()

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  07/21/2020  | RGHOAEL |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  01/28/2022  | YVISWANA            | Fixed build dependency issues
#-------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
#  08/04/2023  | VVIJAYA5            | Fixed build dependency.
#-------------------------------------------------------------------------------------------------------------------
