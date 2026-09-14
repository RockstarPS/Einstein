/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_rem_debug.h                                               *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   16th Feb 2009                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  remote vmf debug api                   *
******************************************************************************/
#ifndef VMF_REM_VMF_DEBUG__H_
#define VMF_REM_VMF_DEBUG__H_

//#define VMF_REM_DEBUG

#ifndef WIN32
#include <sys/slogcodes.h>
#endif


#ifdef WIN32
#ifdef VMF_REM_DEBUG
#ifdef VMF_REM_SERVER_UNIT_TEST
#define NW_REM_VMF_DEBUG_ERROR(args...)     printf("vmf_remote: error: ");printf(args);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_INFO(args...)      printf("vmf_remote: info:  ");printf(args);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_PRINTF(args...)    printf(args);printf("\n");fflush(stdout);
#else
#define NW_REM_VMF_DEBUG_ERROR(text,...)    printf("vmf_remote: error: ");printf(text,__VA_ARGS__);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_INFO(text,...)     printf("vmf_remote: info:  ");printf(text,__VA_ARGS__);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_PRINTF(text,...)   printf(text,__VA_ARGS__);
#endif
#else
#define NW_REM_VMF_DEBUG_ERROR(text,...)     printf("vmf_remote: error: ");printf(text,__VA_ARGS__);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_INFO(text,...)
#define NW_REM_VMF_DEBUG_PRINTF(text,...)
#endif

#define NW_VMF_DBG_ASP_CLIENT_LIB       0
#define NW_VMF_DBG_LVL_INFO             0

#ifdef VMF_REM_SERVER_UNIT_TEST
#ifdef NW_VMF_DEBUG_PRINT
#undef NW_VMF_DEBUG_PRINT
#endif
#endif
#define NW_VMF_DEBUG_PRINT(l1,l2,...)   NW_REM_VMF_DEBUG_PRINTF(__VA_ARGS__)

#ifdef VMF_REM_SERVER_UNIT_TEST
#ifdef NW_VMF_DEBUG_INFO
#undef NW_VMF_DEBUG_INFO
#endif
#endif
#define NW_VMF_DEBUG_INFO               NW_REM_VMF_DEBUG_INFO

#ifdef VMF_REM_SERVER_UNIT_TEST
#ifdef NW_VMF_DEBUG_ERROR
#undef NW_VMF_DEBUG_ERROR
#endif
#endif
#define NW_VMF_DEBUG_ERROR              NW_REM_VMF_DEBUG_ERROR

#else /* QNX */
#ifdef VMF_REM_DEBUG
#define NW_REM_VMF_DEBUG_ERROR(args...)     printf("vmf_remote: error: ");printf(args);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_INFO(args...)      printf("vmf_remote: info:  ");printf(args);printf("\n");fflush(stdout);
#define NW_REM_VMF_DEBUG_PRINTF(args...)    printf(args);
#else
#define NW_REM_VMF_DEBUG_ERROR(args...)     slogf (_SLOGC_NETWORK, _SLOG_ERROR, args);
#define NW_REM_VMF_DEBUG_PRINTF(args...)    
#define NW_REM_VMF_DEBUG_INFO(args...)      
#endif

#endif

#ifdef WIN32
#ifdef _GW_H
void nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg);
#else
DLL_EXPORT void nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg);
#endif
#else
void nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg);
#endif

#endif
