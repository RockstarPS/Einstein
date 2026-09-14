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
/**********************************************************************************************************************
 *  CODE SECTIONS  (CLANG)
 *********************************************************************************************************************/
#if defined ( mOS_LINK_CODE )
.OsCode:
RUN_START(_OS_CODE_START)
RUN_START(__OS_CODE_START)
RUN_END(_OS_CODE_END)
RUN_END(__OS_CODE_END)

.OsCORECode:
RUN_START(_OS_CORE_CODE_START)
RUN_START(__OS_CORE_CODE_START)
RUN_END(_OS_CORE_CODE_END)
RUN_END(__OS_CORE_CODE_END)

#endif

#if defined ( mOS_LINK_INTVECT_CODE )
.OsINTVECTCode: {} ALIGN(128)
RUN_START(_OS_INTVEC_CODE_START)
RUN_END(_OS_INTVEC_CODE_END)
#endif

#if defined ( mOS_LINK_OSERROR_CODE )
.OsERRORCode:
RUN_START(_OS_ERROR_CODE_START)
RUN_START(__OS_ERROR_CODE_START)
RUN_END(_OS_ERROR_CODE_END)
RUN_END(__OS_ERROR_CODE_END)
#endif

#ifdef mOS_LINK_CODE
#undef mOS_LINK_CODE
#endif

#ifdef mOS_LINK_INTVECT_CODE
#undef mOS_LINK_INTVECT_CODE
#endif

#ifdef mOS_LINK_OSERROR_CODE
#undef mOS_LINK_OSERROR_CODE
#endif
/************ Todo: Provide Link segements for Os Used Variables ********************************/
