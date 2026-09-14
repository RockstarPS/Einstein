/*********************************************************************************************************************
 *!  \verbatim
 *!
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2023] Visteon Corporation
 *       All Rights Reserved.
 *
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and intends to
 *               maintain it in confidence to preserve its trade secret status. Visteon
 *               Corporation reserves the right, under the copyright laws of the United States
 *               or those of any other country that may have jurisdiction, to protect this work
 *               as an unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves its rights under
 *               all copyright laws to protect this work as a published work, when appropriate.
 *               Those having access to this work may not copy it, use it, modify it, or
 *               disclose the information contained in it without the written authorization of
 *               Visteon Corporation.
 *
 *  @endverbatim
 *
 *  @file        linux_sys_shutdown.c
 *  @brief       Implementation of abstraction layer to reboot or shutdown the system.
 *  @details     linux_sys_shutdown is an abstraction layer for rebooting and  shutdown the system. It is based
 *               on TI AM62A variant Applications Processor Reference.
 *  @author      durai panneerselavam (dpanneer)
 *  @version     1.0
 *  @addtogroup  dk_bspal
 *  @copyright   Visteon Corporation
 *  @date        30082023
 *  @note        The following document is compliant to:
 *               1. Visteon C Coding Best Practice Rules Ver 1.1
 *********************************************************************************************************************/

/*! *********************************************************************************************************************
 *  @INCLUDES
 *********************************************************************************************************************/

/*! @brief  :  Import shutdown Header File. */
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h> 
#include <systemd/sd-bus.h>
/*! @brief  :  Import  Module Public Header File. */
#include "dk_bspal_sys_shutdown.h"

/*! **********************************************************************************************************************
 *  @PUBLIC FUNCTION IMPLEMENTATIONS
 ************************************************************************************************************************/

/*! *********************************************************************************************************************
 *
 * @brief     Shutdown the system and retain(cause of shutdown) user provided information
 * @param[in] p_type_E     : Type of Operation shutdown/reboot
 *            p_reason_C   : Cause of shutdown/reboot
 *
 * @return    0     : Success
 *           -1     : FAIL
 *
 **********************************************************************************************************************/
int32_t dk_bspal_sys_shutdown ( ESysShutdown_t p_type_E, const char *p_reason_C )
{
    int32_t l_RetVal_S32 = -1;
    int32_t l_result_S32 = -1;

    switch ( p_type_E )
    {
        case ESysShutdown_Reboot:

          
			 /* Initiate the system reboot */
			l_result_S32 = call_systemd_power_action("Reboot");

			if (l_result_S32 == -1)
			{
				fprintf(stderr, "Reboot failed l_result_S32 (code: %d): %s\n",
						l_result_S32, strerror(l_result_S32));
				l_RetVal_S32= EXIT_FAILURE;
			}
			else
			{
				// The program will not reach this point if the reboot is successful
				l_RetVal_S32= EXIT_SUCCESS;
			}

            break;

        case ESysShutdown_Shutdown:
            
			/* Initiate the system PowerOff */
			l_result_S32 = call_systemd_power_action("PowerOff");

			if (l_result_S32 == -1)
			{
				fprintf(stderr, "Poweroff failed (code: %d): %s\n", l_result_S32,
						strerror(l_result_S32));
				l_RetVal_S32= EXIT_FAILURE;
			}
			else
			{
				// The program will not reach this point if the reboot is successful
				l_RetVal_S32= EXIT_SUCCESS;
			}

			break;

        default:
            l_RetVal_S32 = -1;
            break;
    };


	return l_RetVal_S32;
}

/*! *********************************************************************************************************************
 *
 * @brief     This function is to send power off or reboot request through systemd dbus.
 * @param[in] p_dbus_method   : pointer to the dbus method call for power off or reboot
 *
 * @return    0     : Success
 *           -1     : FAIL
 *
 **********************************************************************************************************************/
int32_t call_systemd_power_action(const char *p_dbus_method) {
	sd_bus *bus = NULL;
	sd_bus_message *msg = NULL;
	int32_t l_RetVal_S32 = 0;
	int32_t l_result_S32 = 0;

	if (!p_dbus_method || (strcmp(p_dbus_method, "PowerOff") != 0 &&
                         strcmp(p_dbus_method, "Reboot") != 0))
	{
		fprintf(stderr, "Invalid system dbus method\n");
		fflush(stderr);
		l_RetVal_S32 = -1;
	}
	else
	{
		// Connect to the system bus
		l_result_S32 = sd_bus_open_system(&bus);
		if (l_result_S32 < 0)
		{
		  fprintf(stderr, "Failed to connect to system dbus (code: %d): %s\n",
				  l_result_S32, strerror(l_result_S32));
		  fflush(stderr);
		  l_RetVal_S32 = -1;
		}
		else
		{
		  // Call method: PowerOff or Reboot on org.freedesktop.login1.Manager
		  l_result_S32 =
						sd_bus_call_method(bus,
											"org.freedesktop.login1",         // service
											"/org/freedesktop/login1",        // object path
											"org.freedesktop.login1.Manager", // interface
											p_dbus_method, // p_dbus_method: PowerOff or Reboot
											NULL,          // input signature
											&msg,          // dbus message
											"b",           // input: boolean
											0);            // argument: interactive = false
		  if (l_result_S32 < 0)
		  {
			fprintf(stderr, "system dbus method call failed (code: %d): %s\n",
					l_result_S32, strerror(-l_result_S32));
			fflush(stderr);
			sd_bus_unref(bus);
			l_RetVal_S32 = -1;
		  }
		  else
		  {
			sd_bus_message_unref(msg);
			sd_bus_unref(bus);
		  }
		}
	}

	return l_RetVal_S32;
}


/************************************************** END of FILE *****************************************************/

/*--------------------------------------------------------------------------------------------------------------------
   REVISION HISTORY
 ---------------------------------------------------------------------------------------------------------------------
 Date               : 30-08-2023
 By                 : dpanneer
 Trace-ability      : GIT#
 Change Description : Initial Version
 @version
 22JUL2025   | PKRISH12 |  TFDCX32348-98686 | Dbus based power off and reboot request to systemd is implemented.
 --------------------------------------------------------------------------------------------------------------------*/

