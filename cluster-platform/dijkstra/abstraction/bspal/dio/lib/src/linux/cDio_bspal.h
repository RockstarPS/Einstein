/*============================================================================
 **
 **  \file CDio_Devctl.h
 **
 **  \brief Interface to interact with the DIO of rcar3
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
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

#ifndef CDIO_DEVCTL
#define CDIO_DEVCTL

#define EINSTEIN_TI_DIO

#ifdef EINSTEIN_TI_DIO

#define DIO_MAX_ID (unsigned int)144U

#else

#define DIO_MAX_ID (unsigned int)256U
#define DIO_PIN_PER_BANK (unsigned int)32U
#define RCAR3_MAX_BANK_PER_DIO (unsigned int)7

typedef struct {
  unsigned int bank_mask_addr;
  unsigned int set_bits_count_sa;
} ts_dio_addr_t;

typedef struct {
  unsigned int bank_num_U32;
  unsigned int chnl_num_U32;
  bool is_valid_BOOL;
} ts_dio_pin_t;

typedef struct {
  ts_dio_pin_t dio_pin_sa[DIO_MAX_ID];
  ts_dio_addr_t dio_addr_sa[RCAR3_MAX_BANK_PER_DIO];
} ts_dio_pindata_t;

void dio_count_mask_bits(ts_dio_addr_t dioCountAaddr_p[]);

#endif // EINSTEIN_TI_DIO

#endif // CDIO_DEVCTL