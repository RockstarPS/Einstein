/*
 * DMSC Firmware Unit test infrastructure Unit test IDs
 *
 * Cortex-M3 (CM3) firmware component for unit testing
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef UNIT_TESTIDS_H
#define UNIT_TESTIDS_H

/** Global list of all unit test cases */
typedef enum _unit_test_id {
	/** Basic Ping message */
	UT_ID_HELLO_PING = 0,

	UT_ID_SECURITY_AES,

	UT_ID_UART_16550_PUTCHAR_SIMPLE,
	UT_ID_UART_16550_PUTCHAR_FIFO,

	UT_ID_OSAL_CLOCK_DELAY_SIMPLE,

	UT_ID_SA2UL_CRYPTO,

	/** Maximum tests possible -> XXX: DONOT add beyond this */
	UT_ID_MAX_UNIT_TESTS
} unit_test_id;

#endif /* UNIT_TESTIDS_H */
