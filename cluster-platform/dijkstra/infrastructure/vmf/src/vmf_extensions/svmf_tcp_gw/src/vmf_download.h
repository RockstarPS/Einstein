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
*  MODULE NAME  :  vmf_download.h                                             *
*  AUTHOR NAME  :  Joachim Becker                                             *
*******************************************************************************
*  MODULE DATE  :   2014                                                      *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  vmf download types and definitions                                         *
*******************************************************************************/

#ifndef _VMF_DOWNLOAD_H
#define _VMF_DOWNLOAD_H

#define VMF_TCD_NAK		0x00
#define VMF_TCD_ACK		0x01

#define FLASH_TARGET_LEOPARD        "Leopard-E"


/* message format for VMF_TRACE_DOWNLOAD_REQUEST  */
typedef struct
{
    unsigned8   version;            /* version - 0x00 for version 0 */
    unsigned8   fill;          		/* fill byte */
    unsigned16  download_id;			/* target id */

    unsigned8   group;   			/* group of download data end-user or 0 */
    unsigned8   event;   			/* event of download data end-user or 0 */
    unsigned8   data_len_ll;		/* data length in bytes bit 0-  7 */
    unsigned8   data_len_lh;		/* data length in bytes bit 8- 15 */

    unsigned8   data_len_hl;		/* data len in bytes bit 16-23 */
    unsigned8   transfer_group;		/* this group is used for the transfer */
#if 0
    char        target_name[]; 		/* target name – zero terminated */
    char        name[]; 			/* file-name   – zero terminated */
    char        path[];			    /* file-path   - zero terminated */
#else
    char        pl[0];              /* target, file-name, path - all zero terminated */
#endif
}vmf_download_req_t;



/* message format for VMF_TRACE_DOWNLOAD_RESPONSE  */
typedef struct
{
    unsigned8   version;          	/* version - 0x00 for version 0 */
    unsigned8   fill;          		/* fill byte */
    unsigned16  download_id;		/* target id */

    unsigned8   block_len_ll;		/* data len in bytes bit 0- 7 */
    unsigned8   block_len_lh;		/* data len in bytes bit 8-15 */
}vmf_download_res_t;
 

/* message format for VMF_TRACE_DOWNLOAD_DONE   */
typedef struct
{
    unsigned8   version;          	/* version - 0x00 for version 0 */
    unsigned8   fill;          		/* fill byte */
    unsigned16  download_id;		/* target id */

}vmf_download_done_t;


/* message format for VMF_TRACE_DOWNLOAD_TRANSFER    */
typedef struct
{
    unsigned8   version;        	/* version - 0x00 for version 0 */
    unsigned8   fill;          		/* fill byte */
    unsigned16  download_id;		/* target id */

    unsigned8   block_num;			/* message number starting with 0 */
    unsigned8   block_len_ll;		/* payload message length in bytes bit 0-  7 */
    unsigned8   block_len_lh;		/* payload message length in bytes bit 8- 15 */

    unsigned8   pl[0];			    /* payload */
}vmf_download_trans_t;


/* message format for VMF_TRACE_DOWNLOAD_TRANSFER_RESP    */
typedef struct
{
    unsigned8   version;          	/* version - 0x00 for version 0 */
    unsigned8   fill;          		/* fill byte */
    unsigned16  download_id;    	/* target id */

    unsigned8   response;			/* 0x00 = NAK, 0x01=ACK */
    unsigned8   block_num;			/* block number */
    unsigned8   block_len_ll;		/* next message length in bytes bit 0-  7 */
    unsigned8   block_len_lh;		/* next message length in bytes bit 8- 15 */

}vmf_download_trans_resp_t;







#endif
