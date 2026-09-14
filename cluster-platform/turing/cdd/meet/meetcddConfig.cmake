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
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MeetMgr.diagcdd/src/Mgrdiagcdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Mem.diagCdd/src/Memdiagcdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Trace.diagCdd/src/Tracediagcdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Displaycontrol.diagcdd/src/Displaycontroldiagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Iocalib.diagcdd/src/Iocalibdiagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src/Ioctrlrd_analog_diagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src/Ioctrlrd_dio_diagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src/Ioctrlrd_pwm_diagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/CyberSec.diagCdd/src/Cybersecdiagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Reset.sleep.diagcdd/src/Resetsleepdiagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Comm.diagcdd/src/Commdiagcdd.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Osc.diagcdd/src/Oscdiagcdd.c 
	${CMAKE_CURRENT_SOURCE_DIR}/src/Eth.diagcdd/src/Ethdiagcdd.c
)

# Directories with header files to be shared
target_include_directories(${MODULE_NAME} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/MeetMgr.diagcdd/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Mem.diagCdd/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Trace.diagCdd/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Displaycontrol.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Iocalib.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Ioctrlread.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/CyberSec.diagCdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Reset.sleep.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Comm.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Osc.diagcdd/src
	${CMAKE_CURRENT_SOURCE_DIR}/src/Eth.diagcdd/src
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
	PRIVATE
	CmpLib
	Common
    GenBsw
	GenSwc
	GenMcal
	meetcdd
)


#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  9/21/2020  | RAZHAKES |  1055646   | Created initial file
#-------------------------------------------------------------------------------------------------------------------

