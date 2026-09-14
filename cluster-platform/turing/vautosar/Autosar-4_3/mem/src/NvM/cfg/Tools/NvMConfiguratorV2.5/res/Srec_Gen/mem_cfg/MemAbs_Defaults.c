/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  MemAbs_Defaults.c
Module Short Name:  MemAbs_Defaults.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef MEMABS_DEFAULTS_C
#define MEMABS_DEFAULTS_C


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "MemAbs_Defaults.h"
#include "Rte_Type.h"
#include "Rte_MemAbstractMdl.h"
#include "NvMDefaults.h"
#include "MemLib.h"


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block1,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block1,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block2,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block2,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block2,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block2,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block2,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block2,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block3,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block3,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block3,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block3,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block3,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block3(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block3,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block4,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block4,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block4,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block4,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block4,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block4(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block4;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block4,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block5,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block5,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block5,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block5,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block5,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block5(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block5;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block5,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block6,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block6,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block6,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block6,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block6,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block6(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block6;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block6,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_Fingerprint_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_Fingerprint_Block7,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ProgAttempts_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.Share_ProgAttempts_Block7,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCValue_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCValue_Block7,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCStart_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCStart_Block7,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CRCLength_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.CRCLength_Block7,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EraseState_Block7(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblMetaData.EraseState_Block7;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SegmentLengthList_Block7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblMetaData.SegmentLengthList_Block7,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ProgReqFlag(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.ProgReqFlag;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ValidityFlags(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.Share_ValidityFlags;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetResponseFlag(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.ResetResponseFlag;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ApplValidity(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.ApplValidity;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ProgMarker(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.ProgMarker;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SecAccessDelayFlag(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.SecAccessDelayFlag;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SecAccessInvalidCount(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.SecAccessInvalidCount;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BSBlockSizeActive(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.BSBlockSizeActive;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BSBlockSize(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.BSBlockSize;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DcmDslRxTesterSourceAddr(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblGeneral.DcmDslRxTesterSourceAddr;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FblShareDataPartOneReserved1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartOne.FblShareDataPartOneReserved1,sizeof(Arr_u8_10));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_BootloaderTPBlocksize(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblShareDataPartOne.Share_BootloaderTPBlocksize;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWFAZITIdentificationString(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartOne.Share_VWFAZITIdentificationString,sizeof(Arr_u8_23));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FblShareDataPartOneReserved2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartOne.FblShareDataPartOneReserved2,sizeof(Arr_u8_11));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWECUHardwareNumber_Old(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartOne.Share_VWECUHardwareNumber_Old,sizeof(Arr_u8_11));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FblShareDataPartOneReserved(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartOne.FblShareDataPartOneReserved,sizeof(Arr_u8_72));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FblShareDataPartTwoReserved1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.FblShareDataPartTwoReserved1,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ASAM_ODXFileIdentifier_Old(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_ASAM_ODXFileIdentifier_Old,sizeof(Arr_u8_21));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ASAM_ODXFileVersion_Old(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_ASAM_ODXFileVersion_Old,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWECUHardwareVersionNumber_Old(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_VWECUHardwareVersionNumber_Old,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_FDSProjectData(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_FDSProjectData,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ECUProgrammingInformation(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_ECUProgrammingInformation;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_InvalidKeyCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_InvalidKeyCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VWSoftwareVersionNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.VWSoftwareVersionNumber,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_FblShareDataPartTwoReserved(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartTwo.Share_FblShareDataPartTwoReserved,sizeof(Arr_u8_76));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWSparePartNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.Share_VWSparePartNumber,sizeof(Arr_u8_11));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWECUHardwareNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.Share_VWECUHardwareNumber,sizeof(Arr_u8_11));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_ASAM_ODXFileIdentifier_obsolate(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.Share_ASAM_ODXFileIdentifier_obsolate,sizeof(Arr_u8_21));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ASAMFileVersion(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.ASAMFileVersion,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Share_VWECUHardwareVersionNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.Share_VWECUHardwareVersionNumber,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ASAMFileIdentifier(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.ASAMFileIdentifier,sizeof(Arr_u8_26));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FblShareDataPartThreeReserved(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvMFblShareDataPartThree.FblShareDataPartThreeReserved,sizeof(Arr_u8_50));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zIniSwVer(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.zIniSwVer;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_verlassenswarnung_VWN(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.verlassenswarnung_VWN;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ConfigWarning_Schwelle1_Indien(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.ConfigWarning_Schwelle1_Indien;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Slope_m(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Compensation_Line_Slope_m;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Shift_b(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Compensation_Line_Shift_b;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Brightness_Photosensor_Cal_Error(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Brightness_Photosensor_Cal_Error;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Zero_Potential_Display_Active(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Zero_Potential_Display_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Knockout_Ctr(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Knockout_Ctr;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SG_BusKnockout_Ctr(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.SG_BusKnockout_Ctr;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_MO_StartStop_Coded(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.MO_StartStop_Coded;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_tuben_darstellung(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.tuben_darstellung;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Display_FPA(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Display_FPA;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zweitgeschwindigkeit_einheitenwechsel(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.zweitgeschwindigkeit_einheitenwechsel;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_offroad(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.offroad;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_infotainmentlisten(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_infotainmentlisten;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_funktionslisten(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_funktionslisten;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_mfa_anzeigen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_mfa_anzeigen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_dynamische_bilder(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_dynamische_bilder;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_funktionale_animationen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_funktionale_animationen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_schmuckanimationen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_schmuckanimationen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_systemzustandsanimationen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_systemzustandsanimationen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_bedienunterstuetzende_animationen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_bedienunterstuetzende_animationen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_listentimeout(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_listentimeout;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_Karte(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_Karte;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_CarDecorator(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_CarDecorator;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_PiloFahrt(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_PiloFahrt;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_NPSCoverIntensitaet(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_NPSCoverIntensitaet;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sperrung_AnzahlListeneintraege(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sperrung_AnzahlListeneintraege;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_sport(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.sport;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_glaettungsfaktor_g(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.glaettungsfaktor_g;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_size_n(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.size_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TCO_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.TCO_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PHEV_Statistic_Cycle(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.PHEV_Statistic_Cycle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PHEV_Statistic_Distance(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.PHEV_Statistic_Distance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_kombi_variante_e_traktion(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.kombi_variante_e_traktion;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Knockout_Tmr(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Knockout_Tmr;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SG_BusKnockout_Tmr(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.SG_BusKnockout_Tmr;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PCB_Hot_Spot_Threshold(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.PCB_Hot_Spot_Threshold;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Hot_Spot_Temp_Dimm_Time(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Hot_Spot_Temp_Dimm_Time;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PCB_Timer_Temp_Too_Hot(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.PCB_Timer_Temp_Too_Hot;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_mute_delay(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.p_mute_delay;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TFT_RGB_Gain(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Com_Cfg_VAR.TFT_RGB_Gain,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BootloaderTPBlocksize(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.BootloaderTPBlocksize;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Security_InvalidKeyCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Security_InvalidKeyCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Default_AmbientLight_Color_index(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Default_AmbientLight_Color_index;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_Statistics_distance_ZE(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.BAP_BC_MFA_Statistics_distance_ZE;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_Statistics_distance_currentInterval_ZE(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.BAP_BC_MFA_Statistics_distance_currentInterval_ZE;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RangeAvgConsumption_High_CNG(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.RangeAvgConsumption_High_CNG;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_Com_Cfg_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Com_Cfg_VAR.zReserved_1_Com_Cfg_VAR,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FAZIT_Number(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Com_Cfg_VAR.FAZIT_Number,sizeof(Arr_u8_23));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_consum_correction_electro(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.consum_correction_electro;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_edv_charge_suppress(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.edv_charge_suppress;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_negative_calculations_allowed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.negative_calculations_allowed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Default_AmbientLight_Color_CHINA_index(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.Default_AmbientLight_Color_CHINA_index;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_t_ambientlight_delay(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.da_t_ambientlight_delay;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_t_ambientlight_damping(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Com_Cfg_VAR.da_t_ambientlight_damping;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Com_Cfg_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Com_Cfg_VAR.zReserved_Com_Cfg_VAR,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Red_Gamma_Adjustment_Display1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Red_Gamma_Adjustment_Display1,sizeof(Arr_u8_27));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Green_Gamma_Adjustment_Display1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Green_Gamma_Adjustment_Display1,sizeof(Arr_u8_27));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Blue_Gamma_Adjustment_Display1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Blue_Gamma_Adjustment_Display1,sizeof(Arr_u8_27));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Red_Gamma_Adjustment_Display2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Red_Gamma_Adjustment_Display2,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Green_Gamma_Adjustment_Display2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Green_Gamma_Adjustment_Display2,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Blue_Gamma_Adjustment_Display2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Blue_Gamma_Adjustment_Display2,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Gamma_Adjustment_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.zReserved_Gamma_Adjustment_VAR,sizeof(Arr_u8_17));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Gamma_Adjustment_VAR_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Gamma_Adjustment_VAR.Gamma_Adjustment_VAR_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RGB_Color_Calibration_PWM_AmbientLight_Y_Left(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_RGB_Calibration_VAR.RGB_Color_Calibration_PWM_AmbientLight_Y_Left,sizeof(Arr_u8_180));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RGB_Color_Calibration_PWM_AmbientLight_Y_Right(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_RGB_Calibration_VAR.RGB_Color_Calibration_PWM_AmbientLight_Y_Right,sizeof(Arr_u8_180));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraph_Color_Calibration(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_RGB_Calibration_VAR.Bargraph_Color_Calibration,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_RGB_Calibration_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_RGB_Calibration_VAR.zReserved_RGB_Calibration_VAR,sizeof(Arr_u8_12));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Gain_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Gain_Adjustment,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Red_Gamma_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Red_Gamma_Adjustment,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Green_Gamma_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Green_Gamma_Adjustment,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Blue_Gamma_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Blue_Gamma_Adjustment,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Red_Gamma_Pos_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Red_Gamma_Pos_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Green_Gamma_Pos_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Green_Gamma_Pos_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Blue_Gamma_Pos_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Blue_Gamma_Pos_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Red_Gamma_Neg_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Red_Gamma_Neg_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Green_Gamma_Neg_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Green_Gamma_Neg_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Blue_Gamma_Neg_Adjustment(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Blue_Gamma_Neg_Adjustment,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Compensation_Line_Slope_m(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Compensation_Line_Slope_m,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Diag_Compensation_Line_Shift_b(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.Diag_Compensation_Line_Shift_b,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_kilometerstand_last_value_obsolete(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.p_kilometerstand_last_value_obsolete;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Diag_Adjustment_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_Adjustment_VAR.zReserved_Diag_Adjustment_VAR,sizeof(Arr_u8_18));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Left_Red_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Left_Red_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Left_Green_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Left_Green_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Left_Blue_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Left_Blue_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Right_Red_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Right_Red_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Right_Green_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Right_Green_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AmbientLight_Right_Blue_LED_Coef(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.AmbientLight_Right_Blue_LED_Coef;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Thermal_Timer1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Thermal_Timer1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Thermal_Timer2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Thermal_Timer2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Thermal_Timer3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Thermal_Timer3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraphs_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Bargraphs_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraphs_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Bargraphs_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Lookup_Curve_Bargraphs_Red_Coef_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Lookup_Curve_Bargraphs_Red_Coef_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Lookup_Curve_Bargraphs_Red_Coef_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Lookup_Curve_Bargraphs_Red_Coef_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_Year(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_Year,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_Month(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_Month,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_Day(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_Day,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_TimeLastGAP(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_TimeLastGAP,sizeof(Arr_u16_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_Distance(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_Distance,sizeof(Arr_u32_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_FIFO_NumberResets(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_FIFO_NumberResets,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_gap_tage(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.da_gap_tage;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_gap_reset_tage(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.da_gap_reset_tage;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_tage_default(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_tage_default;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_mfa_max(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_mfa_max;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_mfa_min(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_mfa_min;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gap_vorhanden(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gap_vorhanden;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Default_AmbientLight_Color_Green(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Default_AmbientLight_Color_Green;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Default_AmbientLight_Color_Red(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Default_AmbientLight_Color_Red;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Default_AmbientLight_Color_Blue(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.Default_AmbientLight_Color_Blue;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_gastank_warnung_cng_LED(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.gastank_warnung_cng_LED;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GasTank_Display_Attenuation_On(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.GasTank_Display_Attenuation_On;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GasTank_Display_Attenuation_Off(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.GasTank_Display_Attenuation_Off;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GasTank_Duration_Red_LED_Flashing(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.GasTank_Duration_Red_LED_Flashing;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GasTank_Warning_Special_State(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.GasTank_Warning_Special_State;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Nvm_Block_Reserved_4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_4.zReserved_Nvm_Block_Reserved_4,sizeof(Arr_u8_27));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RPM_Gauge_FIR_Coefficients(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_RPM_Gauge_FIR_Coefficients.RPM_Gauge_FIR_Coefficients,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RGB_Color_Calibration_PWM_AmbientLight_X(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_1.RGB_Color_Calibration_PWM_AmbientLight_X,sizeof(Arr_u32_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Bcct_Cfg_VAR_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_1.zReserved_Bcct_Cfg_VAR_1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Dimming_Coef_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Dimming_Coef_X,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Dimming_Coef_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Dimming_Coef_Y,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Left_Temp_Coef_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Left_Temp_Coef_X,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Left_Temp_Coef_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Left_Temp_Coef_Y,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Right_Temp_Coef_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Right_Temp_Coef_X,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Lookup_Curve_AmbientLight_Right_Temp_Coef_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Lookup_Curve_AmbientLight_Right_Temp_Coef_Y,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Temperature_Sensor_AmbientLight_Conv_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Temperature_Sensor_AmbientLight_Conv_X,sizeof(Arr_u16_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BCCT_Temperature_Sensor_AmbientLight_Conv_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.BCCT_Temperature_Sensor_AmbientLight_Conv_Y,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserveed_Bcct_Cfg_VAR_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2.zReserveed_Bcct_Cfg_VAR_2,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RGB_Color_Calibration_PWM_AmbientLight_Y_Display(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bcct_Cfg_VAR_3.RGB_Color_Calibration_PWM_AmbientLight_Y_Display,sizeof(Arr_u32_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTS_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_2.I5CM_ID_NVM_BlockSTS_2,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DisplayDamping_On_Bargraph_Tank(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.DisplayDamping_On_Bargraph_Tank;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DisplayDamping_Off_Bargraph_Tank(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.DisplayDamping_Off_Bargraph_Tank;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_1_Bargraph_VAR(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Reserved_1_Bargraph_VAR;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Old_Tank_Warning_Other_State_do_not_use(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Old_Tank_Warning_Other_State_do_not_use;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraph_Primary_Engine_Type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Bargraph_Primary_Engine_Type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraph_Secondary_Engine_Type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Bargraph_Secondary_Engine_Type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Damping_Indic_Coolnt_Bargrph_ON(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Damping_Indic_Coolnt_Bargrph_ON;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Damping_Indic_Coolnt_Bargrph_OFF(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Bargraph_VAR.Damping_Indic_Coolnt_Bargrph_OFF;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Zreserved_Bargraph_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bargraph_VAR.Zreserved_Bargraph_VAR,sizeof(Arr_u8_12));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_0,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_1,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_2,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_3,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_4,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_5,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_6,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PSO_DataTag_USER_7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.PSO_DataTag_USER_7,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Nvm_Block_Reserved_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Nvm_Block_Reserved_1.zReserved_Nvm_Block_Reserved_1,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTS_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_1.I5CM_ID_NVM_BlockSTS_1,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_3(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_4(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_4;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_5(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_5;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_6(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_6;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_7(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_7;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_8(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_8;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_9(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_9;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_10(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_10;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_11(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_11;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_12(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_12;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_13(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_13;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_14(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_14;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_15(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_15;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_16(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_16;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_17(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_17;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_18(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_18;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_19(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_19;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_20(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_20;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_21(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_21;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_22(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_22;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_23(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_23;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_24(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_24;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_25(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_25;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_26(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_26;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_27(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_27;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_28(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_28;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_29(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_29;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_30(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_30;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_31(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_31;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Refueling_Drainage_32(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Nvm_Block_Reserved_2.Fuel_Vol_Refueling_Drainage_32;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraph_Hysteresis_Coolant(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bargraph_Hysteresis_Coolant.Bargraph_Hysteresis_Coolant,sizeof(Arr_u8_15));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTS_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_0.I5CM_ID_NVM_BlockSTS_0,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bargraph_Treshold_Switch_Coolant(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Bargraph_Treshold_Switch_Coolant.Bargraph_Treshold_Switch_Coolant,sizeof(Arr_u8_15));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTATE_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_2.I5CM_ID_NVM_BlockSTATE_2,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTATE_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_1.I5CM_ID_NVM_BlockSTATE_1,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSTATE_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_0.I5CM_ID_NVM_BlockSTATE_0,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSRM_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_2.I5CM_ID_NVM_BlockSRM_2,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_InternalLogicalSoftwareBlockVersion_EEP(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_EEPVersionInfo_CONST.InternalLogicalSoftwareBlockVersion_EEP,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VWLogicalSoftwareBlockVersion_EEP(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_EEPVersionInfo_CONST.VWLogicalSoftwareBlockVersion_EEP,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSRM_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_1.I5CM_ID_NVM_BlockSRM_1,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Odometer_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Odometer_0.Odometer_0,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Odometer_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Odometer_1.Odometer_1,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockSRM_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_0.I5CM_ID_NVM_BlockSRM_0,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Odometer_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Odometer_2.Odometer_2,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockPARAM_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_2.I5CM_ID_NVM_BlockPARAM_2,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PointerType(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_VAR.PointerType;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Vehicle_Equipment_Code(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_VAR.Vehicle_Equipment_Code,sizeof(Arr_u8_12));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VW_Data_Set_Number(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_VAR.VW_Data_Set_Number,sizeof(Arr_u8_11));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VW_Data_Set_Version(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_VAR.VW_Data_Set_Version,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VW_Workshop_System_Name(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_VAR.VW_Workshop_System_Name,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_EOL_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_VAR.zReserved_DIAG_EOL_VAR,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DIAG_EOL_DiagCfg_CONST_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.DIAG_EOL_DiagCfg_CONST_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RunInMode_Config(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.RunInMode_Config;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RunInMode_Result(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.RunInMode_Result;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Assembly_Plant_Number(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Assembly_Plant_Number,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Equiped_PCB_Reference(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Equiped_PCB_Reference,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Equiped_PCB_Revision(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Equiped_PCB_Revision,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_PCB_Serial_Number(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_PCB_Serial_Number,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Product_Reference(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Product_Reference,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Product_Revision(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Product_Revision,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_SMD_Manufacturing_Date(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_SMD_Manufacturing_Date,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_SMD_Plant_Number(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_SMD_Plant_Number,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Traceability_PIM(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Traceability_PIM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Traceability_Station_Nr(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manuf_Traceability_Station_Nr,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_EOL_DiagCfg_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.zReserved_DIAG_EOL_DiagCfg_CONST,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manufacturing_Mode(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Manufacturing_Mode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Rework_Param_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Rework_Param_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Rework_Param_2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.Rework_Param_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RCC_IZ(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.RCC_IZ;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_DIAG_EOL_DiagCfg_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST.zReserved_1_DIAG_EOL_DiagCfg_CONST,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockPARAM_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_1.I5CM_ID_NVM_BlockPARAM_1,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockPARAM_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_0.I5CM_ID_NVM_BlockPARAM_0,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockLEARN_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_1.I5CM_ID_NVM_BlockLEARN_1,sizeof(Arr_u8_80));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AD_Value_Max_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.AD_Value_Max_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AD_Value_Min_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.AD_Value_Min_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CorrectionCoefficient_k1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.CorrectionCoefficient_k1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CorrectionCoefficient_k2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.CorrectionCoefficient_k2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DIAG_EOL_HWCalib_CONST_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.DIAG_EOL_HWCalib_CONST_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Display_Illum_Max_Level(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Display_Illum_Max_Level;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_Calib_Max_Lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Photosensor_Calib_Max_Lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_Calib_Min_Lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Photosensor_Calib_Min_Lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_QuartzFrequencyOffset(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.QuartzFrequencyOffset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SupplyVoltage_N1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.SupplyVoltage_N1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SupplyVoltage_N2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.SupplyVoltage_N2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SupplyVoltage_V1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.SupplyVoltage_V1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SupplyVoltage_V2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.SupplyVoltage_V2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Calibrated_RGB_Font_Colour_Triple(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Calibrated_RGB_Font_Colour_Triple,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ECT_Gauge_Magnetic_Offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.ECT_Gauge_Magnetic_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PCB_TrackResistance(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.PCB_TrackResistance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RPM_Gauge_Magnetic_Offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.RPM_Gauge_Magnetic_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Speedo_Gauge_Magnetic_Offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Speedo_Gauge_Magnetic_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Tank_Gauge_Magnetic_Offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Tank_Gauge_Magnetic_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Whisper_Mode_Loudness(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Whisper_Mode_Loudness;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_WhitePointCorrectionMethod(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.WhitePointCorrectionMethod;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Whisper_Mode(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Whisper_Mode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReservedAligmnet_DIAG_EOL_HWCalib_CONST(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.zReservedAligmnet_DIAG_EOL_HWCalib_CONST;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Measured_Value_Max_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Measured_Value_Max_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Measured_Value_Min_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.Measured_Value_Min_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PTC_PCB_Derating_step(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.PTC_PCB_Derating_step;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NTC_TFT_Derating_step(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.NTC_TFT_Derating_step;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DURMW(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.DURMW;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_EOL_HWCalib_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST.zReserved_DIAG_EOL_HWCalib_CONST,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Equipped_PCB_Partnumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_PartNumber_CONST.Manuf_Equipped_PCB_Partnumber,sizeof(Arr_u8_18));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manuf_Product_Partnumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_PartNumber_CONST.Manuf_Product_Partnumber,sizeof(Arr_u8_18));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockLEARN_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_2.I5CM_ID_NVM_BlockLEARN_2,sizeof(Arr_u8_80));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE1.USER_PROFILE1,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockLEARN_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_0.I5CM_ID_NVM_BlockLEARN_0,sizeof(Arr_u8_80));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE2.USER_PROFILE2,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE3.USER_PROFILE3,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE4.USER_PROFILE4,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockKEYLC(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEYLC.I5CM_ID_NVM_BlockKEYLC,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE5.USER_PROFILE5,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockKEY_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_2.I5CM_ID_NVM_BlockKEY_2,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE6(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE6.USER_PROFILE6,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockKEY_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_1.I5CM_ID_NVM_BlockKEY_1,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE7(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE7.USER_PROFILE7,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockKEY_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_0.I5CM_ID_NVM_BlockKEY_0,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_USER_PROFILE0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_USER_PROFILE0.USER_PROFILE0,sizeof(Arr_u8_60));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockDL(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockDL.I5CM_ID_NVM_BlockDL,sizeof(Arr_u8_176));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_I5CM_ID_NVM_BlockDET(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockDET.I5CM_ID_NVM_BlockDET,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Measured_Value_Max_Range_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.Measured_Value_Max_Range_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Measured_Value_Min_Range_lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.Measured_Value_Min_Range_lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_Calib_Max_Range_Lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.Photosensor_Calib_Max_Range_Lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_Calib_Min_Range_Lx(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.Photosensor_Calib_Min_Range_Lx;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CoolantTemp_Gauge_Hysteresis_Angle(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.CoolantTemp_Gauge_Hysteresis_Angle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FuelLevel_Gauge_Hysteresis_Angle(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.FuelLevel_Gauge_Hysteresis_Angle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RPM_Gauge_Hysteresis_Angle(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.RPM_Gauge_Hysteresis_Angle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Speedo_Gauge_Hysteresis_Angle(sint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.Speedo_Gauge_Hysteresis_Angle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_EOL_HWCalib_CONST_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1.zReserved_DIAG_EOL_HWCalib_CONST_1,sizeof(Arr_u8_36));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Actual_Language(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.Actual_Language;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_DimOffset_Scale(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.Celeb_DimOffset_Scale;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_t_Celeb_Pause_Until_EndDim_Scale(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.t_Celeb_Pause_Until_EndDim_Scale;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_EndDim_Scale_Curve_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_EndDim_Scale_Curve_X,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_EndDim_Scale_Curve_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_EndDim_Scale_Curve_Y,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_PreStart_Scale_Curve_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_PreStart_Scale_Curve_X,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_PreStart_Scale_Curve_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_PreStart_Scale_Curve_Y,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_StartDim_Scale_Curve_X(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_StartDim_Scale_Curve_X,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Celeb_StartDim_Scale_Curve_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.Celeb_StartDim_Scale_Curve_Y,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_3D_Geschw_verwenden(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.da_3D_Geschw_verwenden;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_schalter_genaue_geschw(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.da_schalter_genaue_geschw;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockInfo_EEP_Units(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.BlockInfo_EEP_Units;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockInfo_EEP_Engine(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.BlockInfo_EEP_Engine;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockInfo_EEP_Platform(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.BlockInfo_EEP_Platform;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockInfo_EEP_Market(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Cluster_Settings.BlockInfo_EEP_Market;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Cluster_Settings(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Cluster_Settings.zReserved_Cluster_Settings,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DIAG_VariantCoding_CONST_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.DIAG_VariantCoding_CONST_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_CarBody(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_CarBody;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Compass_Position(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Compass_Position;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Date(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Date,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Language(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Language;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Pointer_Kl_58(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Pointer_Kl_58;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_SeatbeltWarning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_SeatbeltWarning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Shop_Code(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Shop_Code,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Staging(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Staging;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_StartUp_Screen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_StartUp_Screen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_DateFormat(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_DateFormat;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_FuelConsumption(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_FuelConsumption;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_FuelConsumption_Gas(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_FuelConsumption_Gas;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Pressure(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Pressure;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Volume(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Volume;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Weight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Weight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Variant(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Fuel_Variant;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_K_Number(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.K_Number;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Acceleration_Display_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Acceleration_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bc_Display_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Bc_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_4WD_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_4WD_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_ACC_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_ACC_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_AFS_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_AFS_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_ARA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_ARA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_ASTA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_ASTA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Audio_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Audio_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_AWV_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_AWV_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_AWV_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_AWV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_BCmE_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_BCmE_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_BVA_with_BKL(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_BVA_with_BKL;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Car_Leaving_Warning_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Car_Leaving_Warning_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Damper_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Damper_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_DayIlluminationPointers(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_DayIlluminationPointers;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_DayIlluminationScales(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_DayIlluminationScales;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_eCall_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_eCall_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_ELV_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_ELV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Epb_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Epb_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_EPS_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_EPS_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_FCWP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_FCWP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_HRE_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_HRE_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Hybrid_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Hybrid_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Hybrid_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Hybrid_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Joker_Button_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Joker_Button_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_KeyWarning(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_KeyWarning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Laptimer(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Laptimer;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_LDW_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_LDW_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_LDW_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_LDW_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Navigation_Compass_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Navigation_Compass_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_PEA_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_PEA_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_PedestrianAssist_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_PedestrianAssist_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Personalization_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Personalization_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_PLA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_PLA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_PLA3_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_PLA3_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_QSP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_QSP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_RDK_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_RDK_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_RDK_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_RDK_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Right_Drive(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Right_Drive;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_RKA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_RKA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_SDS_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_SDS_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_StartStopReasons_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_StartStopReasons_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_SWA_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_SWA_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_SWA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_SWA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_TCO_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_TCO_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Telephone_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Telephone_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_ClockFormat(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_ClockFormat;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_OdoTripDistance(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_OdoTripDistance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Speed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Speed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Temperature(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Temperature;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_V_Warning_Legal(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_V_Warning_Legal;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_VZA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_VZA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_WBA_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_WBA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Customer_Request_Flag(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Customer_Request_Flag;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Dig_OilTemp_Display_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Dig_OilTemp_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DTC_ECU_not_coded(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.DTC_ECU_not_coded;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GRA_High_Display_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.GRA_High_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_OutsideTemperature_Indication(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.OutsideTemperature_Indication;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RefulledVolume_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.RefulledVolume_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_V_Warning_Legal_India(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.V_Warning_Legal_India;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Digital_Key_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Digital_Key_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_IAA_PSO_BAP_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_IAA_PSO_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Telephone2_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Telephone2_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_two_keys(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_two_keys;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Production_Mode_Acoustic(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Production_Mode_Acoustic;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_BMS_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_BMS_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Unit_Consumption_Electrical(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Unit_Consumption_Electrical;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Production_Mode_Key_Lock(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Production_Mode_Key_Lock;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_ADA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_ADA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_VariantCoding_CONST_Handle(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.zReserved_DIAG_VariantCoding_CONST_Handle,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zIniSwVer_DIAG_VariantCoding_CONST(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.zIniSwVer_DIAG_VariantCoding_CONST;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_AGA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_AGA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_EBKV_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_EBKV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_Ignition_EV_LowVoltage(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_Ignition_EV_LowVoltage;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coding_KFG_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.Coding_KFG_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_DIAG_VariantCoding_CONST(boolean* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST.zReserved_1_DIAG_VariantCoding_CONST,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_ExternalFunctionControl_Set_Controlcode(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_ExternalFunctionControl_Set_Controlcode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_ExternalFunctionControl_Status_Installation(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_ExternalFunctionControl_Status_Installation;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_COMPONENTS_Cfg_VAR_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.COMPONENTS_Cfg_VAR_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Immo_DtcLastTestResult(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.Immo_DtcLastTestResult;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_V_Customer_SpeedThreshold(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.V_Customer_SpeedThreshold;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_FSG_Setup_Status_Installation1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_FSG_Setup_Status_Installation1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_FSG_Setup_Status_Installation2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_FSG_Setup_Status_Installation2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_FSG_Setup_Status_SecondaryEngineType(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_FSG_Setup_Status_SecondaryEngineType;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue1_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue1_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue1_2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue1_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue2_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue2_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue2_2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue2_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue3_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue3_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Menue3_2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Menue3_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_MenueSetup_Status_Special(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.BAP_BC_MFA_MenueSetup_Status_Special;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_bcme_consumption_unit(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.bcme_consumption_unit;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DLS_Auto_Day(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.DLS_Auto_Day;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DLS_Auto_Hour(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.DLS_Auto_Hour;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DLS_Auto_Minute(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.DLS_Auto_Minute;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DLS_Auto_Month(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.DLS_Auto_Month;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DLS_Auto_State(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.DLS_Auto_State;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EMSG_Mode_Active(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.EMSG_Mode_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_BR_Systemart(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.p_BR_Systemart;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_primary_engine_type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.primary_engine_type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ROE_Config(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.ROE_Config,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_secondary_engine_type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.secondary_engine_type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Time_TimeSource(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.Time_TimeSource;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vehicle_type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.vehicle_type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_bcme_consumer_available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.bcme_consumer_available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Hmi_Variant(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.Hmi_Variant;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_MFL_Valid(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.MFL_Valid;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_QRS_Mode_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.QRS_Mode_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_T_Mode_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.T_Mode_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_V_Customer_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.V_Customer_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Unit_KWh_per_mile_available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.Unit_KWh_per_mile_available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Unit_mpge_us_available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.Unit_mpge_us_available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_COMPONENTS_Cfg_VAR(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.zReserved_COMPONENTS_Cfg_VAR;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_kilometerstand_last_value(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.p_kilometerstand_last_value;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_COMPONENTS_Cfg_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR.zReserved_1_COMPONENTS_Cfg_VAR,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Service_History(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Service_History_Data.Service_History,sizeof(Arr_u32_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DtcAging(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DtcAgingAdminDataBlock.DtcAging,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Language(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Language;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_CarBody(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_CarBody;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_4WD_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_4WD_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_ACC_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_ACC_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Acceleration_Display_Available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Acceleration_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_AFS_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_AFS_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_ARA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_ARA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_ASTA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_ASTA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Audio_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Audio_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_AWV_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_AWV_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_AWV_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_AWV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Bc_Display_Available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Bc_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_BCmE_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_BCmE_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_BVA_with_BKL(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_BVA_with_BKL;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Car_Leaving_Warning_Available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Car_Leaving_Warning_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Compass_Position(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Compass_Position;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Damper_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Damper_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_DayIlluminationPointers(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_DayIlluminationPointers;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_DayIlluminationScales(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_DayIlluminationScales;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Dig_OilTemp_Display_Available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Dig_OilTemp_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_eCall_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_eCall_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_ELV_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_ELV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Epb_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Epb_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Eps_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Eps_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_FCWP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_FCWP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Telephone2_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Telephone2_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_GRA_High_Display(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_GRA_High_Display;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_HRE_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_HRE_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Hybrid_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Hybrid_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Hybrid_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Hybrid_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Joker_Button_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Joker_Button_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.Reserved_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Key_Warning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Key_Warning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Laptimer(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Laptimer;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_LDW_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_LDW_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_LDW_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_LDW_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Navigation_Compass_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Navigation_Compass_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_OutsideTemperature_Indication(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_OutsideTemperature_Indication;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_PEA_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_PEA_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_PedestrianAssist_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_PedestrianAssist_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Personalization_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Personalization_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_PLA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_PLA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_PLA3_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_PLA3_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Pointer_Kl_58(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Pointer_Kl_58;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_QSP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_QSP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_RDK_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_RDK_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_RDK_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_RDK_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_RefulledVolume_Available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_RefulledVolume_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Right_Drive(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Right_Drive;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_RKA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_RKA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_SDS_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_SDS_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_SeatbeltWarning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_SeatbeltWarning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Staging(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Staging;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_StartStopReasons_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_StartStopReasons_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_StartUp_Screen(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_StartUp_Screen;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_SWA_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_SWA_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_SWA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_SWA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Telephone_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Telephone_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_ClockFormat(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_ClockFormat;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_DateFormat(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_DateFormat;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_FuelConsumption(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_FuelConsumption;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_IAA_PSO_BAP_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_IAA_PSO_BAP_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Language_Ext(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Language_Ext;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Language_Ext1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Language_Ext1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_OdoTripDistance(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_OdoTripDistance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Pressure(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Pressure;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Speed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Speed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Temperature(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Temperature;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Volume(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Volume;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Weight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Weight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_V_Warning_Legal(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_V_Warning_Legal;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_VZA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_VZA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_WBA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_WBA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_AGA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_AGA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_EBKV_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_EBKV_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Consumption_Electric(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Consumption_Electric;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Ignition_EV_LowVoltage(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Ignition_EV_LowVoltage;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_KFG_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_KFG_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Fuel_Variant(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Fuel_Variant;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_K_Number(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_K_Number;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_FuelConsumption_Gas(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_FuelConsumption_Gas;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Digital_Key_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Digital_Key_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Two_Keys_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Two_Keys_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_ADA_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_ADA_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_2_DIAG_VariantCodingCheck_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.zReserved_2_DIAG_VariantCodingCheck_CONST,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_VariantCodingCheck_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.zReserved_DIAG_VariantCodingCheck_CONST,sizeof(Arr_u8_51));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Telephone2_Installed_Obsolete(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Telephone2_Installed_Obsolete,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CodingCheck_Unit_Consumption_Electric_Obsolete(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.CodingCheck_Unit_Consumption_Electric_Obsolete,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_DIAG_VariantCodingCheck_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST.zReserved_1_DIAG_VariantCodingCheck_CONST,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID_Kessy(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID_Kessy;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID4(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID4;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID5(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID5;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID6(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID6;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID7(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID7;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ServiceKey_Counter_Key_ID8(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.ServiceKey_Counter_Key_ID8;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SKey_Error_Counter(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_ServiceKey_VAR.SKey_Error_Counter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_ServiceKey_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_ServiceKey_VAR.zReserved_ServiceKey_VAR,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_Elapsed_Km(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_Elapsed_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_SootContamination_Sum(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_SootContamination_Sum;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_ThermalWear_Sum(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_ThermalWear_Sum;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DailyMileage(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.DailyMileage;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_Elapsed_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_Elapsed_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_Elapsed_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_Elapsed_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_MaxNext_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_MaxNext_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_MaxNext_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_MaxNext_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_ResetValue_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_ResetValue_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Inspection_ResetValue_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Inspection_ResetValue_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_Elapsed_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_Elapsed_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_FixedNext_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_FixedNext_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_FixedNext_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_FixedNext_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_Theoretic_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_Theoretic_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_VariableMaxNext_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_VariableMaxNext_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_VariableMaxNext_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_VariableMaxNext_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_VariableMinNext_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_VariableMinNext_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_VariableMinNext_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_VariableMinNext_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Oil_Exceeded_Days(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.p_Oil_Exceeded_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Oil_Exceeded_Km(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.p_Oil_Exceeded_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_Quality(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_Quality;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Oil_Reset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Oil_Reset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Service_PreWarning_Days(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Service_PreWarning_Days;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Coolant_Cold_Indication_Present(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.Coolant_Cold_Indication_Present;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_AC_ServiceCfg_VAR(boolean* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR.zReserved_DIAG_AC_ServiceCfg_VAR,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockingDistanceVehicleMoving(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.BlockingDistanceVehicleMoving;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Lookup_Compression_Curve_Photosensor_Bus_Coef_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Lookup_Compression_Curve_Photosensor_Bus_Coef_X,sizeof(Arr_u16_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SaveTimeEngineOff(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.SaveTimeEngineOff;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlackIceThresholdHighTemp(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.BlackIceThresholdHighTemp;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlackIceThresholdLowTemp(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.BlackIceThresholdLowTemp;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlockingTimeVehicleMoving(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.BlockingTimeVehicleMoving;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CoolantTemperatureDelta(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.CoolantTemperatureDelta;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Forcewrite_Qual_Time(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Forcewrite_Qual_Time;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Lookup_Compression_Curve_Photosensor_Bus_Coef_Y(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Lookup_Compression_Curve_Photosensor_Bus_Coef_Y,sizeof(Arr_u8_5));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Offset_Color_Blue(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Offset_Color_Blue;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Offset_Color_Green(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Offset_Color_Green;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Offset_Color_Red(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Offset_Color_Red;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SaveTimeDisplayOff(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.SaveTimeDisplayOff;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SlewRate(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.SlewRate;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SpeedThreshold(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.SpeedThreshold;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TimeConstant(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.TimeConstant;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Trend_Threshold(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Trend_Threshold;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TrendTime(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.TrendTime;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VCOM_Adjustment(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.VCOM_Adjustment;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Write_Delay_Speed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Write_Delay_Speed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Write_Delay_Time(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Write_Delay_Time;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Write_Distance(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Write_Distance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Deactivate_SK_Function(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Deactivate_SK_Function;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FAS_menu_ACC(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.FAS_menu_ACC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FAS_menu_GRA(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.FAS_menu_GRA;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FAS_menu_LIM(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.FAS_menu_LIM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_AuxHeater_Consumption_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Fuel_AuxHeater_Consumption_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Main_Switch_Basis(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Main_Switch_Basis;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Main_Switch_Keyless(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.Main_Switch_Keyless;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TrGW_Function_Enable(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.TrGW_Function_Enable;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_personalisation_2x_active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.personalisation_2x_active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_rwdv_cng_default(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.vkmrw_rwdv_cng_default;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_rwdv_lpg_default(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.vkmrw_rwdv_lpg_default;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RangeAvgConsumption_High_LPG(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1.RangeAvgConsumption_High_LPG;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Date_Year(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DATE_VAR.Date_Year;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Date_Day(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DATE_VAR.Date_Day;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Date_Month(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DATE_VAR.Date_Month;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_bap_bc_mfa_SpeedWarning_Speed_Value(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.bap_bc_mfa_SpeedWarning_Speed_Value;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_DIAG_AdaptationChannel_VAR_0_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.DIAG_AdaptationChannel_VAR_0_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Vol_Dead(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Calib_Vol_Dead;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Vol_Filled(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Calib_Vol_Filled;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RangeAvgConsumption_High(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.RangeAvgConsumption_High;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_t_DisplayDelay_KL15Off(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.t_DisplayDelay_KL15Off;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_t_DisplayDelay_KL15On(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.t_DisplayDelay_KL15On;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VKM_Range_RangeAvgConsumptiom_Default(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.VKM_Range_RangeAvgConsumptiom_Default;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Adaption_SeatbeltWarning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Adaption_SeatbeltWarning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_bap_bc_mfa_SpeedWarning_Speed_Unit(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.bap_bc_mfa_SpeedWarning_Speed_Unit;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_bap_bc_mfa_SpeedWarning_State(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.bap_bc_mfa_SpeedWarning_State;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bc_Layer3_Auto_Reset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Bc_Layer3_Auto_Reset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bc_Layer3_Auto_Reset_Gas(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Bc_Layer3_Auto_Reset_Gas;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bc_Layer3_Manual_Reset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Bc_Layer3_Manual_Reset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Calibration_Date(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Calibration_Date,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Calibration_Shop_Code(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Calibration_Shop_Code,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ConsumptionCorrection(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.ConsumptionCorrection;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ConsumptionCorrection_Cng(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.ConsumptionCorrection_Cng;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Full_Offset(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Calib_Full_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Offset_Sensor_1(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Offset_Sensor_1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Offset_Sensor_2(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Offset_Sensor_2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Offset_Sensor_3(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Offset_Sensor_3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Offset_Sensor_4(sint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Fuel_Offset_Sensor_4;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Hmi_Skinning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Hmi_Skinning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_hmi_t_RearBelt(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.hmi_t_RearBelt;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Ignition_Active_Message(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Ignition_Active_Message;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Seatbelt_Rear_Delaytime_acoustic(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Seatbelt_Rear_Delaytime_acoustic;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Seatbelt_Rear_Displaytime_buckle(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Seatbelt_Rear_Displaytime_buckle;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Seatbelt_Rear_speed_blinking_off(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Seatbelt_Rear_speed_blinking_off;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Seatbelt_Rear_speed_blinking_on(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Seatbelt_Rear_speed_blinking_on;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Seatbelt_SBR_Installed(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Seatbelt_SBR_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SynchronizationTime_DriversDoor(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.SynchronizationTime_DriversDoor;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VKM_Range_Distance_Unclass(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.VKM_Range_Distance_Unclass;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_Debug_Mode_enabled(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.BAP_Debug_Mode_enabled;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CylinderDeactivation_Active(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.CylinderDeactivation_Active;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Display_Save_CP(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Display_Save_CP;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Picture_Upload_Download(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Picture_Upload_Download;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ProductionMode(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.ProductionMode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RollTestStandMode(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.RollTestStandMode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Vehicle_Network(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Vehicle_Network;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_lautstaerke_offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.lautstaerke_offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_tachoendwert(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.tachoendwert;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_skinning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.skinning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Bc_Layer3_Auto_Reset_EV(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.Bc_Layer3_Auto_Reset_EV;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_V_Config_WarningThreshold1_Indien(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0.V_Config_WarningThreshold1_Indien;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ACC_Darstellung(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.ACC_Darstellung;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_hmi_anteil_gas_aktiv(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.hmi_anteil_gas_aktiv;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_gesamtreichweite_vorhanden(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.vkmrw_gesamtreichweite_vorhanden;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_verbrauchsfaktor_kombi(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.vkmrw_verbrauchsfaktor_kombi;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_Verbrauchsaequivalent_ein(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.vkmrw_Verbrauchsaequivalent_ein;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_vkmrw_Verbrauchsaequivalent(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.vkmrw_Verbrauchsaequivalent;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_rw_fahrzg_steht(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.rw_fahrzg_steht;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_rw_fahrzg_faehrt(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.rw_fahrzg_faehrt;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_AdaptationChannel_VAR_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2.zReserved_DIAG_AdaptationChannel_VAR_2,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Odometer_Log_n(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Odometer_Log_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Odometer_Log_n1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Odometer_Log_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Odometer_Log_n2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Odometer_Log_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Odometer_Log_n3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Odometer_Log_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Display_Old_Log_n(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Display_Old_Log_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Display_Old_Log_n1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Display_Old_Log_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Display_Old_Log_n2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Display_Old_Log_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Display_Old_Log_n3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Display_Old_Log_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Ref_Log_n(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Ref_Log_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Ref_Log_n1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Ref_Log_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Ref_Log_n2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Ref_Log_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Ref_Log_n3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Ref_Log_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_RefuelHandling_Log_n(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_RefuelHandling_Log_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_RefuelHandling_Log_n1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_RefuelHandling_Log_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_RefuelHandling_Log_n2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_RefuelHandling_Log_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_RefuelHandling_Log_n3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_RefuelHandling_Log_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n3(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_Vol_Sensor_Avrg_RefuelHandling_Log_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_RefuelDetect_Log_Error_n(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_RefuelDetect_Log_Error_n;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_RefuelDetect_Log_Error_n1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_RefuelDetect_Log_Error_n1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_RefuelDetect_Log_Error_n2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_RefuelDetect_Log_Error_n2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_RefuelDetect_Log_Error_n3(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_REFUEL_Logger_VAR.Fuel_RefuelDetect_Log_Error_n3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_REFUEL_Logger_VAR(boolean* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_REFUEL_Logger_VAR.zReserved_REFUEL_Logger_VAR,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Brightness_Photosensor_Cal_Init(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Brightness_Photosensor_Cal_Init;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant_Canada(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant_Canada;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Brightness_Photosensor_Damp_Dimm_Down(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Brightness_Photosensor_Damp_Dimm_Down;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Brightness_Photosensor_Damp_Dimm_Up(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Brightness_Photosensor_Damp_Dimm_Up;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_COMPONENTS_Cfg_CONST_Safety_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.COMPONENTS_Cfg_CONST_Safety_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RunIn_FinalPointerPositions(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.RunIn_FinalPointerPositions,sizeof(Arr_u16_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SpeedFastReading_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.SpeedFastReading_X,sizeof(Arr_u16_10));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SpeedFastReading_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.SpeedFastReading_Y,sizeof(Arr_u16_10));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BAP_BC_MFA_FSG_Setup_Status_PrimaryEngineType(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.BAP_BC_MFA_FSG_Setup_Status_PrimaryEngineType;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Brand_Info(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Brand_Info;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant_ASIA(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant_ASIA;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant_CHINA(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant_CHINA;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant_USA(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant_USA;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Display_Type(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Display_Type;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ego_fahrzeug(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.ego_fahrzeug,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Consumption_Min(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Fuel_Consumption_Min;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_COMPONENTS_Cfg_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.zReserved_COMPONENTS_Cfg_CONST,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_available(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Photosensor_available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RunIn_FuelADC_Max(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.RunIn_FuelADC_Max;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RunIn_FuelADC_Min(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.RunIn_FuelADC_Min;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Service_Early_Warning_Prediction(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Service_Early_Warning_Prediction;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_t_Max_Delay_CLWError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.t_Max_Delay_CLWError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Analog_CoolantTemperature_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Analog_CoolantTemperature_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Cluster_Variant_FBU(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Cluster_Variant_FBU;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Immo_Individual_Schluessel_Fahrberecht(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Immo_Individual_Schluessel_Fahrberecht;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_LIM_Display_Available(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.LIM_Display_Available;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_OutsideTemperature_Exclusive_DisplayArea(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.OutsideTemperature_Exclusive_DisplayArea;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SWA_Telltales_Installed(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.SWA_Telltales_Installed;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_UnintendedMovement(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.UnintendedMovement;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Unit_SpeedoScale(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.Unit_SpeedoScale;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_canrw_initzeit(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.p_canrw_initzeit;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Perso_NumberOfUserProfiles(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.p_Perso_NumberOfUserProfiles;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_total_distance_pass_jump(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.total_distance_pass_jump;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_WLTP_Concept(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.WLTP_Concept;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_anzahl_tueren(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.da_anzahl_tueren;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_1_COMPONENTS_Cfg_CONST(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.zReserved_1_COMPONENTS_Cfg_CONST;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zIniSwVer_COMPONENTS_Cfg_CONST(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.zIniSwVer_COMPONENTS_Cfg_CONST;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Hmi_TripDistance_Max_Km(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.p_Hmi_TripDistance_Max_Km;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Hmi_TripDistance_Max_Miles(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST.p_Hmi_TripDistance_Max_Miles;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_rw_calc_time(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.rw_calc_time;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Dry_Max(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_Dry_Max;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_DryCalibration(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_DryCalibration;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Full_Max(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_Full_Max;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_FullCalibration(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_FullCalibration;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_2_TANK_Variant_CONST(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.zReserved_2_TANK_Variant_CONST;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_Wet_Max(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_Wet_Max;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Fuel_Calib_WetCalibration(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_TANK_Variant_CONST.Fuel_Calib_WetCalibration;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_3_TANK_Variant_CONST(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_TANK_Variant_CONST.zReserved_3_TANK_Variant_CONST,sizeof(Arr_u8_10));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CAN_DEV_Monitoring_Blocks(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Dev_Messages.CAN_DEV_Monitoring_Blocks,sizeof(Arr_u8_20));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CAN_DEV_Monitoring_Status(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Dev_Messages.CAN_DEV_Monitoring_Status;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DEV_Messages(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Dev_Messages.zReserved_DEV_Messages,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AdcTicks_0xA00044(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.AdcTicks_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AdcTicks_0xA00049(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.AdcTicks_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00000(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00000;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00040(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00040;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00041(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00041;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00042(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00042;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00043(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00043;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00044(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterState_0xA00049(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterState_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HmiZpm_0xA00044(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.HmiZpm_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AcuRequest_0xA00044(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.AcuRequest_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AcuStatus_0xA00044(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.AcuStatus_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00000(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00000;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00040(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00040;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00041(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00041;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00042(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00042;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00043(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00043;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00044(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BattVoltage_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BattVoltage_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00000(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00000;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00040(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00040;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00041(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00041;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00042(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00042;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00043(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00043;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00044(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ClusterFunction_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ClusterFunction_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Counter_RamError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.Counter_RamError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ErrorType_0xA00041(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ErrorType_0xA00041;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ErrorType_0xA00042(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ErrorType_0xA00042;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ErrorType_0xA00044(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ErrorType_0xA00044;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_MDO_EN_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.MDO_EN_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_ClockMon(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_ClockMon;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_EcuReset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_EcuReset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_JumpToZero(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_JumpToZero;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_POR(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_POR;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_StackMonitor(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_StackMonitor;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_TimeoutModule(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_TimeoutModule;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_Trap(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_Trap;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_Trap_GS(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_Trap_GS;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_WD(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_WD;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_WD_GS(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_WD_GS;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CTRL_App(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CTRL_App;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CTRL_Warning(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CTRL_Warning;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_ADC(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_ADC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_IOC(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_IOC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_SafeTTMonitor(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_SafeTTMonitor;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_Sound(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_Sound;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_IoHwAb(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_IoHwAb;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_MDL_BCCT(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_MDL_BCCT;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_MDL_CarModes(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_MDL_CarModes;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_Cfg_Safety(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_Cfg_Safety;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_Power(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_Power;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_VIEW_Sound(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_VIEW_Sound;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_ComExt_TaskFast(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_ComExt_TaskFast;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_BURAMMarkerInvalid(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_BURAMMarkerInvalid;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_BuramChecksumError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_BuramChecksumError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_RamHashError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_RamHashError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_EcuMErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_EcuMErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_DeepStopNotEntered(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_DeepStopNotEntered;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_EcuM_BswErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_EcuM_BswErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_TmrFailure(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_TmrFailure;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_ComExt_Task50(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_ComExt_Task50;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_DisplayMonitor(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_DisplayMonitor;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_MemTest(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_MemTest;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_ECC_Error(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_ECC_Error;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_MPU_Error(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_MPU_Error;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CSV_Error(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CSV_Error;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_Illum(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_Illum;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_TFT_alive(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_TFT_alive;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_backlight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_backlight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_CXDR_Sensors(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_CXDR_Sensors;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SiWalaACT_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.SiWalaACT_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SiWalaActive_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.SiWalaActive_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SiWalaExpState_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.SiWalaExpState_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SiWalaId_0xA00049(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.SiWalaId_0xA00049;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_MDL_Immobilizer(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_MDL_Immobilizer;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_MDL_SiWaLa(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_MDL_SiWaLa;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_SRV_Monitor(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_SRV_Monitor;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BlackScreen_Reason(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.BlackScreen_Reason;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_LastResetReason(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_LastResetReason;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_RendererTaskError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_RendererTaskError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_HMITaskError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_HMITaskError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_DpMainTaskError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_DpMainTaskError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_GuiQueueError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_GuiQueueError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_DpQueueError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_DpQueueError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_EventQueueError(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.ResetCounter_EventQueueError;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Recorder_VAR(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR.zReserved_Recorder_VAR;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_OperatingTimeStoredLSB(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_OperatingTime_VAR.OperatingTimeStoredLSB;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_OperatingTimeStoredMSB(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_OperatingTime_VAR.OperatingTimeStoredMSB;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_OperatingTime_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_OperatingTime_VAR.zReserved_OperatingTime_VAR,sizeof(Arr_u8_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scales_Day_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Scales_Day_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scales_Day_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Scales_Day_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scales_Night_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Scales_Night_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scales_Night_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Scales_Night_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scale_Luminosity_Calibration_PWM(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Scale_Luminosity_Calibration_PWM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_FPK_zeigerdaempfung_drehzahl(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.FPK_zeigerdaempfung_drehzahl;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_DIAG_AC_Curve_Scales_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR.Reserved_DIAG_AC_Curve_Scales_VAR,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Display_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.PWM_Display_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Display_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.PWM_Display_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Pointer_xd_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.PWM_Pointer_xd_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Pointer_xd_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.PWM_Pointer_xd_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TT_Red_Luminosity_Calibration_PWM(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.TT_Red_Luminosity_Calibration_PWM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TT_Green_Luminosity_Calibration_PWM(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.TT_Green_Luminosity_Calibration_PWM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TT_Yellow_Luminosity_Calibration_PWM(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.TT_Yellow_Luminosity_Calibration_PWM;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_DIAG_AC_IlluminationCfg_VAR_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0.Reserved_DIAG_AC_IlluminationCfg_VAR_0,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Damping_CurveSwitch(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.PWM_Damping_CurveSwitch;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Pointer_xt_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.PWM_Pointer_xt_X,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PWM_Pointer_xt_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.PWM_Pointer_xt_Y,sizeof(Arr_u16_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Debouncing_AutomaticDrivingLight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Debouncing_AutomaticDrivingLight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Debouncing_FogLight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Debouncing_FogLight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Debouncing_LowBeam(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Debouncing_LowBeam;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Debouncing_Sidelight(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Debouncing_Sidelight;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Pointer_Kl_58xt_Kl_58xd(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Pointer_Kl_58xt_Kl_58xd;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Scales_DayResponseCurve(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.Scales_DayResponseCurve;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_PWM_DampingCurve(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.p_PWM_DampingCurve;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_p_Bargraph_Luminosity_Calibration_PWM(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.p_Bargraph_Luminosity_Calibration_PWM,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_DIAG_AC_IlluminationCfg_1_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1.zReserved_DIAG_AC_IlluminationCfg_1_VAR,sizeof(Arr_u8_14));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_DIAG_AC_IlluminationCfg_VAR_3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Reserved_DIAG_AC_IlluminationCfg_VAR_3,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_IllumThreshold_CRC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.IllumThreshold_CRC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Overheat_DIMM_primary(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Overheat_DIMM_primary;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TFT_Threshold1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.TFT_Threshold1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TFT_Threshold2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.TFT_Threshold2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Temp_Threshold_Max_QuartzTemp(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Temp_Threshold_Max_QuartzTemp;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PCB_Threshold1(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.PCB_Threshold1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Rate(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Rate;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_PCB_Threshold2(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.PCB_Threshold2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Overheat_DIMM_secondary(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Overheat_DIMM_secondary;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_enabled(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Photosensor_enabled;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Slope_m_Left(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Compensation_Line_Slope_m_Left;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Shift_b_Left(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Compensation_Line_Shift_b_Left;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Slope_m_Right(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Compensation_Line_Slope_m_Right;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Compensation_Line_Shift_b_Right(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Compensation_Line_Shift_b_Right;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Photosensor_Plausi_Threshold(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Photosensor_Plausi_Threshold;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TFT_Safety_Offset(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.TFT_Safety_Offset;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Reserved_1_DIAG_AC_IlluminationCfg_VAR_3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3.Reserved_1_DIAG_AC_IlluminationCfg_VAR_3,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed.SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AbsErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.AbsErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AirbagErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.AirbagErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CwlErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.CwlErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EpbErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.EpbErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EspErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.EspErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GeneralBrakeErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.GeneralBrakeErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_LeftIndicatorErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.LeftIndicatorErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RightIndicatorErrorPath(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.RightIndicatorErrorPath;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AbsErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.AbsErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_AirbagErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.AirbagErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CwlErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.CwlErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EpbErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.EpbErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_EspErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.EspErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_GeneralBrakeErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.GeneralBrakeErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_LeftIndicatorErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.LeftIndicatorErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RightIndicatorErrorCounter(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.RightIndicatorErrorCounter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_SAFETY_RECORD_VAR(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SAFETY_RECORD_VAR.zReserved_SAFETY_RECORD_VAR,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_KsNvmBlockGfaKey_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_KsNvmBlockGfaKey_0.KsNvmBlockGfaKey_0,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_KsNvmBlockGfaKey_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_KsNvmBlockGfaKey_1.KsNvmBlockGfaKey_1,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_KsNvmBlockMisc_0(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_KsNvmBlockMisc_0.KsNvmBlockMisc_0,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_KsNvmBlockMisc_1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_KsNvmBlockMisc_1.KsNvmBlockMisc_1,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_CanBusActive(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_CAN_VAR.CanBusActive;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_CAN_VAR(boolean* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_CAN_VAR.zReserved_CAN_VAR,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_ProtectionHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.ResetCounter_ProtectionHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.ResetCounter_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_ShutdownHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.ResetCounter_ShutdownHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ResetCounter_Det_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.ResetCounter_Det_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TaskListEntry1(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.TaskListEntry1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TaskListEntry2(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.TaskListEntry2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TaskListEntry3(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.TaskListEntry3;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TaskListEntry4(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.TaskListEntry4;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_TaskListEntry5(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.TaskListEntry5;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ProtectionHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ProtectionHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ShutdownHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ShutdownHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_BswModuleId_EcuM_BswErrorHook(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_BswModuleId_EcuM_BswErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ErrorId_EcuM_BswErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ErrorId_EcuM_BswErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_EcuM_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_EcuM_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ModuleId_Det_ErrorHook(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ModuleId_Det_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_InstanceId_Det_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_InstanceId_Det_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ApiId_Det_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ApiId_Det_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_HookInfo_ErrorId_Det_ErrorHook(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.HookInfo_ErrorId_Det_ErrorHook;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListEntry1(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListEntry1,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListEntry2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListEntry2,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListEntry3(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListEntry3,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListEntry4(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListEntry4,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListEntry5(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListEntry5,sizeof(Arr_u8_4));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListIndex(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListIndex;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VersionListFlash_Counter(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_Recorder_VAR_2.VersionListFlash_Counter;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_Recorder_VAR_2(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_Recorder_VAR_2.zReserved_Recorder_VAR_2,sizeof(Arr_u8_6));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NvM_VKMS(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NvM_VKMS.NvM_VKMS,sizeof(Arr_u8_2));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NVM_BLOCK_SFD_PersistentData(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NVM_BLOCK_SFD_PersistentData.NVM_BLOCK_SFD_PersistentData,sizeof(Arr_u8_30));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NVM_BLOCK_SFD_ConfigurationFingerprint_Data(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NVM_BLOCK_SFD_ConfigurationFingerprint_Data.NVM_BLOCK_SFD_ConfigurationFingerprint_Data,sizeof(Arr_u8_514));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NVM_BLOCK_IVD_0X0250(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NVM_BLOCK_IVD_0X0250.NVM_BLOCK_IVD_0X0250,sizeof(Arr_u8_202));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_NVM_BLOCK_SFD_PublicKey(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_NVM_BLOCK_SFD_PublicKey.NVM_BLOCK_SFD_PublicKey,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manufacturing_PublicKey(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SecDiag.Manufacturing_PublicKey,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_Manufacturing_SID(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SecDiag.Manufacturing_SID,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SFD_Project_ID(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_SecDiag.SFD_Project_ID;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SFD_Group_Attribute(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SecDiag.SFD_Group_Attribute,sizeof(Arr_u8_23));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_VKMS_InitalKey_IS(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SecDiag.VKMS_InitalKey_IS,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_SecDiag(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_SecDiag.zReserved_SecDiag,sizeof(Arr_u8_27));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Esc_distance_pulse(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Esc_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Number_of_jumps_distance_pulse(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Number_of_jumps_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Biggest_negative_jump_distance_pulse(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Biggest_negative_jump_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Biggest_positive_jump_distance_pulse(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Biggest_positive_jump_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Sum_jumps_distance_pulse(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Sum_jumps_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Balance_sheet_jumps_distance_pulse(sint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Balance_sheet_jumps_distance_pulse;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Number_of_communication_failures_ESC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Number_of_communication_failures_ESC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Total_duration_communication_failures_ESC(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Total_duration_communication_failures_ESC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_Longest_communication_failures_ESC(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_Longest_communication_failures_ESC;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_error_secure_storage_AR(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_error_secure_storage_AR;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampYear(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampYear;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampMonth(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampMonth;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampDay(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampDay;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampHour(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampHour;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampMinute(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampMinute;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_TimeStampSecond(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_TimeStampSecond;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_total_distance_sum_implaus_jump_low_ESP(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.total_distance_sum_implaus_jump_low_ESP;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_total_distance_sum_implaus_jump_high_ESP(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.total_distance_sum_implaus_jump_high_ESP;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_counter_lost_communication_Distance(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.counter_lost_communication_Distance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_counter_lost_communication_EdgeCount(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.counter_lost_communication_EdgeCount;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_counter_lost_communication_time(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.counter_lost_communication_time;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_counter_lost_communication_clamp15(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.counter_lost_communication_clamp15;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_total_distance(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_total_distance;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_dm_error_calculation_dates(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.dm_error_calculation_dates;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_ESP_number_of_teeth_lastmode(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.ESP_number_of_teeth_lastmode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_wheel_circumference_lastmode(uint16* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.wheel_circumference_lastmode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_rawVIN_lastmode(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_WLTP_Odo_VAR.rawVIN_lastmode,sizeof(Arr_u8_18));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_total_distance_pass_jump_lastmode(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.total_distance_pass_jump_lastmode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_rawVin_change_in_clamp15_lastmode(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.rawVin_change_in_clamp15_lastmode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_da_total_distance_pass_jump(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.da_total_distance_pass_jump;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_SSO_EdgeCount_Sum_lastmode(uint32* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.SSO_EdgeCount_Sum_lastmode;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_total_distance_jump_is_valid(uint8* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.total_distance_jump_is_valid;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_distance_unit_default(boolean* Ptr)
{
    *(Ptr) = NvM_Manager_ROM_Default_WLTP_Odo_VAR.distance_unit_default;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_zReserved_WLTP_Odo(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,NvM_Manager_ROM_Default_WLTP_Odo_VAR.zReserved_WLTP_Odo,sizeof(Arr_u8_15));
    return E_OK;
}


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:25 AM
****************************************************************/
