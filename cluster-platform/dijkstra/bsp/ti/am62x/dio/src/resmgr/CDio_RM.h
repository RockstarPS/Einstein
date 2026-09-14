

/*============================================================================
 **
 **  \file CDio_RM.h
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
 **  Author: Dinakar Babu
 **
 **  Revision History
 **  Modified : May 16 2024
 **  Author: Pushkar Kulkarni
 **  
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

#ifndef CDIO_RM_H_
#define CDIO_RM_H_


#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "CDio_Types.h"

#define DIO_MAX_ID         (uint32_t)144U
#define DIO_PIN_PER_BANK   (uint32_t)32U


typedef struct
{
    int32_t dir_pathID_S32;
    int32_t val_pathID_S32;
    uint32_t bank_num_U32;
    uint32_t chnl_num_U32;
    bool is_valid_BOOL;
} ts_dio_pin_t;


typedef struct
{
    struct sigevent event;
    struct _itimer   itime;
    timer_t        timer_id;
} ts_dio_dev_t;


typedef struct
{
    uint32_t physical_addr;
    uint32_t bank_mask_addr;
    uintptr_t virtual_addr_data_out;
    uintptr_t virtual_addr_data_in;
    uintptr_t virtual_addr_dir;
    uint32_t set_bits_count_sa;
} ts_dio_addr_t;

typedef struct
{
    ts_dio_pin_t  dio_pin_sa[DIO_MAX_ID];
    ts_dio_addr_t dio_addr_sa[TI_MAX_BANK_PER_DIO];
} ts_dio_pindata_t;


#endif /* CDIO_RM_H_ */
