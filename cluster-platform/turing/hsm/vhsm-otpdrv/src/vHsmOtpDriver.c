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
 * \file vHsmOtpDriver.c
 *
 * \brief
 * Visteon HSM OTP DRIVER implementation file
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/
#include "vHsmOtpDriver.h"
#include "Std_Types.h"
#include "tisci_protocol.h"
#include "hosts.h"
#include "sec_proxy_minimal.h"
#include "trace.h"
#include "osal_hwi.h"
#include "interrupt.h"
#include "dmsc_irq_map.h"
#include <soc_hsm_data.h>
#include <tisci_ext_otp.h>


#define NUM_BITS_PER_OTP_ROW 	        (25U)
#define OTP_COL_OFFSET       	        (2U)
#define OTP_ROW_FULL_MASK	            (0x01FFFFFFU)
#define MMR_SIZE_BITS			        (32U)
#define EXT_OTP_MAX_MMRS		        (32U)
#define TISCI_MSG_READ_OTP_MMR          (0x9022)
#define TISCI_MSG_WRITE_OTP_ROW         (0x9023)
#define TISCI_MSG_LOCK_OTP_ROW          (0x9024)
#define SPROXY_OTPRECEIVE_TIMEOUT          (0x100)
#define TISCI_MSG_SOFT_LOCK_OTP_WRITE_GLOBAL (0x9025)
#define TISCI_MSG_GET_OTP_ROW_LOCK_STATUS    (0x9026)
#define IPC_INTERRUPT_IRQ               (NVIC_IRQ(HSM_SEC_PROXY_RX_IRQ))

#define LOCAL static

typedef struct 
{
    struct tisci_header	hdr;
    uint8  row_idx;
    uint32 row_val;
    uint32 row_mask;
}vHsmOtpDriver_req_st;

typedef struct 
{
    struct tisci_header	hdr;
    uint8  mmr_idx;
}vHsmOtpDriverRead_req_st;

typedef struct
{
    struct tisci_header hdr;
    uint8 global_soft_lock;
    uint8 hw_write_lock;
    uint8 hw_read_lock;
    uint8 row_soft_lock;
}vHsmOtpDriverLock_res_st;


typedef struct 
{
    struct tisci_header	hdr;
    uint32 row_val;
}vHsmOtpDriver_res_ST;


LOCAL FUNC(uint32,OTP_CODE) vHsmOtp_GetMaskU32(uint32 p_mask);

LOCAL FUNC(uint32,OTP_CODE) vHsmOtp_GetMaskU32(uint32 p_mask)
{
	/* Count number of ones */
	uint32 count = 32U;
	uint32 maskSize = 0;

	while(count--)
	{
		maskSize += (p_mask & 1U);
		p_mask >>= 1;
	}

	return maskSize;
}

FUNC(Std_ReturnType,OTP_CODE) vHsmOtp_WriteRow(uint8 rowIdx, uint32 rowVal, uint32 rowMask, uint32 *rowValRdBk)
{
    Std_ReturnType fl_RetVal_E = E_NOT_OK;
    uint32 l_RetVal_E = 0;
    struct tisci_msg_write_otp_row_req l_vHsmOtp_req_ts;
    struct tisci_msg_write_otp_row_resp l_vHsmOtp_res_ts;
    uint16 l_vhsmOtp_Timeout_U16 = SPROXY_OTPRECEIVE_TIMEOUT;
    if((rowIdx <= 41) && (rowValRdBk != NULL))
    {
        TRACE_info("\r\n OTP check 1");
        (void)memset(&l_vHsmOtp_req_ts,0x00,sizeof(l_vHsmOtp_req_ts));
        (void)memset(&l_vHsmOtp_res_ts,0x00,sizeof(l_vHsmOtp_res_ts));
        l_vHsmOtp_req_ts.hdr.type = TISCI_MSG_WRITE_OTP_ROW;
        l_vHsmOtp_req_ts.hdr.seq = 0u;
        l_vHsmOtp_req_ts.hdr.flags = TISCI_MSG_FLAG_AOP;
        l_vHsmOtp_req_ts.row_idx = rowIdx;
        l_vHsmOtp_req_ts.row_mask = rowMask;
        l_vHsmOtp_req_ts.row_val = rowVal;
        l_RetVal_E = osal_hwip_disable_interrupt(IPC_INTERRUPT_IRQ);
        {
            TRACE_info("\r\n OTP check 2");
            l_RetVal_E = sproxy_send_msg(&l_vHsmOtp_req_ts, sizeof(l_vHsmOtp_req_ts), 1U);
            if(l_RetVal_E == 0)
            {
                TRACE_info("\r\n OTP check 3");
                l_RetVal_E = 0x1;
                while(l_RetVal_E)
                {
                    l_RetVal_E = sproxy_receive_msg(&l_vHsmOtp_res_ts, sizeof(l_vHsmOtp_res_ts));
                    if(l_vhsmOtp_Timeout_U16 < 1){
                        TRACE_info("\r\n OTP check 4");
                        break;
                    }
                    l_vhsmOtp_Timeout_U16-=1;
                } 
            }
            (void)osal_hwip_enable_interrupt(IPC_INTERRUPT_IRQ);
            if((E_OK == l_RetVal_E) && (TISCI_MSG_FLAG_AOP == l_vHsmOtp_res_ts.hdr.flags))
            {
                fl_RetVal_E = E_OK;
                TRACE_info("\r\n OTP write successful");
                TRACE_info_arg_hsm("\r\n OTP ReadBakc ",l_vHsmOtp_res_ts.row_val);
            }
        }        
    }
	return fl_RetVal_E;
}

FUNC(Std_ReturnType,OTP_CODE) vHsmOtp_ReadMMR(uint8 mmrIdx, uint32* mmrVal)
{
    Std_ReturnType fl_RetVal_E = E_NOT_OK;
    vHsmOtpDriverRead_req_st l_vHsmOtpRead_req_ts;
    vHsmOtpDriver_res_ST l_vHsmOtpRead_res_ts;
    uint16 l_vhsmOtp_Timeout_U16 = SPROXY_OTPRECEIVE_TIMEOUT;
    if((mmrIdx <= 0x1f) && (mmrVal != NULL))
    {
        l_vHsmOtpRead_req_ts.hdr.type = (uint16) TISCI_MSG_READ_OTP_MMR;
        l_vHsmOtpRead_req_ts.hdr.flags = (uint32) TISCI_MSG_FLAG_AOP;
        l_vHsmOtpRead_req_ts.hdr.seq = 0u;
        l_vHsmOtpRead_req_ts.hdr.host = HOST_ID_HSM;
        l_vHsmOtpRead_req_ts.mmr_idx = mmrIdx;
        fl_RetVal_E = osal_hwip_disable_interrupt(IPC_INTERRUPT_IRQ);
        if(E_OK == fl_RetVal_E)
        {
            fl_RetVal_E = (uint8)sproxy_send_msg(&l_vHsmOtpRead_req_ts, sizeof(l_vHsmOtpRead_req_ts), 1U);
            TRACE_info_arg_hsm("\r\n sproxy send",fl_RetVal_E);
            if(fl_RetVal_E == E_OK)
            {
                fl_RetVal_E = E_NOT_OK;
                while(fl_RetVal_E)
                {
                    fl_RetVal_E = (uint8)sproxy_receive_msg(&l_vHsmOtpRead_res_ts, sizeof(l_vHsmOtpRead_res_ts));
                    //TRACE_info_arg_hsm("\r\n sproxy Recive",fl_RetVal_E);
                    l_vhsmOtp_Timeout_U16--;
                    if(l_vhsmOtp_Timeout_U16<1)
                    {
                        break;
                    }
                }
                if(E_OK == fl_RetVal_E)
                {
                    TRACE_info_arg_hsm("\r\n OTP type ",l_vHsmOtpRead_res_ts.hdr.type);
                    TRACE_info_arg_hsm("\r\n OTP Flag ",l_vHsmOtpRead_res_ts.hdr.flags);
                    TRACE_info_arg_hsm("\r\n OTP Seq ",l_vHsmOtpRead_res_ts.hdr.seq);
                    TRACE_info_arg_hsm("\r\n OTP Host ",l_vHsmOtpRead_res_ts.hdr.host);
                    TRACE_info_arg_hsm("\r\n OTP data ",l_vHsmOtpRead_res_ts.row_val);
                }
            }
            (void)osal_hwip_enable_interrupt(IPC_INTERRUPT_IRQ);
        } 
    }
	return fl_RetVal_E;
}

FUNC(Std_ReturnType,OTP_CODE) vHsmOtp_MMRWrite(uint32 p_mmrIdx, uint32 p_mmrVal)
{
	Std_ReturnType fl_Retval_E = E_OK;
	uint32 rowStart, rowColStart;
	uint32 rowEnd, rowColEnd, rowCount;
	uint32 maskRow1, maskRow2, maskRow3;
	uint32 valRow1, valRow2, valRow3;
	uint32 rowValRdBk;

	/* Bit position in this start row  */
	rowColStart = ((p_mmrIdx * MMR_SIZE_BITS) % NUM_BITS_PER_OTP_ROW) + OTP_COL_OFFSET;
    if (rowColStart >= NUM_BITS_PER_OTP_ROW)
    {
        rowColStart %= NUM_BITS_PER_OTP_ROW;
        /* EFUSE row start for this MMR */
	    rowStart = ((p_mmrIdx * MMR_SIZE_BITS) / NUM_BITS_PER_OTP_ROW) + 1U;
    }
    else
    {
        /* EFUSE row start for this MMR */
	    rowStart = (p_mmrIdx * MMR_SIZE_BITS) / NUM_BITS_PER_OTP_ROW;
    }
	rowCount = (rowColStart + MMR_SIZE_BITS) / NUM_BITS_PER_OTP_ROW;
	if ( ((rowColStart + MMR_SIZE_BITS) % NUM_BITS_PER_OTP_ROW) != 0 )
	{
		/* Third row needed */
		rowCount += 1;
	}
	/* Total rowCount number of rows needed */
	rowEnd = rowStart + rowCount - 1;
	rowColEnd = ((rowColStart + MMR_SIZE_BITS) % NUM_BITS_PER_OTP_ROW) - 1;

	if (rowCount == 2)
	{
		maskRow1 = (~((1 << rowColStart) - 1)) & OTP_ROW_FULL_MASK; /* for rowStart */
		maskRow2 = ((1 << (rowColEnd + 1)) - 1) & OTP_ROW_FULL_MASK; /* for rowEnd */

		valRow1 = ( (1 << vHsmOtp_GetMaskU32(maskRow1)) - 1 ) & p_mmrVal;
		p_mmrVal >>= vHsmOtp_GetMaskU32(maskRow1);

		valRow2 = ( (1 << vHsmOtp_GetMaskU32(maskRow2)) - 1 ) & p_mmrVal;
		p_mmrVal >>= vHsmOtp_GetMaskU32(maskRow2);

		fl_Retval_E =  vHsmOtp_WriteRow(rowStart, (valRow1 << rowColStart), maskRow1, &rowValRdBk);

		if (fl_Retval_E == E_OK)
		{
			fl_Retval_E =  vHsmOtp_WriteRow(rowEnd, (valRow2 << 0), maskRow2, &rowValRdBk);
		}
	}
	else if (rowCount == 3)
	{
		maskRow1 = (~((1 << rowColStart) - 1)) & OTP_ROW_FULL_MASK;
		maskRow2 = OTP_ROW_FULL_MASK;
		maskRow3 = ((1 << (rowColEnd + 1)) - 1) & OTP_ROW_FULL_MASK;


		valRow1 = ( (1 << vHsmOtp_GetMaskU32(maskRow1)) - 1 ) & p_mmrVal;
		p_mmrVal >>= vHsmOtp_GetMaskU32(maskRow1);

		valRow2 = ( (1 << vHsmOtp_GetMaskU32(maskRow2)) - 1 ) & p_mmrVal;
		p_mmrVal >>= vHsmOtp_GetMaskU32(maskRow2);

		valRow3 = ( (1 << vHsmOtp_GetMaskU32(maskRow3)) - 1 ) & p_mmrVal;
		p_mmrVal >>= vHsmOtp_GetMaskU32(maskRow3);

		fl_Retval_E =  vHsmOtp_WriteRow(rowStart, (valRow1 << rowColStart), maskRow1, &rowValRdBk );
		if (fl_Retval_E == E_OK)
		{
			fl_Retval_E =  vHsmOtp_WriteRow(rowStart + 1, (valRow2 << 0), maskRow2, &rowValRdBk );
		}
		if (fl_Retval_E == E_OK)
		{
			fl_Retval_E =  vHsmOtp_WriteRow(rowEnd, (valRow3 << 0), maskRow3, &rowValRdBk );
		}
	}
	return fl_Retval_E;
}

FUNC(Std_ReturnType,OTP_CODE) vHsmOtp_GetOtplockStatus(uint8 otp_row)
{
    Std_ReturnType fl_RetVal_E = E_NOT_OK;
    vHsmOtpDriverRead_req_st l_vHsmOtplockRead_req_ts;
    vHsmOtpDriverLock_res_st l_vHsmOtplockRead_res_ts;
    uint16 l_vhsmOtp_Timeout_U16 = SPROXY_OTPRECEIVE_TIMEOUT;
    l_vHsmOtplockRead_req_ts.hdr.flags = (uint32) TISCI_MSG_FLAG_AOP;
    l_vHsmOtplockRead_req_ts.hdr.host = HOST_ID_HSM;
    l_vHsmOtplockRead_req_ts.hdr.seq = 0;
    l_vHsmOtplockRead_req_ts.hdr.type = TISCI_MSG_GET_OTP_ROW_LOCK_STATUS;
    l_vHsmOtplockRead_req_ts.mmr_idx = otp_row;
    fl_RetVal_E = osal_hwip_disable_interrupt(IPC_INTERRUPT_IRQ);
    if(E_OK == fl_RetVal_E)
    {
        fl_RetVal_E = (uint8)sproxy_send_msg(&l_vHsmOtplockRead_req_ts, sizeof(l_vHsmOtplockRead_req_ts), 1U);
        if(fl_RetVal_E == E_OK)
        {
            fl_RetVal_E = E_NOT_OK;
            while(fl_RetVal_E)
            {
                fl_RetVal_E = (uint8)sproxy_receive_msg(&l_vHsmOtplockRead_res_ts, sizeof(l_vHsmOtplockRead_res_ts));
                //TRACE_info_arg_hsm("\r\n sproxy Recive",fl_RetVal_E);
                l_vhsmOtp_Timeout_U16--;
                if(l_vhsmOtp_Timeout_U16<1)
                {
                    break;
                }
            }
            (void)osal_hwip_enable_interrupt(IPC_INTERRUPT_IRQ);
            if(E_OK == fl_RetVal_E)
            {
                TRACE_info_arg_hsm("\r\n OTP type ",l_vHsmOtplockRead_res_ts.hdr.type);
                TRACE_info_arg_hsm("\r\n OTP Flag ",l_vHsmOtplockRead_res_ts.hdr.flags);
                TRACE_info_arg_hsm("\r\n OTP Seq ",l_vHsmOtplockRead_res_ts.hdr.seq);
                TRACE_info_arg_hsm("\r\n OTP Host ",l_vHsmOtplockRead_res_ts.hdr.host);
                TRACE_info_arg_hsm("\r\n OTP Global ",l_vHsmOtplockRead_res_ts.global_soft_lock);
                TRACE_info_arg_hsm("\r\n OTP HE read ",l_vHsmOtplockRead_res_ts.hw_read_lock);
                TRACE_info_arg_hsm("\r\n OTP HW write ",l_vHsmOtplockRead_res_ts.hw_write_lock);
                TRACE_info_arg_hsm("\r\n OTP row ",l_vHsmOtplockRead_res_ts.row_soft_lock);
            }

        }
    }
    return fl_RetVal_E;
}





/*EOF*/
