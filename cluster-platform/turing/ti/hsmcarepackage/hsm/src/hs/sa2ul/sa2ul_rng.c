/*
 * System Firmware
 *
 * Copyright (C) 2020-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#include <types/address_types.h>
#include <sa2ul.h>
#include <sa2ul_rng.h>
#include <socmem.h>
#include "sa2ul_regs.h"
#include <lib/bitops.h>
#include <lib/trace.h>
#include <common_funcs.h>

/**
 * \brief RNG module global state
 *
 * \param base_address Pointer to SA2UL top-level registers
 * \param RNG_REGS Pointer to SA2UL RNG registers
 */

extern void delay_1us(void);

#ifdef CONFIG_SECURITY_SA2UL_TRNG
static struct {
	soc_phys_addr_t		base_address;
	struct sa2ul_trng_regs	*RNG_REGS;
} sa2ul_rng_state[SA2UL_MAX_INSTANCES];

/**
 * \brief Initialize SA2UL RNG state.
 *
 * \return EFTOK if successful
 */
fterr sa2ul_rng_init(void)
{
	u32 i;
	fterr ret = EFTOK;

    /* Iterate over all sa2ul instances */
	for (i = 0U; ft_is_ok(ret) && (i < sa2ul_socdata.num_instances); i++) {
		local_phys_addr_t r;
		
        /* Obtain the mapped local address of the sa2ul instance base address */
        sa2ul_rng_state[i].base_address = sa2ul_socdata.base_addr[i];
		ret = socmem_to_local((sa2ul_socdata.base_addr[i] + ((u64) SA2UL_TRNG_REGS_OFFSET)), &r);
		
		/* Fail if sa2ul instance base address if not found */
        if (ft_is_ok(ret)) {
			sa2ul_rng_state[i].RNG_REGS = (struct sa2ul_trng_regs *) r;
		} else {
            ret = -EFAIL;
            break;
        }
	}

	return ret;
}

/**
 * \brief Enable the sa2ul rng engine and set it up
 * 
 * \param instance sa2ul instance number
 *
 * \return EFTOK is successful
*/
fterr sa2ul_rng_setup( u32 instance, u8 md __attribute__((unused)) )
{
	fterr ret = EFTOK;

	ret = sa2ul_enable( instance, SA2UL_MODULE_TRNG );

	/*
	 * Currently, eip76 is setup to generate random numbers without DRBG.
	 * The parameter 'md' is being ignored. Following statement must be 
	 * modified when setup for other modes is enabled.
	 */
	if (ft_is_ok(ret)) {
		ret = sa2ul_rng_setup_eip76( instance, SA2UL_TRNG_MODE_NO_DRBG );
	}

	/* Disable TRNG module if eip76 setup fails*/
	if( !ft_is_ok(ret) ) {
		sa2ul_disable( instance, SA2UL_MODULE_TRNG );
	}

	return ret;
}

/**
 * \brief Setup eip76 within a sa2ul instance
 * 
 * \param instance The sa2ul instance whose trng must be setup
 * \param md The rng mode (not used right now)
 *
 * \return EFTOK is sucessful
*/
/*
 * Section 5.2.5.2 of IP hardware reference/programmer's manual
 * Starting up and obtaining random data without a DRBG when not 
 * using the [SP 800-90A] AES-256 DRBG, the startup sequence is 
 * relatively straightforward and the engine will generate data
 * automatically to keep the output register and buffer RAM filled:
 *
 * 1. Make sure the engine is idle by writing zeroes to the 
 * TRNG_CONTROL register twice. 
 *
 * 2. Write all configuration values in the TRNG_CONFIG and
 * TRNG_ALARMCNT registers, write zeroes to the TRNG_ALARMMASK 
 * and TRNG_ALARMSTOP registers.
 *
 * 3. Enable all FROs in the TRNG_FROENABLE register (note that
 * this can only be done after clearing the TRNG_ALARMSTOP
 * register). 
 *
 * 4. Start the actual engine by setting the ‘enable_trng’ bit
 * in the TRNG_CONTROL register (also a nice point to set the
 * interrupt mask bits). 
 *
 * 5. Optionally, when buffer RAM is configured: Set a data 
 * available interrupt threshold using the ‘load_thresh’ and
 * 'blocks_thresh’ fields of the TRNG_INTACK register. This 
 * allows delaying the data available interrupt until the 
 * indicated number of 128-bit words are available in the buffer 
 * RAM. 
 *
 * 6. Wait until a data word is available in the 
 * TRNG_OUTPUT_... registers (using the interrupt and/or ‘ready’
 * status bit in the TRNG_STATUS register).
 *
 * 7. If secure reading is enabled (with ‘read_timeout’ in 
 * TRNG_CONFIG non-zero), enable the reading by using the 
 * ‘open_read_gate’ field or ‘open_read_gate2’ bit in the 
 * TRNG_INTACK register. 
 *
 * 8. Read the random data from the TRNG_OUTPUT_... registers, 
 * then acknowledge the read by writing a ‘1’ to ‘ready_ack’ in
 * the TRNG_INTACK register. 
 *
 * 9. If more data is needed, go back to steps 5 or 6 above 
 */
fterr sa2ul_rng_setup_eip76( u32 instance, u8 md __attribute__((unused))) {
    fterr ret = EFTOK;
	struct sa2ul_trng_regs *r;
	u32 val, num_retries = 0;

    /* Get the pointer to trng module mmr block */
    r = sa2ul_rng_state[instance].RNG_REGS;

	/* Write zeroes twice to TRNG_CONTROL */
	ret = writel_verified(&r->TRNG_CONTROL, 0U);
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_CONTROL, 0U);
	}

    /* Initialize TRNG_CONFIG */
	val = 0U;
	val |= ((((u32) SA2UL_TRNG_CONFIG_SAMPLE_CYCLES ) << TRNG_CONFIG_SAMPLE_CYCLES_SHIFT) & (TRNG_CONFIG_SAMPLE_CYCLES_MASK));
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_CONFIG, val);
	}

	/* Leave the ALARMCNT register at its reset value */
	val = ((u32) 0xFFU);
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_ALARMCNT, val);
	}

    /* write zeros to ALARMMASK and ALARMSTOP registers */
	val = ((u32) 0U);
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_ALARMMASK, val);
	}
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_ALARMSTOP, val);
	}

    /* We have 8 FRO's in the RNG, enable all */
	val = ((u32) 0xFFU);
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_FROENABLE, val);
	}

    /* Enable TRNG */
	val = (((u32) 1U) << TRNG_CONTROL_ENABLE_TRNG_SHIFT );
	if (ft_is_ok(ret)) {
		ret = writel_verified(&r->TRNG_CONTROL, val);
	}

    /* Loop until a word is available */
	do {
		val = readl(&r->TRNG_STATUS);
		/*using osal_delay() crashes the core due to linker error. Workaround with delay_1us() 
		function as both are functionally similar. TODO.
		*/
		// osal_delay(1U);
		delay_1us();
		num_retries++;
	} while ( ((val & TRNG_STATUS_READY_MASK) != TRNG_STATUS_READY_MASK) && 
				(num_retries <= SA2UL_TRNG_SETUP_TIMEOUT_US) );

	/* Modify error code if setup timed out */
	if( num_retries > SA2UL_TRNG_SETUP_TIMEOUT_US ) {
		ret = -EFAIL;
	}

    return ret;
}

/**
 * \brief Non-blocking read 128-bit random number from TRNG
 *
 * \param instance sa2ul instance number
 * \param out pointer to output buffer
 *
 * \return EFTOK if successful
 * 
 * \note out buffer must be atleast 4 words long
*/
fterr sa2ul_rng_read( u32 instance, u32 *out )
{
	fterr ret = EFTOK;
	u32 mask, val, ready, j;
	struct sa2ul_trng_regs *r;

	r = sa2ul_rng_state[instance].RNG_REGS;

	/* Verify that TRNG is enabled */
	val = readl(&r->TRNG_CONTROL);
	mask = (((u32) 1U) << TRNG_CONTROL_ENABLE_TRNG_SHIFT);
	if ((val & mask) != mask) {
		ret = -EFAIL;
	}

    /* Check if random data is available */
    val = readl(&r->TRNG_STATUS);
    ready = (val & TRNG_STATUS_READY_MASK) >> TRNG_STATUS_READY_SHIFT;
    if ( ready != 1U ) {
        ret = -EAGAIN;
    }

    if (ft_is_ok(ret)) {
        /* If data is available, read it into the output buffer */
        for( j = ((u32) 0U); (j < SA2UL_RNG_NUM_OUTPUT_WORDS); j++ ) {
            out[j] = readl(&r->TRNG_IN_OUT[j]);
        }
        /*
        * Set the INTACK and go back
        * We are not using writel_verified as two registers are muxed here.
        * TRNG_STATUS and TRNG_INTACK
        */
        writel(&r->TRNG_STATUS,
                (TRNG_INTACK_READY_ACK_MASK << TRNG_INTACK_READY_ACK_SHIFT));
    }

	return ret;
}

/**
 * \brief Non-blocking read 128-bit random number from TRNG
 *
 * \param instance sa2ul instance number
 * \param out pointer to output buffer
 * \param timeout read timeout in uS
 *
 * \return EFTOK if successful
 * 
 * \note out buffer must be atleast 4 words long
*/
fterr sa2ul_rng_read_with_timeout( u32 instance, u32 *out, u32 timeout )
{
	u32 num_retries = ((u32) 0U);
	fterr ret = EFTOK;

    /* Wait until timeout */
    while(num_retries < timeout) {
		
        /* Try to 128-bit read random number */
        ret = sa2ul_rng_read( instance, &out[0] );
		
        /* exit if read is successful */
        if (ft_is_ok(ret)) {
			break;
		}
        /* loop back if random number not present */
        else if (ret == -EAGAIN) {
			/*using osal_delay() crashes the core due to linker error. Workaround with delay_1us() 
			function as both are functionally similar. TODO.
			*/
			// osal_delay(1U);
			delay_1us();
			num_retries++;
		} 
        /* exit if something else goes wrong */
        else {
			ret = -EFAIL;
            break;
		}
	}

	/* If a read could not be performed within 'timeout'
	 * uS modify the return code to reflect the same. 
	 */
	if (ret == -EAGAIN) {
		ret = -ETIMEDOUT;
	}

	return ret;
}
#endif
