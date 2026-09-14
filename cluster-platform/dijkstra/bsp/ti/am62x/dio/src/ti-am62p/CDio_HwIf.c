/*********************************************************************************
 **  \file CDio_HwIf.c
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Dec 2 2021
 **  \author: 
 **
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2020-08-02 |  RBABU9  | Create Initial Module.
 **  | 2023-08-25 | damudhar | Added Doxygen document
 **
 **  \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 ***/

#include <limits.h>
#include <stdbool.h>
#include <sys/siginfo.h>
#include <hw/inout.h>

#include "dk_logger.h"
#include "CDio_HwIf.h"

#define NEGATIVEBIT (-1)

LOG_IMPORT_CONTEXT ( gResMgrDioLogContext );

static ts_dio_bank_config_data_t g_dio_bank_config_data_as[TI_MAX_BANK_PER_DIO];

static uint32_t g_set_bit_hwif = 1U;
static uint32_t g_clear_bit_hwif = 0U;


/*!****************************************************************************
    * \fn        void dio_set_default_data( const ts_dio_pindata_t *dioWriteDevdefault_p );
    * \brief     Function that is called set the dafault data to dio pin
    * \param     const ts_dio_pindata_t *dioWriteDevdefault_p
    * \return    int Return Error code to indicate success or failure
    * \details   requirement DI 543466
 *****************************************************************************/
void dio_set_default_data( const ts_dio_pindata_t *dioWriteDevdefault_p )
{
    uint32_t l_write_data_U32;
    uint32_t l_bank_U32;
    ts_dio_addr_t l_dio_addr_ts;

    for ( l_bank_U32 = 0; l_bank_U32 < TI_MAX_BANK_PER_DIO; l_bank_U32++ )
    {
        l_dio_addr_ts = dioWriteDevdefault_p->dio_addr_sa[l_bank_U32];

        if( l_dio_addr_ts.virtual_addr_dir != 0UL )
        {
            l_write_data_U32 = in32 ( ( uintptr_t ) ( uintptr_t ) ( l_dio_addr_ts.virtual_addr_dir ) );
            g_dio_bank_config_data_as[l_bank_U32].direction = l_write_data_U32;

            l_write_data_U32 = in32 ( ( uintptr_t ) ( uintptr_t ) ( l_dio_addr_ts.virtual_addr_data_out ) );
            g_dio_bank_config_data_as[l_bank_U32].out_value = l_write_data_U32;

            l_write_data_U32 = in32 ( ( uintptr_t ) ( uintptr_t ) ( l_dio_addr_ts.virtual_addr_data_in ) );
            g_dio_bank_config_data_as[l_bank_U32].in_value = l_write_data_U32;
			
            LOGD(&gResMgrDioLogContext, " virt addr 0x%x direction is 0x%x OUT value is 0x%x and IN value is 0x%x ",(uint32_t)l_dio_addr_ts.virtual_addr_dir, (uint32_t)g_dio_bank_config_data_as[l_bank_U32].direction, (uint32_t)g_dio_bank_config_data_as[l_bank_U32].out_value, (uint32_t)g_dio_bank_config_data_as[l_bank_U32].in_value );
        }
        else { };
    }
}

/*!****************************************************************************
    * \fn        int32_t dio_set_dir ( const ts_dio_pin_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p );
    * \brief     Function that is called to set the direction of a pin
    * \param     const ts_dio_dev_t *dioSetDirDev_p, const ts_dio_addr_t *dioSetDirAddr_p, uint32_t dir_UINT32
    * \return    int32_t Return 1 on success or -1 on failure
    * \details   requirement ID 543270
 *****************************************************************************/

int32_t dio_set_dir ( const ts_dio_pin_t *dioSetDirDev_p, const ts_dio_addr_t *dioSetDirAddr_p, uint32_t dir_UINT32 )
{
    int32_t l_ret_S32 = 1;
    uint32_t l_value_U32 = 0 ;
    uint32_t l_mask_U32;
    uint32_t l_setbit_U32 = 1U;
    uint32_t l_write_dir_U32;

    uint32_t l_temp_dir = dir_UINT32;

    l_mask_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioSetDirAddr_p->virtual_addr_dir ) ) );

    if ( l_temp_dir == 0U )
    {
        l_mask_U32 |= ( l_setbit_U32 << dioSetDirDev_p->chnl_num_U32 );
    }
    else if ( l_temp_dir == 1U )
    {
        l_mask_U32 &= ~ ( l_setbit_U32 << dioSetDirDev_p->chnl_num_U32 );
    }
    else
    {
        l_ret_S32 = NEGATIVEBIT;
        LOGE(&gResMgrDioLogContext, "invalid data to write & Write failed %x , status is %d ", l_value_U32, l_ret_S32 );
    }
    if(l_ret_S32 != NEGATIVEBIT)
    {
        out32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioSetDirAddr_p->virtual_addr_dir ) ), l_mask_U32 );
        l_write_dir_U32 = in32 ( ( uintptr_t ) ( uintptr_t ) ( dioSetDirAddr_p->virtual_addr_dir ) );
        if( dioSetDirDev_p->bank_num_U32 < TI_MAX_BANK_PER_DIO)
        {
            g_dio_bank_config_data_as[dioSetDirDev_p->bank_num_U32].direction = l_write_dir_U32;
            LOGD(&gResMgrDioLogContext, "direction value is %x ", g_dio_bank_config_data_as[dioSetDirDev_p->bank_num_U32].direction );
        }
        else
        {
            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", dioSetDirDev_p->bank_num_U32 );
        }
    }

    return l_ret_S32;
}


/*!****************************************************************************
    * \fn        Function Name: dio_get_dir
    * \brief     Function that is called to get the direction of a pin
    * \param     const ts_dio_dev_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p_
    * \return    int32_t Return 1 on success or 0 on failure
    * \details   requirement ID 543270
 *****************************************************************************/

int32_t dio_get_dir ( const ts_dio_pin_t *dioGetDirDev_p, const ts_dio_addr_t *dioGetDirAddr_p )
{
    int32_t l_bitstatus_S32 = 0;
    uint32_t l_dir_U32;

    l_dir_U32 = in32 ( ( ( dioGetDirAddr_p->virtual_addr_dir ) ) );

        l_bitstatus_S32 = (( l_dir_U32 >> dioGetDirDev_p->chnl_num_U32 ) & g_set_bit_hwif);

    if ( l_bitstatus_S32 == (int32_t) g_clear_bit_hwif )
    {
            LOGD(&gResMgrDioLogContext, "bitstatus is %d ", l_bitstatus_S32 );
    }
    else if ( l_bitstatus_S32 == (int32_t) g_set_bit_hwif )
    {
            LOGD(&gResMgrDioLogContext, "bitstatus is %d ", l_bitstatus_S32 );
    }
    else
    {/*MISRA*/}

    return l_bitstatus_S32;
}

/*!****************************************************************************
    * \fn        int32_t dio_read_channel ( const ts_dio_pin_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p )
    * \brief     Function that is called to read the data on a pin
    * \param     const ts_dio_dev_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p
    * \return    int32_t Return 1 on success or 0 on failure
    * \details   requirement DI 543466
 *****************************************************************************/

int32_t dio_read_channel ( const ts_dio_pin_t *dioReadChnlDev_p, const ts_dio_addr_t *dioReadChnlAddr_p )
{
    int32_t l_bitstatus_S32 = 0 ;
	int32_t l_bitdirstatus_S32;
	uint32_t l_data_U32;
	l_bitdirstatus_S32 = dio_get_dir(dioReadChnlDev_p, dioReadChnlAddr_p);
	
	if(l_bitdirstatus_S32 == 0){
        LOGD(&gResMgrDioLogContext, "%d --> output pin_1", l_bitdirstatus_S32 );
		l_data_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioReadChnlAddr_p->virtual_addr_data_out ) ) );
	}
	else{
        LOGD(&gResMgrDioLogContext, "%d --> input pin_0", l_bitdirstatus_S32 );
		l_data_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioReadChnlAddr_p->virtual_addr_data_in) ) );
	}

    l_bitstatus_S32 = (( l_data_U32 >> dioReadChnlDev_p->chnl_num_U32 ) & g_set_bit_hwif);

    if ( l_bitstatus_S32 == (int32_t) g_clear_bit_hwif )
    {
        LOGD(&gResMgrDioLogContext, "bitstatus is %d ", l_bitstatus_S32 );
    }
    else if ( l_bitstatus_S32 == (int32_t) g_set_bit_hwif )
    {
        LOGD(&gResMgrDioLogContext, "bitstatus is %d ", l_bitstatus_S32 );
    }
    else
    {/*MISRA*/}

    return  l_bitstatus_S32;
}


/*!****************************************************************************
    * \fn        int32_t dio_write_channel ( const ts_dio_pin_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32 )
    * \brief     Function that is called to write the data on a pin
    * \param     const ts_dio_dev_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32
    * \return    int32_t Return 1 on success or -1 on failure
    * \details   requirement ID 543466
 *****************************************************************************/


int32_t dio_write_channel ( const ts_dio_pin_t *dioWriteChnlDev_p, const ts_dio_addr_t *dioWriteChnlAddr_p, uint32_t data_UINT32 )
{
    uint32_t l_mask_U32 = 0;
    uint32_t l_setbit_U32 = 1;
    int32_t l_ret_S32 = 1;
    uint32_t l_write_data_U32;

    uint32_t l_temp_data_INT32 = data_UINT32;

    l_mask_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioWriteChnlAddr_p->virtual_addr_data_out ) ) );

    if ( l_temp_data_INT32 == 1U )
    {
        l_mask_U32 |= ( l_setbit_U32 << dioWriteChnlDev_p->chnl_num_U32 );
    }
    else if( l_temp_data_INT32 == 0U )
    {
        l_mask_U32 &= ~ ( l_setbit_U32 << dioWriteChnlDev_p->chnl_num_U32 );
    }
    else
    {
        l_ret_S32 = ( int32_t ) NEGATIVEBIT;
        LOGE(&gResMgrDioLogContext, "Write Failed : %x, bytes written : %d ", l_mask_U32, l_ret_S32 );
    }

    if(l_ret_S32 != NEGATIVEBIT)
    {
        out32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioWriteChnlAddr_p->virtual_addr_data_out ) ), l_mask_U32 );
        l_write_data_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioWriteChnlAddr_p->virtual_addr_data_out ) ) );
        if( dioWriteChnlDev_p->bank_num_U32 < TI_MAX_BANK_PER_DIO )
        {
            g_dio_bank_config_data_as[dioWriteChnlDev_p->bank_num_U32].out_value = l_write_data_U32;
        }
        else
        {
            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", dioWriteChnlDev_p->bank_num_U32 );
        }

        out32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioWriteChnlAddr_p->virtual_addr_data_in ) ), l_mask_U32 );
        l_write_data_U32 = in32 ( ( uintptr_t ) ( ( uintptr_t ) ( dioWriteChnlAddr_p->virtual_addr_data_in ) ) );
        if( dioWriteChnlDev_p->bank_num_U32 < TI_MAX_BANK_PER_DIO )
        {
            g_dio_bank_config_data_as[dioWriteChnlDev_p->bank_num_U32].in_value = l_write_data_U32;
        }
        else
        {
            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", dioWriteChnlDev_p->bank_num_U32 );
        }
    }
    else {}

    return l_ret_S32;
}

/*!****************************************************************************
    * \fn        int dio_periodic_task ( ts_dio_pindata_t *dioTimerTaskPinData_p )
    * \brief     Function that is called for every 4 sec to check the data on the registers 
                 is as expected or corrupted periodically
    * \param     const ts_dio_addr_t *dioTimerTaskAddr_p
    * \return    int Return Error code to indicate success or failure
    * \details requirement DI 543466
 *****************************************************************************/

int dio_periodic_task ( ts_dio_pindata_t *dioTimerTaskPinData_p )
{
    uint32_t l_dir_val_U32 = 0;
    uint32_t l_data_val_U32 = 0;
    uint32_t l_pin_U32 = 0;
    int32_t l_status_S32 = 0;
    uint32_t l_setbit_U32 = 1;
    uint32_t l_dir_data_U32 = 0;
    uint32_t l_val_data_U32 = 0;
    uint32_t l_gpio_dir_val_U32 = 0;
    uint32_t l_gpio_data_val_U32 = 0;
    uint32_t l_channl_U32 = 0 ;
    uint32_t l_banknum_U32 = 0;

    for ( l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID; l_pin_U32++ )
    {
        l_banknum_U32 = dioTimerTaskPinData_p->dio_pin_sa[l_pin_U32].bank_num_U32;
        l_channl_U32 = dioTimerTaskPinData_p->dio_pin_sa[l_pin_U32].chnl_num_U32;

        if ( dioTimerTaskPinData_p->dio_pin_sa[l_pin_U32].is_valid_BOOL == true )
        {
            if( l_banknum_U32 < TI_MAX_BANK_PER_DIO)
            {
                l_dir_val_U32 = ((uint32_t)dio_get_dir ( &dioTimerTaskPinData_p->dio_pin_sa[l_pin_U32], &dioTimerTaskPinData_p->dio_addr_sa[l_banknum_U32]));
                l_dir_data_U32 = g_dio_bank_config_data_as[l_banknum_U32].direction;
            }
            else
            {
                LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32); 
            }
            l_gpio_dir_val_U32 = l_setbit_U32 & (l_dir_data_U32 >> l_channl_U32);

            if ( l_dir_val_U32 == l_gpio_dir_val_U32 )
            {
                LOGD(&gResMgrDioLogContext, "Dir Data periodic check pass .Data in register is %x, data expected is %x ", (uint32_t)l_dir_val_U32, (uint32_t)l_gpio_dir_val_U32);

                if( l_banknum_U32 < TI_MAX_BANK_PER_DIO)
                {
                    l_data_val_U32 = ((uint32_t)dio_read_channel (&dioTimerTaskPinData_p->dio_pin_sa[l_pin_U32], &dioTimerTaskPinData_p->dio_addr_sa[l_banknum_U32]));

                    if(l_dir_val_U32)
                    {
                        l_val_data_U32 = g_dio_bank_config_data_as[l_banknum_U32].in_value;
                    }
                    else
                    {
                        l_val_data_U32 = g_dio_bank_config_data_as[l_banknum_U32].out_value;             
                    }
                }
                else
                {
                    LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                }

                l_gpio_data_val_U32 = l_setbit_U32 & (l_val_data_U32 >> l_channl_U32);
                if ( l_data_val_U32 == l_gpio_data_val_U32)
                {
                    l_status_S32 = 0;
                    LOGD(&gResMgrDioLogContext, "gpio pin %d  bank no of gpio %d channel no of gpio %d: Value Data periodic check pass .Data in register is %x, data expected is %x ",l_pin_U32, l_banknum_U32, l_channl_U32, (uint32_t)l_data_val_U32, (uint32_t)l_gpio_data_val_U32 );
                }
                else
                {
                    LOGE(&gResMgrDioLogContext, "gpio pin %d  bank no of gpio %d channel no of gpio %d:  Value Data is corrupted. Data in register is %x, data expected is %x ",l_pin_U32, l_banknum_U32, l_channl_U32, (uint32_t)l_data_val_U32, (uint32_t)l_gpio_data_val_U32);
                }
            }
            else
            {
                LOGE(&gResMgrDioLogContext, "gpio pin %d  bank no of gpio %d channel no of gpio %d: Direction Data is corrupted. Data in register is %x, data expected is %x",l_pin_U32, l_banknum_U32,l_channl_U32, (uint32_t)l_dir_val_U32, (uint32_t)l_gpio_dir_val_U32);
            }
        }
        else
        {
            /* added for MISRA */
        }
    }

    return l_status_S32;
}


