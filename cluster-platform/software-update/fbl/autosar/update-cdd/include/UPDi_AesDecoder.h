/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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

# ifndef UPD_AesDecoder_H
# define UPD_AesDecoder_H

#include "UPDi_AbstractInstaller.h"
#include "UPDi_GenDecoder.h"
#if (STD_ON == UPD_AES_DECODER)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
typedef enum
{
    AES_ERROR     = 0x0,
    AES_INIT      = 0x1,
    AES_TRANSFORM = 0x2,
    AES_FINISHING = 0x3,
    AES_FINISHED  = 0x4,
} tUPDiAESDecoderState;

typedef uint8 tUPDiAESDecoderBuffer[UPDd_AES_BLOCK_SIZE + AES_DECRYPT_BLOCK_LEN];

typedef struct
{
    tUPDiGenDecoderRam Parent; // Parent Ram Data
    tUPDiAESDecoderBuffer buffer;
    uint32 ImgSize;
    uint32 ImgPending;
    uint16 BytesToSkip;
    tUPDiAESDecoderState State;
} tUPDiAESDecoderRam;

typedef const struct
{
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiAESDecoderRam* pRam;
} tUPDiAESDecoder;

//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiGenDecoder_Vtbl UPDiAESDecoder_VTBL;

# endif /* UPD_AES_DECODER */
# endif /* UPD_AESDecoder_H */
