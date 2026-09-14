/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
/* ***** Os Core File Memory Segments ****** */

#ifdef OS_CORE_CODE_SEC_START
#pragma clang section text = ".OsCORECode"
#undef OS_CORE_CODE_SEC_START
#endif

#ifdef OS_CORE_CODE_SEC_END
#pragma clang section text = ""
#undef OS_CORE_CODE_SEC_END
#endif

#ifdef OS_CORE_CONST_SEC_START
#pragma clang section rodata = ".OsCOREConst"
#undef OS_CORE_CONST_SEC_START
#endif

#ifdef OS_CORE_CONST_SEC_END
#pragma clang section rodata = ""
#undef OS_CORE_CONST_SEC_END
#endif

#ifdef OS_CORE_DATA_SEC_START
#pragma clang section data = ".OsCOREData"
#undef OS_CORE_DATA_SEC_START
#endif

#ifdef OS_CORE_DATA_SEC_END
#pragma clang section data = ""
#undef OS_CORE_DATA_SEC_END
#endif

#ifdef OS_CORE_DATA_NOCACHE_SEC_START
#pragma clang section data = ".OsCOREData_NoCache"
#undef OS_CORE_DATA_NOCACHE_SEC_START
#endif

#ifdef OS_CORE_DATA_NOCACHE_SEC_END
#pragma clang section data = ""
#undef OS_CORE_DATA_NOCACHE_SEC_END
#endif

#ifdef OS_CORE_BSS_SEC_START
#pragma clang section bss = ".OsCOREBss"
#undef OS_CORE_BSS_SEC_START
#endif

#ifdef OS_CORE_BSS_SEC_END
#pragma clang section bss = ""
#undef OS_CORE_BSS_SEC_END
#endif

#ifdef OS_CORE_BSS_NOCACHE_SEC_START
#pragma clang section bss = ".OsCOREBss_NoCache"
#undef OS_CORE_BSS_NOCACHE_SEC_START
#endif

#ifdef OS_CORE_BSS_NOCACHE_SEC_END
#pragma clang section bss = ""
#undef OS_CORE_BSS_NOCACHE_SEC_END
#endif

#ifdef OS_CORE_BSS_BSW_SEC_START
#pragma clang section bss = ".bss_bsw"
#undef OS_CORE_BSS_BSW_SEC_START
#endif

#ifdef OS_CORE_BSS_BSW_SEC_END
#pragma clang section bss = ""
#undef OS_CORE_BSS_BSW_SEC_END
#endif


/* ******** End of Core Segments ******** */

/* ******** Start of Error Segments ******** */

#ifdef OS_ERROR_CODE_SEC_START
#pragma clang section text = ".OsERRORCode"
#undef OS_ERROR_CODE_SEC_START
#endif

#ifdef OS_ERROR_CODE_SEC_END
#pragma clang section text = ""
#undef OS_ERROR_CODE_SEC_END
#endif

/* ******** End of Core Segments ******** */


/* *************INTVECT Segments ********** */
#ifdef OS_INTVECT_CODE_SEC_START
#pragma clang section text = ".OsINTVECTCode"
#undef OS_INTVECT_CODE_SEC_START
#endif

#ifdef OS_INTVECT_CODE_SEC_END
#pragma clang section text = ""
#undef OS_INTVECT_CODE_SEC_END
#endif

#ifdef OS_INTVECT_CONST_SEC_START
#pragma clang section rodata = ".OsINTVECTConst"
#undef OS_INTVECT_CONST_SEC_START
#endif

#ifdef OS_INTVECT_CONST_SEC_END
#pragma clang section rodata = ""
#undef OS_INTVECT_CONST_SEC_END
#endif

#ifdef OS_INTVECT_DATA_SEC_START
#pragma clang section data = ".OsINTVECTData"
#undef OS_INTVECT_DATA_SEC_START
#endif

#ifdef OS_INTVECT_DATA_SEC_END
#pragma clang section data = ""
#undef OS_INTVECT_DATA_SEC_END
#endif

#ifdef OS_INTVECT_DATA_NOCACHE_SEC_START
#pragma clang section data = ".OsINTVECTData_NoCache"
#undef OS_INTVECT_DATA_NOCACHE_SEC_START
#endif

#ifdef OS_INTVECT_DATA_NOCACHE_SEC_END
#pragma clang section data = ""
#undef OS_INTVECT_DATA_NOCACHE_SEC_END
#endif

#ifdef OS_INTVECT_BSS_SEC_START
#pragma clang section bss = ".OsINTVECTBss"
#undef OS_INTVECT_BSS_SEC_START
#endif

#ifdef OS_INTVECT_BSS_SEC_END
#pragma clang section bss = ""
#undef OS_INTVECT_BSS_SEC_END
#endif

#ifdef OS_INTVECT_BSS_NOCACHE_SEC_START
#pragma clang section bss = ".OsINTVECTBss_NoCache"
#undef OS_INTVECT_BSS_NOCACHE_SEC_START
#endif

#ifdef OS_INTVECT_BSS_NOCACHE_SEC_END
#pragma clang section bss = ""
#undef OS_INTVECT_BSS_NOCACHE_SEC_END
#endif

/* ******** End of INTVECT Segments ******** */

/* ***** Os Cfg File Memory Segments ****** */

#ifdef OS_CFG_CODE_SEC_START
#pragma clang section text = ".OsCFGCode"
#undef OS_CFG_CODE_SEC_START
#endif

#ifdef OS_CFG_CODE_SEC_END
#pragma clang section text = ""
#undef OS_CFG_CODE_SEC_END
#endif

#ifdef OS_CFG_CONST_SEC_START
#pragma clang section rodata = ".OsCFGConst"
#undef OS_CFG_CONST_SEC_START
#endif

#ifdef OS_CFG_CONST_SEC_END
#pragma clang section rodata = ""
#undef OS_CFG_CONST_SEC_END
#endif

#ifdef OS_CFG_DATA_SEC_START
#pragma clang section data = ".OsCFGData"
#undef OS_CFG_DATA_SEC_START
#endif

#ifdef OS_CFG_DATA_SEC_END
#pragma clang section data = ""
#undef OS_CFG_DATA_SEC_END
#endif

#ifdef OS_CFG_DATA_NOCACHE_SEC_START
#pragma clang section data = ".OsCFGData_NoCache"
#undef OS_CFG_DATA_NOCACHE_SEC_START
#endif

#ifdef OS_CFG_DATA_NOCACHE_SEC_END
#pragma clang section data = ""
#undef OS_CFG_DATA_NOCACHE_SEC_END
#endif

#ifdef OS_CFG_BSS_SEC_START
#pragma clang section bss = ".OsCFGBss"
#undef OS_CFG_BSS_SEC_START
#endif

#ifdef OS_CFG_BSS_SEC_END
#pragma clang section bss = ""
#undef OS_CFG_BSS_SEC_END
#endif

#ifdef OS_CFG_BSS_NOCACHE_SEC_START
#pragma clang section bss = ".OsCFGBss_NoCache"
#undef OS_CFG_BSS_NOCACHE_SEC_START
#endif

#ifdef OS_CFG_BSS_NOCACHE_SEC_END
#pragma clang section bss = ""
#undef OS_CFG_BSS_NOCACHE_SEC_END
#endif


/* ******** End of Cfg Segments ******** */



