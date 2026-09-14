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
 *  CODE SECTIONS  (GHS)
 *********************************************************************************************************************/
 #if defined ( mOS_LINK_CODE )
.OsCode :> .
_OS_CODE_START = ADDR(.OsCode);
__OS_CODE_START = ADDR(.OsCode);
_OS_CODE_END = ENDADDR(.OsCode) - 1;
__OS_CODE_END = ENDADDR(.OsCode) - 1;

.OsCORECode :> .
_OS_CORE_CODE_START = ADDR(.OsCORECode);
__OS_CORE_CODE_START = ADDR(.OsCORECode);
_OS_CORE_CODE_END = ENDADDR(.OsCORECode) - 1;
__OS_CORE_CODE_END = ENDADDR(.OsCORECode) - 1;
#endif
 
#if defined ( mOS_LINK_INTVECT_CODE )
.OsINTVECTCode ALIGN(128) :> .
_OS_INTVEC_CODE_START = ADDR(.OsINTVECTCode);
_OS_INTVEC_CODE_END = ENDADDR(.OsINTVECTCode) - 1;
#endif

#if defined ( mOS_LINK_OSERROR_CODE )
.OsERRORCode :> .
_OS_ERROR_CODE_START = ADDR(.OsERRORCode);
__OS_ERROR_CODE_START = ADDR(.OsERRORCode);
_OS_ERROR_CODE_END = ENDADDR(.OsERRORCode) - 1;
__OS_ERROR_CODE_END = ENDADDR(.OsERRORCode) - 1;
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
