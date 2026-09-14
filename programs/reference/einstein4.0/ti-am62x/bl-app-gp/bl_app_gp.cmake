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
add_executable(${BINARY_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/bl_upd_ucl_adapter_component/src/bl_upd_ucl_adapter_component.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bl_upd_ucl_adapter_component/src/SharedMem.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bl_upd_doip_adapter_component/src/bl_upd_doip_adapter_component.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/bl_einstein_uds_app_component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_manager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_session_management_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_io_control_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_routine_control_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_data_identifier_handler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_download_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/dk_srvc_uds_service_ecu_reset_handler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/FlashHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/PartitionHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UpdateHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/updLocalUpdater.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UPDd.c
	${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UPDd_BootControl.c
	${BL_GP_RTE_DIR}/gip/src/applications/bl_app_gp/bl_app_gp.cpp
	${BL_GP_RTE_DIR}/gip/src/applications/bl_app_gp/main.cpp
	
	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/doip_component.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/infra_comm_doip_handler.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/infra_comm_doip_ringbuffer.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/infra_comm_doip_soad.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/infra_comm_doip_timer.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/uds-core/src/dk_srvc_uds_core.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/uds-core/src/dk_srvc_uds_tp_doip.cpp
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/uds-core/src/uds_core_component.cpp

)

# target_compile_definitions(${BINARY_NAME} PRIVATE UDSCORE_LOG_ENABLED UDSCFG_LOG_ENABLED DIAG_BOOT_PATH)

# Add target include directories
target_include_directories(
   ${BINARY_NAME}
   PRIVATE
   PUBLIC
   ${BL_GP_RTE_DIR}/gip/src/applications/bl_app_gp/
   ${BL_GP_RTE_DIR}/gip/src/common/
   ${CMAKE_CURRENT_SOURCE_DIR}/bl_upd_doip_adapter_component/include/
   ${CMAKE_CURRENT_SOURCE_DIR}/bl_upd_ucl_adapter_component/include/
   ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/include/
   ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/uds_udsmgr/
   ${CMAKE_CURRENT_SOURCE_DIR}/bl_einstein_uds_app_component/src/uds_security/
   ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/include/
   ${OPTEE_SECURITYMANAGER}/SecurityManager/out/include
   ${OPTEE_SECURITYMANAGER}/Prebuilt_client/out/export/usr/include
   ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/doip/src/
   ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/diagnostics/uds-core/src/
)

# Add the OpenSSL package
find_package(OpenSSL REQUIRED)

# Link static libraries
target_link_libraries(${BINARY_NAME} PRIVATE
   OpenSSL::Crypto
   ${OPTEE_SECURITYMANAGER}/SecurityManager/out/lib/libopteesecurity.a
   ${OPTEE_SECURITYMANAGER}/Prebuilt_client/out/export/usr/lib/libteec.a
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
	PRIVATE
	PUBLIC
	dk_logger
	dk_runtime
	metadata
	GpUpdateCdd
	uds_core.a
)
  
# Link installed libraries that are not build with VBuild
target_link_libraries(${BINARY_NAME}
	PRIVATE 	
)

 # Install the binary
install(
	TARGETS ${BINARY_NAME}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
	 

#-----------------------------------------------------------------------------------------------------------------}
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  9/8/2020  | rkrishn8 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
