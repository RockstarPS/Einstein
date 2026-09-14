#ifndef METADATA_CFG_H
#define METADATA_CFG_H

#include "build_info.h"

/**
 * @def METADATA_DEV
 * @brief Metadata device
 */
#ifdef FILE_META
  #define META_DEV                                "metadata.bin"
  #define META_A_OFFSET                           0x00000000
  #define META_B_OFFSET                           0x00020000
#else
  #define META_DEV                                "/dev/mtd14"
  #define META_A_OFFSET                           0x00000000
  #define META_B_OFFSET                           0x00020000
#endif

#define META_SIZE                                 0x00020000
#define META_VARIANT_ID                           0x00

/**
 * @brief List of Software part ids
 */
typedef uint8_t ESwPartId_t;
#define ESwPartId_SBL                                       (0U)
#define ESwPartId_SBL_Recovery                              (1U)
#define ESwPartId_HSM                                       (2U)
#define ESwPartId_HSM_Recovery                              (3U)
#define ESwPartId_BL		                                (4U)
#define ESwPartId_MCU                                       (5U)
#define ESwPartId_Kernel                                    (6U)
#define ESwPartId_Kernel_Recovery                           (7U)
#define ESwPartId_RootFS                                    (8U)
#define ESwPartId_RootFS_Recovery                           (9U)
#define ESwPartId_System                                    (10U)
#define ESwPartId_Appl                                      (11U)
#define ESwPartId_Asset                                     (12U)
#define ESwPartId_Last                                      (13U)

/* imageType, swPartId, swPartNum (16 bytes) imageName (64 bytes), Update Type, deviceType ( A ), devicePhyPartitionId ( A ), Start Address ( A ), deviceType ( B ), devicePhyPartitionId ( B ),  Start Address ( B ), deviceType ( Inactive ), devicePhyPartitionId ( Inactive ),  Start Address ( Inactive ), imageSize, Version - Major, Version - Minor, Version - Patch  */
#define METADATA_CFG  \
  { ESwImageType_BIN, ESwPartId_SBL,            { 0x00 }, "sbl_ospi_linux_stage2.release.appimage.hs_fs",  EUpdateType_AB, EDeviceType_NOR,  0, 0x00080000, EDeviceType_NOR,  0, 0x00180000, EPartition_Last, 0, 0x00000000,     1048576, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_SBL_Recovery,   { 0x00 }, "sbl_ospi_linux_stage2.release.appimage.hs_fs",  EUpdateType_AB, EDeviceType_NOR,  0, 0x00280000, EDeviceType_NOR,  0, 0x00380000, EPartition_Last, 0, 0x00000000,     1048576, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_HSM,            { 0x00 }, "hsm.appimage.hs_fs",                            EUpdateType_AB, EDeviceType_NOR,  0, 0x00480000, EDeviceType_NOR,  0, 0x004A0000, EPartition_Last, 0, 0x00000000,     131072,  GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_HSM_Recovery,   { 0x00 }, "hsm.appimage.hs_fs",                            EUpdateType_AB, EDeviceType_NOR,  0, 0x004C0000, EDeviceType_NOR,  0, 0x004E0000, EPartition_Last, 0, 0x00000000,     131072,  GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_BL,             { 0x00 }, "BL_App.hs_fs",                                  EUpdateType_AB, EDeviceType_NOR,  0, 0x00500000, EDeviceType_NOR,  0, 0x00540000, EPartition_Last, 0, 0x00000000,     262144,  GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_MCU,            { 0x00 }, "VP_App.hs_fs",                                  EUpdateType_AB, EDeviceType_NOR,  0, 0x00580000, EDeviceType_NOR,  0, 0x00980000, EPartition_Last, 0, 0x00000000,     4194304, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_Kernel,         { 0x00 }, "linux.appimage.hs_fs",                          EUpdateType_AB, EDeviceType_EMMC, 1, 0x00000000, EDeviceType_EMMC, 2, 0x00000000, EPartition_Last, 0, 0x00000000,    16777216, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_Kernel_Recovery,{ 0x00 }, "linux.appimage.hs_fs",                          EUpdateType_AB, EDeviceType_EMMC, 1, 0x01000000, EDeviceType_EMMC, 2, 0x01000000, EPartition_Last, 0, 0x00000000,    16777216, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_RootFS,         { 0x00 }, "ext4-rootfs-partition.img",                     EUpdateType_AB, EDeviceType_EMMC, 0, 0x00100000, EDeviceType_EMMC, 0, 0x20100000, EPartition_Last, 0, 0x00000000,   536870912, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_RootFS_Recovery,{ 0x00 }, "ext4-rootfs-partition.img",                     EUpdateType_AB, EDeviceType_EMMC, 0, 0x40100000, EDeviceType_EMMC, 0, 0x60100000, EPartition_Last, 0, 0x00000000,   536870912, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_System,         { 0x00 }, "ext4-system-partition.img",                     EUpdateType_AB, EDeviceType_EMMC, 0, 0x80100000, EDeviceType_EMMC, 0, 0x88100000, EPartition_Last, 0, 0x00000000,   134217728, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_Appl,           { 0x00 }, "ext4-app-partition.img",                        EUpdateType_AB, EDeviceType_EMMC, 0, 0x90100000, EDeviceType_EMMC, 0, 0xA0100000, EPartition_Last, 0, 0x00000000,   268435456, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\
  { ESwImageType_BIN, ESwPartId_Asset,          { 0x00 }, "ext4-asset-partition.img",                      EUpdateType_AB, EDeviceType_EMMC, 0, 0xB0100000, EDeviceType_EMMC, 0, 0xF0100000, EPartition_Last, 0, 0x00000000,  1073741824, GP_SW_VERSION_MAJOR, GP_SW_VERSION_MINOR, GP_SW_VERSION_PATCH},\

/**
 * @def META_SW_NUM_PARTS
 * @brief size of the hardware part number string
 */
#define META_SW_NUM_PARTS                     (ESwPartId_Last)

#endif /* METADATA_CFG_H */
