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
#ifndef UPD_CFG_C_
#define UPD_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
# include "UPD_Cfg.h"
# include "UPDi.h"
# include "UPDi_GipIoAdapter.h"
# include "UPDi_FlsIoAdapter.h"
# include "UPDi_HsmIoAdapter.h"
# include "UPDi_SblIoAdapter.h"
# include "UPDi_HyperFlashIoAdapter.h"
# include "UPDi_TarDecoder.h"
# include "UPDi_AesDecoder.h"
# include "UPDi_LzmaDecoder.h"

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 UPD Buffers                                *
******************************************************************************/
#pragma ghs section bss = ".upd_buffers"
static uint8 oUPD_RootInstallBuffer[cUPDRootInstallBufferSize];
static uint8 oUPD_NestedRootInstallBuffer[cUPDNestedRootInstallBufferSize];
static uint8 oUPD_ChildInstallBuffer[cUPDChildInstallBufferSize];
#pragma ghs section bss = default

tUPDiBufferPool oUPDCdd_Buffers = 
{ 
    .Root.Addr = &oUPD_RootInstallBuffer[0],                .Root.Buffersize = cUPDRootInstallBufferSize, 
    .NestedRoot.Addr = &oUPD_NestedRootInstallBuffer[0],    .NestedRoot.Buffersize = cUPDNestedRootInstallBufferSize,
    .Child.Addr = &oUPD_ChildInstallBuffer[0],              .Child.Buffersize = cUPDChildInstallBufferSize
};

/*****************************************************************************
*                                 UPD Io Adapters                            *
******************************************************************************/
tUPDiIoAdapterRam oCommonIoAdapter_Ram;
                                      /*      Vtbl,                       Ram             */
tUPDiIoAdapter oFlsIoAdapter        = { &UPDFlsIoAdapterVtbl,        &oCommonIoAdapter_Ram };
tUPDiIoAdapter oSblIoAdapter        = { &UPDSblIoAdapterVtbl,        &oCommonIoAdapter_Ram };
tUPDiIoAdapter oHsmIoAdapter        = { &UPDHsmIoAdapterVtbl,        &oCommonIoAdapter_Ram };
tUPDiIoAdapter oHyperFlashoAdapter  = { &UPDHyperFlashIoAdapterVtbl, &oCommonIoAdapter_Ram };

tUPDiIoAdapter* oUPDCdd_IoAdapters[cIoAdaptersCount] = 
{ 
    &oFlsIoAdapter,
    &oHsmIoAdapter,
    &oSblIoAdapter,
    &oHyperFlashoAdapter
};

/*****************************************************************************
*                                 UPD Targets                                *
******************************************************************************/
tUPDiTargetRam oVipAppTarget_Ram;
tUPDiTargetRam oVipHsmTarget_Ram;
tUPDiTargetRam oVipSblTarget_Ram;
tUPDiTargetRam oVipBlUpdaterTarget_Ram;
tUPDiTargetRam oVipHyperFlashTarget_Ram;

tUPDiPartition oVipPartitions[cPartitionsCount] = 
{
    /* Address,         Size,           IoAdapter       */
    { 0x10048000uL, 0x00040000uL, &oFlsIoAdapter        },  /* BLA Partition */
    { 0x10088000uL, 0x00040000uL, &oFlsIoAdapter        },  /* BLB Partition */
    { 0x100C8000uL, 0x00338000uL, &oFlsIoAdapter        },  /* App Partition */
    { 0x10000000uL, 0x00040000uL, &oHsmIoAdapter        },  /* HSM Partition */
    { 0x2804F000uL, 0x00001000uL, &oSblIoAdapter        },  /* SBL Partition */
    { 0x60000000uL, 0x04000000UL, &oHyperFlashoAdapter  },  /* HyperFlash Partition */
};
/* Partition groups */
tUPDiPartitionGroup oVipTarget_Groups[cTargetsCount] =
{
    /* BankA,                   BankB,                  BankExt */
    { &oVipPartitions[0],        &oVipPartitions[1],    NULL    },  /*  BL Target Group */
    { &oVipPartitions[2],        NULL,                  NULL    },  /* App Target Group */
    { &oVipPartitions[3],        NULL,                  NULL    },  /* HSM Target Group */
    { &oVipPartitions[4],        NULL,                  NULL    },  /* SBL Target Group */
    { &oVipPartitions[5],        NULL,                  NULL    },  /* HyperFlash Target Group */
};

tUPDiTarget oVipTargets[cTargetsCount] = 
{ 

    /* Ram,                     Name,       GroupsCount,        Groups*/
    {&oVipBlUpdaterTarget_Ram,  "VipBlUpdater",  1u,        &oVipTarget_Groups[0] },  /*  BL Target */
    {&oVipAppTarget_Ram,        "VipApp",        1u,        &oVipTarget_Groups[1] },  /* App Target */
    {&oVipHsmTarget_Ram,        "VipHsm",        1u,        &oVipTarget_Groups[2] },  /* HSM Target */
    {&oVipSblTarget_Ram,        "VipSbl",        1u,        &oVipTarget_Groups[3] },  /* SBL Target */
    {&oVipHyperFlashTarget_Ram, "VipHyperFlash", 1u,        &oVipTarget_Groups[4] },  /* HyperFlash Target */
};

tUPDiTarget* oUPDCdd_Targets[cTargetsCount] = 
{ 
    &oVipTargets[0],  /*  BL Target */
    &oVipTargets[1],  /* App Target */
    &oVipTargets[2],  /* HSM Target */
    &oVipTargets[3],  /* SBL Target */
    &oVipTargets[4],  /* HyperFlash Target */
};

/*****************************************************************************
*                                 UPD Installers                             *
******************************************************************************/
tUPDiBlockInstaller_Ram oBlockInstaller_Ram;
tUPDiAesDecoder_Ram oAesDecoder_Ram;
tUPDiLzmaDecoderRam oLzmaDecoder_Ram;

                                        /*  Vtbl                    Ram                 */
tUPDiBlockInstaller oBlockInstaller = { &UPDBlockInstaller_Vtbl, &oBlockInstaller_Ram   };
tUPDiAesDecoder     oAesDecoder     = { &UPDAesDecoder_Vtbl,     &oAesDecoder_Ram       };
tUPDiLzmaDecoder    oLzmaDecoder   = { &UPDiLzmaDecoder_vtbl,   &oLzmaDecoder_Ram     };

tUPDiAbstractInstaller* oUPDCdd_Installer[cInstallersCount] = 
{ 
    (tUPDiAbstractInstaller*)&oAesDecoder.Vtbl,         /* Root Installer */
    (tUPDiAbstractInstaller*)&oLzmaDecoder.Vtbl,        /* Nested Root Installer */
    (tUPDiAbstractInstaller*)&oBlockInstaller.Vtbl,     /* Child Installer */
};

/*****************************************************************************
*                                 UPD Main Structure                         *
******************************************************************************/
tUPDiInstallSession oUPDCdd_Sessions[cSessionsCount] ;
tUPDiUpdateCdd oUPDCdd =
{
    .Mode = eUPDiMode_Reprog,
    .TargetsCount = cTargetsCount,.Targets = oUPDCdd_Targets,
    .InstallersCount = cInstallersCount,.Installers = oUPDCdd_Installer,
    .IoAdaptersCount = cIoAdaptersCount,.IoAdapters = oUPDCdd_IoAdapters,
    .SessionsCount = cSessionsCount,.Sessions = oUPDCdd_Sessions, /*root installer,targe ,package size etc abstracted here*/
    .Buffer = &oUPDCdd_Buffers,
};

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
