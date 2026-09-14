/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*   @file ComXf.c
*   @ingroup ComXf
*   @brief This file implements the AUTOSAR ComXf module.The ComXf module The com transformer is a 
*   transformer of the class Serializer. It serializes structured data into a linear form.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComXf.h"
#include "ComXf_Lcfg.h"
#include "ComXf_Int.h"
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((COMXF_SW_MAJOR_VERSION != COMXF_CFG_SW_MAJOR_VERSION) || \
     (COMXF_SW_MINOR_VERSION != COMXF_CFG_SW_MINOR_VERSION) || \
     (COMXF_SW_PATCH_VERSION != COMXF_CFG_SW_PATCH_VERSION))
#error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((COMXF_AR_RELEASE_MAJOR_VERSION != COMXF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (COMXF_AR_RELEASE_MINOR_VERSION != COMXF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (COMXF_AR_RELEASE_REVISION_VERSION != COMXF_CFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  #! Feature validation check                                                                                      *
********************************************************************************************************************/
/********************************************************************************************************************
*  #! PRIVATE MACRO DEFINITIONS                                                                                     *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef COMXF_LOCAL 
#define COMXF_LOCAL                             static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE                            static inline
#endif

#ifndef COMXF_LOCAL_INLINE
#define COMXF_LOCAL_INLINE                      LOCAL_INLINE
#endif

/********************************************************************************************************************
*  #! PRIVATE TYPE DEFINITIONS                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  #! PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                     *
********************************************************************************************************************/
/*! @brief utility lookup for bit width mask  */
static uint8 const ComXf_UtilBitWidthMasks[9] =
{
    0x00U,  /* 0 Bits Wide  */
    0x01u,  /* 1 Bits Wide */
    0x03u,  /* 2 Bits Wide  */
    0x07u,  /* 3 Bits Wide  */
    0x0Fu,  /* 4 Bits Wide  */
    0x1Fu,  /* 5 Bits Wide  */
    0x3Fu,  /* 6 Bits Wide  */
    0x7Fu,  /* 7 Bits Wide  */
    0xFFu   /* 8 Bits Wide  */
}; 
/********************************************************************************************************************
*  #! PRIVATE FUNCTION PROTOTYPES                                                                                   *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service used to set or clear the bit mask
*   @param[out] pData Pointer to data buffer to update the bit mask
*   @param[in] BitMask value of bitmask
*   @param[in] SetMode TRUE: set the value in bit mask FALSE: clear the value in bit mask
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilSetClearBitMask 
(
    CONSTP2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) pData,
    uint8 const BitMask,
    boolean SetMode
);
/*!******************************************************************************************************************
*   @brief      This service used to set the memory with the value.
*   @param[out] pDest Pointer to data buffer 
*   @param[in]  Value value to be set
*   @param[in]  Length length to be initialized
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) pDest,
    uint8 Value,
    uint32 Length
);
/*!******************************************************************************************************************
*   @brief      This service used to copy the value from src to dest buffer with buffer bit properties
*   @param[in]  UtilBitCopyPropsPtr Pointer to the buffer properties
*   @param[in]  SrcBufferPtr pointer to the source buffer 
*   @param[out] DestBufferPtr pointer to the destination buffer
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilBitCopy
(
    P2CONST(ComXf_UtilBitCopyPropsType,AUTOMATIC,COMXF_APPL_VAR) UtilBitCopyPropsPtr,
    CONSTP2CONST(uint8,AUTOMATIC,COMXF_APPL_VAR) SrcBufferPtr,
    CONSTP2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) DestBufferPtr
);
/*!******************************************************************************************************************
*   @brief      This service used to update the sign extension for sint8
*   @param[in]  pData Pointer to the data buffer 
*   @param[in]  BitSize bit size of the buffer 
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended8BitData
(
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief      This service used to update the sign extension for sint16
*   @param[in]  pData Pointer to the data buffer 
*   @param[in]  BitSize bit size of the buffer 
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended16BitData
(
    P2VAR(uint16,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief      This service used to update the sign extension for sint32
*   @param[in]  pData Pointer to the data buffer 
*   @param[in]  BitSize bit size of the buffer 
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended32BitData
(
    P2VAR(uint32,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
);
#if ((COMXF_BASIC_TYPE_UINT64_SUPPORT == STD_ON) || (COMXF_BASIC_TYPE_SINT64_SUPPORT == STD_ON))
/*!******************************************************************************************************************
*   @brief      This service used to update the sign extension for sint64
*   @param[in]  pData Pointer to the data buffer 
*   @param[in]  BitSize bit size of the buffer 
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended64BitData
(
    P2VAR(uint64,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
);
#endif
#define COMXF_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*   @brief      This service initializes the transformer for the further processing.
********************************************************************************************************************/
FUNC(void, COMXF_CODE) ComXf_Init( P2CONST(ComXf_ConfigType,AUTOMATIC,COMXF_APPL_VAR) config)
{
    ComXf_InitStatus = COMXF_STATUS_INIT;
    ComXf_LocalInit();
    COMXF_DUMMY_STATEMENT(config);
}
/********************************************************************************************************************
*   @brief      This service deinitializes the transformer.
********************************************************************************************************************/
FUNC(void, COMXF_CODE) ComXf_DeInit(void)
{
    ComXf_InitStatus = COMXF_STATUS_UNINIT;
}
/********************************************************************************************************************
*   @brief      This service returns the version information of the called transformer module.
********************************************************************************************************************/
FUNC(void, COMXF_CODE) ComXf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,COMXF_APPL_VAR) VersionInfo 
)
{
    uint8 ErrorId = COMXF_E_NO_ERROR;
    
    if (NULL_PTR == VersionInfo)
    {
        ErrorId = COMXF_E_PARAM_POINTER;   
    }
    else
    {
        /* update the version info */
        VersionInfo->moduleID           = COMXF_MODULE_ID;  
        VersionInfo->vendorID           = COMXF_VENDOR_ID;  
        VersionInfo->sw_major_version   = COMXF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version   = COMXF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version   = COMXF_SW_PATCH_VERSION;
    }
    
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
    if (COMXF_E_NO_ERROR != ErrorId)
    {
        ComXf_DetReportError(COMXF_GETVERSIONINFO_API, ErrorId);
    }
#else
    COMXF_DUMMY_STATEMENT(ErrorId);
#endif
} 
/********************************************************************************************************************
*   @brief  This function is used to read signal from the provided input buffer.
********************************************************************************************************************/
FUNC(void,COMXF_CODE) ComXf_ReadSignalFromBuffer
(
    ComXf_SignalId SignalId,
    P2VAR(void,AUTOMATIC,COMXF_APPL_CONST) pSignalData,
    P2CONST(uint8,AUTOMATIC,COMXF_APPL_DATA) pSrcBuffer,
    uint32 BufferLength,
    uint32 BufferOffset
)
{
    uint8 ErrorId = COMXF_E_NO_ERROR;
    ComXf_UtilBitCopyPropsType UtilBitCopyProps;
    ComXf_SignalConfigType const * pSignalConfig;
    if (SignalId >= ComXf_Num_Of_Signals)
    {
        ErrorId = COMXF_E_PARAM;
    }
    else if ((pSignalData == NULL_PTR) || (pSrcBuffer == NULL_PTR))
    {
        ErrorId = COMXF_E_PARAM_POINTER;
    }
    else
    {
        pSignalConfig = &ComXf_SignalConfig[SignalId];
        if((BufferLength > BufferOffset ) && (pSignalConfig->LsBytePosition >= BufferOffset))
        {
            /* Get buffer for the Pdu */
            UtilBitCopyProps.SignalLengthInBits  = pSignalConfig->BitSize;
            UtilBitCopyProps.SignalLengthInBytes = pSignalConfig->ByteLength;
            /* Update the bit copy details */
            UtilBitCopyProps.SrcLsBit = pSignalConfig->LsBitPosition;
            UtilBitCopyProps.SrcLsByte = pSignalConfig->LsBytePosition - BufferOffset;
            if (pSignalConfig->SignalEndiannessType == COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
            {
                UtilBitCopyProps.SrcBufferEndianess = COMXF_ENDIANESS_BIG;
            }
            else
            {
                /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
                UtilBitCopyProps.SrcBufferEndianess = COMXF_ENDIANESS_LITTLE;
            }
            UtilBitCopyProps.MaxSrcBufferSize = BufferLength;

            #if(COMXF_MICRO_ENDIANESS == COMXF_ENDIANESS_LITTLE)
            UtilBitCopyProps.DestLsBit = 0U;
            UtilBitCopyProps.DestLsByte = 0U;
            UtilBitCopyProps.DestBufferEndianess = COMXF_ENDIANESS_LITTLE;
            #else
            UtilBitCopyProps.DestLsBit = 0U;
            UtilBitCopyProps.DestLsByte = pSignalConfig->ByteLength;
            UtilBitCopyProps.DestBufferEndianess = COMXF_ENDIANESS_BIG;
            #endif
            UtilBitCopyProps.MaxDestBufferSize = pSignalConfig->ByteLength;
            /* Clear source buffer */
            ComXf_UtilMemSet((uint8*)pSignalData,0U,pSignalConfig->ByteLength);
            /* copy the data from RxIpdu Rte buffer to SignalDataPtr */
            ComXf_UtilBitCopy(&UtilBitCopyProps,pSrcBuffer,(uint8*)pSignalData);
            /* Extend sign */
            switch(pSignalConfig->SignalType)
            {
                case COMXF_SIGNALTYPE_SINT8:
                    ComXf_UtilGetSignExtended8BitData((uint8*)pSignalData,pSignalConfig->BitSize);
                    break;
                case COMXF_SIGNALTYPE_SINT16:
                    ComXf_UtilGetSignExtended16BitData((uint16*)pSignalData,pSignalConfig->BitSize);
                    break;
                case COMXF_SIGNALTYPE_SINT32:
                    ComXf_UtilGetSignExtended32BitData((uint32*)pSignalData,pSignalConfig->BitSize);
                    break;
                #if ((COMXF_BASIC_TYPE_UINT64_SUPPORT == STD_ON) || (COMXF_BASIC_TYPE_SINT64_SUPPORT == STD_ON))
                case COMXF_SIGNALTYPE_SINT64:
                    ComXf_UtilGetSignExtended64BitData((uint64*)pSignalData,pSignalConfig->BitSize);
                    break;
                #endif
                default:
                    break;
            }
        
        }
        else
        {
            ErrorId = COMXF_E_PARAM;
        }
    }
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
    if (COMXF_E_NO_ERROR != ErrorId)
    {
        ComXf_DetReportError(COMXF_INV_TRANSFORMER_API, ErrorId);
    }
#else
    COMXF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief  This function is used to write signal to the provided buffer.
********************************************************************************************************************/
FUNC(void,COMXF_CODE) ComXf_WriteSignalToBuffer
(
    ComXf_SignalId SignalId,
    P2CONST(void,AUTOMATIC,COMXF_APPL_CONST) pSignalData,
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_DATA) pDestBuffer,
    P2CONST(uint32,AUTOMATIC,COMXF_APPL_DATA) pDestBufferLength,
    uint32 BufferOffset
)
{
    uint8 ErrorId = COMXF_E_NO_ERROR;
    ComXf_UtilBitCopyPropsType UtilBitCopyProps;
    ComXf_SignalConfigType const * pSignalConfig;

    if (SignalId >= ComXf_Num_Of_Signals)
    {
        ErrorId = COMXF_E_PARAM;
    }
    else if ((pSignalData == NULL_PTR) || (pDestBuffer == NULL_PTR) || (pDestBufferLength == NULL_PTR))
    {
        ErrorId = COMXF_E_PARAM_POINTER;
    }
    else
    {
        pSignalConfig = &ComXf_SignalConfig[SignalId];
        if((*pDestBufferLength > BufferOffset ) && (pSignalConfig->LsBytePosition >= BufferOffset))
        {
            /* Get buffer for the Pdu */
            UtilBitCopyProps.SignalLengthInBits  = pSignalConfig->BitSize;
            UtilBitCopyProps.SignalLengthInBytes = pSignalConfig->ByteLength;
            /* Update the bit copy details */
            #if(COMXF_MICRO_ENDIANESS == COMXF_ENDIANESS_LITTLE)
            UtilBitCopyProps.SrcLsBit = 0;
            UtilBitCopyProps.SrcLsByte = 0;
            UtilBitCopyProps.SrcBufferEndianess = COMXF_ENDIANESS_LITTLE;
            #else
            UtilBitCopyProps.SrcLsBit = 0;
            UtilBitCopyProps.SrcLsByte = pSignalConfig->ByteLength;
            UtilBitCopyProps.SrcBufferEndianess = COMXF_ENDIANESS_BIG;
            #endif
            UtilBitCopyProps.MaxSrcBufferSize = pSignalConfig->ByteLength;
            UtilBitCopyProps.DestLsBit = pSignalConfig->LsBitPosition;
            UtilBitCopyProps.DestLsByte = pSignalConfig->LsBytePosition - BufferOffset;
            if (pSignalConfig->SignalEndiannessType == COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
            {
                UtilBitCopyProps.DestBufferEndianess = COMXF_ENDIANESS_BIG;
            }
            else
            {
                /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
                UtilBitCopyProps.DestBufferEndianess = COMXF_ENDIANESS_LITTLE;
            }
            UtilBitCopyProps.MaxDestBufferSize = *pDestBufferLength;
            /* copy the signal to the buffer  */
            ComXf_UtilBitCopy(&UtilBitCopyProps,(uint8*)pSignalData,pDestBuffer);
        }
        else
        {
            ErrorId = COMXF_E_PARAM;
        }
    }
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
    if (COMXF_E_NO_ERROR != ErrorId)
    {
        ComXf_DetReportError(COMXF_TRANSFORMER_API, ErrorId);
    }
#else
    COMXF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service used to set or clear the bit mask
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilSetClearBitMask 
(
    CONSTP2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) pData,
    uint8 const BitMask,
    boolean SetMode
)
{
    ComXf_EnterCriticalSection();
    if(TRUE == SetMode)
    {
        (*(pData)) |= BitMask;
    }
    else
    {
        (*(pData)) &= ((0xFFU) ^ (BitMask));
    }
    ComXf_ExitCriticalSection();
}
/********************************************************************************************************************
*   @brief      This service used to set the memory with the value.
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) pDest,
    uint8 Value,
    uint32 Length
)
{
    uint32 Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        pDest[Idx] = Value;
    }
}
/********************************************************************************************************************
*   @brief      This service used to copy the value from src to dest buffer with buffer bit properties
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilBitCopy
(
    P2CONST(ComXf_UtilBitCopyPropsType,AUTOMATIC,COMXF_APPL_VAR) UtilBitCopyPropsPtr,
    CONSTP2CONST(uint8,AUTOMATIC,COMXF_APPL_VAR) SrcBufferPtr,
    CONSTP2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) DestBufferPtr
)
{
    uint32 destBufferByteIndex;
    uint8 destBufferBitOffset;
    uint8 srcBufferBitOffset;
    uint32 srcBufferByteIndex;
    uint8 copyBitPosition;
    uint32 remainingSignalLength;
    uint32 noOfBitsToCopy;
    uint8 tempSrcValue;

    /* Set the initial position of destination buffer byte index */
    destBufferByteIndex = UtilBitCopyPropsPtr->DestLsByte;
    /* Set the initial position of destination buffer bit index */
    destBufferBitOffset = UtilBitCopyPropsPtr->DestLsBit;
    /* Set the initial position of source buffer bit index */
    srcBufferBitOffset = UtilBitCopyPropsPtr->SrcLsBit;
    /* Set the initial position of source buffer Byte index */
    srcBufferByteIndex = UtilBitCopyPropsPtr->SrcLsByte;
    /* set remaining signal length */
    remainingSignalLength = UtilBitCopyPropsPtr->SignalLengthInBits;
    
    if ((8U > destBufferBitOffset) && (8U > srcBufferBitOffset))
    {
        /* Copy to destination data buffer , should be in critical section */
        ComXf_EnterCriticalSection();
        while((remainingSignalLength!=0U) &&
               (UtilBitCopyPropsPtr->MaxDestBufferSize > destBufferByteIndex)  &&
               (UtilBitCopyPropsPtr->MaxSrcBufferSize > srcBufferByteIndex))
        {
            /* find bits position for copy in current iteration*/
            if ((destBufferBitOffset == 0U) && (srcBufferBitOffset != 0U))
            {
                copyBitPosition = 8U-srcBufferBitOffset;
            }
            else if((srcBufferBitOffset == 0U) && (destBufferBitOffset != 0U))
            {
                copyBitPosition = 8U-destBufferBitOffset;
            }
            else
            {
                copyBitPosition = 8U-destBufferBitOffset;
            }
            /* Get the number of bits to be copied in the current iteration , select the minimum*/
            if (remainingSignalLength<copyBitPosition)
            {
                noOfBitsToCopy = remainingSignalLength;
            }
            else
            {
                noOfBitsToCopy = copyBitPosition;
            }
            /* Get the source byte to be copied for current iteration*/
            tempSrcValue = SrcBufferPtr[srcBufferByteIndex] >> srcBufferBitOffset;
            tempSrcValue &= ComXf_UtilBitWidthMasks[noOfBitsToCopy];
            tempSrcValue = (tempSrcValue << destBufferBitOffset);
            /* Copy it to the destination */
            /* First Clear the Signal Bits in the MSByte */
            ComXf_UtilSetClearBitMask(&DestBufferPtr[destBufferByteIndex],
                                    (uint8)(ComXf_UtilBitWidthMasks[noOfBitsToCopy] << destBufferBitOffset), FALSE);
            DestBufferPtr[destBufferByteIndex] |= tempSrcValue;

            /* Update source buffer offset and index */
            if (UtilBitCopyPropsPtr->SrcBufferEndianess == COMXF_ENDIANESS_LITTLE)
            {
                srcBufferByteIndex += (srcBufferBitOffset+copyBitPosition)/8U;
            }
            else
            {
                srcBufferByteIndex -= (srcBufferBitOffset+copyBitPosition)/8U;
            }
            srcBufferBitOffset = (srcBufferBitOffset+copyBitPosition) % 8U;
            /* Update destination buffer offset and index */
            if (UtilBitCopyPropsPtr->DestBufferEndianess == COMXF_ENDIANESS_LITTLE)
            {
                /* cert 17223937 - The bit offset and bit position will be within 64, so no overflow */
                /* for Intel format */
                destBufferByteIndex +=((destBufferBitOffset+copyBitPosition)/8U);
            }
            else
            {
                /* for Motorola format */
                destBufferByteIndex -=((destBufferBitOffset+copyBitPosition)/8U);
            }
            destBufferBitOffset = ((destBufferBitOffset+copyBitPosition) % 8U);
            /* Update the remaining signal length */
            remainingSignalLength -= noOfBitsToCopy;
        }
        ComXf_ExitCriticalSection();
    }
}

/********************************************************************************************************************
*   @brief      This service used to update the sign extension for sint8
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended8BitData
(
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
)
{
    uint8 Mask;
    uint8 SignMask;
    uint8 SignBitMask;
    if (8U > BitSize)
    {
        Mask = (uint8)(0xFFU >> (8U - BitSize));
        SignMask =(uint8)(~(Mask >> 1U));
        (*pData) &= Mask;
        SignBitMask = (uint8)((uint8)1U << (uint8)(BitSize - 1U));
        if (((uint8)(*pData) & SignBitMask)  != 0U)
        {
            (*pData) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   @brief      This service used to update the sign extension for sint16
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended16BitData
(
    P2VAR(uint16,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
)
{
    uint16 Mask;
    uint16 SignMask;
    uint16 SignBitMask;
    if (16U > BitSize)
    {
        Mask = (uint16)(0xFFFFU >> (16U - BitSize));
        SignMask = (uint16)(~((uint16)(Mask >> 1U)));
        *pData &= Mask;
        SignBitMask = (uint16)((uint16)1U << (uint16)(BitSize - 1U));
        if (((uint16)(*pData) & SignBitMask)  != 0U)
        {
            (*pData) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   @brief      This service used to update the sign extension for sint32
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended32BitData
(
    P2VAR(uint32,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
)
{
    uint32 Mask;
    uint32 SignMask;
    uint32 SignBitMask;
    if (32U > BitSize)
    {
        Mask = (uint32)(0xFFFFFFFFUL >> (32U - BitSize));
        SignMask = (uint32)(~(Mask >> 1U));
        (*pData) &= Mask;
        SignBitMask = (uint32)((uint32)1U << (uint32)(BitSize - 1U));
        if (((uint32)(*pData) & SignBitMask)  != 0U)
        {
            (*pData) |= SignMask; /* add sign bits */
        }
    }
}
#if ((COMXF_BASIC_TYPE_UINT64_SUPPORT == STD_ON) || (COMXF_BASIC_TYPE_SINT64_SUPPORT == STD_ON))
/********************************************************************************************************************
*   @brief      This service used to update the sign extension for sint64
********************************************************************************************************************/
COMXF_LOCAL FUNC(void,COMXF_CODE) ComXf_UtilGetSignExtended64BitData
(
    P2VAR(uint64,AUTOMATIC,COMXF_APPL_DATA) pData,
    uint32 BitSize
)
{
    uint64 Mask;
    uint64 SignMask;
    uint64 SignBitMask;
    if (64U > BitSize)
    {
        Mask = (uint64)(0xFFFFFFFFFFFFFFFFULL >> (64U - BitSize));
        SignMask = (uint64)(~(Mask >> 1U));
        (*pData) &= Mask;
        SignBitMask = (uint64)((uint64)1U << (uint64)(BitSize - 1U));
        if (((uint64)(*pData) & SignBitMask)  != 0U)
        {
            (*pData) |= SignMask; /* add sign bits */
        }
    }
}
#endif

#define COMXF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    29-Dec-2024
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/