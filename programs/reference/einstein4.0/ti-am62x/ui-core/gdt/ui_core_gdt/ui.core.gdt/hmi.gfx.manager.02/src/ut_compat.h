/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **==========================================================================*/
/**
 * \file        ut_compat.h
 * \brief       This file defines some macro mapping for Traveo1 APIs to Traveo2.
 */

#ifndef UT_COMPAT_H
#define UT_COMPAT_H


#if defined(GFX_MGR02_TRAVEO2)
#ifdef __cplusplus
extern "C"
{
#endif

#define MML_GDC_SURF_FORMAT_A6R6G6B6    CYGFX_SM_FORMAT_A6R6G6B6
#define MML_MMAN_HEAP_HANDLE			UT_MEMMAN_HEAP_HANDLE

#define mmlGdcSmGenSurfaceObjects 		utSmGenSurfaceObjects
#define mmlGdcSmDeleteSurfaceObjects 	utSmDeleteSurfaceObjects
#define mmlGdcPeGenContext				utPeGenContext
#define mmlGdcPeDeleteContext 			utPeDeleteContext
#define mmlGdcSyncCreate 				utSyncCreate
#define mmlGdcSyncDelete 				utSyncDelete

#define mmlGdcVideoAlloc				utVideoAlloc					
#define mmlGdcVideoFree					utVideoFree						
#define mmlGdcVideoGetSize				utVideoGetSize					
#define mmlGdcVideoGetFreeTotal			utVideoGetFreeTotal				
#define mmlGdcVideoGetLargestBlock		utVideoGetLargestBlock	

#ifdef __cplusplus
}
#endif
#endif 
#endif

