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
#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include "debug.h"
#include "res_mon_extract_package.h"
#include "res_mon_package.h"

static struct stat file_stat;
static char filename [ PACKAGE_PATH_MAX ];
static FILE *fp;
static uint32_t file_bytes_sent;

int32_t ResMonExtractPackage_Init ( void )
{
	int32_t ret = RM_OK;

	file_bytes_sent = 0;
	fp = NULL;

	return ret;
}

int32_t ResMonExtractPackage_Start ( package_hdr_t *file_hdr, uint32_t encrypt )
{
	int32_t ret;

	file_bytes_sent = 0;

	ret = ResMonPackage_Create ( encrypt, filename, PACKAGE_PATH_MAX );	
	if( ret == RM_OK )
	{
		fp = fopen ( filename, "r" );
		if( NULL != fp )
		{
			if( 0 == fstat ( fileno(fp), &file_stat ) )
			{
				LOGI ( "Created package %s, Size: %ld", filename, file_stat.st_size );
				( void ) memcpy( file_hdr->filename, filename, PACKAGE_PATH_MAX );
				file_hdr->filesize = file_stat.st_size;
				( void ) fseek( fp, 0, SEEK_SET );
				ret = RM_OK;
			}
			else
			{
				LOGE ( "fstat failed for %s", filename );
				ret = RM_FAILED;
			}
		}
		else
		{
			LOGE ( "fopen failed for %s", filename );
			ret = RM_FAILED;
		}
	}
	else
	{
		LOGE ( "%s", "Package creation failed" );
	}

	return ret;
}

int32_t ResMonExtractPackage_Read ( uint8_t *data, uint32_t *size )
{
	int32_t ret = RM_FAILED;
	uint64_t bytes_read = 0U;

	if( (data != NULL ) && ( size != NULL ) && ( file_bytes_sent < file_stat.st_size ) )
	{
		bytes_read = fread ( data, sizeof ( uint8_t ), (size_t) *size, fp );

		if( 0 < bytes_read)
		{
			file_bytes_sent += bytes_read;
			*size = bytes_read;
			ret = RM_OK;
		}
	}

	return ret;
}

int32_t ResMonExtractPackage_Close ( void )
{
	int32_t ret = RM_OK;

	/* Close the file */
	( void ) fclose ( fp );
	/* Remove the file */
	( void ) remove ( filename );
	/* Reset the variables */
	fp = NULL;
	file_bytes_sent = 0U;

	return ret;
}
