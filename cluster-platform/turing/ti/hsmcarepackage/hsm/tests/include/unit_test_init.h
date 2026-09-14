/*
 * DMSC Firmware Unit test infrastructure interface header
 *
 * Cortex-M3 (CM3) firmware component for unit testing
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef UNIT_TEST_INIT_H_
#define UNIT_TEST_INIT_H_

#include <inttypes.h>
#include <types/sbool.h>
#include <types/short_types.h>

#ifdef CONFIG_UNIT_TESTS
/**
 * \brief Init function for the unit_test component
 */
s32 unit_test_init(void);

/**
 * \brief Init function for the unit_test_secure component
 */
s32 unit_test_secure_init(void);

#else /* CONFIG_UNIT_TESTS */

static inline s32 unit_test_init(void)
{
	/* XXX: Print a warning on to the debug output */
	return 0;
}

static inline s32 unit_test_secure_init(void)
{
	/* XXX: Print a warning on to the debug output */
	return 0;
}
#endif /* CONFIG_UNIT_TESTS */

/**
 * \brief Unit test message handler
 *
 * \param irq
 * unused
 * \param priv
 * unused
 *
 * \return
 * 0 if message is handled, else returns non-zero value.
 */
s32 unit_test_message_handler(void *irq, void *priv);

#endif /* UNIT_TEST_INIT_H_ */
