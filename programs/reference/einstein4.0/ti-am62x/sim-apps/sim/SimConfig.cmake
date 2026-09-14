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



# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/NvmStubs.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/CanStub.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/VectorCANSim.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/xlLoadlib.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/PortSim.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/DcmSim.c
)

target_include_directories(${MODULE_NAME}
    PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ecumext/src
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bsw-gen/bsw/com
    ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/nvmext/src/src
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/vp-build/stubs
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/vp-build/stubs/Bsw_Stubs/AsrGnrl/inc
	${CMAKE_SOURCE_DIR}/cluster-platform/turing/vautosar/Autosar-4_3/com/can/CanIf/include
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
	Sim
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
