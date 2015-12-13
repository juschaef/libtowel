#include <project.h>
#include "twl_printf.h"
#include "twl_xstring.h"

static void simple(t_test *test)
{
	mt_assert(twl_strstr_count("aa bb cc", "bb") == 1);
}

static void not_found(t_test *test)
{
	mt_assert(twl_strstr_count("aa cc", "bb") == 0);
}

static void two(t_test *test)
{
	mt_assert(twl_strstr_count("aa bb cc bb", "bb") == 2);
}

static void one_near(t_test *test)
{
	mt_assert(twl_strstr_count("bbb", "bb") == 1);
}

static void three_near(t_test *test)
{
	mt_assert(twl_strstr_count("aa bbb cc bbbb", "bb") == 3);
}

static void empty_haytask(t_test *test)
{
	mt_assert(twl_strstr_count("", "bb") == 0);
}

static void empty_needle(t_test *test)
{
	mt_assert(twl_strstr_count("abc", "") == 0);
}

void	suite_twl_strstr_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, not_found);
	SUITE_ADD_TEST(suite, two);
	SUITE_ADD_TEST(suite, one_near);
	SUITE_ADD_TEST(suite, three_near);
	SUITE_ADD_TEST(suite, empty_haytask);
	SUITE_ADD_TEST(suite, empty_needle);
}
