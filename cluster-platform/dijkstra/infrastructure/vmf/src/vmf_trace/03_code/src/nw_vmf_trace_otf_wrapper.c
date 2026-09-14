/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/
/*                                                                            *
*******************************************************************************
*  PROJECT NAME :  VMF_TRACE                                                  *
*******************************************************************************
*  MODULE NAME  :  vmf_trace_otf_wrapper.c                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   13 July 2009                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/
#define  TEST_OPEN
#define  LAYOUT2

#include <BMWOTF.h>

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"


/* there is only one trid per  wrapper possible ! */
static unsigned8 wrapper_trid;
static char      wrapper_trid_name[MAX_TRACE_NAME_LEN+1];   

static inline unsigned32 getmypid(void);

/* defines */
#define DEFAULT_SCOPE   "otf-wrapper"


/**************************************************************************//**
 *
 *   OTF_trace
 *   The function OTF open is wrapped to the vmf_trace function
 *
 *   \param[in]     OTF_ScopeEntry      scope
 *   \param[in]     pFmt,...            trace message
 *
 *   \return        OTF_S_OK if OK, OTF_E_INTERNALFAILURE if error
 *
 ******************************************************************************/
OTF_API 
OTF_Result      OTF_trace( const OTF_ScopeEntry* pOTFScope
                    , const OTF_Char* pFmt, ... )
{
    vmf_ret_t   my_ret;
    OTF_Result  otf_result = OTF_S_OK;
    char        my_buffer[MAX_VMF_TRACE_PL_LEN];
    va_list     arglist;


#ifdef TEST_OPEN
    if (0 == wrapper_trid)
    {
#if 0
        VMF_TRACE_ERROR_PRINT("pid=%d, OTF-Trace wrapper: OTF_trace() called without calling OTF_open()\n",getmypid()); 
#else
        VMF_TRACE_INFO_PRINT("pid=%d, OTF-Trace wrapper: OTF_trace() called without calling OTF_open()\n",getmypid());  
#endif
        return OTF_E_INTERNALFAILURE;
    }
#endif


    /* check if trace is allowed */
    if (vmf_trace_check_filter(wrapper_trid,VMF_TRACE_SEV_OTF_TRACE))
    {
        /* no trace*/
        return OTF_S_OK;
    }


    /* create the trace message */
    va_start (arglist, pFmt);
    vsnprintf(my_buffer,MAX_VMF_TRACE_PL_LEN,pFmt, arglist);
#ifdef LAYOUT2
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_TRACE,(char*)pOTFScope->te.pName,(char*)pOTFScope->te.pName,my_buffer);
#else
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_TRACE,wrapper_trid_name,(char*)pOTFScope->te.pName,my_buffer);
#endif
    va_end (arglist);

    if (VMF_OK == my_ret)
    {
        /* store trid name */
        otf_result = OTF_S_OK;  
    }
    else
    {
        otf_result = OTF_E_INTERNALFAILURE;
    }

    return otf_result;
}





/**************************************************************************//**
 *
 *   OTF_hex
 *   The function OTF open is wrapped to the vmf_trace_hex function
 *
 *   \param[in]     OTF_ScopeEntry      scope
 *   \param[in]     pData               hex data
 *   \param[in]     nLen                size of data
 *
 *
 *   \return        OTF_S_OK if OK, OTF_E_INTERNALFAILURE if error
 *
 ******************************************************************************/
OTF_API
OTF_Result       OTF_hex( const OTF_ScopeEntry* pOTFScope
                        , const OTF_UByte* pData
                        , OTF_UInt32 nLen )
{
    vmf_ret_t   my_ret;
    OTF_Result  otf_result = OTF_S_OK;



#ifdef TEST_OPEN
    if (0 == wrapper_trid)
    {
        VMF_TRACE_ERROR_PRINT("pid=%d, OTF-Trace wrapper: OTF_hex() called without calling OTF_open()\n",getmypid());   
        return OTF_E_INTERNALFAILURE;
    }
#endif

    /* check if trace is allowed */
    if (vmf_trace_check_filter(wrapper_trid,VMF_TRACE_SEV_OTF_HEX))
    {
        /* no trace*/
        return OTF_S_OK;
    }

    /* send data to trace client */
#ifdef LAYOUT2
    my_ret = vmf_trace_hex(wrapper_trid, VMF_TRACE_SEV_OTF_HEX,(char*)pOTFScope->te.pName,(char*)pOTFScope->te.pName,nLen,(unsigned8*)pData);
#else
    my_ret = vmf_trace_hex(wrapper_trid, VMF_TRACE_SEV_OTF_HEX,wrapper_trid_name,(char*)pOTFScope->te.pName,nLen,(unsigned8*)pData);
#endif
    if (VMF_OK == my_ret)
    {
        /* store trid name */
        otf_result = OTF_S_OK;  
    }
    else
    {
        otf_result = OTF_E_INTERNALFAILURE;
    }

    return otf_result;
}






/**************************************************************************//**
 *
 *   OTF_error
 *   The function OTF open is wrapped to the vmf_trace function
 *
 *   \param[in]     OTF_ScopeEntry      scope
 *   \param[in]     pMsg                trace message
 *
 *   \return        OTF_S_OK if OK, OTF_E_INTERNALFAILURE if error
 *
 ******************************************************************************/
OTF_API
OTF_Result       OTF_error( const OTF_ScopeEntry* pOTFScope
                          , const OTF_Char* pMsg )
{
    vmf_ret_t   my_ret;
    OTF_Result  otf_result;


#ifdef TEST_OPEN
    if (0 == wrapper_trid)
    {
        VMF_TRACE_ERROR_PRINT("pid=%d, OTF-Trace wrapper: OTF_error() called without calling OTF_open()\n",getmypid()); 
        return OTF_E_INTERNALFAILURE;
    }
#endif


    /* check if trace is allowed */
    if (vmf_trace_check_filter(wrapper_trid,VMF_TRACE_SEV_OTF_ERROR))
    {
        /* no trace*/
        return OTF_S_OK;
    }


    /* create the trace message */
#ifdef LAYOUT2
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_ERROR,(char*)pOTFScope->te.pName,(char*)pOTFScope->te.pName,(char *)pMsg);
#else
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_ERROR,wrapper_trid_name,(char*)pOTFScope->te.pName,(char *)pMsg);
#endif

    if (VMF_OK == my_ret)
    {
        /* store trid name */
        otf_result = OTF_S_OK;  
    }
    else
    {
        otf_result = OTF_E_INTERNALFAILURE;
    }

    return otf_result;
}






/**************************************************************************//**
 *
 *   OTF_warning
 *   The function OTF open is wrapped to the vmf_trace function
 *
 *   \param[in]     OTF_ScopeEntry      scope
 *   \param[in]     pMsg                trace message
 *
 *   \return        OTF_S_OK if OK, OTF_E_INTERNALFAILURE if error
 *
 ******************************************************************************/
OTF_API
OTF_Result       OTF_warning( const OTF_ScopeEntry* pOTFScope
                            , const OTF_Char* pMsg )
{
    vmf_ret_t   my_ret;
    OTF_Result  otf_result;

#ifdef TEST_OPEN
    if (0 == wrapper_trid)
    {
        VMF_TRACE_ERROR_PRINT("pid=%d, OTF-Trace wrapper: OTF_warning() called without calling OTF_open()\n",getmypid());   
        return OTF_E_INTERNALFAILURE;
    }
#endif

    /* check if trace is allowed */
    if (vmf_trace_check_filter(wrapper_trid,VMF_TRACE_SEV_OTF_WARNING))
    {
        /* no trace*/
        return OTF_S_OK;
    }

    /* create the trace message */
#ifdef LAYOUT2
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_WARNING,(char*)pOTFScope->te.pName,(char*)pOTFScope->te.pName,(char *)pMsg);
#else
    my_ret = vmf_trace(wrapper_trid, VMF_TRACE_SEV_OTF_WARNING,wrapper_trid_name,(char*)pOTFScope->te.pName,(char*)pMsg);
#endif

    if (VMF_OK == my_ret)
    {
        /* store trid name */
        otf_result = OTF_S_OK;  
    }
    else
    {
        otf_result = OTF_E_INTERNALFAILURE;
    }

    return otf_result;
}









/**************************************************************************//**
 *   OTF_close
 *   The function is currently ignored 
 ******************************************************************************/
OTF_API
OTF_Result       OTF_entry( const OTF_ScopeEntry* pOTFScope)
{
    return OTF_S_OK;
}



/**************************************************************************//**
 *   OTF_close
 *   The function is currently ignored 
 ******************************************************************************/
void             OTF_register()
{
}






/**************************************************************************//**
 *
 *   OTF_open
 *   The function OTF open is wrapped to the vmf_trace_register function
 *
 *   \param[in]     pAppName            app name
 *   \param[in]     nMaxQueueSize       ignored
 *   \param[in]     OTF_PersistenRead   ignored
 *   \param[in]     OTF_PersistenWrite  ignored
 *
 *   \return        0 if OK, -1 if error
 *
 ******************************************************************************/
OTF_API
OTF_Result       OTF_open( const OTF_Char* pAppName
                            , OTF_UInt32 nMaxQueueSize
                            , OTF_PersistenRead pfnCallbackRead
                            , OTF_PersistenWrite pfnCallbackWrite)
{
    vmf_ret_t my_ret;
    OTF_Result otf_result=OTF_S_OK;
    
    my_ret = vmf_trace_register(&wrapper_trid,(char *)pAppName);
    
    if (VMF_OK == my_ret)
    {
        /* store trid name */
        strncpy(wrapper_trid_name,pAppName,sizeof(wrapper_trid_name));
        wrapper_trid_name[sizeof(wrapper_trid_name)-1]=0;
        otf_result = OTF_S_OK;  
    }
    else
    {
        otf_result = OTF_E_INTERNALFAILURE;
    }

    return otf_result;
}



/**************************************************************************//**
 *   OTF_close
 *   The function is currently ignored 
 ******************************************************************************/
OTF_API
OTF_Result       OTF_close( void )
{
    return OTF_S_OK;
}



/**************************************************************************//**
 *   OTF_registerEntry
 *   The function is currently ignored 
 ******************************************************************************/
OTF_API
OTF_Result       OTF_registerEntry( OTF_TreeEntry* pOTFEntr
                                  , const OTF_Char* pName)
{
    return OTF_S_OK;
}




/****************************************************************************/
/*                          unused OTF functions                            */
/****************************************************************************/

/*
OTF_API
OTF_Result       OTF_traceV( const OTF_ScopeEntry* pOTFScope
                              , const OTF_Char* pFmt
                              , va_list argptr )
{
}
*/


/*
OTF_API
OTF_Result       OTF_exit( const OTF_ScopeEntry* pOTFScope)
{
}
*/


/*
OTF_API
OTF_Result       OTF_settime( OTF_UInt32 nYear, OTF_UInt32 nMonth , OTF_UInt32 nDay
                            , OTF_UInt32 nHour, OTF_UInt32 nMinute, OTF_UInt32 nSecond, OTF_UInt32 nMilliSeconds)
{
}
*/


/*
OTF_API
OTF_Result       OTF_initScopesFromStorage( OTF_PersistenRead pfnCallbackRead)
{
}
*/

/*
OTF_API
void             OTF_setAllocators( OTF_allocFn pfnAlloc
                                         , OTF_freeFn pfnFree )
{
}
*/

/*
OTF_API
void*            OTF_heapalloc( size_t sz )
{
}




OTF_API
void             OTF_heapfree( void* p )
{
}
*/

/****************************************************************************/
/*                  Helper Funktionen                                       */          
/****************************************************************************/


 /**************************************************************************//**
 *
 *   Function Name: getmypid()
 *
 *   Description:   get the pid
 *
 *   Parameters:
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
static inline unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= nw_os_getpid();
    }
    
    return u32myPid;
}

