/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
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
 * \file vHsmMemMap.h
 *
 * \brief
 * HSM Memory Map file for TI AM62Px
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef VHSMMEMMAP_H
#define VHSMMEMMAP_H


#define MPU_CODE __attribute__((section(".text_mpu")))

#define IPC_CODE __attribute__((section(".text_ipc")))

#define CRYPT_CODE __attribute__((section(".text_crypt")))

#define DMN_CODE __attribute__((section(".text_dmn")))

#define OTP_CODE __attribute__((section(".text_otp")))

#define TIMER_CODE __attribute__((section(".text_timer")))

#define WDG_CODE __attribute__((section(".text_wdg")))

#define CRY_CODE __attribute__((section(".text_cryptman")))

#define KEYMAN_CODE __attribute__((section(".text_key")))

#define REFLASH_CODE __attribute__((section(".text_reflash")))

#define FW_CODE __attribute__((section(".text_fw")))


#define DLT_CODE __attribute__((section("text_dlt")))
#endif /*VHSMMEMMAP_H*/
