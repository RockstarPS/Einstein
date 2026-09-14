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

# Create Binary
(
	${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmIpc.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/vHsmIpcMain.c
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
	GenRuntime
	dk_logger
	dk_runtime
	bspal_sys_shutdown
)
if(${CMAKE_SYSTEM_NAME} STREQUAL QNX)
target_link_libraries(${BINARY_NAME}
	PRIVATE
	ham
	mq
	slog2
)
endif()

target_include_directories(${BINARY_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/system_state
	${GP_RTE_DIR}/gip/src/applications/power_mgr
    ${GP_RTE_DIR}/gip/src/components/health_mgr_component
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 10/05/2020  | KSHANMU4 |           | Created initial file
#-------------------------------------------------------------------------------------------------------------------