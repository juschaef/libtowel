#include <project.h>
#include "twl_xstring.h"

static void simple_test(t_test *test)
{
	mt_assert(strcmp(twl_ldtoa(111.1L), "111.100000") == 0);
}

static void micro_value(t_test *test)
{
	mt_assert(strcmp(twl_ldtoa(0.0001L), "0.000100") == 0);
}

static void negative(t_test *test)
{
	mt_assert(strcmp(twl_ldtoa(-0.0001L), "-0.000100") == 0);
}

static void large_number(t_test *test)
{
	mt_assert(strcmp(twl_ldtoa(42.0001L), "42.000100") == 0);
}

void	suite_twl_ldtoa(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, micro_value);
	SUITE_ADD_TEST(suite, negative);
	SUITE_ADD_TEST(suite, large_number);
}
