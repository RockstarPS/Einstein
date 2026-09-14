/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2022] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file SecurestorageCrypto_ca.h
 *
 * \brief
 * Main Implementation of Securitymanager library optee Client application 
 * optee-os version 4.2.0
 *
 * \version 1.1.0
 * |Version | Date       | Author         | Task Id 		 | Description                                                           						  |
 * |--------|------------|----------------|------------------|------------------------------------------------------------------------------------------------|
 * |1.00.00 | 2025-04-22 | hsriniv5       | BMIC29130-27372 | Implement Ipsec services start stop disable restart status API                                  |
*/

#ifndef IPSEC_SERVICE_H
#define IPSEC_SERVICE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


#ifndef EOK
#define EOK             0      /* no error */
#endif //EOK

#ifndef ENOK
#define ENOK             1      /* no error */
#endif //EOK

#define IP_MASK_CMD_LEN 256


#define CONFIG_PATH_LENGTH 26

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************
** \fn int32_t StartStrongSwan_Service(void);
** This interface shall used to start the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan started successfully 
** - 1 - if not able to start strongswan service
**
*****************************************************************************/
int32_t StartStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t StopStrongSwan_Service(void);
** This interface shall used to stop the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan stoped successfully 
** - 1 - if not able to stop strongswan service
**
*****************************************************************************/
int32_t StopStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t DisableStrongSwan_Service(void);
** This interface shall used to disable the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan disable successfully 
** - 1 - if not able to disable strongswan service
**
*****************************************************************************/
int32_t DisableStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t RestartStrongSwan_Service(void);
** This interface shall used to restart the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan restarted successfully 
** - 1 - if not able to restart strongswan service
**
*****************************************************************************/
int32_t RestartStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t StatusStrongSwan_Service(void);
** This interface shall used to status the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan status is printed successfully 
** - 1 - if not able to print strongswan status
**
*****************************************************************************/
int32_t StatusStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t ErrorStrongSwan_Service(void);
** This interface shall used to status the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan error status is printed successfully 
** - 1 - if not able to print strongswan error status
**
*****************************************************************************/
int32_t ErrorStrongSwan_Service(void);

/****************************************************************************
** \fn int32_t IpMaskStrongSwan_Service(void);
** This interface shall used to status the strongswan service
** \param [in] third_octet
** pointer to the third octet value to mask the ip
**
** \param [in] hex_mask
** pointer to the hex mask to calulate the 4th octet value to mask the ip
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan ip mask is successful 
** - 1 - if not able to perform ip mask in strongswan
**
*****************************************************************************/
int32_t IpMaskStrongSwan_Service(const char* third_octet, const char* hex_mask);

int32_t LockStrongSwan_Service(void);
int32_t UnlockStrongSwan_Service(void);

#define LOCK_FILE "/persist/swanctl.lock" 

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif
