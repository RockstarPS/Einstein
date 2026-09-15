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

#VBuild Target Checks

set(VBUILD_SKIP_TARGET_CHECKS True)
# Set project information variables
set(${PROJECT_NAME}_DK_VERSION_MAJOR 0)
set(${PROJECT_NAME}_DK_VERSION_MINOR 1)
set(${PROJECT_NAME}_DK_VERSION_PATCH 0)

set(${PROJECT_NAME}_DK_VERSION ${${PROJECT_NAME}_DK_VERSION_MAJOR}.${${PROJECT_NAME}_DK_VERSION_MINOR}.${${PROJECT_NAME}_DK_VERSION_PATCH})
set(${PROJECT_NAME}_DK_BUILD_USER $ENV{USERNAME})

string(TIMESTAMP ${PROJECT_NAME}_DK_BUILD_TIMESTAMP "%Y-%m-%d %H:%M")
cmake_host_system_information(RESULT ${PROJECT_NAME}_DK_BUILD_HOSTNAME QUERY HOSTNAME)

set(BUILD_SOC_PLATFORM TI_AM62P)
set(OPTEE_SECURITYMANAGER       ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib)

if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
	set(BOARD_VAR e4_a1)
	add_definitions( -DBOOT_MODE_XSPI)

elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
	set(BOARD_VAR e4_a0)
	add_definitions( -DBOOT_MODE_SPI)
endif()

SET(CONAN_USER_HOME $ENV{TI_HOME})
# Options configuration
option(DK_DLT_ENABLED			"Set to ON/OFF to enable/disable DLT Integration"		ON)
option(BSPAL_DISPLAY_TESTS		"Set to ON/OFF to enable/disable Display bspal tests"	ON)
option(DK_VMF_ENABLED			"Set to ON/OFF to enable/disable VMF Integration"		ON)
option(DK_LOGGER_TESTS			"Set to ON/OFF to enable/disable logger tests"			OFF)
option(DK_RUNTIME_TESTS			"Set to ON/OFF to enable/disable runtime tests"			OFF)
option(DK_NETWORK_MGR_TESTS		"Set to ON/OFF to enable/disable network manager tests"	OFF)
option(OSAL_TESTS				"Set to ON/OFF to enable/disable osal tests"			OFF)
option(UCL_MESSAGE_API			"Set to OFF to disable UCL Message based IL"			ON)
option(UCL_ADAPTER_VMF			"Set to OFF to disable UCL VMF Adapter"					ON)
option(SUPPORT_AB_PARTITION     "Filesystem will have A/B partitions"                   ON)
option(BSPAL_DESER_TESTS        "Set to ON/OFF to enable/disable DESER test"            ON)

# Specify Platform name and endianess
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
	set(PLATFORM	${CMAKE_SYSTEM_PROCESSOR}le)
else()
	set(PLATFORM	${CMAKE_SYSTEM_PROCESSOR})
endif()

# Install paths configurations
set(CMAKE_INSTALL_PREFIX		${CMAKE_BINARY_DIR}/install/${PLATFORM})
set(CMAKE_INSTALL_BINDIR		usr/bin)
set(CMAKE_INSTALL_LIBDIR		usr/lib)
set(CMAKE_INSTALL_INCLUDEDIR	usr/include)

#set(GP_APPS_DIR				 ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/gp-apps)
set(GP_RTE_DIR					${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/runtime-gen)
set(BL_GP_RTE_DIR				${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-runtime-gen)
set(SIP_GEN_DIR					${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/someip-gen)

# Save original Python env
set(ENV{_OLD_PYTHON} "$ENV{PYTHON}")
set(ENV{_OLD_PYTHONPATH} "$ENV{PYTHONPATH}")
set(ENV{_OLD_LD_LIBRARY_PATH} "$ENV{LD_LIBRARY_PATH}")

# Override Python env for OPTEE-CMake
set(ENV{PYTHON} "/usr/bin/python3")
set(ENV{PYTHON3} "/usr/bin/python3")

# Including the optee-lib CMake which triggers its logic
include(${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib/opteelib.cmake)
include(${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib/optee.cmake)


set(Boost_LIBRARY_DIR ${CONAN_USER_HOME}/sysroots/aarch64-oe-linux/usr/lib)
set(Boost_INCLUDE_DIR ${CONAN_USER_HOME}/sysroots/aarch64-oe-linux/usr/include/boost)
set(DRM_INCLUDE_DIR ${CONAN_USER_HOME}/sysroots/aarch64-oe-linux/usr/include/drm)
set(WITH_VSOMEIP_V3_DEPEND		 TRUE)
set(VSOMEIP_INC_DIR ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/vsomeip/interface)
set(ZLIB_INCLUDE_DIR /opt/ti_sdk/linux-devkit/sysroots/aarch64-linux/usr/include/)

# Add support scripts
include(${CMAKE_CURRENT_SOURCE_DIR}/make/cmake/linux_bsp.cmake)

# Create header files based on variable settings
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/prebuilt_${BOARD_VAR}/usr/include/wdg_proxy_cfg.h ${CMAKE_BINARY_DIR}/install/usr/include/wdg_proxy_cfg.h COPYONLY)

add_link_options(-Wl,--no-whole-archive)
add_compile_options(-O2 -D_FORTIFY_SOURCE=2 -fstack-protector-strong)

# Set 3rd party configurations
set(WITH_DLT_USE_IPv6		OFF CACHE BOOL "Set to OFF to disable IPv6" FORCE)
set(WITH_MAN 			OFF CACHE BOOL "Set to OFF to disable man output" FORCE)
set(WITH_DLT_SYSTEM		 ON CACHE BOOL "Set to OFF to disable man output" FORCE)
set(WITH_SYSTEMD_JOURNAL	 ON CACHE BOOL "Set to OFF to disable man output" FORCE)
set(WITH_DLT_ADAPTOR 		 ON CACHE BOOL "Set to OFF to disable adapters" FORCE)
set(WITH_DLT_FILETRANSFER	 ON CACHE BOOL "Set to ON to build dlt-system with filetransfer support" FORCE)
set(WITH_DLT_CXX11_EXT		 ON CACHE BOOL "Set to ON to build C++11 extensions" FORCE)
set(WITH_DLT_TESTS		OFF CACHE BOOL "Set to ON to build src/test binaries" FORCE)
set(WITH_DLT_EXAMPLES		OFF CACHE BOOL "Set to ON to build src/examples binaries" FORCE)
set(BSPAL_DIO_TESTS		 ON CACHE BOOL "Set to OFF to disable tests" FORCE)
set(BSPAL_SIGUNIT_TESTS		 ON CACHE BOOL "Set to OFF to disable tests" FORCE)
set(DLT_IPC	"UNIX_SOCKET"   CACHE STRING "UNIX_SOCKET,FIFO" FORCE)

add_definitions(
	-DDEBUG_LOGGING_ENABLED
	-D_GNU_SOURCE
)

# Set paths to search for *Config.cmake files
add_search_paths(
	INCLUDE
	${CMAKE_SOURCE_DIR}/cluster-platform/software-update
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/gp-build/linux
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/runtime-gen
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-runtime-gen
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/mainhmi-app
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/safehmi-app
)

# Add binary scripts
binary_scripts(
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/vmf/bin/build_vmf.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/ucl/src/build_ucl.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/vsomeip/build_vsomeip.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/abstraction/osal/src/build_osal.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/logger/src/build_dk_logger.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/runtime/src/build_dk_runtime.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/metadata/src/build_metadata.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/power/src/power_mgr.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/display/display_mgr.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/health/src/build_dk_wdg_client.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/network/network_mgr.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/ucl-gen/ucl_proxy_vmf.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-ucl-gen/bl_ucl_proxy_vmf.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/mainhmi-app/rendercore/ui-app/uiappConfig.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/safehmi-app/build/build_safeHmi.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/abstraction/bspal/dio/build_dio_bspal.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/bl-app-gp/bl_app_gp.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/fota-app-gp/fota_app.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/gp-build/linux/boot-kpi/boot_kpi.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/gp-build/linux/boot-kpi/boot-kpi-logger/boot_kpi_logger.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/abstraction/bspal/display/build_display_bspal.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/vsomeip-gw/Gateway/srvgw_vsomeip.cmake
	# ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/health/src/build_dk_wdg_client.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/abstraction/bspal/sigunit/build_sigunit_bspal.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/abstraction/bspal/deserializer/build_deserializer_bspal.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/infrastructure/secure_qtd_mount/src/secure_qtd_mount.cmake
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/optee-security/securitymanager_test/securitymanager_test.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/meet-gp-app/meet_app.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/diag-app-gp/diag_app_gp.cmake
	#Enable PKCS11 Engine
    #${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/optee-security/pkcs11_test/pkcs11_test.cmake
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/dlt-gateway/dlt_gateway.cmake
	# Do not add below this line
	#${GP_APPS_DIR}/make/gp_apps.cmake
	)

add_custom_command(
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/OPTEE
	COMMAND ${OPTEE_SECURITYMANAGER}/scripts/copy-optee-securitymanager.sh ${OPTEE_SECURITYMANAGER} ${CMAKE_BINARY_DIR}/OPTEE

	WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}
	DEPENDS
		${OPTEE_SECURITYMANAGER}/scripts/copy-optee-securitymanager.sh
	OUTPUT
		${CMAKE_BINARY_DIR}/OPTEE
	COMMENT "Copying prebuilt OPTEE OS , client, required CA and TA"
)
add_custom_target(CopyOPTEE ALL DEPENDS ${CMAKE_BINARY_DIR}/OPTEE)
# Add global libraries and includes paths
link_directories(${CMAKE_INSTALL_PREFIX}/lib ${CMAKE_INSTALL_PREFIX}/usr/lib)
include_directories(
	${CMAKE_INSTALL_PREFIX}/include
	${CMAKE_INSTALL_PREFIX}/usr/include
	${CMAKE_CURRENT_SOURCE_DIR}/prebuilt_common/usr/include
	${CMAKE_CURRENT_SOURCE_DIR}/prebuilt_${BOARD_VAR}/usr/include
	)



set(USERNAME				vsoci)
set(PASSWORD				ChiPD008_123)
set(KLOCWORK_SERVER			https://kw.group4.visteon.com:8443)
set(KLOCWORK_PROJECT_NAME		VC_DI_E4.0-GIP_MY25_EP29141)
set(KLOCWORK_STREAM			VC_DI_E4.0-GIP_MY25_EP29141_INT)

# Include klocwork script
include(${CMAKE_CURRENT_SOURCE_DIR}/klocwork.cmake)

# Include doxygen script
#include(${CMAKE_CURRENT_SOURCE_DIR}/doxygen.cmake)

#-------------------------------------------------------------------------------------------------------------------
#	  Date	   |   User	  |	  Task	  |										Description
#-------------------------------------------------------------------------------------------------------------------
#  12/03/2025  | STHANGA4 |	   N/A	  | Added/Updated support for linux only build, build cmds updated
#-------------------------------------------------------------------------------------------------------------------
#  29/03/2024  | NSUBRAM2 |	   N/A	  | Added/Updated support for QNX
#-------------------------------------------------------------------------------------------------------------------
#  07/07/2023  |	MMK   |	   N/A	  | Created initial file from P33 program
#-------------------------------------------------------------------------------------------------------------------
