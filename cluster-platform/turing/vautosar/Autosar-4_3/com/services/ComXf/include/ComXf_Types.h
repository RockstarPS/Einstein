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
*    @file ComXf_Types.h
*    @ingroup ComXf
*    @brief This file provides the types for the ComXf module.
********************************************************************************************************************/
#ifndef COMXF_TYPES_H
#define COMXF_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/

/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef COMXF_CODE
#define COMXF_CODE
#endif 

#ifndef COMXF_CONST
#define COMXF_CONST
#endif  

#ifndef COMXF_APPL_DATA
#define COMXF_APPL_DATA
#endif

#ifndef COMXF_APPL_VAR
#define COMXF_APPL_VAR
#endif

#ifndef COMXF_APPL_CONST
#define COMXF_APPL_CONST
#endif

#ifndef COMXF_CALLOUT_CODE
#define COMXF_CALLOUT_CODE
#endif

#ifndef COMXF_VAR
#define COMXF_VAR
#endif

#ifndef COMXF_VAR_INIT
#define COMXF_VAR_INIT
#endif

#ifndef COMXF_VAR_NOINIT
#define COMXF_VAR_NOINIT
#endif

#ifndef COMXF_VAR_POWER_ON_INIT
#define COMXF_VAR_POWER_ON_INIT
#endif

#ifndef COMXF_VAR_FAST
#define COMXF_VAR_FAST
#endif

#ifndef COMXF_VAR_SLOW
#define COMXF_VAR_SLOW
#endif

#ifndef COMXF_CONFIG_DATA
#define COMXF_CONFIG_DATA
#endif

/* #! ComXf Types */
/*! @brief Defines the ComXf init status type */
typedef enum 
{    
    COMXF_STATUS_UNINIT=0U, /*! @brief ComXf not initialized */   
    COMXF_STATUS_INIT       /*! @brief ComXf initialized */      
}ComXf_InitStatusType;

/*! Defines the endianess type as little */
#define COMXF_ENDIANESS_LITTLE  0U
/*! Defines the endianess type as BIG */
#define COMXF_ENDIANESS_BIG     1U
/*! Defines the endianess type */
typedef uint8 ComXf_EndianessType;

/*! @brief Defines the endianness of the signal's network representation as Big endian */
#define COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN 0U
/*! @brief Defines the endianness of the signal's network representation as Little endian */
#define COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN 1U
/*! @brief Defines the endianness of the signal's network representation as Opaque.
 With this type , the data is interpret as a n-bytes sized signal*/
#define COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_OPAQUE 2U
/*! @brief Defines the endianness of the signal's network representation */
typedef uint8 ComXf_SignalEndiannessType;

/*! @brief Defines the AUTOSAR type as BOOLEAN*/
#define COMXF_SIGNALTYPE_BOOLEAN    0U
/*! @brief Defines the AUTOSAR type as IEEE754 float32*/
#define COMXF_SIGNALTYPE_FLOAT32    1U
/*! @brief Defines the AUTOSAR type as IEEE754 float64*/
#define COMXF_SIGNALTYPE_FLOAT64    2U
/*! @brief Defines the AUTOSAR type as sint16*/
#define COMXF_SIGNALTYPE_SINT16     3U
/*! @brief Defines the AUTOSAR type as sint32*/
#define COMXF_SIGNALTYPE_SINT32     4U
/*! @brief Defines the AUTOSAR type as sint64*/
#define COMXF_SIGNALTYPE_SINT64     5U  
/*! @brief Defines the AUTOSAR type as sint8*/
#define COMXF_SIGNALTYPE_SINT8      6U
/*! @brief Defines the AUTOSAR type as uint16*/
#define COMXF_SIGNALTYPE_UINT16     7U
/*! @brief Defines the AUTOSAR type as uint32*/
#define COMXF_SIGNALTYPE_UINT32     8U
/*! @brief Defines the AUTOSAR type as uint64*/
#define COMXF_SIGNALTYPE_UINT64     9U
/*! @brief Defines the AUTOSAR type as uint8*/
#define COMXF_SIGNALTYPE_UINT8      10U
/*! @brief Defines the AUTOSAR type as uint8 Dynamic array .
 The maximum length of the array is defined .*/
#define COMXF_SIGNALTYPE_UINT8_DYN  11U
/*! @brief Defines the AUTOSAR type as uint8 array */
#define COMXF_SIGNALTYPE_UINT8_N    12U
/*! Defines the AUTOSAR type of the signal */
typedef uint8 ComXf_SignalType;

typedef struct
{
    /*! @brief Defines the AUTOSAR type of the signal */
    ComXf_SignalType            SignalType;
    /*! @brief Defines the endianness of the signal's network representation */
    ComXf_SignalEndiannessType  SignalEndiannessType;
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                       MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition */
    uint8                       LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data bytes*/
    uint32                      MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data bytes*/
    uint32                      LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types . For ComSignalType UINT8_N and UINT8_DYN the size 
    shall be configured by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is already defined by the 
    signal type and therefore may be omitted*/
    uint32                      BitSize;
    /*! @brief Defines the Size in bytes */
    uint32                      ByteLength;
}ComXf_SignalConfigType;

/*! @brief Defines the copy util type */
typedef struct
{
    /*! @brief Defines the source least significant bit position */
    uint8               SrcLsBit;
    /*! @brief Defines the source least significant byte position */
    uint32              SrcLsByte;
    /*! @brief Defines the destination least significant bit position */
    uint8               DestLsBit;
    /*! @brief Defines the destination least significant bit position */
    uint32              DestLsByte;
    /*! @brief Defines the maximum source buffer size */
    uint32              MaxSrcBufferSize;
    /*! @brief Defines the maximum destination buffer size */
    uint32              MaxDestBufferSize;
    /*! @brief Defines the endianess type for the source buffer */
    ComXf_EndianessType SrcBufferEndianess;
    /*! @brief Defines the endianess type for the destination buffer */
    ComXf_EndianessType DestBufferEndianess;
    /*! @brief Defines the signal length in bits */
    uint32              SignalLengthInBits;
    /*! @brief Defines the signal length in bytes */
    uint32              SignalLengthInBytes;
}ComXf_UtilBitCopyPropsType;

#endif /* COMXF_TYPES_H */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
*******************************************************************************************************************/
