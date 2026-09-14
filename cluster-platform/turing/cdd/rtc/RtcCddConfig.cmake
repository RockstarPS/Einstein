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

if(RTCCDD_VAR STREQUAL IMX8QXP)
    # Create library target
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Imx8/RtcDrvCdd_IMX8QXP.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcIfCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcMgrCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Imx8/RtcDrvCdd_TemperatureCompensation_IMX8QXP.c
    )

elseif(RTCCDD_VAR STREQUAL RA8900CE)
    # Create library target
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcDrvCdd_RA8900CE.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcDrvCdd_I2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcIfCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcMgrCdd.c
    )

elseif(RTCCDD_VAR STREQUAL RA8804CE)
    # Create library target
    add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RA8804CE/RtcDrvCdd_RA8804CE.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RA8804CE/RtcDrvCdd_I2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcIfCdd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcMgrCdd.c
    )
elseif(RTCCDD_VAR STREQUAL PCA2131)
	# Create library target
	add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
		${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcCdd.c
		${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcDrvCdd_PCA2131.c
		${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcIfCdd.c
		${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcMgrCdd.c
)	
elseif(RTCCDD_VAR STREQUAL TRAVEO2)
	# Create library target
	add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Traveo2/RtcDrvCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Traveo2/RtcDrvCdd_Irq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcIfCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RtcMgrCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Traveo2/RtcDrvCdd_TemperatureCompensation.c

)
endif()

# Directories with header files to be shared
if(RTCCDD_VAR STREQUAL TRAVEO2)
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Traveo2
)

elseif(RTCCDD_VAR STREQUAL IMX8QXP)
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/Imx8
)
elseif(RTCCDD_VAR STREQUAL RA8804CE)
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src/RA8804CE
)

else()
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src
)
endif()

if(RTCCDD_VAR STREQUAL IMX8QXP)
    # Add dependency libraries
    target_add_dependencies(${MODULE_NAME}
        PRIVATE
        Common
        CmpLib
        GenBsw
        GenSwc
        GenMcal
        MathLib
        Scfw
        Port
    )
elseif(RTCCDD_VAR STREQUAL RA8900CE)
    # Add dependency libraries
    target_add_dependencies(${MODULE_NAME}
        PRIVATE
        Common
        CmpLib
        GenBsw
        GenSwc
        GenMcal
	    I2cDrv
    )
elseif(RTCCDD_VAR STREQUAL RA8804CE)
    # Add dependency libraries
    target_add_dependencies(${MODULE_NAME}
        PRIVATE
        Common
        CmpLib
        GenBsw
        GenSwc
        GenMcal
	    I2cDrv
    )
elseif(RTCCDD_VAR STREQUAL PCA2131)
    # Add dependency libraries
    target_add_dependencies(${MODULE_NAME}
		PRIVATE
		Common
		CmpLib
		GenBsw
		GenSwc
		MathLib
		AssertLib
		EcuMExt
		Scfw
		Port
	)
elseif(RTCCDD_VAR STREQUAL TRAVEO2)
# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    Common
    GenBsw
    GenSwc
    MathLib
    AssertLib
    EcuMExt
    CmpLib
)
endif()

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  9/04/2020  | RMITEV   |  1037227  | Add CMAKE files
#-------------------------------------------------------------------------------------------------------------------
