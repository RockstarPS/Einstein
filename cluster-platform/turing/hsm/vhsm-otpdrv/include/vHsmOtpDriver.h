/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
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
 * \file vHsmOtpDriver.h
 *
 * \brief
 * Visteon HSM OTP DRIVER implementation header
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

#include "Std_Types.h"
#include "string.h"


Std_ReturnType vHsmOtp_MMRWrite(uint32 mmrIdx, uint32 mmrVal);
Std_ReturnType vHsmOtp_WriteRow(uint8 rowIdx, uint32 rowVal, uint32 rowMask, uint32 *rowValRdBk);
Std_ReturnType vHsmOtp_ReadMMR(uint8 mmrIdx, uint32* mmrVal);
Std_ReturnType vHsmOtp_GetOtplockStatus(uint8 otp_row);

/*EOF*/
