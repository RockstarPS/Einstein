/*
 * DMSC Firmware Unit test infrastructure Common include
 *
 * Cortex-M3 (CM3) firmware component for unit testing
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <config.h>

#include <compiler.h>
#include <types.h>
#include <types/short_types.h>

#ifdef CONFIG_UNIT_TESTS

#include <unit_test_ids.h>

/**
 * \brief Test case entry function
 *
 * u32 param is an optional parameter passed to the test case
 * returns 0 if test case passed, or returns a value for passing to caller
 */
typedef u32 (*unit_test_t)(u32 param);

/**
 * \brief Unit test case structure
 *
 * \param fn
 * Test case function to call
 * \param ut_id
 * test case ID
 */
struct unit_testcase {
	unit_test_t	fn;
	unit_test_id	ut_id;
};
/** Unit test case type */
typedef struct unit_testcase unit_testcase_t;

/* Registration macro for unit tests */
#define unit_test(_fn, id, _name)					\
	unit_testcase_t __unit_test_##_fn				\
	NEEDED __attribute__((__section__(".unittests"))) = {		\
		.fn = _fn, .ut_id = id }

/* Registration macro for unit tests */
#define unit_test_secure(_fn, id, _name)					\
	unit_testcase_t __unit_test_secure_##_fn				\
	NEEDED __attribute__((__section__(".unittestssecure"))) = {		\
		.fn = _fn, .ut_id = id }
#else

/*
 * use empty definitions for unit test macros when tests are not enabled
 * This aids in pre-silicon development for invoking unit testcases directly
 * without using the unit test framework
 */
#define unit_test(_fn, id, _name)

#define unit_test_secure(_fn, id, _name)

#endif  /* CONFIG_UNIT_TESTS */

#endif  /* UNIT_TEST_H */
