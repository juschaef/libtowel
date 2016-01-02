#include <project.h>
#include <limits.h>
#include "twl_xstring.h"

static void test1(t_test *test)
{
	mt_assert(strcmp(twl_lltoa(LLONG_MIN), "-9223372036854775808") == 0);
}

void	suite_twl_lltoa(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}
