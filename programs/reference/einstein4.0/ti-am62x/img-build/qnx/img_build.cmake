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
# The PRODUCTION_MODE switch will have to be configured somewhere in the parent scripts
# eg. set(PRODUCTION_MODE ON)
# Build command eg. dn build --env VARIANT=ti-am62x_e4_evk --type=imgqnx --env PRODUCTION_MODE=ON
# Build command eg. dn build --env VARIANT=ti-am62x_e4_run0 --type=imgqnx --env PRODUCTION_MODE=ON
if ($ENV{PRODUCTION_MODE} MATCHES "ON")
	message(STATUS "====PRODUCTION MODE IS ENABLED====")
	set(PROD_OPT_DEF -DPRODUCTION_MODE)
  set(BUILD_INFO "PRODUCTION")
else()
	message(STATUS "====DEVELOPMENT MODE IS ENABLED====")
  set(BUILD_INFO "DEVELOPMENT")
endif()

message(STATUS "BUILD_INFO: ${BUILD_INFO}")

if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
	set(BOARD_VAR e4_a1)
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
	set(BOARD_VAR e4_a0)
endif() 

set(METADATA_DIR    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/metadata)

# Generate images
set(IMAGES_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/images)
# Set variables used by the support scripts
set(BSP_DIR ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/qnx8-bsp)
set(PGM_BSP_DIR ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/qnx8-bsp)
set(BSP_INSTALL_DIR ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/GP_QNX/${PROJECT_VAR}/${CMAKE_BUILD_TYPE}/install)
set(PSDK_OUT_DIR ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/qnx8-psdk/psdkqa/qnxfs)
# set(QNX_SCREEN_DIR ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/qnx71-screen) # Place holder for future update
set(QNX_SCREEN_DIR $ENV{QNX_TARGET})
set(GEN_QNX_APP_IMG ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/dm-firmware/$ENV{VARIANT}/qnxAppimageGen)
set(DM_INSTALL_DIR  ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/DM/${PROJECT_VAR}_QNX/${CMAKE_BUILD_TYPE}/install)
set(MCU_PLUS_SDK_PATH ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/mcu-sdk)
set(VP_INSTALL_DIR	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/VP_Platform/EINSTIEN4.0_EVK/${CMAKE_BUILD_TYPE}/EINSTIEN4.0_VP)
set(HSM_INSTALL_DIR ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/HSM/EINSTIEN4.0_EVK/${CMAKE_BUILD_TYPE}/EINSTIEN4.0_HSM/binaries/Hsmbinary)

# Specify Platform name and endianess
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
    set(PLATFORM    ${CMAKE_SYSTEM_PROCESSOR}le)
else()
    set(PLATFORM    ${CMAKE_SYSTEM_PROCESSOR})
endif()

#Strip operation for the release build
if(CMAKE_BUILD_TYPE STREQUAL release )
	# Strip GP binaries from install dir
	file(GLOB files LIST_DIRECTORIES false CONFIGURE_DEPENDS ${BSP_INSTALL_DIR}/${PLATFORM}/usr/bin/*)
	foreach(file ${files})
		get_filename_component(filename ${file} NAME)
		string(REPLACE "." "_" filename ${filename})
		add_custom_target(${filename}_bin_striped ALL
			COMMAND nto${CMAKE_SYSTEM_PROCESSOR}-strip --strip-debug ${file}
			COMMENT "Striping ${file}"
			)
		list(APPEND strip_targets ${filename}_bin_striped)
	endforeach()

	# Strip GP Shared libraries from install dir
	file(GLOB files LIST_DIRECTORIES false CONFIGURE_DEPENDS ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib/*)
	foreach(file ${files})
		get_filename_component(filename ${file} NAME)
		string(REPLACE "." "_" filename ${filename})
		add_custom_target(${filename}_lib_striped ALL
			COMMAND nto${CMAKE_SYSTEM_PROCESSOR}-strip --strip-debug ${file}
			COMMENT "Striping ${file}"
			)
		list(APPEND strip_targets ${filename}_lib_striped)
	endforeach()

	# Check imported libraries that must be added explicit
	get_directory_property(imported_shared_libs IMPORTED_SHARED_LIB_TARGETS)
	foreach(lib_name ${imported_shared_libs})
		add_custom_command(
			COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${lib_name} ./
			COMMAND nto${CMAKE_SYSTEM_PROCESSOR}-strip --strip-debug ${lib_name}
			WORKING_DIRECTORY ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib
			DEPENDS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${lib_name}
			OUTPUT ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib/${lib_name}
			COMMENT "Striping ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib/${lib_name}"
			)
		add_custom_target(${lib_name}_striped DEPENDS ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib/${lib_name})
		list(APPEND strip_targets ${lib_name}_striped)
		list(APPEND PROJ_SHARED_OBJ ${BSP_INSTALL_DIR}/${PLATFORM}/usr/lib/${lib_name})
	endforeach()
endif()

# Generate images based on CONFIG
set(VARIANT_LIST -DEINSTEIN_4_0_A0=0 -DEINSTEIN_4_0_A1=1)
set(IFS_TYPE_LIST -DIFS_TYPE_PRIMARY=0 -DIFS_TYPE_RECOVERY=1 -DIFS_TYPE_REFLASH=2)

# Generate Primary, Recovery IFS image
add_custom_command(
  COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGES_OUTPUT_DIRECTORY}
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${PROD_OPT_DEF} ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${IFS_TYPE_LIST} -DIFS_TYPE=IFS_TYPE_PRIMARY -DBUILD_INFO=${BUILD_INFO} ${CMAKE_CURRENT_SOURCE_DIR}/make/ifs-primary.tmpl -o ${IMAGES_OUTPUT_DIRECTORY}/ifs-primary.build
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${PROD_OPT_DEF} ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${IFS_TYPE_LIST} -DIFS_TYPE=IFS_TYPE_RECOVERY ${CMAKE_CURRENT_SOURCE_DIR}/make/ifs-recovery.tmpl -o ${IMAGES_OUTPUT_DIRECTORY}/ifs-recovery.build
  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" "QNX_SCREEN_DIR=${QNX_SCREEN_DIR}" "PSDK_OUT_DIR=${PSDK_OUT_DIR}"
    mkifs -vvvv -nn -r ${BSP_INSTALL_DIR} ${IMAGES_OUTPUT_DIRECTORY}/ifs-primary.build ifs-primary.bin
  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" "QNX_SCREEN_DIR=${QNX_SCREEN_DIR}"
    mkifs -vvvv -nn -r ${BSP_INSTALL_DIR} ${IMAGES_OUTPUT_DIRECTORY}/ifs-recovery.build ifs-recovery.bin
  COMMAND ls -l ifs-primary.bin
  COMMAND ls -l ifs-recovery.bin
  #COMMAND truncate -s 16M ifs-primary.bin
  #COMMAND truncate -s 16M ifs-recovery.bin
  COMMAND ${CMAKE_COMMAND} -E remove -f  ${IMAGES_OUTPUT_DIRECTORY}/ifs-primary.build
  COMMAND ${CMAKE_COMMAND} -E remove -f  ${IMAGES_OUTPUT_DIRECTORY}/ifs-recovery.build

  WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}

  DEPENDS
    ${PROJ_BINARIES} ${PROJ_SHARED_OBJ} ${strip_targets} ${CMAKE_CURRENT_SOURCE_DIR}/make/ifs-primary.tmpl
    ${PROJ_BINARIES} ${PROJ_SHARED_OBJ} ${strip_targets} ${CMAKE_CURRENT_SOURCE_DIR}/make/ifs-recovery.tmpl

  OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-primary.bin
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-recovery.bin
  COMMENT "Building Primary/Recovery QNX IFS"
)

# Packing Images inside Reflash IFS
add_custom_command(
# USB_PACKAGE Generation
    COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage1.release.hs_fs.tiimage ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage2.release.appimage.hs_fs ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage1.release.hs_fs.tiimage ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage2.release.appimage.hs_fs ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${GEN_QNX_APP_IMG}/board/am62px-sk/qnx.appimage.hs_fs ${BSP_INSTALL_DIR}/etc/images/ifs-primary-qnx.appimage.hs_fs
    COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.tar.gz ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.tar.gz ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.tar.gz ${BSP_INSTALL_DIR}/etc/images/.
	  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/metadata.bin ${BSP_INSTALL_DIR}/etc/images/.
    #COMMAND ${CMAKE_COMMAND} -E copy ${VP_INSTALL_DIR}/EINSTIEN4.0_VP.appimage.hs_fs ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E copy ${HSM_INSTALL_DIR}/hsm.appimage.hs_fs ${BSP_INSTALL_DIR}/etc/images/.
    COMMAND ${CMAKE_COMMAND} -E touch ${IMAGES_OUTPUT_DIRECTORY}/start_reflash_bin_generation


 
 
    DEPENDS
    ${GEN_QNX_APP_IMG}/install/QNX_App_Image_Generated
    ${DM_INSTALL_DIR}/sbl_ospi_stage1.release.hs_fs.tiimage
    ${DM_INSTALL_DIR}/sbl_ospi_stage2.release.appimage.hs_fs
    #${VP_INSTALL_DIR}/EINSTIEN4.0_VP.appimage.hs_fs
    ${HSM_INSTALL_DIR}/hsm.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.tar.gz

  OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/start_reflash_bin_generation



  WORKING_DIRECTORY
    ${IMAGES_OUTPUT_DIRECTORY}

  COMMENT "Packing Images inside Reflash IFS"
)

# Generate Reflash IFS image
add_custom_command(
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${PROD_OPT_DEF} ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${IFS_TYPE_LIST} -DIFS_TYPE=IFS_TYPE_REFLASH ${CMAKE_CURRENT_SOURCE_DIR}/make/ifs-reflash.tmpl -o ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.build
  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" "QNX_SCREEN_DIR=${QNX_SCREEN_DIR}"
    mkifs -vvvv -nn -r ${BSP_INSTALL_DIR} ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.build ifs-reflash.bin
  COMMAND ls -l ifs-reflash.bin
  COMMAND ${CMAKE_COMMAND} -E remove -f  ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.build
  COMMAND ${CMAKE_COMMAND} -E remove -f  ${IMAGES_OUTPUT_DIRECTORY}/start_reflash_bin_generation

  WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}

  DEPENDS
    ${IMAGES_OUTPUT_DIRECTORY}/start_reflash_bin_generation

  OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.bin

  COMMENT "Building Reflash QNX IFS"
)

# Generate QNX6FS Images
add_custom_command(
  # System partition
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-system-partition.tmpl -o qnx6fs-system-partition.build
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-app-partition.tmpl -o qnx6fs-app-partition.build
  COMMAND filepp -I ${CMAKE_CURRENT_SOURCE_DIR}/make/build_scripts ${VARIANT_LIST} -DVARIANT=${PROJECT_VAR} ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-asset-partition.tmpl -o qnx6fs-asset-partition.build

  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" mkqnx6fsimg qnx6fs-system-partition.build qnx6fs-system-partition.bin
  COMMAND ${CMAKE_COMMAND} -E tar -czvf qnx6fs-system-partition.tar.gz qnx6fs-system-partition.bin
  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" mkqnx6fsimg qnx6fs-app-partition.build qnx6fs-app-partition.bin
  COMMAND ${CMAKE_COMMAND} -E tar -czvf qnx6fs-app-partition.tar.gz qnx6fs-app-partition.bin
  COMMAND ${CMAKE_COMMAND} -E env "PLATFORM=${PLATFORM}" "BSP_INSTALL_DIR=${BSP_INSTALL_DIR}" mkqnx6fsimg qnx6fs-asset-partition.build qnx6fs-asset-partition.bin
  COMMAND ${CMAKE_COMMAND} -E tar -czvf qnx6fs-asset-partition.tar.gz qnx6fs-asset-partition.bin

  COMMAND gcc -DFILE_META -DSECURE -I ${METADATA_DIR}/src -I ${METADATA_DIR}/src/lib -I ${METADATA_DIR}/src/public -I ${BSP_INSTALL_DIR}/usr/include -I ${CMAKE_SOURCE_DIR}programs/reference/einstein4.0/ti-am62x/gp-build/qnx/prebuilt_common/usr/include ${METADATA_DIR}/src/tool/metadata_gen.c -o metadata_gen
  COMMAND ./metadata_gen -o ${IMAGES_OUTPUT_DIRECTORY}/metadata-signed.bin
  COMMAND ${CMAKE_COMMAND} -E remove -rf ${IMAGES_OUTPUT_DIRECTORY}/metadata_gen

  COMMAND ${CMAKE_COMMAND} -E remove -f qnx6fs-system-partition.build
  COMMAND ${CMAKE_COMMAND} -E remove -f qnx6fs-app-partition.build
  COMMAND ${CMAKE_COMMAND} -E remove -f qnx6fs-asset-partition.build

  WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}
  DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-system-partition.tmpl
    ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-app-partition.tmpl
    ${CMAKE_CURRENT_SOURCE_DIR}/make/qnx6fs-asset-partition.tmpl
  OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.tar.gz
  COMMENT "Building QNX6FS Images"
)

# Copy all the images to a single location
add_custom_command(
  COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE
  COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGES_OUTPUT_DIRECTORY}/DFU_PACKAGE
  COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE
  COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE

# DFU_PACKAGE Generation
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.bin ${IMAGES_OUTPUT_DIRECTORY}/DFU_PACKAGE/ifs-reflash.bin

# USB_PACKAGE Generation
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage1.release.hs_fs.tiimage ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage2.release.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage1.release.hs_fs.tiimage ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage2.release.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${VP_INSTALL_DIR}/EINSTIEN4.0_VP.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${HSM_INSTALL_DIR}/hsm.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${GEN_QNX_APP_IMG}/board/am62px-sk/qnx.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/ifs-primary-qnx.appimage.hs_fs
  COMMAND ${CMAKE_COMMAND} -E copy ${BSP_INSTALL_DIR}/etc/images/hsm.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/metadata.bin ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.bin ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.bin ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.bin ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/.


# USB_STICK_PACKAGE Generation
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage1.release.hs_fs.tiimage ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_ospi_stage2.release.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage1.release.hs_fs.tiimage ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_emmc_stage2.release.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${VP_INSTALL_DIR}/EINSTIEN4.0_VP.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${HSM_INSTALL_DIR}/hsm.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${GEN_QNX_APP_IMG}/board/am62px-sk/qnx.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/ifs-primary-qnx.appimage.hs_fs
  COMMAND ${CMAKE_COMMAND} -E copy ${BSP_INSTALL_DIR}/etc/images/hsm.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/metadata.bin ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.tar.gz ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.tar.gz ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.tar.gz ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E touch ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/usb.txt


# UART_PACKAGE Generation
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_uart_uniflash_stage1.release.hs_fs.tiimage ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${DM_INSTALL_DIR}/sbl_uart_uniflash_stage2.release.appimage.hs_fs ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy ${BSP_INSTALL_DIR}/etc/images/*.cfg ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/.
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${BSP_INSTALL_DIR}/etc/images/UART_flash ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/UART_flash

# Cleanup after image packing
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-system-partition.tar.gz
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-app-partition.tar.gz
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-asset-partition.tar.gz
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-system-partition.bin
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-app-partition.bin
  COMMAND ${CMAKE_COMMAND} -E remove qnx6fs-asset-partition.bin
  COMMAND ${CMAKE_COMMAND} -E remove ifs-primary.bin
  COMMAND ${CMAKE_COMMAND} -E remove ifs-reflash.bin
  COMMAND ${CMAKE_COMMAND} -E remove ifs-recovery.bin

  WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}

  DEPENDS
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-reflash.bin
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-system-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-app-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/qnx6fs-asset-partition.tar.gz
    ${GEN_QNX_APP_IMG}/install/QNX_App_Image_Generated

  OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/sbl_ospi_stage1.release.hs_fs.tiimage
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/sbl_ospi_stage2.release.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/sbl_emmc_stage1.release.hs_fs.tiimage
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/sbl_emmc_stage2.release.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/ifs-primary-qnx.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/EINSTIEN4.0_VP.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/hsm.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/metadata.bin
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/qnx6fs-system-partition.bin
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/qnx6fs-asset-partition.bin
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/qnx6fs-app-partition.bin
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/sbl_ospi_stage1.release.hs_fs.tiimage
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/sbl_ospi_stage2.release.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/ifs-primary-qnx.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/EINSTIEN4.0_VP.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/hsm.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/metadata.bin
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/qnx6fs-system-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/qnx6fs-app-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/USB_STICK_PACKAGE/qnx6fs-asset-partition.tar.gz
    ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/sbl_uart_uniflash_stage1.release.hs_fs.tiimage
    ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/sbl_uart_uniflash_stage2.release.appimage.hs_fs
    ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/*.cfg
    ${IMAGES_OUTPUT_DIRECTORY}/UART_PACKAGE/UART_flash

  COMMENT "Copying all the images"
)

# Add custom target to build BSP when it is not compiled
add_custom_command(
  COMMAND ${CMAKE_COMMAND} -E make_directory ${GEN_QNX_APP_IMG}/install
  COMMAND cp -rf ${BSP_INSTALL_DIR}/etc/images/prebuilt ${IMAGES_OUTPUT_DIRECTORY}
  COMMAND ${CMAKE_COMMAND} -E copy ${BSP_INSTALL_DIR}/etc/images/conf/config.mak ${GEN_QNX_APP_IMG}/board/am62px-sk/config.mak
  COMMAND export MCU_PLUS_SDK_PATH=${MCU_PLUS_SDK_PATH}
  COMMAND make -e QNX_IFS_PATH=${IMAGES_OUTPUT_DIRECTORY} PSDK_QNX_PREBUILT_IMAGES=${IMAGES_OUTPUT_DIRECTORY}/prebuilt -s -f ${GEN_QNX_APP_IMG}/makefile BOARD=am62px-sk clean
  COMMAND make -e QNX_IFS_PATH=${IMAGES_OUTPUT_DIRECTORY} PSDK_QNX_PREBUILT_IMAGES=${IMAGES_OUTPUT_DIRECTORY}/prebuilt -s -f ${GEN_QNX_APP_IMG}/makefile BOARD=am62px-sk all
  COMMAND ${CMAKE_COMMAND} -E touch ${GEN_QNX_APP_IMG}/install/QNX_App_Image_Generated

  WORKING_DIRECTORY ${GEN_QNX_APP_IMG}
  USES_TERMINAL

  DEPENDS
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-primary.bin
    ${IMAGES_OUTPUT_DIRECTORY}/ifs-recovery.bin
  OUTPUT
    ${GEN_QNX_APP_IMG}/install/QNX_App_Image_Generated

  COMMENT "Building QNX App Image"
)

add_custom_target(BuildImages ALL DEPENDS
    ${IMAGES_OUTPUT_DIRECTORY}/USB_PACKAGE/qnx6fs-app-partition.bin
    COMMENT "IMG-BUILD Success"
    )

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  12/03/2025  | STHANGA4 |    N/A    | Added/Updated support for QNX only build, build cmds updated
#-------------------------------------------------------------------------------------------------------------------
#  29/03/2024  | NSUBRAM2 |    N/A    | Added support for QNX
#-------------------------------------------------------------------------------------------------------------------
#  20/07/2023  | MMK      |    N/A    | Created initial file - TI AM62AX EVK
#-------------------------------------------------------------------------------------------------------------------
