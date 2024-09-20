/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */
#include <unity.h>
#include <stdbool.h>

#include "foo.h"

void test_foo_init(void)
{
	int err;

	err = foo_init(NULL);
	TEST_ASSERT_EQUAL(0, err);
}

void test_foo_execute(void)
{
	int err;

	err = foo_execute();
	TEST_ASSERT_EQUAL(0, err);
}

/* It is required to be added to each test. That is because unity's
 * main may return nonzero, while zephyr's main currently must
 * return 0 in all cases (other values are reserved).
 */
extern int unity_main(void);

int main(void)
{
	(void)unity_main();

	return 0;
}
