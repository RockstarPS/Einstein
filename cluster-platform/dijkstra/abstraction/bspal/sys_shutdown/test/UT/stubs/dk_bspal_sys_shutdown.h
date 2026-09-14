/*
 * dk_system_shutdown.h
 *
 *  Created on: 13-Aug-2020
 *      Author: DRAJ5
 */

#ifndef DK_BSPAL_SYS_SHUTDOWN_H_
#define DK_BSPAL_SYS_SHUTDOWN_H_
typedef signed int int32_t;
typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef enum
{
	ESysShutdown_Reboot = 0,
    ESysShutdown_Shutdown,
} ESysShutdown_t;


/*! *********************************************************************************************************************
 *
 * @brief     Shutdown the system and retain(cause of shutdown) user provided information
 * @param[in] types    : Type of shutdown
 *            reason   : Cause of shutdown
 *
 * @return    E_OK     : Success
 * 		      E_NOT_OK : FAIL
 *
 **********************************************************************************************************************/
int32_t dk_bspal_sys_shutdown( ESysShutdown_t type, const char *reason );
#define EOK 0
#endif /* DK_BSPAL_SYS_SHUTDOWN_H_ */
