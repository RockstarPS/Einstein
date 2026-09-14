/****************************************************************************
 **
 **  \file CDio_HwInit.c
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
 **  \Author: Dinakar Babu
 **
 **  Revision History
 **  Modified : May 16 2024
 **  In AM62P, we have common base address defined as instances and the offsets are varying based on banks.
 **  Hence, updated the logic as per the requirement so that io mapping is carried out as expected for the banks. 
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
 ***/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <sys/mman.h>

#include "dk_logger.h"
#include "CDio_Reg.h"
#include "CDio_HwIf.h"
#include "CDio_RM.h"

LOG_IMPORT_CONTEXT ( gResMgrDioLogContext );

/*!****************************************************************************
	* \fn 		 bool dio_hw_init ( ts_dio_pindata_t *dioHWInitpindata_p )
 	* \brief     Function that is called to do IO Mapping with the banks having bits set more than 0
 	* \param     dioHWInitAddr_p Array of structure in which physical addr of gpio bank and bank's mask address is stored.
 	* \return    bool Return value to indicate true or false for the operation done
	* \details   requirement id 543466
 *****************************************************************************/

bool dio_hw_init ( ts_dio_pindata_t *dioHWInitpindata_p )
{

    bool l_ret_BOOL = true;
    uint32_t l_bank_U32;
    ts_dio_addr_t l_dio_addr_ts;

    if ( ThreadCtl ( _NTO_TCTL_IO, NULL ) == -1 )
    {
        LOGE(&gResMgrDioLogContext, "ThreadCtl Function Failed " );
        l_ret_BOOL = false;
    }
    else
    {
        for ( l_bank_U32 = 0; l_bank_U32 < TI_MAX_BANK_PER_DIO; l_bank_U32++ )
        {
            if ( (0 == l_bank_U32) || (3 == l_bank_U32) )
            {

                l_dio_addr_ts = dioHWInitpindata_p->dio_addr_sa[l_bank_U32];
                if ( 0 == l_dio_addr_ts.set_bits_count_sa )
                {
                    LOGD(&gResMgrDioLogContext, "Mapping not needed as number of bits in the mask address are %d", l_dio_addr_ts.set_bits_count_sa );
                }
                else
                {
                    //dioHWInitAddr_p[i].virtual_addr = ( uint32_t ) mmap_device_io ( ( (DIO_REG_SIZE) * (DIO_REG_COUNT) ), dioHWInitAddr_p[i].physical_addr );
                    l_dio_addr_ts.virtual_addr_dir = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_dir),  l_dio_addr_ts.physical_addr + DIO_GPIO_DIR_01);
                    
                    if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) ) )
                    {
                        LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                        l_ret_BOOL  = false;
                        
                    }
                    else
                    {
                        LOGI(&gResMgrDioLogContext, "Mapped address of banks for DIR %d is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_dir );
                        l_dio_addr_ts.virtual_addr_data_out = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_out),  l_dio_addr_ts.physical_addr + DIO_GPIO_OUT_DR_01);
                        l_dio_addr_ts.virtual_addr_data_in = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_in),  l_dio_addr_ts.physical_addr + DIO_GPIO_IN_DR_01);
                        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) )
                        {
                            LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                            l_ret_BOOL  = false;
                        }
                        else
                        {
                            dioHWInitpindata_p->dio_addr_sa[l_bank_U32] = l_dio_addr_ts;
                            LOGI(&gResMgrDioLogContext, "Mapped address of banks for DATA %d for OUT is %x and for IN is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_data_out,(uint32_t) l_dio_addr_ts.virtual_addr_data_in );
                        }
                    }
                }
            }
            else if( (1 == l_bank_U32) || (4 == l_bank_U32) )
            {

                l_dio_addr_ts = dioHWInitpindata_p->dio_addr_sa[l_bank_U32];
                if ( 0 == l_dio_addr_ts.set_bits_count_sa )
                {
                    LOGD(&gResMgrDioLogContext, "Mapping not needed as number of bits in the mask address are %d", l_dio_addr_ts.set_bits_count_sa );
                }
                else
                {
                    //dioHWInitAddr_p[i].virtual_addr = ( uint32_t ) mmap_device_io ( ( (DIO_REG_SIZE) * (DIO_REG_COUNT) ), dioHWInitAddr_p[i].physical_addr );
                    l_dio_addr_ts.virtual_addr_dir = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_dir),  l_dio_addr_ts.physical_addr + DIO_GPIO_DIR_23);
                    
                    if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) ) )
                    {
                        LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                        l_ret_BOOL  = false;
                        
                    }
                    else
                    {
                        LOGI(&gResMgrDioLogContext, "Mapped address of banks for DIR %d is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_dir );
                        l_dio_addr_ts.virtual_addr_data_out = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_out),  l_dio_addr_ts.physical_addr + DIO_GPIO_OUT_DR_23);
                        l_dio_addr_ts.virtual_addr_data_in = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_in),  l_dio_addr_ts.physical_addr + DIO_GPIO_IN_DR_23);
                        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) )
                        {
                            LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                            l_ret_BOOL  = false;
                        }
                        else
                        {
                            dioHWInitpindata_p->dio_addr_sa[l_bank_U32] = l_dio_addr_ts;
                            LOGI(&gResMgrDioLogContext, "Mapped address of banks for DATA %d for OUT is %x and for IN is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_data_out,(uint32_t) l_dio_addr_ts.virtual_addr_data_in );
                        }
                    }
                }
            }
            else
            {

                l_dio_addr_ts = dioHWInitpindata_p->dio_addr_sa[l_bank_U32];
                if ( 0 == l_dio_addr_ts.set_bits_count_sa )
                {
                    LOGD(&gResMgrDioLogContext, "Mapping not needed as number of bits in the mask address are %d", l_dio_addr_ts.set_bits_count_sa );
                }
                else
                {
                    //dioHWInitAddr_p[i].virtual_addr = ( uint32_t ) mmap_device_io ( ( (DIO_REG_SIZE) * (DIO_REG_COUNT) ), dioHWInitAddr_p[i].physical_addr );
                    l_dio_addr_ts.virtual_addr_dir = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_dir),  l_dio_addr_ts.physical_addr + DIO_GPIO_DIR_45);
                    
                    if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) ) )
                    {
                        LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                        l_ret_BOOL  = false;
                        
                    }
                    else
                    {
                        LOGI(&gResMgrDioLogContext, "Mapped address of banks for DIR %d is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_dir );
                        l_dio_addr_ts.virtual_addr_data_out = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_out),  l_dio_addr_ts.physical_addr + DIO_GPIO_OUT_DR_45);
                        l_dio_addr_ts.virtual_addr_data_in = mmap_device_io ( sizeof(l_dio_addr_ts.virtual_addr_data_in),  l_dio_addr_ts.physical_addr + DIO_GPIO_IN_DR_45);
                        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) )
                        {
                            LOGE(&gResMgrDioLogContext, "MAP_DEVICE_FAILED : mmap_device_io failed" );
                            l_ret_BOOL  = false;
                        }
                        else
                        {
                            dioHWInitpindata_p->dio_addr_sa[l_bank_U32] = l_dio_addr_ts;
                            LOGI(&gResMgrDioLogContext, "Mapped address of banks for DATA %d for OUT is %x and for IN is %x ", l_bank_U32, (uint32_t) l_dio_addr_ts.virtual_addr_data_out,(uint32_t) l_dio_addr_ts.virtual_addr_data_in );
                        }
                    }
                }
            }    
        }
    }
    return l_ret_BOOL;
}


/*!****************************************************************************
	* \fn 		 bool dio_hw_fini ( const ts_dio_pindata_t *dioHWFinipindata_p )
 	* \brief     Function that is called to do IO UnMapping with the banks having bits set more than 0
 	* \param     dioHWFiniAddr Array of structure in which physical addr of gpio bank and bank's mask address is stored.
 	* \return    bool Return value to indicate true or false for the operation done
	* \details   requirement id 543466
 *****************************************************************************/

bool dio_hw_fini ( const ts_dio_pindata_t *dioHWFinipindata_p )
{
    uint32_t l_bank_U32;
    bool l_ret = true;
    ts_dio_addr_t l_dio_addr_ts;

    for ( l_bank_U32 = 0; l_bank_U32 < TI_MAX_BANK_PER_DIO; l_bank_U32++ )
    {
        l_dio_addr_ts = dioHWFinipindata_p->dio_addr_sa[l_bank_U32];
        if ( 0 == l_dio_addr_ts.set_bits_count_sa )
        {
            LOGD(&gResMgrDioLogContext, "UnMapping not needed as number of bits in the mask address are %d", l_dio_addr_ts.set_bits_count_sa );
        }
        else
        {
            if ( ( munmap_device_io ( l_dio_addr_ts.virtual_addr_dir, sizeof ( l_dio_addr_ts.virtual_addr_dir ) ) ) == -1 )
            {
                LOGE(&gResMgrDioLogContext, "mummap_device_io for direction failed" );
                l_ret = false;
            }
            else
            {
                if ( ( munmap_device_io ( l_dio_addr_ts.virtual_addr_data_out, sizeof ( l_dio_addr_ts.virtual_addr_data_out ) ) ) == -1 )
                {
                    LOGE(&gResMgrDioLogContext, "mummap_device_io for data failed" );
                    l_ret = false;
                }
                if ( ( munmap_device_io ( l_dio_addr_ts.virtual_addr_data_in, sizeof ( l_dio_addr_ts.virtual_addr_data_in ) ) ) == -1 )
                {
                    LOGE(&gResMgrDioLogContext, "mummap_device_io for data failed" );
                    l_ret = false;
                }
                else
                {
                    /* added for MISRA */
                }
            }
        }
    }
    return l_ret;
}


