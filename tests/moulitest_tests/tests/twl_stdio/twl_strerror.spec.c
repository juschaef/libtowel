#include <project.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "twl_stdio.h"

#define mt_test_strerror(name, errnum, debug) \
static void test_## name(t_test *test) \
{ \
	char	*actual = twl_strerror(errnum); \
	char	*expected = strerror(errnum); \
	if (debug) \
	{ \
		printf("===== errnum: %i\n", errnum); \
		printf("actual   {%s}\n", actual); \
		printf("expected {%s}\n", expected); \
	} \
	mt_assert(strcmp(actual, expected) == 0); \
}

mt_test_strerror(num01, EPERM, false);
mt_test_strerror(num02, ENOENT, false);
mt_test_strerror(num03, ESRCH, false);
mt_test_strerror(num04, EINTR, false);
mt_test_strerror(num05, EIO, false);
mt_test_strerror(num06, ENXIO, true);
mt_test_strerror(num07, E2BIG, true);
mt_test_strerror(num08, ENOEXEC, true);
mt_test_strerror(num09, EBADF, true);

void	suite_twl_strerror(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
	SUITE_ADD_TEST(suite, test_num06);
	SUITE_ADD_TEST(suite, test_num07);
	SUITE_ADD_TEST(suite, test_num08);
	SUITE_ADD_TEST(suite, test_num09);
}
