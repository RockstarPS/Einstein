/*****************************************************************************
 **
 **  \file CDio_HwIf.h
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
 **  \author: 
 **  
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2020-08-02 |  RBABU9  | Create Initial Module.
 **  | 2023-08-25 | damudhar | Added Doxygen document
 **
 **  Revision History
 **  Added out_value and in_value parameters as per AM62P 
 **  Modified : May 16 2024
 **  Author: Pushkar Kulkarni
 **  
 **  \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef SRC_DIO_HW_FUNCS_H_
#define SRC_DIO_HW_FUNCS_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "CDio_RM.h"

#define DIO_REG_SIZE    sizeof(uint32_t)
#define DIO_REG_COUNT   (size_t)2U

/**********************************************************************************************************************
 *  STRUCTURE
 *********************************************************************************************************************/

/*!
 * \struct       ts_dio_bank_config_data_t
 * \brief        To config gpio bank.
 *  
 *  \var         ts_dio_bank_config_data_t::direction
 *  \brief       Setting and getting direction
 *  
 *  \var         ts_dio_bank_config_data_t::value
 *  \brief       To set and read , write the value
 */
typedef struct
{
    uint32_t direction;
    uint32_t out_value;
    uint32_t in_value;
} ts_dio_bank_config_data_t;

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/
//Setting and getting direction

/*!****************************************************************************
    * \fn        int32_t dio_get_dir ( const ts_dio_pin_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p );
    * \brief     Function that is called to get the direction of a pin
    * \param     const ts_dio_dev_t *diogetDirDev_p, const ts_dio_addr_t *diogetDirAddr_p,
    * \return    int32_t Return 1 on success or -1 on failure
    * \details   requirement ID 543270
 *****************************************************************************/

extern int32_t dio_get_dir ( const ts_dio_pin_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p );

/*!****************************************************************************
    * \fn        int32_t dio_set_dir ( const ts_dio_pin_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p );
    * \brief     Function that is called to set the direction of a pin
    * \param     const ts_dio_dev_t *dioSetDirDev_p, const ts_dio_addr_t *dioSetDirAddr_p, uint32_t dir_UINT32
    * \return    int32_t Return 1 on success or -1 on failure
    * \details   requirement ID 543270
 *****************************************************************************/
extern int32_t dio_set_dir ( const ts_dio_pin_t *dioSetDirDev_p, const ts_dio_addr_t *dioSetDirAddr_p, uint32_t dir_UINT32 );

/* *****************************
 Reading Channel & Write Channel
 */

/*!****************************************************************************
    * \fn        int32_t dio_read_channel ( const ts_dio_pin_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p )
    * \brief     Function that is called to read the data on a pin
    * \param     const ts_dio_dev_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p
    * \return    int32_t Return 1 on success or 0 on failure
    * \details   requirement DI 543466
 *****************************************************************************/

extern int32_t dio_read_channel ( const ts_dio_pin_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p );

/*!****************************************************************************
    * \fn        int32_t dio_write_channel ( const ts_dio_pin_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32 )
    * \brief     Function that is called to write the data on a pin
    * \param     const ts_dio_dev_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32
    * \return    int32_t Return 1 on success or -1 on failure
    * \details   requirement ID 543466
 *****************************************************************************/
extern int32_t dio_write_channel ( const ts_dio_pin_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32 );


extern bool dio_hw_init ( ts_dio_pindata_t *dioHWInitpindata_p );
extern bool dio_hw_fini ( const ts_dio_pindata_t *dioHWFinipindata_p );

/*!****************************************************************************
    * \fn        int dio_periodic_task ( ts_dio_pindata_t *dioTimerTaskPinData_p )
    * \brief     Function that is called for every 4 sec to check the data on the registers 
                 is as expected or corrupted periodically
    * \param     const ts_dio_addr_t *dioTimerTaskAddr_p
    * \return    int Return Error code to indicate success or failure
    * \details requirement DI 543466
 *****************************************************************************/
extern int dio_periodic_task ( ts_dio_pindata_t *dioTimerTaskPinData_p );

/*!****************************************************************************
    * \fn        void dio_set_default_data( const ts_dio_pindata_t *dioWriteDevdefault_p );
    * \brief     Function that is called set the dafault data to dio pin
    * \param     const ts_dio_pindata_t *dioWriteDevdefault_p
    * \return    int Return Error code to indicate success or failure
    * \details   requirement DI 543466
 *****************************************************************************/
extern void dio_set_default_data( const ts_dio_pindata_t *dioWriteDevdefault_p );

#endif /* SRC_DIO_HW_FUNCS_H_ */
