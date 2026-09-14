/**********************************************************************************************************************
 *!  \verbatim
 *!
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
 *       All Rights Reserved.
 *
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and intends to
 *               maintain it in confidence to preserve its trade secret status. Visteon
 *               Corporation reserves the right, under the copyright laws of the United States
 *               or those of any other country that may have jurisdiction, to protect this work
 *               as an unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves its rights under
 *               all copyright laws to protect this work as a published work, when appropriate.
 *               Those having access to this work may not copy it, use it, modify it, or
 *               disclose the information contained in it without the written authorization of
 *               Visteon Corporation.
 *
 *  \endverbatim
 *
 *  \file        main.c
 *  \brief       Dynamically mounting the A/B partitions of file system
 *  \details     secure qtd mount will provide options to mount both qfs and qtd type partitions dynamically.
 *  \author      Nisar Ahamed Khan (nkhan2)
 *  \version     1.0
 *  \addtogroup  dk_bsp
 *  \copyright   Visteon Corporation
 *  \date        20210209
 *  \note        The following document is compliant to:
 *               1. Visteon C Coding Best Practice Rules Ver 1.1
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*!
 * \brief        Standard io header
 */
#include <stdio.h>
/*!
 * \brief        Standard library header
 */
#include <stdlib.h>
/*!
 * \brief        standard boolean support header
 */
#include <stdbool.h>
/*!
 * \brief        Library supports string operations
 */
#include <string.h>
/*!
 * \brief        Library provides access to the POSIX operating system API
 */
#include <unistd.h>
/*!
 * \brief        Library defines macros for reporting and retrieving error conditions
 */
#include <errno.h>
/*!
 * \brief        Library provides subroutines for file operations
 */
#include <fcntl.h>
/*!
 * \brief        Library provides system logging APIs
 */
#if defined(__QNX__)
#include <sys/slog2.h>
#endif
/*!
 * \brief        Library for mounting/ unmounting QNX file system
 */
#include <sys/mount.h>
/*!
 * \brief        Library for json structures and  parsing subroutines
 */
#if defined(__QNX__)
#include <sys/json.h>
#elif defined(__linux__)
#include <json-c/json.h>
#endif
/*!
 * \brief        Library defines the wait API for Linux
 */
#if defined(__linux__)
#include <sys/wait.h>
#endif
/*!
 * \brief        Library defines the logging levels
 */
#include "dk_logger.h"
/*!
 * \brief        Library defines posix spawn operations
 */
#include "spawn.h"
/*!
 * \brief        Library defines mmeory mapping operations
 */
#include <sys/mman.h>
/*!
 * \brief        Library defines physical memory operations
 */
#if defined(__QNX__)
#include <hw/inout.h>
#endif

#ifndef EOK
#define EOK 0
#endif

#ifdef SUPPORT_AB //SUPPORT_AB

/*!
 * \def          SINGLE BIT BITMASK
 * \brief        Bit mask to traverse and fetch the partition info.
 */
#define BIT_MASK            0x00000001

#ifdef NXP_MX8
/*!
 * \brief        Library for scu ioctl
 */
#include <sys/imx8_sci_mgr.h>
/*!
 * \def          DEVCTL ID FOR GET ACTIVE PARTITON INFORMATION
 * \brief        DCMD_BOARD_IOCTL id to get the active partition information.
 */
#define BOARD_CTL_GET_ACTIVE_PARTITON (0xB)

/*!
 * \def          DEVCTL SC PATH
 * \brief        Path through which scu board ioctl can be accessed.
 */
#define SC_PATH             "/dev/sc"

#endif //NXP_MX8

#ifdef SAM_EXYNOS
/*!
 * \def          OM_STAT_A_VAL
 * \brief        BOOT_A active value
 */
#define OM_STAT_A_VAL           0x0
/*!
 * \def          EXYNOSAUTO_V9_POWER_BASE
 * \brief        Register address to read A/B Chain information
 */
#define EXYNOSAUTO_V9_POWER_BASE   0x10460000
/*!
 * \def          OM_STAT_BOOT_MASK_EVT0
 * \brief        Register mask for EVT0 to read A/B Chain information
 */
#define OM_STAT_BOOT_MASK_EVT0  0xf
/*!
 * \def          OM_STAT_BOOT_MASK_EVT1
 * \brief        Register mask for EVT1 to read A/B Chain information
 */
#define OM_STAT_BOOT_MASK_EVT1  0x1f
/*!
 * \def          OM_STAT_BOOT_SHIFT_EVT0
 * \brief        Register shift value to read A/B Chain information
 */
#define OM_STAT_BOOT_SHIFT_EVT0 3
/*!
 * \def          OM_STAT_BOOT_SHIFT_EVT1
 * \brief        Register shift value to read A/B Chain information
 */
#define OM_STAT_BOOT_SHIFT_EVT1 4

#endif //SAM_EXYNOS

#ifdef TI_AM62P
#include "metadata.h"
#endif //TI_AM62P

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*!
 * \brief        Global variable to hold the partition info bit map
 */
uint32_t gPart_info = 0xFFFFFFFF;

/**********************************************************************************************************************
 *  STATIC FUNCTIONS
 *********************************************************************************************************************/
/*!
 * \brief        function to read the parition bit map using devctl
 */
static int32_t get_partition_info();

#endif //SUPPORT_AB


LOG_DECLARE_CONTEXT ( gSecQtdMntLogContext );
/**********************************************************************************************************************
 *  INTERNAL MACROS
 *********************************************************************************************************************/
/*!
 * \def          SIZE OF BUFFER
 * \brief        256 Byte buffer to store string literals
 */
#define BUFF_SIZE            256U
/*!
 * \def          QTD FILE SYSTEM
 * \brief        String literal prefix for QTD file systems
 */
#define TYPE_QTD             "qtd\0"
/*!
 * \def          QNX6 FILE SYSTEM
 * \brief        String literal prefix for QNX6 file systems
 */
#define TYPE_QNX6            "qnx6\0"
/*!
 * \def          FORMAT PARTITON
 * \brief        Argument for format partition
 */
#define FORMAT               "format"

/**********************************************************************************************************************
 *  INTERNAL TYPES
 *********************************************************************************************************************/
/*!
 * \brief        Typedef for native type of char
 */
typedef char char8_t;

#ifdef SUPPORT_AB
static int32_t check_mount_condition ( int32_t p_part_id_S32, int32_t p_part_val_S32 );
#endif
#if defined(__QNX__)
static int32_t mount_qtd_fs (const char8_t *dev, const char8_t *mnt, const char8_t *key);
#endif
static int32_t mount_fs (const char8_t *devPr, const char8_t *fs_type, const char8_t *mnt, const char8_t *option);
static int32_t parse_config(const char8_t *file);
/*!
 * \brief         This function opens the /dev/sc path to fetch the partition info
 *                through devctl calls.
 *
 * \return        int32_t to main function
 */

#ifdef SUPPORT_AB

#ifdef NXP_MX8
static int32_t get_partition_info(void)
{
  imx_dcmd_sc_misc_board_ioctl_t  l_data_S = {0};
  int32_t             l_ret_S32 = ENOTSUP;
  int32_t             l_status = -1;
  int32_t             l_scfd_S32;
  
  l_data_S.parm1 = BOARD_CTL_GET_ACTIVE_PARTITON;

  l_scfd_S32 = open(SC_PATH, O_RDWR);
  if (l_scfd_S32 >= 0)
  {
    l_ret_S32 = devctl(l_scfd_S32, IMX_DCMD_SC_OPEN, NULL, 0, &l_status);
    if (l_ret_S32 == EOK)
    {
      l_ret_S32 = devctl(l_scfd_S32, IMX_DCMD_SC_MISC_BOARD_IOCTL, &l_data_S, sizeof(imx_dcmd_sc_misc_board_ioctl_t), &l_status);

      if( EOK == l_ret_S32 )
      {
        gPart_info = l_data_S.parm2;
      }
      else
      {
        LOGE(&gSecQtdMntLogContext, "devctl call failed %d: %s\n", l_scfd_S32, strerror(errno));
      }
      l_ret_S32 = devctl(l_scfd_S32, IMX_DCMD_SC_CLOSE, NULL, 0, &l_status);
      if (l_ret_S32 == EOK)
      {
        LOGI(&gSecQtdMntLogContext, "l_status for IMX_DCMD_SC_CLOSE = %x\n", l_status);
      }
    }
    close( l_scfd_S32 );
  }
  else
  {
    LOGE(&gSecQtdMntLogContext, "/dev/sc open failed %d: %s\n", l_scfd_S32, strerror(errno));
  }

  return l_ret_S32;
}
#endif //NXP_MX8

#ifdef SAM_EXYNOS
static int32_t get_partition_info(void)
{
    uintptr_t l_reg_U32P;
    uint32_t l_val_U32P;
    int32_t l_ret_S32 = ENOTSUP;

    l_reg_U32P = mmap_device_io(4, EXYNOSAUTO_V9_POWER_BASE);
    
    if (l_reg_U32P != MAP_DEVICE_FAILED)
    {
#if defined(CONFIG_SOC_EXYNOSAUTO9_EVT1)
      l_val_U32P = (in32(l_reg_U32P) & OM_STAT_BOOT_MASK_EVT1) >> OM_STAT_BOOT_SHIFT_EVT1;
#else
      l_val_U32P = (in32(l_reg_U32P) & OM_STAT_BOOT_MASK_EVT0) >> OM_STAT_BOOT_SHIFT_EVT0;
#endif
      if (l_val_U32P == OM_STAT_A_VAL) 
      {
          LOGI(&gSecQtdMntLogContext, "Boot A Active\n");
          gPart_info = 0x00000000; //BOOT A Active
      } 
      else 
      {
          LOGI(&gSecQtdMntLogContext, "Boot B Active\n");
          gPart_info = 0xFFFFFFFF; //BOOT B Active
      }
      munmap_device_io(l_reg_U32P, 4);

      l_ret_S32 = EOK;
    }
    
    return l_ret_S32;
}
#endif //SAM_EXYNOS

#ifdef TI_AM62P
static int32_t get_partition_info(void)
{
    int32_t l_ret_S32 = EOK;
    int32_t status;
    EPartition_t partition;

    Metadata_Init();

    status = Metadata_GetActivePartition(ESwPartId_SBL, &partition);
    if(EOK == status)
    {
      if(EPartition_A == partition)
      {
        LOGI(&gSecQtdMntLogContext, "Boot A Active\n");
        gPart_info = 0x00000000; //BOOT A Active
      }
      else if(EPartition_B == partition)
      {
        LOGI(&gSecQtdMntLogContext, "Boot B Active\n");
        gPart_info = 0xFFFFFFFF; //BOOT B Active
      }
      else
      {
        gPart_info = 0x00000000; //BOOT A Active
        LOGE(&gSecQtdMntLogContext, "Invalid Partition %d\n", partition);
        l_ret_S32 = -1;
      }
    }
    return l_ret_S32;
}
#endif

#ifdef QCOM_GEN3
static int32_t get_partition_info(void)
{
    gPart_info = 0x00000000; //BOOT A Active

    return EOK;
}
#endif

#endif

/*!
 * \brief         This function performs bit wise operations to fetch the partition id
 *                Based on the id/number the corresponding partition to be mounted is identified
 *
 *
 * \return        int32_t to parse_config function
 */
#ifdef SUPPORT_AB
static int32_t check_mount_condition ( int32_t p_part_id_S32, int32_t p_part_val_S32 )
{
  int32_t l_ret_S32 = EOK;

  if( ( p_part_id_S32 != -1 ) && (p_part_val_S32 != -1) )
  {
    //we will have p_part_id_S32 as the bit index to traverse the bitmap updated by VIP
    //left shift BIT_MASK by p_part_id_S32 times and perform logical AND with gPart_info

    if( p_part_val_S32 == ((gPart_info >>p_part_id_S32) & BIT_MASK) )
    {
      l_ret_S32 = EOK;
    }
    else
    {
      l_ret_S32 = ENOTSUP;
    }
  }
  return l_ret_S32;
}
#endif
/*!
 * \brief         This function performs mounting operation of QTD type file systems
 *                In case of failure to mount QTD type, as a recovery action, the partition
 *                is formatted to QNX6 and mounted
 *
 *
 * \return        int32_t to parse_config function
 */
#if defined(__QNX__)
static int32_t mount_qtd_fs (const char8_t *dev, const char8_t *mnt, const char8_t *key) {
  int32_t l_ret_S32 = EOK;
  char8_t l_tmp_mnt_U8A[BUFF_SIZE];
  char8_t l_tmp_opt_U8A[BUFF_SIZE];

  if((NULL == dev) || (NULL == key) || (NULL == mnt))
  {
    LOGE(&gSecQtdMntLogContext, "Mount not possible due to NULL pointer: %s\n", strerror(errno));
    l_ret_S32 = -1;
  }
  else
  {

    LOGI(&gSecQtdMntLogContext, "%s %s %s\n", dev, mnt, key);

    (void)memset(l_tmp_mnt_U8A, 0, BUFF_SIZE);
    (void)memset(l_tmp_opt_U8A, 0, BUFF_SIZE);

    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
    (void)snprintf(l_tmp_mnt_U8A, BUFF_SIZE, "/qtd_%s", (char const *) &mnt[1]);
    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
    (void)snprintf(l_tmp_opt_U8A, BUFF_SIZE, "stats,key=%s", (char const *) key);

    /* coverity[cert_int31_c_violation] : FALSE */
    l_ret_S32 = mount(dev, l_tmp_mnt_U8A, 0, TYPE_QTD, l_tmp_opt_U8A, (int32_t)strlen(l_tmp_opt_U8A) + 1);
    if(l_ret_S32 < 0)
    {
      LOGE(&gSecQtdMntLogContext, "Mount Failed %s: %s\n", l_tmp_mnt_U8A, strerror(errno));
    }

    /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
    l_ret_S32 = mount(l_tmp_mnt_U8A, mnt, _MOUNT_READONLY | _MOUNT_NOATIME, TYPE_QNX6, NULL, 0);
    if(l_ret_S32 < 0)
    {
      LOGE(&gSecQtdMntLogContext, "Mount Failed %s: %s\n", mnt, strerror(errno));
    }
  }
  return l_ret_S32;
}
#endif
/*!
 * \brief         This function performs mounting operation of QNX6 type file systems
 *
 *
 * \return        int32_t to parse_config function
 */
static int32_t mount_fs (const char8_t *devPr, const char8_t *fs_type, const char8_t *mnt , const char8_t *option) {
  int32_t l_ret_S32 = EOK;
  
  if((NULL == devPr) || (NULL == fs_type) || (NULL == mnt))
  {
    LOGE(&gSecQtdMntLogContext, "Mount not possible due to NULL pointer: %s\n", strerror(errno));
    l_ret_S32 = -1;
  }
  else
  {
    LOGI(&gSecQtdMntLogContext, "%s %s %s %s\n", devPr, fs_type, mnt, option);

    #if defined(__QNX__)
    if (NULL != option && (0 == strncmp( option, "ro", sizeof("ro"))) )
    {
        l_ret_S32 = mount(devPr, mnt, _MOUNT_READONLY | _MOUNT_NOATIME, fs_type, NULL, 0);
    }
    else
    {
        l_ret_S32 = mount(devPr, mnt, _MOUNT_NOATIME, fs_type, NULL, 0);
    }
    #elif defined(__linux__)
    if (NULL != option && (0 == strncmp( option, "ro", sizeof("ro"))) )
    {
      l_ret_S32 = mount(devPr, mnt, fs_type, MS_NOATIME | MS_RDONLY, NULL);
    }
    else
    {
      l_ret_S32 = mount(devPr, mnt, fs_type, MS_NOATIME, NULL);
    }
    #endif
    if(l_ret_S32 < 0)
    {
      LOGE(&gSecQtdMntLogContext, "Mount Failed %s: %s\n", mnt, strerror(errno));
    }
  }
  return l_ret_S32;
}
/*!
 * \brief         This function performs parsing of JSON configuration file.
 *                This reads/decodes configuration params of each partition and decides the mounting operation
 *
 * \return        int32_t to main function
 */
#if defined(__QNX__)
static int32_t parse_config(const char8_t *file)
{
  int32_t l_ret_S32 = -1;
  json_decoder_error_t err;
  json_decoder_t *dec;
  const char8_t *p_dev_S8P = NULL;
  const char8_t *p_mount_S8P = NULL;
  const char8_t *p_key_S8P = NULL;
  const char8_t *p_fs_type_S8P = NULL;
  const char8_t *p_option_S8P = "rw";
  const char8_t *p_recovery_type_S8P = NULL;
  char *spawnedArgs_dos_format[] = {"mkdosfs", "-F 32", NULL, NULL};
  char *spawnedArgs_qnx6_format[] = {"mkqnx6fs","-q", NULL, NULL};
  char *spawnedEnv[] = {NULL};
  int32_t p_part_id_S32 = -1;
  int32_t p_part_val_S32 = -1;
  pid_t pid;

  dec = json_decoder_create();
  err = json_decoder_parse_file(dec, file);

  if((dec != NULL) && (JSON_DECODER_OK == err))
  {
    err = json_decoder_push_object(dec, NULL, true);
    if(JSON_DECODER_OK == err)
    {
      do
      {
        err = json_decoder_push_object(dec, NULL, true);
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "dev", &p_dev_S8P, false);
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "fs_type", &p_fs_type_S8P, false);
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "mount", &p_mount_S8P, false);
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "key", &p_key_S8P, true);
          if( JSON_DECODER_NOT_FOUND == err )
          {
            /* If no key it is a normal mount */
            err = JSON_DECODER_OK;
          }
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "recovery", &p_recovery_type_S8P, false);
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_string(dec, "option", &p_option_S8P, false);
          if( JSON_DECODER_NOT_FOUND == err )
           {
             /* If no type it is a normal mount read write */
             err = JSON_DECODER_OK;
           }
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_int(dec, "part_id", &p_part_id_S32, true);
          if( JSON_DECODER_NOT_FOUND == err )
          {
            /* If no key it is a normal mount */
            err = JSON_DECODER_OK;
          }
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_get_int(dec, "part_val", &p_part_val_S32, true);
          if( JSON_DECODER_NOT_FOUND == err )
          {
            /* If no key it is a normal mount */
            err = JSON_DECODER_OK;
          }
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_pop(dec);
        }
        if(JSON_DECODER_OK == err)
        {
          err = json_decoder_previous(dec);
        }
        if(JSON_DECODER_OK == err)
        {
#ifdef SUPPORT_AB
          if( EOK == check_mount_condition ( p_part_id_S32, p_part_val_S32 ))
          {
#endif
            if( 0 == strncmp( p_fs_type_S8P, TYPE_QTD, sizeof( TYPE_QTD ) ) )
            {
              l_ret_S32 = mount_qtd_fs(p_dev_S8P, p_mount_S8P, p_key_S8P);
            }
            else
            {
              l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
            }
            if(l_ret_S32 < 0)
            {
              if( 0 == strncmp( p_recovery_type_S8P, FORMAT, sizeof( FORMAT )))
              {
                if(0 == strncmp( p_fs_type_S8P, "dos", sizeof( "dos" )))
                {
                  LOGI(&gSecQtdMntLogContext, "FORMAT of %s partition \n\n", p_dev_S8P);
                  /* coverity[misra_c_2012_rule_11_8_violation] : FALSE */
                  /* coverity[cert_exp40_c_violation] : FALSE */
                  /* coverity[cert_str30_c_violation] : FALSE */
                  spawnedArgs_dos_format[2U] = (char*)p_dev_S8P;
                  l_ret_S32 = posix_spawn(&pid, SYSTEM_PATH_BIN_DOSFS, NULL, NULL, spawnedArgs_dos_format, spawnedEnv);
                  if(l_ret_S32 == 0)
                  {
                    (void)wait(NULL);
                    LOGI(&gSecQtdMntLogContext, "Mounting the formatted partition as recovery action..\n\n");
                    l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
                  }
                }
                  else if(0 == strncmp( p_fs_type_S8P, "qnx6", sizeof( "qnx6" )))
                {
                  LOGI(&gSecQtdMntLogContext, "FORMAT of %s partition \n\n", p_dev_S8P);
                  /* coverity[misra_c_2012_rule_11_8_violation] : FALSE */
                  /* coverity[cert_exp40_c_violation] : FALSE */
                  /* coverity[cert_str30_c_violation] : FALSE */
                  spawnedArgs_qnx6_format[2U] = (char*)p_dev_S8P;

                  l_ret_S32=posix_spawn(&pid, SYSTEM_PATH_BIN_QNX6FS, NULL, NULL, spawnedArgs_qnx6_format, spawnedEnv);
                  if(l_ret_S32 == 0)
                  {
                    (void)wait(NULL);
                    LOGI(&gSecQtdMntLogContext, "Mounting the formatted partition as recovery action..\n\n");
                    l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
                  }
                }
                else
                {
                  l_ret_S32 = EOK;
                } 
              }
              else
              {
                l_ret_S32 = EOK;
              }
            }
#ifdef SUPPORT_AB
          }
          else
          {
            l_ret_S32 = EOK;
          }
#endif
          p_part_id_S32 = -1;
          p_part_val_S32 = -1;
        }
        if(EOK != l_ret_S32)
        {
          break;
        }
      }
      while(JSON_DECODER_OK == json_decoder_next(dec));
    }
  }
  return l_ret_S32;
}
#elif defined(__linux__)
static int32_t parse_config(const char8_t *file)
{
  int32_t l_ret_S32 = -1;
  json_object *root;
  const char8_t *p_dev_S8P = NULL;
  const char8_t *p_mount_S8P = NULL;
  const char8_t *p_fs_type_S8P = "";
  const char8_t *p_recovery_type_S8P = "";
  const char8_t *p_option_S8P = "rw";
  char *spawnedArgs_dos_format[] = {"mkfs.vfat", NULL, NULL, NULL};
  char *spawnedArgs_ext4_format[] = {"mkfs.ext4", NULL, NULL, NULL};
  char *spawnedEnv[] = {NULL};
  #ifdef SUPPORT_AB
  int32_t p_part_id_S32 = -1;
  int32_t p_part_val_S32 = -1;
  #endif
  pid_t pid;

  root = json_object_from_file(file);

  if(root != NULL) 
  {
    json_object_object_foreach(root, key, val)
    {
      (void)key;
      json_object_object_foreach(val, child_key, child_val)
      {
        if(0 == strncmp(child_key, "dev", sizeof("dev")))
        {
          p_dev_S8P = json_object_get_string(child_val);
        }
        else if(0 == strncmp(child_key, "fs_type", sizeof("fs_type")))
        {
          p_fs_type_S8P = json_object_get_string(child_val);
        }
        else if(0 == strncmp(child_key, "mount", sizeof("mount")))
        {
          p_mount_S8P = json_object_get_string(child_val);
        }
        else if(0 == strncmp(child_key, "recovery", sizeof("recovery")))
        {
          p_recovery_type_S8P = json_object_get_string(child_val);
        }
        else if(0 == strncmp(child_key, "option", sizeof("option")))
        {
          p_option_S8P = json_object_get_string(child_val);
        }
        #ifdef SUPPORT_AB
        else if(0 == strncmp(child_key, "part_id", sizeof("part_id")))
        {
          p_part_id_S32 = json_object_get_int(child_val);
        }
        else if(0 == strncmp(child_key, "part_val", sizeof("part_val")))
        {
          p_part_val_S32 = json_object_get_int(child_val);
        }
        #endif
        else
        {
          LOGE (&gSecQtdMntLogContext, "Unknown Key %s\n",  child_key);
        }
      }

      #ifdef SUPPORT_AB
      if( EOK == check_mount_condition ( p_part_id_S32, p_part_val_S32 ))
      #endif
      {
        l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
        if(l_ret_S32 < 0)
        {
          if( 0 == strncmp( p_recovery_type_S8P, FORMAT, sizeof( FORMAT )))
          {
            if(0 == strncmp( p_fs_type_S8P, "dos", sizeof( "dos" )))
            {
              LOGI(&gSecQtdMntLogContext, "FORMAT of %s partition \n\n", p_dev_S8P);
              /* coverity[misra_c_2012_rule_11_8_violation] : FALSE */
              /* coverity[cert_exp40_c_violation] : FALSE */
              /* coverity[cert_str30_c_violation] : FALSE */
              spawnedArgs_ext4_format[1U] = (char*)p_dev_S8P;

              l_ret_S32=posix_spawn(&pid, SYSTEM_PATH_BIN_DOSFS, NULL, NULL, spawnedArgs_dos_format, spawnedEnv);
              if(l_ret_S32 == 0)
              {
                (void)wait(NULL);
                LOGI(&gSecQtdMntLogContext, "Mounting the formatted partition as recovery action..\n\n");
                l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
              }
            }
            else if(0 == strncmp( p_fs_type_S8P, "ext4", sizeof( "ext4" )))
            {
              LOGI(&gSecQtdMntLogContext, "FORMAT of %s partition \n\n", p_dev_S8P);
              /* coverity[misra_c_2012_rule_11_8_violation] : FALSE */
              /* coverity[cert_exp40_c_violation] : FALSE */
              /* coverity[cert_str30_c_violation] : FALSE */
              spawnedArgs_ext4_format[1U] = (char*)p_dev_S8P;

              l_ret_S32=posix_spawn(&pid, SYSTEM_PATH_BIN_EXT4FS, NULL, NULL, spawnedArgs_ext4_format, spawnedEnv);
              if(l_ret_S32 == 0)
              {
                (void)wait(NULL);
                LOGI(&gSecQtdMntLogContext, "Mounting the formatted partition as recovery action..\n\n");
                l_ret_S32 = mount_fs(p_dev_S8P, p_fs_type_S8P, p_mount_S8P, p_option_S8P);
              }
            }
            else
            {
              LOGE (&gSecQtdMntLogContext, "Invalid FS Type %s\n",  p_fs_type_S8P);
            }
          }
        }
      }
#ifdef SUPPORT_AB
      else
      {
        l_ret_S32 = EOK;
      }
      p_part_id_S32 = -1;
      p_part_val_S32 = -1;
#endif
      if(l_ret_S32 < 0)
      {
        break;
      }
    }
  }
  else
  {
    LOGE (&gSecQtdMntLogContext, "Unable to parse %s\n",  file);
  }

  return l_ret_S32;
}
#endif

/*!
 * \brief         Main function to display the usage and initializes the slog2.
 *
 *
 * \return        int32_t (Exception as the return is to KSHELL)
 */
int32_t main(int32_t argc, char8_t * const argv[])
{
  int32_t l_ret_S32 = EXIT_FAILURE;
  int32_t l_opt_S32;
  const char8_t *l_cfg_file_S8P = NULL;

  LOG_REGISTER_APP_SLOG2("SQM","Secure Qtd Mount");
  LOG_REGISTER_CONTEXT(gSecQtdMntLogContext, "SQM", "Secure Qtd Mount Component", DLT_LOG_WARN);
  

#ifdef SUPPORT_AB
  l_ret_S32 = get_partition_info();
  if(l_ret_S32 < 0)
  {
    LOGE (&gSecQtdMntLogContext, "%s", "Unabled to get partition info\n" );
  }
#endif

  l_opt_S32 = getopt(argc, argv, "c:");
  while(l_opt_S32 != -1)
  {
    switch(l_opt_S32)
    {
    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
    case 'c':
      l_cfg_file_S8P = optarg;
      break;
    default:
      //misra
      break;
    }
    l_opt_S32 = getopt(argc, argv, "c:");
  }
  
  if(NULL != l_cfg_file_S8P)
  {
    LOGI(&gSecQtdMntLogContext, "Config file %s\n", l_cfg_file_S8P);
  
    if(EOK == parse_config(l_cfg_file_S8P))
    {
      l_ret_S32 = EXIT_SUCCESS;
    }
    else
    {
      LOGE (&gSecQtdMntLogContext, "%s", "Parsing failed\n");
    }
  }
  else
  {
    LOGI(&gSecQtdMntLogContext, "%s", "Usage:");
    LOGI(&gSecQtdMntLogContext, "%s", "\tsecure_qtd_mount -c <config_file>\n");
  }

  LOG_UNREGISTER_CONTEXT(gSecQtdMntLogContext);

  return l_ret_S32;
}
