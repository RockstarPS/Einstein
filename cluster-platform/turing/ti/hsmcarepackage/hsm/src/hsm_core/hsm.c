/*
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "uart_16550_description.h"
#include "hsm.h"
#include "trace.h"
#include "secure_proxy.h"
#include "short_types.h"
#include "rat.h"
#include "sec_proxy_minimal.h"
#include "tisci_protocol.h"
#include "tisci_dkek.h"
#include "firewall.h"
#include "hosts.h"
#include "hsm_data.h"
#include "hwip.h"
#include "ti_app.h"
#include "dmsc_ia.h"
#include "osal_platform.h"
#include "tisci_firewall.h"
#include "soc_hsm_data.h"
#include "firewall_conf.h"

extern struct fwl_multi_region_data_item FWL_DATA[NUM_FIREWALLS];


/* OSAL interface */
#include "osal_halt.h"
static u32 hwi_id;
#define SPROXY_RECEIVE_TIMEOUT 10
s32 HSM_init(void)
{
	s32 ret = 0;

	/**
	 * Initialise the UART configuration
	 */
#if 0
	ret = uart_16550_init();
	if (ret != 0) {
		err_handler();
	}
#endif

	/**
	* Initialise the Trace configuration for HSM core
	*/
	ret = trace_init();
	if (ret != 0) {
		err_handler();
	}

	/**
	*  rat init is used to map Soc address to the HSM memory
	*/
	ret = rat_init();
	if (ret != 0) {
		TRACE_info(" rat_init fails \n");
		osal_system_halt(ret);
	}

	/**
	* configure the secure proxy threads
	*/
	ret = sproxy_init();
	if (ret != 0) {
		TRACE_info(" sproxy_init fails \n");
		osal_system_halt(ret);
	}

   /**
	 * Set the firewalls required for secure
	 * proxy communication.
	 */
#if 0 // firewall init is done from program 
	ret = fw_init();
	if (ret != 0) {
		TRACE_info(" fw_init req fails \n");
		osal_system_halt(ret);
	}
#endif

    /**
     * Enable the main domain sa2ul module power
     **/
#ifdef CONFIG_SECURITY_SA2UL_PKA
#if 0
    ret = set_device_state(MAIN_DEV_SA2_UL0,0x1,MSG_DEVICE_SW_STATE_ON);
	if (ret != 0) {
        TRACE_info("set_device_state fail\n");
		osal_system_halt(ret);
    }
#endif

#endif
/*
	ret = create_interrupt();
	if (ret != 0) {
		TRACE_info(" create_interrupt fails \n");
		osal_system_halt(ret);
	}
*/
	ret = dmsc_ia_init();
	if (ret != 0) {
		TRACE_info(" dmsc_ia_init req fails \n");
		osal_system_halt(ret);
	}

	return ret;
}

s32 create_interrupt()
{
	u32 i, ret = 0;
	struct hwip_params hwi_params;

	mask_interrupts();

	for (i = 0; (i < hsm_evt_data_list_size) && (ret == SUCCESS); i++) {
		hwi_params.priority = hsm_evt_data_list[i].priority;
		ret = hwip_create(hwi_id++, (s32) hsm_evt_data_list[i].irq_num,
				  secure_msg_hwi_fxn, &hwi_params);
		if (ret != 0) {
			TRACE_info(" hwip_create req fails \n");
			osal_system_halt(ret);
		}
		ret = hwip_clear_interrupt(hsm_evt_data_list[i].irq_num);
		if (ret != 0) {
			TRACE_info(" hwip_create req fails \n");
			osal_system_halt(ret);
		}
		ret = hwip_enable_interrupt(hsm_evt_data_list[i].irq_num, NULL);
		if (ret != 0) {
			TRACE_info(" hwip_enable_interrupt req fails \n");
			osal_system_halt(ret);
		}
	}

	unmask_interrupts();

	return ret;
}

void err_handler(void)
{
	volatile unsigned long x = HSM_FAILURE;
	TRACE_info(" HSM Failure Error Handler");

	while (x) {
	}
	/* Will NOT return */
}

s32 fw_init()
{
	s32 ret = 0;
	u16 i;
	for (i = 0; i < NUM_FIREWALLS; i++)
	{
		ret = set_fw_region(FWL_DATA[i].id, \
				FWL_DATA[i].region_number,\
				FWL_DATA[i].n_permission_regs,\
				FWL_DATA[i].control,\
				FWL_DATA[i].start_address,\
				FWL_DATA[i].end_address,\
				FWL_DATA[i].permission1,\
				FWL_DATA[i].permission2,\
				FWL_DATA[i].permission3);
		if (ret){
			break;
		}
	}

	return ret;
}


s32 set_fw_region(u16 fwl_id, u16 region, u32 n_permission_regs, u32 control, \
		  soc_phys_addr_t start_address, soc_phys_addr_t end_address, \
		  u32 permission_0, u32 permission_1, u32 permission_2)
{
	s32 ret = 0;
	struct tisci_msg_fwl_set_firewall_region_req region_info;
	struct tisci_msg_sa2ul_get_dkek_resp get_resp;

	u16 timeout = SPROXY_RECEIVE_TIMEOUT;
	region_info.hdr.type = TISCI_MSG_SET_FWL_REGION;
	region_info.hdr.host = HOST_ID_HSM;
	region_info.hdr.flags = TISCI_MSG_FLAG_AOP;
	region_info.fwl_id = fwl_id;
	region_info.region = region;
	region_info.n_permission_regs = n_permission_regs;
	region_info.control = control;
	region_info.start_address = start_address;
	region_info.end_address = end_address;
	if (permission_0 != 0) {
		region_info.permissions[0] = permission_0;
	}
	if (permission_1 != 0) {
		region_info.permissions[1] = permission_1;
	}
	if (permission_2 != 0) {
		region_info.permissions[2] = permission_2;
	}

	ret = sproxy_send_msg(&region_info, sizeof(region_info), 1U);
    if(ret == 0)
    {
		do{
			ret = sproxy_receive_msg(&get_resp, sizeof(get_resp));
			if(!timeout--){
				break;
			}
		}
		while(ret);
    }
    if (ret != 0)
	{
		ret = -ETIMEDOUT;
	}

	return ret;
}

#ifdef CONFIG_SECURITY_SA2UL_PKA
s32 set_device_state(u32 device_id, s32 tx_queue, u8 state)
{
    s32 ret = 0;
	s32 timeout = SPROXY_RECEIVE_TIMEOUT;
    struct tisci_msg_set_device_req set_device_req;
    struct tisci_msg_set_device_resp set_device_resp;
    set_device_req.hdr.type = TISCI_MSG_SET_DEVICE;
    set_device_req.hdr.host = HOST_ID_HSM;
    set_device_req.hdr.flags = TISCI_MSG_FLAG_AOP;
    set_device_req.state = state;
    set_device_req.id = device_id;

    ret = sproxy_send_msg(&set_device_req, sizeof(set_device_req), tx_queue);

    if(ret == 0)
    {
		do{
        	ret = sproxy_receive_msg(&set_device_resp, sizeof(set_device_resp));
			if(!(timeout--)){
				break;
			}
		}
		while(ret);
    }
    if (ret != 0)
	{
		ret = ETIMEDOUT;
	}
	

    return ret;
}
#endif
