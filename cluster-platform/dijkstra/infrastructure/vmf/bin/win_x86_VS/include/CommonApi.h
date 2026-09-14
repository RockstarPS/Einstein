/**
 ******************************************************************************
 *
 *  @file CommonApi.h
 *
 *  @brief Common library API functions.
 *
 *  @copyright This software is Visteon property. Duplication or disclosure
 *             without Visteon written authorization is prohibited.
 *
 *  @note See Common Library SDD for more information.
 *
 ******************************************************************************
*/

#ifndef COMMON_API_H
#define COMMON_API_H

// Needed for struct timespec.
#include <time.h>
#include "GlobalDefs.h"

/******************************************************************************
  Macro Definitions
 ******************************************************************************/

//! This macro is the *nix 0777 (all permissions) in hex used in the mq_open.
//! This obfuscation is necessary, because MISRA demands that octal numbers not
//! be used.
#define ALLPERMISSIONS0777                0x1FF

//! Defaults values for calling terminate process API.
//! PID to be passed for terminating the current process.
#define TERMINATE_THIS_PROCESS            0
//! Default kill retry count.
#define TERMINATE_DEFAULT_RETRY_COUNT     3
//! Time is milliseconds to wait between kill retries.
#define TERMINATE_DEFAULT_WAIT_TIME       50

//! Define maximum lengths for storage fields.
#define STORAGE_DEVICE_MAX_MOUNT_LEN      256
#define STORAGE_DEVICE_FORMAT_LEN         20

//! Define possible permissions for the storage device.
#define STORAGE_DEVICE_READ               ((U8) 0x1)
#define STORAGE_DEVICE_WRITE              ((U8) 0x2)
#define STORAGE_DEVICE_EXEC               ((U8) 0x4)

/******************************************************************************
  Type Definitions
 ******************************************************************************/

//! For standardization, these are defined here as extensions.
typedef struct mq_attr tmq_attr;

//! Trap call back function type.
typedef void (tTrapFunc)(void);

//! Hold the information about a storage device.
typedef struct
{
    //! The mount point path.  Empty means no mount point.
    S8  s8MountPath[STORAGE_DEVICE_MAX_MOUNT_LEN];
    //! Specifies how the device is formatted.  Empty means not formatted.
    S8  s8FormattedAs[STORAGE_DEVICE_FORMAT_LEN];
    //! The read, write and execute permissions.
    U8  u8Premissions;
    //! How much free space, in bytes, on the device.
    U64 u64FreeSpace;
    //! Total size, in bytes, for the device.
    U64 u64TotalSpace;
} tsStorageInfo;

/******************************************************************************
  Function Prototypes
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CommonApiCalls Common Library API Functions
 * @brief Common library API functions.
 * @{
 */

U32            CalculateCrc(U32        fp_u32PreCrc,
                            const void *fp_pvBuffer,
                            U32        fp_u32BufferSize);

S8             *EnvironCoreFilesDir(void);
S8             *EnvironNandDir(void);
S8             *EnvironScratchpadDir(void);

teReturnStatus GetMessageQueueSize(const S8 *fp_ps8Name,
                                   U32      *fp_pu32MaxSize,
                                   U32      *fp_pu32MaxCount);

S32            GetProcessId(S8 *fp_ps8Name);
S8             *GetProcessName(S32 fp_s32Pid);
tsStorageInfo  *GetStorageDeviceInfo(const S8 *fp_ps8Device);
S8             LowerCase(S8 fp_s8Char);

void           NanoSecondToTimespec(struct timespec *fp_psTimespec,
                                    U64             fp_u64NanoSecond);

teReturnStatus SpawnProcess(const S8    *fp_ps8Command,
                            S8   *const *fp_ps8Argv,
                            S8          fp_s8Policy,
                            S32         fp_s32Priority);

void           SetThreadName(const S8 *fp_ps8Name);
U32            StrHash(const void *fp_pvStr);

U16            StrCopy(void       *fp_pvDest,
                       const void *fp_pvSrc,
                       U16        fp_u16MaxLen);

U32            SysFreeMem(void);

U64            TimespecToNanoSecond(const struct timespec *fp_psTimespec);

// teReturnStatus TerminateProcess(S32 fp_s32Pid,
//                                 S32 fp_s32RetryCount,
//                                 U32 fp_u32WaitTimeMs);

teReturnStatus TrapOn(tTrapFunc *fp_ptTrapCallback);
S8             UpperCase(S8 fp_s8Char);

/**
 * @}
 */// End of CommonApiCalls group

#ifdef __cplusplus
}
#endif

#endif
