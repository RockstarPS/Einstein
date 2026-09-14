/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
#ifndef RES_MON_EXTRACT_PACKAGE_H
#define RES_MON_EXTRACT_PACKAGE_H

#include "res_mon.h"

typedef struct
{
	char filename[PACKAGE_PATH_MAX];
	uint32_t filesize;
} package_hdr_t ;

int32_t ResMonExtractPackage_Init ( void );
int32_t ResMonExtractPackage_Start ( package_hdr_t *file_hdr, uint32_t encrypt );
int32_t ResMonExtractPackage_Read ( uint8_t *data, uint32_t *size );
int32_t ResMonExtractPackage_Close ( void );

#endif /* RES_MON_EXTRACT_PACKAGE_H */
