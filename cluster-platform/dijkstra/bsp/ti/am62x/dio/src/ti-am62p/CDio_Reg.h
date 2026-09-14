/*============================================================================
 **
 **  \file CDio_Reg.h
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
 **  Updated different offsets for different banks accordingly, to be used for io mapping.
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

#ifndef CDIO_REG_H_

#define CDIO_REG_H_


/* DIO Bank offset Register address code */

#define DIO_GPIO_OUT_DR_01         (uint32_t)0x14       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_IN_DR_01           (uint32_t)0x20       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_DIR_01       (uint32_t)0x10       /* GPIO Direction Register using which driver can set the Pin Direction */       

#define DIO_GPIO_OUT_DR_23         (uint32_t)0x3C       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_IN_DR_23           (uint32_t)0x48       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_DIR_23       (uint32_t)0x38       /* GPIO Direction Register using which driver can set the Pin Direction */       

#define DIO_GPIO_OUT_DR_45         (uint32_t)0x64       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_IN_DR_45           (uint32_t)0x70       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_DIR_45       (uint32_t)0x60       /* GPIO Direction Register using which driver can set the Pin Direction */

#if 0
#define DIO_GPIO_OUT_DR_67         (uint32_t)0x8C       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_IN_DR_67           (uint32_t)0x98       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_DIR_67       (uint32_t)0x88       /* GPIO Direction Register using which driver can set the Pin Direction */

#define DIO_GPIO_OUT_DR_8         (uint32_t)0xB4       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_IN_DR_8           (uint32_t)0xC0       /* GPIO Data Register to which data can be written */
#define DIO_GPIO_DIR_8       (uint32_t)0xB0       /* GPIO Direction Register using which driver can set the Pin Direction */
#endif
#endif /* CDIO_REG_H_ */
