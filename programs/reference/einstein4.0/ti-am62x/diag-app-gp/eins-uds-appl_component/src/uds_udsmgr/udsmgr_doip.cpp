/*
 * udsmgr.c
 *
 *  Created on: May 14, 2020
 *      Author: MMK
 */

#include "udsmgr_doip_cfg.h"
#include "system.h"

/**  Private Functions  **/
//static bool UdsMgr_TravBoolVoidLst(bool (*const (*list_ptr))(void));

/*
** The 'deny_diag_request_process_list' lists pre-conditions for
** executing the dianostic commands
*/
/*
static BOOLEAN (*const DenyDiagReqProcessList[])(void)  =
{
  PROD_SPEC_DENY_DIAG_REQUEST_LIST
  NULL_PTR
};
*/
/*============================================================================
 ** Function Name:    UdsMgr_IsDiagReqPermitted
 **
 ** Visibility:       Public
 **
 ** Description:      This function is used to evaluate conditions if the
 **                   digonstics request can be performed or not
 **
 ** Invocation:       Invoked by UDS Stack
 **
 ** Inputs:           None
 **
 ** Return:           BOOLEAN
 **                   TRUE  - Diagonstics can be performed
 **                   FALSE - Diagonstics cannot be performed
 **
 ** Critical Section: None.
 **==========================================================================*/
BOOLEAN UdsMgr_IsDiagReqPermitted(void)
{
    return TRUE;//UdsMgr_TravBoolVoidLst(DenyDiagReqProcessList);
}


/*============================================================================
 ** Function Name:    UdsMgr_TravBoolVoidLst
 **
 ** Visibility:       Private
 **
 ** Description:      This function is traverse array of funtion pointers and
 **                   returns the value
 **
 ** Invocation:       Invoked by UDS Stack
 **
 ** Inputs:           BOOLEAN (*const (*list_ptr))(void) - List of functions
 **
 ** Return:           BOOLEAN
 **                   1 - If any one function return TRUE
 **                   0 - If all functions return FALSE
 **
 ** Critical Section: None.
 **==========================================================================*/
/*static BOOLEAN UdsMgr_TravBoolVoidLst(BOOLEAN (*const (*list_ptr))(void))
{
    BOOLEAN status = 0u;

    if(NULL_PTR != list_ptr)
	{
    	while(NULL_PTR != *list_ptr)
        {
            if(FALSE != ((**list_ptr)()))
            {
                status = 1u;
                break;
            }
            ++list_ptr;
        }
    }
    return (status);
}*/


