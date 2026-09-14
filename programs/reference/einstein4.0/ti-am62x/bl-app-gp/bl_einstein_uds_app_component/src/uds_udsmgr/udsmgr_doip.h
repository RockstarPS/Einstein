/*
 * udsmgr.h
 *
 *  Created on: May 14, 2020
 *      Author: MMK
 */

#ifndef UDSMGR_UDSMGR_H_
#define UDSMGR_UDSMGR_H_


/*============================================================================
 ** Function Name:    UdsMgr_IsDiagReqPermitted
 **
 ** Visibility:       Public
 **
 ** Description:      This function is used to evaluate conditions if the
 **                   diagnostics  request can be performed or not
 **
 ** Invocation:       Invoked by UDS Stack
 **
 ** Inputs:           None
 **
 ** Return:           BOOLEAN
 **                   TRUE  - Diagnostics can be performed
 **                   FALSE - Diagnostics cannot be performed
 **
 ** Critical Section: None.
 **==========================================================================*/
bool UdsMgr_IsDiagReqPermitted(void);


#endif /* UDSMGR_UDSMGR_H_ */
