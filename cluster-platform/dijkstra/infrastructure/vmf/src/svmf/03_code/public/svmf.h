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

/***************************************************************************

  Module:               vmf_app.h
  Description:          header file for vmf_app 
  Project Scope:        leopard-e

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar
  Target Hardware:      leopard-e

  *****************************************************************************/

#ifndef VMF_APP_H
#define VMF_APP_H


/* vmf sizes */
#define SVMF_PL_LEN_STD				(400)
#define SVMF_PL_LEN_MAX				(400)
#define SVMF_PL_LEN_MIN				(1)
#define MAX_SVMF_DATA_LEN			VMF_PL_LEN_MAX

/*! Handle definitions */
#define BROADCAST							250
#define VMF_HANDLE_INVALID                  0x7F
#define VMF_HANDLE_BROADCAST                0x7A
#define VMF_BROADCAST_GROUP                 BROADCAST

/* enums */
enum VMF_MSG_T
{
	SVMF_BASIC_MSG				= 0x20,                /* small basic message */
	VMF_CTRL_MSG				= 0x21	               /* control message     */
};

enum SVMF_CTRL_MSG_T
{
	VMF_CTRL_CONNECT			= 3,				   /* connect     */
	VMF_CTRL_REGISTER_MSG_GRP	= 9,		           /* register msg groups  */
	VMF_CTRL_DEREGISTER_MSG_GRP = 10,				   /* de-register msg groups  */
	VMF_CTRL_REGISTER_SPY		= 12,				   /* regsiter the spy */
	VMF_CTRL_DISCONNECT		    = 13			       /* discconnect     */
};


typedef unsigned8		vmf_event_t;
typedef unsigned8		vmf_group_t;
typedef unsigned8		vmf_cid_t;
typedef unsigned16		vmf_pid_t;


/*! \struct VMF_VAR_BASIC_MSG_TYP for small systems
 *   vmf variable size base message */
#define ctrl_type	event
#pragma pack(push,4)
#define SVMF_VAR_MSG_TYP(VAR_DATA_LEN)                 						    		\
struct                                                      							\
{                                                           							\
    unsigned8          	msg_type;               /* control or basic message */ 			\
	vmf_event_t       	event;              	/* message event or         */			\
	vmf_group_t       	group;                  /* message group            */  		\
	vmf_cid_t  			cid;                 	/* client id                */  		\
/* 32bit boundary */																	\
	vmf_pid_t         	pid;                    /* process id               */			\
	unsigned16          msg_time;               /* bit 0-15 of message time in ms 	*/	\
												/* time in little endian    */	 	    \
/* 32bit boundary */																	\
	unsigned8           msg_time_hh;          	/* bit 16-23 of message time in ms	*/	\
    unsigned8           client_count;           /* for debugging use        */  		\
																						\
	unsigned16          pl_len;                	/* pl length in little endian */		\
/* 32bit boundary */																	\
    unsigned8           pl[(VAR_DATA_LEN)];             								\
}                                                      							
#pragma pack(pop)

/* pre define vmf message types */
typedef SVMF_VAR_MSG_TYP(SVMF_PL_LEN_MAX)    	svmf_msg_max_t;
typedef SVMF_VAR_MSG_TYP(SVMF_PL_LEN_MIN)    	svmf_msg_min_t;
typedef SVMF_VAR_MSG_TYP(SVMF_PL_LEN_STD)    	svmf_msg_std_t;
typedef svmf_msg_std_t                      	svmf_msg_t;

#define SVMF_MSG_LEN(pl_len)					(sizeof(SVMF_VAR_MSG_TYP(SVMF_PL_LEN_MIN))+pl_len)
#define SVMF_STD_MSG_LEN 						(sizeof(svmf_msg_std_t))
#define SVMF_MAX_MSG_LEN 						(sizeof(svmf_msg_max_t))
#define SVMF_MIN_MSG_LEN 						(sizeof(svmf_msg_min_t))
#define SVMF_HEADER_LEN							(SVMF_STD_MSG_LEN - SVMF_PL_LEN_STD)					/* handle alignment */


/* VMF access macros  */
/* MACROS without cast - these MACROS will only work with VMF_BASIC messages */
#define NW_SVMF_BASIC_MSG_GROUP(msg)         ((msg)->group)
#define NW_SVMF_BASIC_MSG_EVENT(msg)         ((msg)->event)
#define NW_SVMF_BASIC_MSG_TYPE(msg)          ((msg)->msg_type)
#define NW_SVMF_BASIC_MSG_DATA_LENGTH(msg)   ((msg)->pl_len)
#define NW_SVMF_BASIC_MSG_DATA_PTR(msg)      (&(msg)->pl[0])

/*  old MACROS for compatibility reasons  */
#define NW_SVMF_MSG_EVENT(msg)               NW_SVMF_BASIC_MSG_GROUP(msg)
#define NW_SVMF_MSG_GROUP(msg)               NW_SVMF_BASIC_MSG_EVENT(msg)
#define NW_SVMF_MSG_TYPE(msg)                NW_SVMF_BASIC_MSG_TYPE(msg)
#define NW_SVMF_MSG_DATA_LENGTH(msg)         NW_SVMF_BASIC_MSG_DATA_LENGTH(msg)
#define NW_SVMF_MSG_DATA_PTR(msg)            NW_SVMF_BASIC_MSG_DATA_PTR(msg)



#endif


  
