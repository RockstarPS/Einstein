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

# Update CDD build switches (kept from the original fota_app.cmake)
set(BUILD_VARIANT          GP_Platform)
set(LZMA_SWITCH            OFF)
set(LZBW_SWITCH            OFF)
set(AES_SWITCH             ON)
set(TAR_SWITCH             OFF)
set(HSM_SWITCH             OFF)
set(QSPI_SWITCH            OFF)
set(HYP_SWITCH             OFF)
set(GP_APT_SWITCH          OFF)
set(BLK_DEV_APT_SWITCH     ON)

# Create Binary (fota_app_gp : UpdUclAdapterComponent + UpdDoipAdapterComponent)
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/upd_ucl_adapter_component/src/upd_ucl_adapter_component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/upd_ucl_adapter_component/src/SharedMem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/upd_doip_adapter_component/src/upd_doip_adapter_component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/FlashHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/PartitionHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UpdateHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/updLocalUpdater.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UPDd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/src/UPDd_BootControl.c
    ${GP_RTE_DIR}/gip/src/applications/fota_app_gp/fota_app_gp.cpp
    ${GP_RTE_DIR}/gip/src/applications/fota_app_gp/main.cpp
)

# Add target include directories
target_include_directories(
   ${BINARY_NAME}
   PRIVATE
   PUBLIC
    ${GP_RTE_DIR}/gip/src/applications/fota_app_gp/
    ${GP_RTE_DIR}/gip/src/common
    ${CMAKE_CURRENT_SOURCE_DIR}/upd_doip_adapter_component/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/upd_ucl_adapter_component/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/update_handler/include/
  )

# Add the OpenSSL package
find_package(OpenSSL REQUIRED)

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
    GpUpdateCdd
    metadata
)

 # Install the binary
install(
    TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


#-----------------------------------------------------------------------------------------------------------------}
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 19/9/2024   | agodara  |           | Created initial file (dummy fota_app)
#-------------------------------------------------------------------------------------------------------------------
# 25/11/2026  |          |           | fota_app_gp: UpdUclAdapter/UpdDoipAdapter components moved from diag_app_gp
#-------------------------------------------------------------------------------------------------------------------
