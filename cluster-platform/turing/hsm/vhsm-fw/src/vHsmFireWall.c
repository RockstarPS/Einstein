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
 * \file vHsmFireWall.c
 *
 * \brief
 * HSM FireWall settings for AM62PX HSM M4F core source file
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
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "vHsmFireWall.h"
#include "vHsmMemMap.h"
#include "address_types.h"
#include "tisci_firewall.h"
#include "hwip.h"
#include "interrupt.h"
#include "trace.h"
#include "hosts.h"
#include "firewall.h"
#include "sec_proxy_minimal.h"

#ifdef VHSMFW_ENABLE

#define UNUSED_PARAM                   (void)

#define HSM_FW_SPROXY_TIMEOUT          (10u)
#define HSM_FW_EXEPTION_NUMBER         (176u)    /* Interrupt Nuber + NVIC offset*/
#define HSM_FW_DEFAULT_PRIORITY        (0xFFu)   /* set as maximum value*/
#define TISCI_MSG_CHANGE_FWL_OWNER     (0x9002u)
#define TISCI_MSG_GET_FWL_REGION       (0x9001u)

/*Local Variables*/
static uint8 l_vHsmFireWall_Init = 0u;

/*Configuration for Firewall*/
extern struct fwl_multi_region_data_item vHsmFireWall_Cfg_stA[vHSMFIREWALLNUMBER];

/*Function with External linkage*/
/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_Isr
 **
 ** \brief     ISR to service the FireWall Interrupt
 **
 ** \param[in] a,  not used
 **
 ** \return    none
 **
 ** \note DLT loggin is not enabled yet
 **
 *********************************************************************************************
 */
extern void vHsmFireWall_Isr(uint32 a);

/*Static Functions*/
static FUNC(void, FW_CODE)vHsmFireWall_InterruptEnable(void);
static FUNC(Std_ReturnType,FW_CODE) vHsmFireWall_SetRegion(uint16 fwl_id, uint16 region, uint32 n_permission_regs, uint32 control, \
		  soc_phys_addr_t start_address, soc_phys_addr_t end_address, \
		  uint32 permission_0, uint32 permission_1, uint32 permission_2);

/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_InterruptEnable
 **
 ** \brief     Enables the Interrupt for HSM FW violations
 **
 ** \param[in] none
 **
 ** \return    none
 **
 ** \note Strongly recommended to be Enabled after setting Firewall
 **
 *********************************************************************************************
 */
static FUNC(void, FW_CODE)vHsmFireWall_InterruptEnable(void)
{
    sint32 l_retVal = 0;
    struct hwip_params vHsmFwParam_st;
    vHsmFwParam_st.priority = HSM_FW_DEFAULT_PRIORITY; /*default Priority*/
    mask_interrupts();
    l_retVal = hwip_create(0u,HSM_FW_EXEPTION_NUMBER,vHsmFireWall_Isr,&vHsmFwParam_st);
    if(l_retVal != 0)
    {
       /* error case*/
    }
    l_retVal = hwip_clear_interrupt(HSM_FW_EXEPTION_NUMBER);
    if(l_retVal != 0)
    {
       /*error case*/
    }
    l_retVal = hwip_enable_interrupt(HSM_FW_EXEPTION_NUMBER,NULL);
    if(l_retVal != 0)
    {
       /*error Case*/
    }
    unmask_interrupts();
}


/**
 *********************************************************************************************
 ** \copydoc vHsmFireWall_isEnable
 *********************************************************************************************
 */
FUNC(uint8,FW_CODE) vHsmFireWall_isEnable(void)
{
    return (l_vHsmFireWall_Init);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmFireWall_init
 *********************************************************************************************
 */
FUNC(void,FW_CODE) vHsmFireWall_init(void)
{
    Std_ReturnType l_retVal_E = E_NOT_OK;
    uint8 i = 0u;
    if(l_vHsmFireWall_Init == 0u)
    {
        for(i=0;i<vHSMFIREWALLNUMBER;i++)
        {
            l_retVal_E = vHsmFireWall_SetRegion(vHsmFireWall_Cfg_stA[i].id, \
				vHsmFireWall_Cfg_stA[i].region_number,\
				vHsmFireWall_Cfg_stA[i].n_permission_regs,\
				vHsmFireWall_Cfg_stA[i].control,\
				vHsmFireWall_Cfg_stA[i].start_address,\
				vHsmFireWall_Cfg_stA[i].end_address,\
				vHsmFireWall_Cfg_stA[i].permission1,\
				vHsmFireWall_Cfg_stA[i].permission2,\
				vHsmFireWall_Cfg_stA[i].permission3);
            if(l_retVal_E != E_OK)
            {
                TRACE_info_arg_hsm("\r\n Firewall Failed :", i);
                break;
            }
        }
        if(E_OK == l_retVal_E)
        {
            vHsmFireWall_InterruptEnable();
            l_vHsmFireWall_Init = 1u;
            TRACE_info("\r\n Firewall Set");
        }
    }
    else
    {
        /*Misra Warning*/
    }
}

/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_SetRegion
 **
 ** \brief     Function to set each region in FW using TISCI message to TIFS
 **
 ** \param[in] fwl_id,  firewall ID in question. fwl_id is defined in the TRM.
 ** \param[in] region,  Region or channel number to set config info. This field is unused 
 **                     in case of a simple firewall and must be initialized to zero. 
 **                     In case of a region based firewall, this field indicates the region in question. 
 **                     (index starting from 0) In case of a channel based firewall, 
 **                     this field indicates the channel in question (index starting from 0)
 ** \param[in] n_permission_regs,  Number of permission registers to set
 ** \param[in] control,  Contents of the firewall CONTROL register to set
 ** \param[in] start_address,  Contents of the firewall START_ADDRESS register to set. 
 **                            The address is restricted to 44-bit; otherwise, it returns failure.
 ** \param[in] end_address,  Contents of the firewall END_ADDRESS register to set.
 **                          The address is restricted to 44-bit; otherwise, it returns failure
 ** \param[in] permission_0,  Contents of the firewall PERMISSION register to set
 ** \param[in] permission_1,  Contents of the firewall PERMISSION register to set
 ** \param[in] permission_2,  Contents of the firewall PERMISSION register to set
 **
 ** \return    none
 **
 ** \note This function is mandatory for FW settings
 **
 *********************************************************************************************
 */
static FUNC(Std_ReturnType,FW_CODE) vHsmFireWall_SetRegion(uint16 fwl_id, uint16 region, uint32 n_permission_regs, uint32 control, \
		  soc_phys_addr_t start_address, soc_phys_addr_t end_address, \
		  uint32 permission_0, uint32 permission_1, uint32 permission_2)
{
	Std_ReturnType l_RetVal_E = E_OK;
    sint32 fl_ret = 0;
	struct tisci_msg_fwl_set_firewall_region_req vHsmFW_regionInfo_st;
	struct tisci_msg_fwl_set_firewall_region_resp vHsmFW_FwResp_st;
	uint16 vHsmFW_Timeout_U16 = HSM_FW_SPROXY_TIMEOUT;
	vHsmFW_regionInfo_st.hdr.type = TISCI_MSG_SET_FWL_REGION;
	vHsmFW_regionInfo_st.hdr.host = HOST_ID_HSM;
	vHsmFW_regionInfo_st.hdr.flags = TISCI_MSG_FLAG_AOP;
	vHsmFW_regionInfo_st.fwl_id = fwl_id;
	vHsmFW_regionInfo_st.region = region;
	vHsmFW_regionInfo_st.n_permission_regs = n_permission_regs;
	vHsmFW_regionInfo_st.control = control;
	vHsmFW_regionInfo_st.start_address = start_address;
	vHsmFW_regionInfo_st.end_address = end_address;
	if (permission_0 != 0u) 
    {
		vHsmFW_regionInfo_st.permissions[0] = permission_0;
	}
	if (permission_1 != 0u) 
    {
		vHsmFW_regionInfo_st.permissions[1] = permission_1;
	}
	if (permission_2 != 0u) 
    {
		vHsmFW_regionInfo_st.permissions[2] = permission_2;
	}
	fl_ret = sproxy_send_msg(&vHsmFW_regionInfo_st, sizeof(vHsmFW_regionInfo_st), 1U);
    if(fl_ret == 0)
    {
		do{
			fl_ret = sproxy_receive_msg(&vHsmFW_FwResp_st, sizeof(vHsmFW_FwResp_st));
            vHsmFW_Timeout_U16--;
			if(vHsmFW_Timeout_U16 == 0u){
				break;
			}
		}
		while(fl_ret != 0);
    }
    if (fl_ret != 0)
	{
		l_RetVal_E = E_NOT_OK;
        TRACE_info_arg_hsm("\r\n Firewall Region set failed: ",fwl_id);
	}
    else
    {
        /*Do Nothing*/
    }
	return l_RetVal_E;
}

#ifdef FIREWALL_FETCHAPI
/**
 *********************************************************************************************
 ** \copydoc vHsmFireWall_ChangeOwner
 *********************************************************************************************
 */
FUNC(Std_ReturnType, FW_CODE) vHsmFireWall_ChangeOwner(uint16 fw_Id, uint16 region, uint8 owner_index)
{
    Std_ReturnType l_RetVal_E = E_OK;
    sint32 fl_ret = 0;
    struct tisci_msg_fwl_change_owner_info_req vHsmFW_OwnerReq_st;
    struct tisci_msg_fwl_change_owner_info_resp vHsmFW_OwnerResp_st;
    uint16 vHsmFW_Timeout_U16 = HSM_FW_SPROXY_TIMEOUT;
    vHsmFW_OwnerReq_st.hdr.type = TISCI_MSG_CHANGE_FWL_OWNER;
    vHsmFW_OwnerReq_st.hdr.host = HOST_ID_HSM;
    vHsmFW_OwnerReq_st.hdr.flags = TISCI_MSG_FLAG_AOP;
    vHsmFW_OwnerReq_st.fwl_id = fw_Id;
    vHsmFW_OwnerReq_st.region = region;
    vHsmFW_OwnerReq_st.owner_index = owner_index;
    fl_ret = sproxy_send_msg(&vHsmFW_OwnerReq_st, sizeof(vHsmFW_OwnerReq_st), 1U);
    if(fl_ret == 0)
    {
		do{
			fl_ret = sproxy_receive_msg(&vHsmFW_OwnerResp_st, sizeof(vHsmFW_OwnerResp_st));
			if(!vHsmFW_Timeout_U16--){
				break;
			}
		}
		while(fl_ret);
    }
    if (fl_ret != 0)
	{
		l_RetVal_E = E_NOT_OK;
        TRACE_info("\r\n Firewall Owner Change Failed");
	}
    else
    {
        TRACE_info_arg_hsm("\r\n FWL Id: ",vHsmFW_OwnerResp_st.fwl_id);
        TRACE_info_arg_hsm("\r\n Region: ",vHsmFW_OwnerResp_st.region);
        TRACE_info_arg_hsm("\r\n Owner Index: ",vHsmFW_OwnerResp_st.owner_index);
        TRACE_info_arg_hsm("\r\n Owner PrivId: ",vHsmFW_OwnerResp_st.owner_privid);
        TRACE_info_arg_hsm("\r\n Owner Permission: ",vHsmFW_OwnerResp_st.owner_permission_bits);
    }
	return l_RetVal_E;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmFireWall_GetFireWall
 *********************************************************************************************
 */
FUNC(Std_ReturnType, FW_CODE) vHsmFireWall_GetFireWall(uint16 fw_Id, uint16 region, uint32 n_permission_regs)
{
    Std_ReturnType l_RetVal_E = E_OK;
    sint32 fl_ret = 0;
    struct tisci_msg_fwl_get_firewall_region_req vHsmFW_GetFwReq_st;
    struct tisci_msg_fwl_get_firewall_region_resp vHsmFW_GetFwResp_st;
    uint16 vHsmFW_Timeout_U16 = HSM_FW_SPROXY_TIMEOUT;
    vHsmFW_GetFwReq_st.hdr.type = TISCI_MSG_GET_FWL_REGION;
    vHsmFW_GetFwReq_st.hdr.host = HOST_ID_HSM;
    vHsmFW_GetFwReq_st.hdr.flags = TISCI_MSG_FLAG_AOP;
    vHsmFW_GetFwReq_st.fwl_id = fw_Id;
    vHsmFW_GetFwReq_st.region = region;
    vHsmFW_GetFwReq_st.n_permission_regs = n_permission_regs;
    fl_ret = sproxy_send_msg(&vHsmFW_GetFwReq_st, sizeof(vHsmFW_GetFwReq_st), 1U);
    if(fl_ret == 0)
    {
		do{
			fl_ret = sproxy_receive_msg(&vHsmFW_GetFwResp_st, sizeof(vHsmFW_GetFwResp_st));
			if(!vHsmFW_Timeout_U16--){
				break;
			}
		}
		while(fl_ret);
    }
    if (fl_ret != 0)
	{
		l_RetVal_E = E_NOT_OK;
        TRACE_info("\r\n Firewall get Failed");
	}
    else
    {  
        TRACE_info_arg_hsm("\r\n FWL Id: ",vHsmFW_GetFwResp_st.fwl_id);
        TRACE_info_arg_hsm("\r\n Region: ",vHsmFW_GetFwResp_st.region);
        TRACE_info_arg_hsm("\r\n n_permission_regs: ",vHsmFW_GetFwResp_st.n_permission_regs);
        TRACE_info_arg_hsm("\r\n control: ",vHsmFW_GetFwResp_st.control);
        TRACE_info_arg_hsm("\r\n permissions 1: ",vHsmFW_GetFwResp_st.permissions[0]);
        TRACE_info_arg_hsm("\r\n permissions 2: ",vHsmFW_GetFwResp_st.permissions[1]);
        TRACE_info_arg_hsm("\r\n permissions 3: ",vHsmFW_GetFwResp_st.permissions[2]);
        TRACE_info_arg_hsm("\r\n start_address: ",vHsmFW_GetFwResp_st.start_address);
        TRACE_info_arg_hsm("\r\n end_address: ",vHsmFW_GetFwResp_st.end_address);
    }
	return l_RetVal_E;
}
#endif
#endif /*VHSMFW_ENABLE*/
/*EOF*/
