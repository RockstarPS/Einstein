/*
 * System Firmware Trace Layer
 *
 * Utility itoa function for number to string conversion
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <types/short_types.h>

u8 *lib_itoa(u32 value, u8 *str, u32 base)
{
	u32 idx = 0;
	u32 val;
	u32 i;

	if (value == 0U) {
		str[0] = (u8) '0';
		idx++;
	}

	while (value > 0U) {
		val = value % base;
		if (val < 10U) {
			str[idx] = (u8) (val + '0');
		} else {
			str[idx] = (u8) ((val - 10U) + 'A');
		}

		idx++;
		value /= base;
	}

	str[idx] = (u8) '\0';

	if (idx > 1U) {
		/* Get length of string - NULL terminator*/
		idx--;

		/* Reverse the string as we converted from low digit to high */
		for (i = 0U; i <= idx / 2U; i++) {
			val = str[idx - i];
			str[idx - i] = str[i];
			str[i] = (u8) val;
		}
	}

	return str;
}
