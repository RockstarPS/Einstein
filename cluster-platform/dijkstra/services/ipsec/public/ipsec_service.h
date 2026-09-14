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
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fs.h> 

#define MAX_ERROR 255U
#define MAX_LINES   200
#define MAX_LINE_LEN 128
#define MAX_LINE_LEN_ERROR  256

typedef struct
{
    char lines[MAX_LINES][MAX_LINE_LEN_ERROR];
    uint8_t line_count;
} IPSEC_ERROR_t;

typedef struct
{
    char lines[MAX_LINES][MAX_LINE_LEN];
    int32_t line_count;

} IPSEC_STATUS_t;

#define IPSEC_KEY_FILE_PATH "/persist/device1-key.pem"
#define SWANCTL_KEY_LINK "/etc/swanctl/private/device1-key.pem"
#define IPSEC_KEY_ID_STR  "Secure"
#define IPSEC_TEMP_CONF "/persist/swanctl_tmp.conf"


#ifndef EOK
#define EOK             0      /* no error */
#endif //EOK

#ifndef ENOK
#define ENOK             1      /* no error */
#endif //EOK

#define IP_MASK_CMD_LEN 256

#define STATUS_LEN 512u
#define IP_MASK_SIZE_BYTES     32u
#define IP_MASK_BUF_LEN_HEX    ((IP_MASK_SIZE_BYTES * 2u) + 1u)
#define THIRD_OCTET_MAX_LEN 4u
#define THIRD_OCTET_MAX_LEN_N 3u
#define CHILD_LEN 6u
#define IKE_LEN 4u
#define SSCANF 2
#define SUBNET_INDEX       4U
#define BITMASK_START_IDX  5U
#define BITMASK_LEN        32U
#define UDS_MAX_LEN        255U
#define EXPECTED_PAYLOAD_LEN (BITMASK_START_IDX + BITMASK_LEN)
#define IP_MASK_READ_LEN   (2U + BITMASK_LEN)
#define HEX_MAX_STR     ((BITMASK_LEN * 2U) + 3U)
#define HEX_MASK 2U
#define TWO_BYTE 16
#define STRBUF 10


#define OPERATION_ALREADY_RUNNING  2
#define FORBIDDEN  3
#define INVALID  0xFF 

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
** - 1 - if not able to start strongswan service, 
** - 0x02 -OPERATION_ALREADY_RUNNING
** - 0xFF -INVALID (IPsec is locked)
** Requirement ID - BMIC29130-19214, BMIC29130-19215
**
*****************************************************************************/
int32_t StartStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t securitymanager_store_ipsec_key(const uint8_t *p_pem_data_U8,
**                                             size_t pem_len_U32);
**
** \brief This interface is used to store an IPSec key provided in PEM format.
**
** This API validates the given PEM data buffer and length, then stores the
** IPSec key securely for later use by the security subsystem.
**
** \param p_pem_data_U8  Pointer to the PEM-formatted key data (not used directly)
** \param pem_len_U32    Length of the provided PEM data
**
** \return int32_t<br>
** This function returns:
** - 0  – Key stored successfully  
** - 1  – Invalid input or key storage failed  
**
*****************************************************************************/
int32_t securitymanager_store_ipsec_key(const uint8_t *p_pem_data_U8, size_t pem_len_U32);
/****************************************************************************
** \fn int32_t StopStrongSwan_Service(void);
** This interface shall used to stop the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan stoped successfully 
** - 1 - if not able to stop strongswan service
** - 0x02 -OPERATION_ALREADY_RUNNING
** - 0x03 - FORBIDDEN - Operation not allowed because IPsec locked.
** - 0xFF  - INVALID
** Requirement ID - BMIC29130-19217, BMIC29130-19218
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
** \param [in] status
** pointer stores the status of strongswan service
** \param [in] dataLength
** pointer to the lenght of status 
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan status is printed successfully 
** - 1 - if not able to print strongswan status
** Requirement ID - BMIC29130-19236, BMIC29130-19224, BMIC29130-19225
**
*****************************************************************************/
int32_t StatusStrongSwan_Service(uint8_t *status, uint8_t *dataLength);
/****************************************************************************
** \fn int32_t ErrorStrongSwan_Service(void);
** This interface shall used to store error the strongswan service
** \param [in] error
** pointer stores the error of strongswan service 
** \param [in] dataLength
** pointer to the lenght of error
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan error status is printed successfully 
** - 1 - if not able to print strongswan error status
** Requirement ID - BMIC29130-19237
**
*****************************************************************************/
int32_t ErrorStrongSwan_Service(uint8_t *error, uint8_t *dataLength);
/****************************************************************************
** \fn int32_t IpMaskStrongSwan_Service(void);
** This interface shall used to ip mask the strongswan service
** \param [in] req
** pointer to the ip value to mask in configuration
**
** \param [in] len
** size of the req pointer 
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan ip mask write is successful 
** - 1 - if not able to perform ip mask write in strongswan
** Requirement ID - BMIC29130-19285BMIC29130-19592
**
*****************************************************************************/
int32_t IpMaskStrongSwan_Service(const uint8_t *req, uint8_t len);

/****************************************************************************
** \fn int32_t IpMaskStrongSwan_Service(void);
** This interface shall used to ip mask the strongswan service
** \param [out] req
** pointer to the ip which is masked in configuration
**
** \param [out] len
** size of the req pointer 
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan ip mask read is successful 
** - 1 - if not able to perform ip mask read in strongswan
** Requirement ID - BMIC29130-19285
**
*****************************************************************************/
int32_t IpMaskReadStrongSwan_Service(uint8_t *data, uint8_t *len);
/****************************************************************************
** \fn int32_t LockStrongSwan_Service(void);
** This interface shall used to lock the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan service locked successfully 
** - 1 - if not able to lock the service 
** - 0x02 - OPERATION_ALREADY_RUNNING
** - 0x03 - FORBIDDEN - Operation not allowed because IPsec has not been started.
** - 0xFF  - INVALID
** Requirement ID - BMIC29130-19219, BMIC29130-19220
**
*****************************************************************************/
int32_t LockStrongSwan_Service(void);
/****************************************************************************
** \fn int32_t UnlockStrongSwan_Service(void);
** This interface shall used to unlock the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan service unlocked successfully 
** - 1 - if not able to unlock the service 
** - 0x02 - OPERATION_ALREADY_RUNNING
** - 0xFF  - INVALID
** Requirement ID - BMIC29130-19221, BMIC29130-19222
**
*****************************************************************************/
int32_t UnlockStrongSwan_Service(void);

/****************************************************************************
** \fn int32_t LockStatus_Service(void);
** This interface shall used to check the lock status of the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan locked already 
** - 1 - if strongswan not locked
**
*****************************************************************************/
int32_t LockStatus_Service(void);
/****************************************************************************
** \fn int32_t EnableStatus_Service(void);
** This interface shall used to check the enable status of the strongswan service
**
**
** \return int32_t<br>
** This function returns:
** - 0 - if Strongswan enabled successfully 
** - 1 - if not able to enable strongswan service
**
*****************************************************************************/
int32_t EnableStatus_Service(void);

#define LOCK_FILE "/persist/swanctl.lock" 

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif
