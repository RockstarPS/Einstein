/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

# ifndef UPD_TarInstaller_H
# define UPD_TarInstaller_H

#include "UPDi_GenDecoder.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define UPDITAR_BLOCK_SIZE (512)

typedef enum
{
	eTarDone=0,
    eTarLoadingHeader,
    eTarInstallingFile,
    eTarLoadingPadding,
    eTarLoadingEndOfArchive,
} tUPDiTarDecoderState;

typedef struct __attribute__((packed)) sUPDiTarHeader
{
    char name[100];		/*   0 */
    char mode[8];			/* 100 */
    char uid[8];			/* 108 */
    char gid[8];			/* 116 */
    char size[12];		/* 124 */
    char mtime[12];		/* 136 */
    char chksum[8];		/* 148 */
    char typeflag;		/* 156 */
    char linkname[100];		/* 157 */
    char padding[255];
} tUPDiTarHeader;

typedef struct
{ 
    tUPDiGenDecoderRam Parent;
    tUPDiTarDecoderState State;
    uint32_t         PaddingSize;
} tUPDiTarDecoderRam;

typedef const struct 
{ 
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiTarDecoderRam* pRam;
} tUPDiTarDecoder;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
const char*    UPDiTarDecoder_GetExtension(tUPDiTarDecoder* This);
Std_ReturnType UPDiTarDecoder_Start(tUPDiTarDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiTarDecoder_Exit(tUPDiTarDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiTarDecoder_Process(tUPDiTarDecoder* This, tUPDiInstallSession* pSession);
boolean        UPDiTarDecoder_Rewind(tUPDiTarDecoder* This, uint32_t FlashOffset, uint32_t* pImageOffset );
Std_ReturnType UPDiTarDecoder_Serialize(tUPDiTarDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiTarDecoder_Deserialize(tUPDiTarDecoder* This, tUPDStream *pStream);


//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiGenDecoder_Vtbl UPDTarDecoder_Vtbl;


# endif /*UPD_TarInstaller_H*/
