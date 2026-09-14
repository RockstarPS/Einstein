/*
 * uds_mgr_cfg.h
 *
 *  Created on: May 14, 2020
 *      Author: MMK
 */

#ifndef UDS_MGR_CFG_H
#define UDS_MGR_CFG_H

#include "system.h"

#define DATA_LEN_0_BYTE                     ( 0x00u)
#define DATA_LEN_1_BYTE                     ( 0x01u)
#define DATA_LEN_2_BYTE                     ( 0x02u)
#define DATA_LEN_3_BYTE                     ( 0x03u)
#define DATA_LEN_4_BYTE                     ( 0x04u)
#define DATA_LEN_5_BYTE                     ( 0x05u)
#define DATA_LEN_6_BYTE                     ( 0x06u)
#define DATA_LEN_9_BYTE                     ( 0x09u)
#define DATA_LEN_18_BYTE                    ( 0x12u)

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* NAME:         PROD_SPEC_DENY_DIAG_REQUEST_LIST                          */
/*                                                                         */
/* TYPE:         MACRO                                                     */
/*                                                                         */
/* DESCRIPTION:  This macro must contain a list of all functions that are  */
/*               to be executed when any diagnostic command is received.   */
/*               Any tasks that have conditions which can prevent          */
/*               processing diagnostic request are to be listed here.      */
/*               Functions in this list must match the following prototype.*/
/*                                                                         */
/*                 BOOLEAN function_name_KSDenydiagrequest(void)           */
/*                                                                         */
/*               The values returned by functions in this list must be as  */
/*               follows:                                                  */
/*                                                                         */
/*                 FALSE if ok to process diagnostic request.              */
/*                 TRUE  if not ready for reset.                           */
/*                                                                         */
/*               If any function in the list returns TRUE, request is      */
/*               aborted and negative response is sent.                    */
/*                                                                         */
/*               Functions in this list are executed sequentially from the */
/*               first function in the list until the last.                */
/*                                                                         */
/* REQUIRED:     YES.(List can be NULL)                                    */
/*                                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
#define PROD_SPEC_DENY_DIAG_REQUEST_LIST      \
	    NULL,                  \


#endif /* UDS_MGR_CFG_H */
