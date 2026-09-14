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
*  MODULE NAME  :  nw_vmf_rem_server_connector.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  target connector header file                     *
******************************************************************************/
#ifndef __REM_VMF_CLIENT_CONNECTOR_H
#define __REM_VMF_CLIENT_CONNECTOR_H

#ifndef WIN32
/* windows compatibility definitions */
#define WSAStartup(...)     (0)
#define WSACleanup(...)
#define WSAGetLastError()   errno
#define SOCKADDR_IN         struct sockaddr_in
#define SOCKADDR            struct sockaddr
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#define INVALID_SOCKET      (-1)
#define closesocket(s) 		close(s)

#define _TCHAR              char
#endif

/* define */
#define VMF_REM_SPY_COLL_TIMEOUT	(500)	/* timeout in ms for spy message collector */
#define WMF_REN_SPY_COLLECTOR_LEN	(1300)	/* size of spy collector buffer */
/* function prototypes */
vmf_error_t vmf_client_con_init(void);
vmf_ret_t nw_vmf_create_rem_vmf_thread(void);
void *vmf_client_rpc_handler(void *pArg);

#endif
