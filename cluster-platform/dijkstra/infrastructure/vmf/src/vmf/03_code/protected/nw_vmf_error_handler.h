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
*  MODULE NAME  :  nw_vmf_error_handler.h                                     *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   2nd September 2008                                        *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file of nw_vmf_error_handler.c                                      *
******************************************************************************/
#ifndef VMF_ERROR_HANDLER_H_
#define VMF_ERROR_HANDLER_H_


/* macros */
#define NW_VMF_ERROR_HDLR_DEBUG(verbose,args...){                                           \
                                                    if (verbose <1)                         \
                                                    {                                       \
                                                        NW_VMF_DEBUG_ERROR(args);           \
                                                    }                                       \
                                                    else                                    \
                                                    {                                       \
                                                        NW_VMF_DEBUG_PRINT("",verbose,args);\
                                                    }                                       \
                                                }

/* function prototypes */
vmf_ret_t nw_vmf_handle_invalid_most_msg (vmf_msg_t *vmf_message, vmf_ret_t vmf_router_error,unsigned8 *p_raw_msg);



#endif

