

/*============================================================================
 **
 **  \file CDio_Types.h
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
 **  Updated the Max Bank Per DIO macro as per AM62P, which is taken as 5 banks, as per convenience. 
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

#ifndef CDIO_TYPES_H_

#define CDIO_TYPES_H_

#include <stdint.h>

/**
 * DIO supported Hardware Banks
 */
#define TI_MAX_BANK_PER_DIO   (uint32_t)5U


#endif /* CDIO_TYPES_H_ */
