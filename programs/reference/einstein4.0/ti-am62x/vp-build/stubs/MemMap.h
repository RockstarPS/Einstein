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

#include "ComM_MemMap.h"

/*****************************************************************************/
/* SAFENVM Code Section Start*/

#ifdef SAFENVM_SEC_CODE_START
//#pragma clang section text=.""
#undef SAFENVM_SEC_CODE_START
#endif

#ifdef SAFENVM_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef SAFENVM_CORE_CONST_SEC_START
#endif

#ifdef SAFENVM_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.SafeNvM"
#undef SAFENVM_CORE_DATA_SEC_START
#endif

#ifdef SAFENVM_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.SafeNvM"
#undef SAFENVM_CORE_BSS_SEC_START
#endif

/* SAFENVM Code Section End */
#ifdef SAFENVM_SEC_CODE_END
//#pragma clang section text=""
#undef SAFENVM_SEC_CODE_END
#endif

#ifdef SAFENVM_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef SAFENVM_CORE_CONST_SEC_END
#endif

#ifdef SAFENVM_CORE_DATA_SEC_END
#pragma clang section data =""
#undef SAFENVM_CORE_DATA_SEC_END
#endif

#ifdef SAFENVM_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef SAFENVM_CORE_BSS_SEC_END
#endif

/******************************************************************************/
/* FLTM Code Section Start*/

#ifdef FLTM_SEC_CODE_START
//#pragma clang section text="FLTM_SEC_CODE_SECTION"
#undef FLTM_SEC_CODE_START
#endif

#ifdef FLTM_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef FLTM_CORE_CONST_SEC_START
#endif

#ifdef FLTM_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.FltM"
#undef FLTM_CORE_DATA_SEC_START
#endif

#ifdef FLTM_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.FltM"
#undef FLTM_CORE_BSS_SEC_START
#endif

/* FLTM Code Section End */
#ifdef FLTM_SEC_CODE_END
//#pragma clang section text=""
#undef FLTM_SEC_CODE_END
#endif

#ifdef FLTM_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef FLTM_CORE_CONST_SEC_END
#endif

#ifdef FLTM_CORE_DATA_SEC_END
#pragma clang section data =""
#undef FLTM_CORE_DATA_SEC_END
#endif

#ifdef FLTM_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef FLTM_CORE_BSS_SEC_END
#endif

/******************************************************************************/

/******************************************************************************/
/* COMABSMDLSafe Code Section Start*/
#ifdef COMABSMDLSAFE_SEC_CODE_START
//#pragma clang section text="COMABSMDLSAFE_SEC_CODE_SECTION"
#undef COMABSMDLSAFE_SEC_CODE_START
#endif

#ifdef COMABSMDLSAFE_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef COMABSMDLSAFE_CORE_CONST_SEC_START
#endif

#ifdef COMABSMDLSAFE_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.ComAbsMdlSafe"
#undef COMABSMDLSAFE_CORE_DATA_SEC_START
#endif

#ifdef COMABSMDLSAFE_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.ComAbsMdlSafe"
#undef COMABSMDLSAFE_CORE_BSS_SEC_START
#endif

/* COMABSMDLSAFE_ Code Section End */
#ifdef COMABSMDLSAFE_SEC_CODE_END
//#pragma clang section text=""
#undef COMABSMDLSAFE_SEC_CODE_END
#endif

#ifdef COMABSMDLSAFE_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef COMABSMDLSAFE_CORE_CONST_SEC_END
#endif

#ifdef COMABSMDLSAFE_CORE_DATA_SEC_END
#pragma clang section data =""
#undef COMABSMDLSAFE_CORE_DATA_SEC_END
#endif

#ifdef COMABSMDLSAFE_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef COMABSMDLSAFE_CORE_BSS_SEC_END
#endif
/******************************************************************************/

/******************************************************************************/
/* COMXF Code Section Start*/
#ifdef COMXF_SEC_CODE_START
//#pragma clang section text="COMXF_SEC_CODE_SECTION"
#undef COMXFSEC_CODE_START
#endif

#ifdef COMXF_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef COMXF_CORE_CONST_SEC_START
#endif

#ifdef COMXF_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.COMXF"
#undef COMXF_CORE_DATA_SEC_START
#endif

#ifdef COMXF_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.COMXF"
#undef COMXF_CORE_BSS_SEC_START
#endif

/* COMXF_ Code Section End */
#ifdef COMXF__SEC_CODE_END
//#pragma clang section text=""
#undef COMXF_SEC_CODE_END
#endif

#ifdef COMXF_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef COMXF_CORE_CONST_SEC_END
#endif

#ifdef COMXF_CORE_DATA_SEC_END
#pragma clang section data =""
#undef COMXF_CORE_DATA_SEC_END
#endif

#ifdef COMXF_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef COMXF_CORE_BSS_SEC_END
#endif
/******************************************************************************/

/******************************************************************************/
/* E2EXF Code Section Start*/
#ifdef E2EXF_SEC_CODE_START
//#pragma clang section text="E2EXF_SEC_CODE_SECTION"
#undef E2EXF_SEC_CODE_START
#endif

#ifdef E2EXF_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef E2EXF_CORE_CONST_SEC_START
#endif

#ifdef E2EXF_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.E2EXF"
#undef E2EXF_CORE_DATA_SEC_START
#endif

#ifdef E2EXF_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.E2EXF"
#undef E2EXF_CORE_BSS_SEC_START
#endif

/* E2EXF_ Code Section End */
#ifdef E2EXF_SEC_CODE_END
//#pragma clang section text=""
#undef E2EXF_SEC_CODE_END
#endif

#ifdef E2EXF_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef E2EXF_CORE_CONST_SEC_END
#endif

#ifdef E2EXF_CORE_DATA_SEC_END
#pragma clang section data =""
#undef E2EXF_CORE_DATA_SEC_END
#endif

#ifdef E2EXF_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef E2EXF_CORE_BSS_SEC_END
#endif

/******************************************************************************/

/******************************************************************************/
/* RSTM Code Section Start*/

#ifdef RSTM_SEC_CODE_START
//#pragma clang section text="RSTM_SEC_CODE_SECTION"
#undef RSTM_SEC_CODE_START
#endif

#ifdef RSTM_CORE_CONST_SEC_START
//#pragma clang section rodata =".SafeRoData"
#undef RSTM_CORE_CONST_SEC_START
#endif

#ifdef RSTM_CORE_DATA_SEC_START
#pragma clang section data =".SafeData.RstM"
#undef RSTM_CORE_DATA_SEC_START
#endif

#ifdef RSTM_CORE_BSS_SEC_START
#pragma clang section bss =".SafeBss.RstM"
#undef RSTM_CORE_BSS_SEC_START
#endif

/* FLTM Code Section End */
#ifdef RSTM_SEC_CODE_END
//#pragma clang section text=""
#undef RSTM_SEC_CODE_END
#endif

#ifdef RSTM_CORE_CONST_SEC_END
//#pragma clang section rodata =""
#undef RSTM_CORE_CONST_SEC_END
#endif

#ifdef RSTM_CORE_DATA_SEC_END
#pragma clang section data =""
#undef RSTM_CORE_DATA_SEC_END
#endif

#ifdef RSTM_CORE_BSS_SEC_END
#pragma clang section bss =""
#undef RSTM_CORE_BSS_SEC_END
#endif

/******************************************************************************/

/* Rte Trusted - Triple Buffer elements*/
#ifdef RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#pragma clang section bss =".SafeBss.Rte"
#pragma clang section data =".SafeData.Rte"
#undef RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#endif

#ifdef RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#pragma clang section bss =""
#pragma clang section data =""
#undef RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#endif

/*
#ifdef OS_START_SEC_OsApplication_Trusted_VAR_UNSPECIFIED
#pragma clang section bss =".SafeBss.Rte"
#pragma clang section data =".SafeData.Rte"
#undef OS_START_SEC_OsApplication_Trusted_VAR_UNSPECIFIED
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_VAR_UNSPECIFIED
#pragma clang section bss =""
#pragma clang section data ="."
#undef OS_STOP_SEC_OsApplication_Trusted_VAR_UNSPECIFIED
#endif
*/

/* PmicCdd Code Section */
#ifdef PMICCDD_SEC_CODE_START
#define OPEN_PMICCDD_SEC_CODE_START
#undef PMICCDD_SEC_CODE_START
#endif

#ifdef PMICCDD_SEC_CODE_STOP
#define OPEN_PMICCDD_SEC_CODE_STOP
#undef PMICCDD_SEC_CODE_STOP
#endif

#ifdef OPEN_PMICCDD_SEC_CODE_START
#pragma clang section text="PMICCDD_SEC_CODE_SECTION"
#undef OPEN_PMICCDD_SEC_CODE_START
#endif

#ifdef OPEN_PMICCDD_SEC_CODE_STOP
#pragma clang section text=""
#undef OPEN_PMICCDD_SEC_CODE_STOP
#endif

/* PmicCdd Data Section (initialized)*/
#ifdef PMICCDD_CORE_DATA_SEC_START
#define OPEN_PMICCDD_CORE_DATA_SEC_START
#undef PMICCDD_CORE_DATA_SEC_START
#endif

#ifdef PMICCDD_CORE_DATA_SEC_END
#define OPEN_PMICCDD_CORE_DATA_SEC_END
#undef PMICCDD_CORE_DATA_SEC_END
#endif

#ifdef OPEN_PMICCDD_CORE_DATA_SEC_START
#pragma clang section data=".SafeData.PmicCdd"
#undef OPEN_PMICCDD_CORE_DATA_SEC_START
#endif

#ifdef OPEN_PMICCDD_CORE_DATA_SEC_END
#pragma clang section data=""
#undef OPEN_PMICCDD_CORE_DATA_SEC_END
#endif

/* PmicCdd BSS Section (uinitialized)*/
#ifdef PMICCDD_CORE_BSS_SEC_START
#define OPEN_PMICCDD_CORE_BSS_SEC_START
#undef PMICCDD_CORE_BSS_SEC_START
#endif

#ifdef PMICCDD_CORE_BSS_SEC_END
#define OPEN_PMICCDD_CORE_BSS_SEC_END
#undef PMICCDD_CORE_BSS_SEC_END
#endif

#ifdef OPEN_PMICCDD_CORE_BSS_SEC_START
#pragma clang section bss=".SafeBss.PmicCdd"
#undef OPEN_PMICCDD_CORE_BSS_SEC_START
#endif

#ifdef OPEN_PMICCDD_CORE_BSS_SEC_END
#pragma clang section bss=""
#undef OPEN_PMICCDD_CORE_BSS_SEC_END
#endif



/* WdgMgr Code Section */
#ifdef WDGMGR_CODE_SEC_START
#define OPEN_WDGMGR_CODE_SEC_START
#undef WDGMGR_CODE_SEC_START
#endif

#ifdef WDGMGR_CODE_SEC_END
#define OPEN_WDGMGR_CODE_SEC_END
#undef WDGMGR_CODE_SEC_END
#endif

#ifdef OPEN_WDGMGR_CODE_SEC_START
#pragma clang section text="WDGMGR_SEC_CODE_SECTION"
#undef OPEN_WDGMGR_CODE_SEC_START
#endif

#ifdef OPEN_WDGMGR_CODE_SEC_END
#pragma clang section text=""
#undef OPEN_WDGMGR_CODE_SEC_END
#endif

/* WdgMgr bss Section */
#ifdef WDGMGR_DATA_SEC_START
#define OPEN_WDGMGR_DATA_SEC_START
#undef WDGMGR_DATA_SEC_START
#endif

#ifdef WDGMGR_DATA_SEC_END
#define OPEN_WDGMGR_DATA_SEC_END
#undef WDGMGR_DATA_SEC_END
#endif

#ifdef OPEN_WDGMGR_DATA_SEC_START
#pragma clang section bss=".SafeBss.WdgMgr"
#undef OPEN_WDGMGR_DATA_SEC_START
#endif

#ifdef OPEN_WDGMGR_DATA_SEC_END
#pragma clang section bss=""
#undef OPEN_WDGMGR_DATA_SEC_END
#endif

/* WdgMgr data Section */
#ifdef WDGMGR_DATA_SEC_START
#define OPEN_WDGMGR_DATA_SEC_START
#undef WDGMGR_DATA_SEC_START
#endif

#ifdef WDGMGR_DATA_SEC_END
#define OPEN_WDGMGR_DATA_SEC_END
#undef WDGMGR_DATA_SEC_END
#endif

#ifdef OPEN_WDGMGR_DATA_SEC_START
#pragma clang section data=".SafeData.WdgMgr"
#undef OPEN_WDGMGR_DATA_SEC_START
#endif

#ifdef OPEN_WDGMGR_DATA_SEC_END
#pragma clang section data=""
#undef OPEN_WDGMGR_DATA_SEC_END
#endif

/* WdgIf Code Section */
#ifdef WDGIF_CODE_SEC_START
#define OPEN_WDGIF_CODE_SEC_START
#undef WDGIF_CODE_SEC_START
#endif

#ifdef WDGIF_CODE_SEC_END
#define OPEN_WDGIF_CODE_SEC_END
#undef WDGIF_CODE_SEC_END
#endif

#ifdef OPEN_WDGIF_CODE_SEC_START
#pragma clang section text="WDGIF_SEC_CODE_SECTION"
#undef OPEN_WDGIF_CODE_SEC_START
#endif

#ifdef OPEN_WDGIF_CODE_SEC_END
#pragma clang section text=""
#undef OPEN_WDGIF_CODE_SEC_END
#endif

/* WdgIf bss Section */
#ifdef WDGIF_DATA_SEC_START
#define OPEN_WDGIF_DATA_SEC_START
#undef WDGIF_DATA_SEC_START
#endif

#ifdef WDGIF_DATA_SEC_END
#define OPEN_WDGIF_DATA_SEC_END
#undef WDGIF_DATA_SEC_END
#endif

#ifdef OPEN_WDGIF_DATA_SEC_START
#pragma clang section bss=".SafeBss.WdgIf"
#undef OPEN_WDGIF_DATA_SEC_START
#endif

#ifdef OPEN_WDGIF_DATA_SEC_END
#pragma clang section bss=""
#undef OPEN_WDGIF_DATA_SEC_END
#endif
 
/* WdgIf Data Section */
#ifdef WDGIF_DATA_SEC_START
#define OPEN_WDGIF_DATA_SEC_START
#undef WDGIF_DATA_SEC_START
#endif
 
#ifdef WDGIF_DATA_SEC_END
#define OPEN_WDGIF_DATA_SEC_END
#undef WDGIF_DATA_SEC_END
#endif
 
#ifdef OPEN_WDGIF_DATA_SEC_START
#pragma clang section data=".SafeData.WdgIf"
#undef OPEN_WDGIF_DATA_SEC_START
#endif
 
#ifdef OPEN_WDGIF_DATA_SEC_END
#pragma clang section data=""
#undef OPEN_WDGIF_DATA_SEC_END
#endif