/*
 * ethernet_register_read_write.h
 *
 *  Created on: Jun 19, 2018
 *      Author: DevendraT
 */

#ifndef ETHERNET_REGISTER_READ_WRITE_V2_H_
#define ETHERNET_REGISTER_READ_WRITE_V2_H_

/*****************************************************************************
*                                 Macro Definitions                          *
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define READ_STATUS_OK    (uint8_t) 0x62
#define READ_STATUS_NOK   (uint8_t) 0

#define WRITE_STATUS_OK   (uint8_t) 0x6E
#define WRITE_STATUS_NOK  (uint8_t) 0
#define READ_REG  0xE
#define REGISTER_SIZE     (uint8_t) 16


/*****************************************************************************
*                            Public Functions                                *
******************************************************************************/
/*============================================================================
**
** Function Name:    Phy_read_register
**
** Visibility:       Public
**
** Description:      Read Ethernet register by given access DID
**                   and saves register value in the parameter structure
**
** Inputs:           Address, Data
**
** Outputs:          uint8_t
**                      READ_STATUS_OK - register value is read
**                      READ_STATUS_NOK - register value is not read
**
** Critical Section: None
**
**==========================================================================*/
uint8_t Phy_read_register(uint16_t p_Address, uint16_t *p_Data );

/*============================================================================
**
** Function Name:    Phy_write_register
**
** Visibility:       Public
**
** Description:      Write bits from given value by the register mask
**                   to the Ethernet register.
**
**                   When mask bit equals 1, value bit is set to register.
**
** Inputs:            Address
**                   Data
**
** Outputs:          uint8_t
**                      WRITE_STATUS_OK - Ethernet register is updated
**                      WRITE_STATUS_NOK - Ethernet register is not updated
**
** Critical Section: None
**
**==========================================================================*/
uint8_t Phy_write_register(uint16_t p_Address , uint16_t p_Data);

/*============================================================================
**
** Function Name:    MMD_read_register
**
** Visibility:       Public
**
** Description:      Read Ethernet register by given access DID
**                   and saves register value in the parameter structure
**
** Inputs:           Address, Data
**
** Outputs:          uint8_t
**                      READ_STATUS_OK - register value is read
**                      READ_STATUS_NOK - register value is not read
**
** Critical Section: None
**
**==========================================================================*/
uint8_t MMD1_read_register(uint16_t p_addr, uint16_t *p_data );

/*============================================================================
**
** Function Name:    MMD_write_register
**
** Visibility:       Public
**
** Description:      Write bits from given value by the register mask
**                   to the Ethernet register.
**
**                   When mask bit equals 1, value bit is set to register.
**
** Inputs:            Address
**                   Data
**
** Outputs:          uint8_t
**                      WRITE_STATUS_OK - Ethernet register is updated
**                      WRITE_STATUS_NOK - Ethernet register is not updated
**
** Critical Section: None
**
**==========================================================================*/
uint8_t MMD1_write_register(uint16_t p_addr, uint16_t data);
/*============================================================================
**
** Function Name:    MMD_read_register
**
** Visibility:       Public
**
** Description:      Read Ethernet register by given access DID
**                   and saves register value in the parameter structure
**
** Inputs:           Address, Data
**
** Outputs:          uint8_t
**                      READ_STATUS_OK - register value is read
**                      READ_STATUS_NOK - register value is not read
**
** Critical Section: None
**
**==========================================================================*/
uint8_t MMD1F_read_register(uint16_t p_addr, uint16_t *p_data );

/*============================================================================
**
** Function Name:    MMD_write_register
**
** Visibility:       Public
**
** Description:      Write bits from given value by the register mask
**                   to the Ethernet register.
**
**                   When mask bit equals 1, value bit is set to register.
**
** Inputs:            Address
**                   Data
**
** Outputs:          uint8_t
**                      WRITE_STATUS_OK - Ethernet register is updated
**                      WRITE_STATUS_NOK - Ethernet register is not updated
**
** Critical Section: None
**
**==========================================================================*/
uint8_t MMD1F_write_register(uint16_t p_addr, uint16_t data);
#ifdef __cplusplus
}
#endif
#endif /* ETHERNET_REGISTER_READ_WRITE_H_ */
