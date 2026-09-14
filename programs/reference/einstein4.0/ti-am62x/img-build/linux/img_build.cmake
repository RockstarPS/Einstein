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
if(DEFINED ENV{PRODUCTION_MODE})
    if("$ENV{PRODUCTION_MODE}" STREQUAL "ON")
        message(STATUS "======= PRODUCTION_MODE IS SET ========")
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HS =====")
        set(DEVICE_TYPE "hs")
        set(METADATA_DEFINE_FLAG "-DDEVICE_TYPE_HS")
    else()
        message(STATUS "==== COMPILING FOR DEVICE_TYPE HSFS =====")
        set(DEVICE_TYPE "hs_fs")
        set(METADATA_DEFINE_FLAG "")
    endif()
else()
    message(STATUS "==== PRODUCTION_MODE OFF. COMPILING FOR DEVICE_TYPE HSFS =====")
    set(DEVICE_TYPE "hs_fs")
    set(METADATA_DEFINE_FLAG "")
endif()

if(PROJECT_VAR STREQUAL EINSTEIN_4_0_A1)
	set(BOARD_VAR e4_a1)
elseif(PROJECT_VAR STREQUAL EINSTEIN_4_0_A0)
	set(BOARD_VAR e4_a0)
endif()

set(METADATA_DIR	${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/metadata)

# Generate images
set(BUILD_OUT_DIR		${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out)
set(IMAGES_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/images)
set(BSP_INSTALL_DIR		${BUILD_OUT_DIR}/GP_LINUX/${PROJECT_VAR}/${CMAKE_BUILD_TYPE}/install)
set(YOCTO_BINS			${CMAKE_SOURCE_DIR}/$ENV{ARTI_OUTPUT_PATH}/$ENV{ARTI_PATTERN}/Jenkins_Images/${BOARD_VAR})
set(DM_BINS				${BUILD_OUT_DIR}/DM/${PROJECT_VAR}/${CMAKE_BUILD_TYPE}/install)
set(VP_BINS				${BUILD_OUT_DIR}/VP_Platform/${PROJECT_VAR}/${CMAKE_BUILD_TYPE}/EINSTIEN4.0_VP)
set(BL_BINS             ${BUILD_OUT_DIR}/BL_Platform/EINSTIEN4.0_EVK/${CMAKE_BUILD_TYPE}/EINSTIEN4.0_BL)
set(HSM_BINS			${BUILD_OUT_DIR}/HSM/EINSTIEN4.0_EVK/${CMAKE_BUILD_TYPE}/EINSTIEN4.0_HSM/binaries/Hsmbinary)
set(IMG_TOOLS_DIR       ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/img-build/tools)
set(CAN_FULL_PACKAGE_BIN_DIRECTORY    ${IMAGES_OUTPUT_DIRECTORY}/CAN_FULL_PACKAGE)
set(CAN_DELTA_PACKAGE_BIN_DIRECTORY   ${IMAGES_OUTPUT_DIRECTORY}/CAN_DELTA_PACKAGE)
set(DELTA_OG_IMG_DIR   ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/delta_images)
set(STAGE1_CRC_CHECKSUM_OFFSET          0x7FFFC)

# Specify Platform name and endianess
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
	set(PLATFORM	${CMAKE_SYSTEM_PROCESSOR}le)
else()
	set(PLATFORM	${CMAKE_SYSTEM_PROCESSOR})
endif()

	#Strip operation for the release build
if(CMAKE_BUILD_TYPE STREQUAL release )
	# Strip GP binaries from install dir
	file(GLOB files LIST_DIRECTORIES false CONFIGURE_DEPENDS ${BSP_INSTALL_DIR}/${PLATFORM}/usr/bin/*)
        foreach(file ${files})
            get_filename_component(filename ${file} NAME)
            string(REPLACE "." "_" filename ${filename})
		add_custom_target(${filename}_bin_striped ALL
			COMMAND aarch64-oe-linux-strip --strip-debug ${file}
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
			COMMAND aarch64-oe-linux-strip --strip-debug ${file}
			COMMENT "Striping ${file}"
			)
		list(APPEND strip_targets ${filename}_lib_striped)
	endforeach()

	# Check imported libraries that must be added explicit
	get_directory_property(imported_shared_libs IMPORTED_SHARED_LIB_TARGETS)
	foreach(lib_name ${imported_shared_libs})
		add_custom_command(
			COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${lib_name} ./
			COMMAND aarch64-oe-linux-strip --strip-debug ${lib_name}
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

# Generate EXT4 Images
add_custom_command(
	# System partition
	COMMAND ${CMAKE_COMMAND} -E make_directory ./system
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-system-partition.sh ${BSP_INSTALL_DIR} ./system
	COMMAND genext2fs -b 65536 -d ./system ./ext4-system-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-system-partition.img
	COMMAND e2fsck -pDf ./ext4-system-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-system-partition.tar.gz ext4-system-partition.img
	COMMAND yes | rm -rf ./system

	# App partition
	COMMAND ${CMAKE_COMMAND} -E make_directory ./app
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-app-partition.sh ${BSP_INSTALL_DIR} ./app
	COMMAND genext2fs -b 131072 -d ./app ./ext4-app-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-app-partition.img
	COMMAND e2fsck -pDf ./ext4-app-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-app-partition.tar.gz ext4-app-partition.img
	COMMAND yes | rm -rf ./app

	# Asset partition
	COMMAND ${CMAKE_COMMAND} -E make_directory ./asset
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-asset-partition.sh ${BSP_INSTALL_DIR} ./asset
	COMMAND genext2fs -b 16384 -d ./asset ./ext4-asset-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-asset-partition.img
	COMMAND e2fsck -pDf ./ext4-asset-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-asset-partition.tar.gz ext4-asset-partition.img
	COMMAND yes | rm -rf ./asset

	# Data partition
	COMMAND ${CMAKE_COMMAND} -E make_directory ./data
	COMMAND genext2fs -m 4 -b 131072 -d ./data ./ext4-data-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-data-partition.img
	COMMAND e2fsck -pDf ./ext4-data-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-data-partition.tar.gz ext4-data-partition.img
	COMMAND yes | rm -rf ./data

	# Persist
	COMMAND ${CMAKE_COMMAND} -E make_directory ./persist
	COMMAND genext2fs -b 16384 -d ./persist ./ext4-persist-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-persist-partition.img
	COMMAND e2fsck -pDf ./ext4-persist-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-persist-partition.tar.gz ext4-persist-partition.img
	COMMAND yes | rm -rf ./persist

	# Update-cache partition
	COMMAND ${CMAKE_COMMAND} -E make_directory ./update-cache
	COMMAND genext2fs -b 16384 -d ./update-cache ./ext4-update-cache-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-update-cache-partition.img
	COMMAND e2fsck -pDf ./ext4-update-cache-partition.img || (exit 0)
	#COMMAND ${CMAKE_COMMAND} -E tar -czvf ext4-update-cache-partition.tar.gz ext4-update-cache-partition.img
	COMMAND yes | rm -rf ./update-cache

	# Generate EXT4 rootfs Images
	COMMAND ${CMAKE_COMMAND} -E make_directory ./rootfs
	COMMAND tar -xvf ${YOCTO_BINS}/core-image-minimal-am62pxx-${BOARD_VAR}.rootfs.tar.xz -C ./rootfs
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-rootfs-partition.sh ${BSP_INSTALL_DIR} ${IMAGES_OUTPUT_DIRECTORY}/rootfs
	COMMAND genext2fs -m 4 -U -b 524288	-d ./rootfs ext4-rootfs-partition.img
	COMMAND tune2fs -j -J size=1 -O filetype,extents,uninit_bg,dir_index ./ext4-rootfs-partition.img
	COMMAND e2fsck -pDf ./ext4-rootfs-partition.img || (exit 0)
	COMMAND yes | rm -rf ./rootfs

	COMMAND gcc -DFILE_META -DSECURE ${METADATA_DEFINE_FLAG} -I ${METADATA_DIR}/src -I ${METADATA_DIR}/src/lib -I ${METADATA_DIR}/src/public -I ${BSP_INSTALL_DIR}/usr/include -I ${CMAKE_SOURCE_DIR}programs/reference/einstein4.0/ti-am62x/gp-build/linux/prebuilt_common/usr/include ${METADATA_DIR}/src/tool/metadata_gen.c -o metadata_gen
	COMMAND ./metadata_gen -o ${IMAGES_OUTPUT_DIRECTORY}/metadata-signed.bin
	COMMAND ${CMAKE_COMMAND} -E remove -rf ${IMAGES_OUTPUT_DIRECTORY}/metadata_gen

	WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}

	DEPENDS
		${strip_targets}
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-system-partition.sh
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-app-partition.sh
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-asset-partition.sh
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/copy-rootfs-partition.sh
		${YOCTO_BINS}/core-image-minimal-am62pxx-${BOARD_VAR}.rootfs.tar.xz

	OUTPUT
		${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-data-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-update-cache-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-persist-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/metadata-signed.bin

	COMMENT "Building EXT4 Images"
)

# For build Linux App image.
set(PROJECT_DM_DIR      ${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/dm-firmware)
set(SECMGR_SOURCE_DIR   ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib)
set(MCU_SDK_DIR			${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/bsp/ti/am62x/mcu-sdk)

add_custom_command(

    COMMAND ${CMAKE_COMMAND} -E copy ${SECMGR_SOURCE_DIR}/Prebuilt_OS/arm-plat-k3/core/tee-pager_v2.bin ${YOCTO_BINS}/bl32.bin
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} PSDK_LINUX_PREBUILT_IMAGES=${YOCTO_BINS} -j -s -C ${PROJECT_DM_DIR}/linuxAppimageGen clean
    COMMAND make -e DEVICE_TYPE=${DEVICE_TYPE} MCU_PLUS_SDK_PATH=${MCU_SDK_DIR} PSDK_LINUX_PREBUILT_IMAGES=${YOCTO_BINS} -j -s -C ${PROJECT_DM_DIR}/linuxAppimageGen all
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/linuxAppimageGen/linux.appimage.${DEVICE_TYPE} ${IMAGES_OUTPUT_DIRECTORY}/
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_DM_DIR}/linuxAppimageGen/linux.appimage ${DM_BINS}/linux.appimage

    DEPENDS
    ${YOCTO_BINS}/bl31.bin
    ${YOCTO_BINS}/bl32.bin
    ${YOCTO_BINS}/k3-am62p5-einstein.dtb
    ${YOCTO_BINS}/Image

    OUTPUT
    ${IMAGES_OUTPUT_DIRECTORY}/linux.appimage.${DEVICE_TYPE}
)

add_custom_command(

	WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}

	COMMAND ${CMAKE_COMMAND} -E make_directory ./USB
	COMMAND ${CMAKE_COMMAND} -E make_directory ./NOR
	COMMAND ${CMAKE_COMMAND} -E make_directory ./eMMC

	COMMAND ${CMAKE_COMMAND} -E copy ${YOCTO_BINS}/tiboot3-am62px-hs-fs-e4.bin				./USB
	COMMAND ${CMAKE_COMMAND} -E copy ${YOCTO_BINS}/tispl.bin								./USB
	COMMAND ${CMAKE_COMMAND} -E copy ${YOCTO_BINS}/u-boot.img								./USB

	COMMAND ${CMAKE_COMMAND} -E copy ${VP_BINS}/EINSTIEN4.0_VP.appimage.${DEVICE_TYPE}				./NOR
	COMMAND ${CMAKE_COMMAND} -E copy ${BL_BINS}/EINSTIEN4.0_BL.appimage.${DEVICE_TYPE}               ./NOR
	COMMAND ${CMAKE_COMMAND} -E copy ${HSM_BINS}/hsm.appimage.${DEVICE_TYPE}							./NOR
	COMMAND ${CMAKE_COMMAND} -E copy ${DM_BINS}/sbl_ospi_stage1.release.${DEVICE_TYPE}.tiimage		./NOR
    COMMAND truncate -s 512K "./NOR/sbl_ospi_stage1.release.${DEVICE_TYPE}.tiimage"
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/scripts/add_crc32_checksum.py ./NOR/sbl_ospi_stage1.release.${DEVICE_TYPE}.tiimage ${STAGE1_CRC_CHECKSUM_OFFSET} ${STAGE1_CRC_CHECKSUM_OFFSET}
	COMMAND ${CMAKE_COMMAND} -E copy ${DM_BINS}/sbl_ospi_stage2.release.appimage.${DEVICE_TYPE}		./NOR
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/metadata.bin				./NOR

	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/linux.appimage.${DEVICE_TYPE}	./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.img		./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.img			./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.img		./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-data-partition.img			./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-update-cache-partition.img	./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-persist-partition.img		./eMMC
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.img		./eMMC

	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-data-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-update-cache-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-persist-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.img
	COMMAND ${CMAKE_COMMAND} -E remove ${IMAGES_OUTPUT_DIRECTORY}/metadata.bin

	## Creating for DFU Package
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/scripts/DFU_Flash	${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${IMAGES_OUTPUT_DIRECTORY}/USB					${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash/images/USB
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${IMAGES_OUTPUT_DIRECTORY}/NOR					${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash/images/NOR
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${IMAGES_OUTPUT_DIRECTORY}/eMMC					${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash/images/eMMC
	COMMAND ${CMAKE_COMMAND} -E tar -czvf DFU_Flash.tar.gz DFU_Flash
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash

	DEPENDS
		${YOCTO_BINS}/tiboot3-am62px-hs-fs-e4.bin
		${YOCTO_BINS}/tispl.bin
		${YOCTO_BINS}/u-boot.img
		${VP_BINS}/EINSTIEN4.0_VP.appimage.${DEVICE_TYPE}
		${HSM_BINS}/hsm.appimage.${DEVICE_TYPE}
		${DM_BINS}/sbl_ospi_stage1.release.${DEVICE_TYPE}.tiimage
		${DM_BINS}/sbl_ospi_stage2.release.appimage.${DEVICE_TYPE}
		${IMAGES_OUTPUT_DIRECTORY}/linux.appimage.${DEVICE_TYPE}
		${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-data-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-update-cache-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-persist-partition.img
		${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.img

	OUTPUT
		${IMAGES_OUTPUT_DIRECTORY}/USB
		${IMAGES_OUTPUT_DIRECTORY}/NOR
		${IMAGES_OUTPUT_DIRECTORY}/eMMC
		${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash.tar.gz

	COMMENT "Creating a package and make ready for flashing "

)

# Generate CAN Flash Full Package
add_custom_command(
    COMMENT "Building CAN Package Images"
	COMMAND chmod +x ${IMG_TOOLS_DIR}/UpdPack
    COMMAND chmod +x ${IMG_TOOLS_DIR}/PackageGen
    COMMAND chmod +x ${IMG_TOOLS_DIR}/SrecGen
	COMMAND chmod +x ${IMG_TOOLS_DIR}/SignGen
	COMMAND chmod +x ${IMG_TOOLS_DIR}/EncPackGen
	COMMAND chmod 777 ${IMG_TOOLS_DIR}/private_key.pem
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CAN_FULL_PACKAGE_BIN_DIRECTORY}

	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-asset-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.raw.x2 -hash:SHA256 -dictK:4 -sizeM:16 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-asset-partition.img -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.raw.x2.aes128.bin -m encrypt

	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-app-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.raw.x2 -hash:SHA256 -dictK:4 -sizeM:128 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-app-partition.img -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.raw.x2.aes128.bin -m encrypt

	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-system-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.raw.x2 -hash:SHA256 -dictK:4 -sizeM:64 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-system-partition.img -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.raw.x2.aes128.bin -m encrypt

	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-rootfs-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.raw.x2 -hash:SHA256 -dictK:4 -sizeM:512 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-rootfs-partition.img -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.raw.x2.aes128.bin -m encrypt

	COMMAND dd if=${IMAGES_OUTPUT_DIRECTORY}/eMMC/linux.appimage.${DEVICE_TYPE} of=${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE} bs=1M count=16 conv=sync
	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE} -out:${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.raw.x2 -hash:SHA256 -dictK:4 -sizeM:16 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE} -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/linux-appimage.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/linux-appimage.raw.x2.aes128.bin -m encrypt

	COMMAND dd if=${IMAGES_OUTPUT_DIRECTORY}/NOR/EINSTIEN4.0_BL.appimage.${DEVICE_TYPE} of=${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.${DEVICE_TYPE} bs=256K count=1 conv=sync
	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.${DEVICE_TYPE} -out:${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.x2 -hash:SHA256 -dictK:4 -sizeK:256 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.${DEVICE_TYPE} -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-BL-appimage.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.x2.aes128.bin -m encrypt

	COMMAND dd if=${IMAGES_OUTPUT_DIRECTORY}/NOR/EINSTIEN4.0_VP.appimage.${DEVICE_TYPE} of=${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.${DEVICE_TYPE} bs=4M count=1 conv=sync
	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.${DEVICE_TYPE} -out:${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.x2 -hash:SHA256 -dictK:4 -sizeM:4 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.${DEVICE_TYPE} -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-VP-appimage.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.x2.aes128.bin -m encrypt

	COMMAND dd if=${IMAGES_OUTPUT_DIRECTORY}/NOR/hsm.appimage.${DEVICE_TYPE} of=${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.${DEVICE_TYPE} bs=128K count=1 conv=sync
	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.${DEVICE_TYPE} -out:${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.raw.x2 -hash:SHA256 -dictK:4 -sizeK:128 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.${DEVICE_TYPE} -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/hsm-appimage.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/hsm-appimage.raw.x2.aes128.bin -m encrypt

	COMMAND dd if=${IMAGES_OUTPUT_DIRECTORY}/NOR/sbl_ospi_stage2.release.appimage.${DEVICE_TYPE} of=${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.${DEVICE_TYPE} bs=1M count=1 conv=sync
	COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.${DEVICE_TYPE} -out:${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.x2 -hash:SHA256 -dictK:4 -sizeM:1 -padding:255
	COMMAND ${IMG_TOOLS_DIR}/SignGen -i ${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.${DEVICE_TYPE} -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/sbl_ospi_stage2-release-appimage.sign.bin -k ${IMG_TOOLS_DIR}/private_key.pem
	COMMAND ${IMG_TOOLS_DIR}/EncPackGen -i ${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.x2 -o ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.x2.aes128.bin -m encrypt

	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.raw.x2                  ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.raw.x2                  ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.raw.x2                  ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.raw.x2                  ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.raw.x2                        ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/linux-appimage.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.x2 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.x2 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.raw.x2 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/hsm-appimage.raw.x2.bin
	COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.x2 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.x2.bin

	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-asset-partition.img	                 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-app-partition.img	                 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-system-partition.img	                 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-rootfs-partition.img	                 ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE}                        ${CAN_FULL_PACKAGE_BIN_DIRECTORY}/linux-appimage.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-BL-appimage.${DEVICE_TYPE} 	${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-BL-appimage.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/EINSTIEN-4-0-VP-appimage.${DEVICE_TYPE} 	${CAN_FULL_PACKAGE_BIN_DIRECTORY}/EINSTIEN-4-0-VP-appimage.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/hsm-appimage.${DEVICE_TYPE} 	${CAN_FULL_PACKAGE_BIN_DIRECTORY}/hsm-appimage.raw.bin
	#COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/sbl_ospi_stage2-release-appimage.${DEVICE_TYPE} 	${CAN_FULL_PACKAGE_BIN_DIRECTORY}/sbl_ospi_stage2-release-appimage.raw.bin

	COMMAND ${CMAKE_COMMAND} -E rm -f *.x2
	COMMAND ${CMAKE_COMMAND} -E rm -f *.sha256
	COMMAND ${CMAKE_COMMAND} -E rm -f *.${DEVICE_TYPE}

    # Generating TAR Files
    COMMAND ${CMAKE_COMMAND} -E tar -czvf CAN_FULL_PACKAGE.tar.gz ${CAN_FULL_PACKAGE_BIN_DIRECTORY}

    # Removing Folders
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CAN_FULL_PACKAGE_BIN_DIRECTORY}

    WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}
    DEPENDS
        ${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash.tar.gz
    OUTPUT
        ${IMAGES_OUTPUT_DIRECTORY}/CAN_FULL_PACKAGE.tar.gz
    COMMENT "Generating CAN Flash Full Package"
)

# Generate CAN Flash Delta Package
if(EXISTS ${DELTA_OG_IMG_DIR})
    add_custom_command(
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}

		#COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-asset-partition.img -org:${DELTA_OG_IMG_DIR}/eMMC/ext4-asset-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.dt.x2 -hash:SHA256 -dictK:4 -sizeM:16 -padding:255
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.dt.x2        ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.dt.x2
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-asset-partition.dt.x2.sha256 ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-asset-partition.dt.x2.sha256

		#COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-app-partition.img -org:${DELTA_OG_IMG_DIR}/eMMC/ext4-app-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.dt.x2 -hash:SHA256 -dictK:4 -sizeM:128 -padding:255
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.dt.x2        ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.dt.x2
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-app-partition.dt.x2.sha256 ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-app-partition.dt.x2.sha256

		#COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-system-partition.img -org:${DELTA_OG_IMG_DIR}/eMMC/ext4-system-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.dt.x2 -hash:SHA256 -dictK:4 -sizeM:64 -padding:255
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.dt.x2        ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.dt.x2
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-system-partition.dt.x2.sha256 ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-system-partition.dt.x2.sha256

		#COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/eMMC/ext4-rootfs-partition.img -org:${DELTA_OG_IMG_DIR}/eMMC/ext4-rootfs-partition.img -out:${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.dt.x2 -hash:SHA256 -dictK:4 -sizeM:512 -padding:255
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.dt.x2        ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.dt.x2
        #COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/ext4-rootfs-partition.dt.x2.sha256 ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/ext4-rootfs-partition.dt.x2.sha256

		COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/eMMC/linux.appimage.${DEVICE_TYPE}             ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE}
		COMMAND ${CMAKE_COMMAND} -E copy ${DELTA_OG_IMG_DIR}/eMMC/linux.appimage.${DEVICE_TYPE}                    ${DELTA_OG_IMG_DIR}/linux-appimage.${DEVICE_TYPE}
		COMMAND ${IMG_TOOLS_DIR}/UpdPack -in:${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.${DEVICE_TYPE} -org:${DELTA_OG_IMG_DIR}/linux-appimage.img -out:${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.dt.x2 -hash:SHA256 -dictK:4 -sizeM:15 -padding:255
        COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.dt.x2        ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/linux-appimage.dt.x2
        COMMAND ${CMAKE_COMMAND} -E copy ${IMAGES_OUTPUT_DIRECTORY}/linux-appimage.dt.x2.sha256 ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}/linux-appimage.dt.x2.sha256

        # Generating TAR Files
        COMMAND ${CMAKE_COMMAND} -E tar -czvf CAN_DELTA_PACKAGE.tar.gz ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}

        # Removing Folders
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CAN_DELTA_PACKAGE_BIN_DIRECTORY}
        COMMAND find . -type f -name '*.dt.x2' -delete
        COMMAND find . -type f -name '*.dt.x2.sha256' -delete

        WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}
        DEPENDS
            ${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash.tar.gz
        OUTPUT
            ${IMAGES_OUTPUT_DIRECTORY}/CAN_DELTA_PACKAGE.tar.gz
        COMMENT "Generating CAN Flash Delta Package"
    )
else()
    add_custom_command(
        WORKING_DIRECTORY ${IMAGES_OUTPUT_DIRECTORY}
        DEPENDS
            ${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash.tar.gz
        OUTPUT
            ${IMAGES_OUTPUT_DIRECTORY}/CAN_DELTA_PACKAGE.tar.gz
        COMMENT "Skipping CAN Flash Delta Package"
    )
endif()
add_custom_target(BuildImages ALL DEPENDS
	${IMAGES_OUTPUT_DIRECTORY}/USB
	${IMAGES_OUTPUT_DIRECTORY}/NOR
	${IMAGES_OUTPUT_DIRECTORY}/eMMC
	${IMAGES_OUTPUT_DIRECTORY}/DFU_Flash.tar.gz
	${IMAGES_OUTPUT_DIRECTORY}/CAN_FULL_PACKAGE.tar.gz
	#${IMAGES_OUTPUT_DIRECTORY}/CAN_DELTA_PACKAGE.tar.gz
)


#-------------------------------------------------------------------------------------------------------------------
#	  Date	   |   User	  |	  Task	  |										Description
#-------------------------------------------------------------------------------------------------------------------
#  12/03/2025  | STHANGA4 |    N/A    | Added/Updated support for linux only build, build cmds updated
#-------------------------------------------------------------------------------------------------------------------
#  29/03/2024  | NSUBRAM2 |	   N/A	  | Added support for QNX
#-------------------------------------------------------------------------------------------------------------------
#  20/07/2023  | MMK	  |	   N/A	  | Created initial file - TI AM62AX EVK
#-------------------------------------------------------------------------------------------------------------------
