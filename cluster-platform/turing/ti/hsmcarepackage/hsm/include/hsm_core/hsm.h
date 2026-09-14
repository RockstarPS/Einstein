/**
 * HSM library interface
 *
 * Main interface definition to the HSM library
 *
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef HSM_H
#define HSM_H

#include <address_types.h>

#define BIT2_SET(x)     (u32) (0x3 << (2 * x))



#define HSM_SUCCESS            BIT2_SET(0)
#define HSM_FAILURE            BIT2_SET(1)

#define MSG_DEVICE_SW_STATE_AUTO_OFF    0
#define MSG_DEVICE_SW_STATE_RETENTION   1
#define MSG_DEVICE_SW_STATE_ON          2

#define MSG_DEVICE_HW_STATE_OFF         0
#define MSG_DEVICE_HW_STATE_ON          1
#define MSG_DEVICE_HW_STATE_TRANS       2


s32 fw_init();

s32 set_fw_region(u16 fwl_id, u16 region, u32 n_permission_regs, u32 control, soc_phys_addr_t start_address, soc_phys_addr_t end_address, u32 permission_0, u32 permission_1, u32 permission_2);

s32 set_device_state(u32 device_id, s32 tx_queue, u8 state);

/**
 * \def HSM_SUCCESS
 * This status code is used to indicate successful operation.
 *
 * \def HSM_FAILURE
 * This is used to indicate a catastrophic system failure during processing.
 * This should be treated as a major error and cause for system reset.
 */
#define HSM_SUCCESS            BIT2_SET(0)
#define HSM_FAILURE            BIT2_SET(1)

/* Function prototypes */

/**
 * \brief HSM initialization
 *
 * Configures all HSM drivers and services
 *
 * \return HSM_SUCCESS upon success
 *	   HSM_FAILURE upon failure
 */
s32 HSM_init(void);

s32 create_interrupt();
void err_handler(void);

/**
 * \brief HSM ISR handler
 *
 * This function is intended to be called within ISR context from handler
 * registered by OS. It is responsible for detecting whether any events are
 * pending which must be serviced by HSM and prepare the library for
 * processing.
 *
 * \return error code:
 *
 *  HSM_SUCCESS upon successful servicing of any events or in the case no
 *  events are needing to be serviced.
 *
 *  HSM_FAILURE indicates a fault with the servicing of the incoming message.
 *  This must be treated as a catastropic fault.
 */
s32 HSM_isr();

/**
 * \brief HSM Process handler
 *
 * Intended to be called within processing context from handler registered by
 * OS. This will process any events which were found from in the HSM-owned
 * resources.
 *
 * \return error code:
 *
 *  HSM_SUCCESS upon successful processing of any events, or in the case there
 *  are no events to process.
 *
 *  HSM_FAILURE indicates a fault with the servicing of the incoming message.
 *  This must be treated as a catastropic fault.
 */
s32 HSM_process();

/**
 * \brief HSM watchdog service
 *
 * This must be called periodically to prevent watchdog timer
 * expiration triggering system reset. The timer is currently set
 * to 3 minutes.
 *
 * Recommendation is to call during message handling as well as in an
 * idle context in case a large period of time elapses without receiving
 * any messages.
 */
void HSM_rti_wdt_pet(void);

#endif /* HSM_H */
