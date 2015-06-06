#include <limits.h>
#include <project.h>
#include "twl_printf.h"

static void simple(t_test *test)
{
	mt_assert(twl_str_is_int("11") == true);
}

static void empty_str(t_test *test)
{
	mt_assert(twl_str_is_int("") == false);
}

static void negative_nbr(t_test *test)
{
	mt_assert(twl_str_is_int("-42") == true);
}

static void int_max(t_test *test)
{
	mt_assert(twl_str_is_int("2147483647") == true);
}

static void int_min(t_test *test)
{
	mt_assert(twl_str_is_int("-2147483648") == true);
}

static void int_max_plus_one(t_test *test)
{
	mt_assert(twl_str_is_int("2147483648") == false);
}

static void int_min_plus_one(t_test *test)
{
	mt_assert(twl_str_is_int("-2147483649") == false);
}

void	suite_twl_str_is_int(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, empty_str);
	SUITE_ADD_TEST(suite, negative_nbr);
	SUITE_ADD_TEST(suite, int_min);
	SUITE_ADD_TEST(suite, int_max);
	SUITE_ADD_TEST(suite, int_max_plus_one);
	SUITE_ADD_TEST(suite, int_min_plus_one);
}
