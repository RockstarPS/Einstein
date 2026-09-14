/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  UPD_Cfg.c                                            *
*  Module Short Name :  Updatecdd                                            *
*  VOBName           :                                                       *
*  Author            : pvaratha                                              *
*  Description       : This file contains the UPD Configurations             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef UPD_CFG_H_
#define UPD_CFG_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
# include "UPDi_types.h"

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
# define TV2_HSM_SIGN_VERIFY                STD_ON 
# define UPD_NESTED_ROOT_SUPPORT            STD_ON
# define eSHE_SUPPORT                       STD_ON

# define cSessionsCount                     5u
# define cTargetsCount                      5u
# define cPartitionsCount                   6u
# define cInstallersCount                   3u
# define cIoAdaptersCount                   4u
# define cVipInfraPGroupsCount              0u

# define cUPDRootInstallBufferSize          (4096u)
# define cUPDNestedRootInstallBufferSize    (4096u)
# define cUPDChildInstallBufferSize         (131072u)

# define APP_START_ADDRESS               0x10088000uL
# define APP_END_ADDRESS                 0x103FFFFFuL
# define HSM_START_ADDRESS               0x10000000uL
# define HSM_END_ADDRESS                 0x1003FFFFuL
# define BL_UPDATER_START_ADDRESS        0x10048000uL
# define BL_UPDATER_END_ADDRESS          0x10087FFFuL
# define SBL_STARTADDRESS                0x28034000uL
# define SBL_ENDADDRESS                  0x28037FFFuL
# define HYPERFLASH_STARTADDRESS         0x60000000uL
# define HYPERFLASH_ENDADDRESS           0x63FFFFFFuL

#if (TV2_HSM_SIGN_VERIFY == STD_ON) 
# define HSM_HRAM_SIGN_VERIFY_ADDRESS    0x80000000uL
#endif

# define TRAVEOMICRO_HSM_STARTADDRESS               0x10000000uL
# define TRAVEOMICRO_HSM_ENDADDRESS                 0x1003FFFFuL
# define TRAVEOMICRO_LARGESECTOR_STARTADDRESS       0x10048000uL
//# define TRAVEOMICRO_LARGESECTOR_STARTADDRESS       0x10088000uL
# define TRAVEOMICRO_LARGESECTOR_ENDADDRESS         0x103EFFFFuL
# define TRAVEOMICRO_SMALLSECTOR_STARTADDRESS       0x103F0000uL
# define TRAVEOMICRO_SMALLSECTOR_ENDADDRESS         0x1040FFFFuL

# define UPD_ROM_DRV_INIT()                 FblFlashDrv_Init()
# define UPD_ROM_WRITE(x,y,z)               FblFlashDrv_Write(x,y,z)
# define UPD_ROM_ERASE(x,y)                 FblFlashDrv_Erase(x,y)

# define UPD_HSM_WRITE(x,y,z)               FblHsmFlashDrv_Write(x,y,z)
# define UPD_HSM_ERASE()                    FblHsmFlashDrv_Erase()
# define UPD_HSM_WAIT_FOR_WRITE_RESPONSE()  FblHsmFlashGetResp_write()
# define UPD_HSM_WAIT_FOR_ERASE_RESPONSE()  FblHsmFlashGetResp_erase()
# define UPD_HSM_PERIODIC()                 FblHsmFlashPeriodic()
# define UPD_HSM_DRV_INIT()                 FblHsmFlashDrv_Init()

# define DEFAULT_IV_VALUE        \
    {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00}

extern tUPDiUpdateCdd oUPDCdd;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
extern Std_ReturnType FblFlashDrv_Write(uint32 addr, uint32 *pLen,  const uint8 *pBuffer);
extern Std_ReturnType FblFlashDrv_Erase(uint32 addr, uint32 len);
extern Std_ReturnType FblHsmFlashDrv_Write(uint32 addr, uint32 *pLen,  const uint8 *pBuffer);
extern Std_ReturnType FblHsmFlashDrv_Erase(void);
extern uint8 FblHsmFlashGetResp_write(void);
extern uint8 FblHsmFlashGetResp_erase(void);
extern void FblHsmFlashPeriodic(void);
extern void FblHsmFlashDrv_Init(void);
extern void FblFlashDrv_Init(void);

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
