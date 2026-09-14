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

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/klocwork)
SET(KLOCWORK_HOME $ENV{KLOCWORK_HOME})
SET(KLOCWORK_TABLES_DIR $ENV{BUILD_BASE_LOCATION})

add_custom_target(gp_kw_build DEPENDS ${CMAKE_BINARY_DIR}/klocwork
	COMMENT "Running Klocwork Analysis for All files" VERBATIM
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/klocwork/
)
#Custom command for the Klocwork
add_custom_command(
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} -- -t clean all
	COMMAND ${KLOCWORK_HOME}/bin/kwinject --overwrite --ignore-files */CMakeTmp/* --cache-files "*.c,*.h" --output ${CMAKE_BINARY_DIR}/klocwork/gpinject.out ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
	COMMAND ${KLOCWORK_HOME}/bin/kwbuildproject --replace-path ${CMAKE_SOURCE_DIR}=EU-TI-AM62X-EVK-IC --url ${KLOCWORK_SERVER}/${KLOCWORK_PROJECT_NAME} --incremental  --exclude-issues ${CMAKE_CURRENT_SOURCE_DIR}/klocwork.sconf	--tables-directory ${CMAKE_SOURCE_DIR}/${KLOCWORK_TABLES_DIR}/out/fda/GP_Tables ${CMAKE_BINARY_DIR}/klocwork/gpinject.out
	COMMAND ${KLOCWORK_HOME}/bin/kwadmin --url ${KLOCWORK_SERVER} load ${KLOCWORK_PROJECT_NAME}/${KLOCWORK_STREAM} ${CMAKE_SOURCE_DIR}/${KLOCWORK_TABLES_DIR}/out/fda/GP_Tables
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/klocwork/
	USES_TERMINAL
	OUTPUT ${CMAKE_BINARY_DIR}/klocwork
	COMMENT "Building Klocwork Project"
)
