#include <project.h>
#include "twl_printf.h"

static void success(t_test *test)
{
	mt_assert(twl_str_ends_with("abd", "bd") == true);
}

static void success_empty_str(t_test *test)
{
	mt_assert(twl_str_ends_with("abd", "") == true);
}

static void success_one_char(t_test *test)
{
	mt_assert(twl_str_ends_with("abd", "d") == true);
}

static void not_equal(t_test *test)
{
	mt_assert(twl_str_ends_with("abdee", "cee") == false);
}

static void full_string(t_test *test)
{
	mt_assert(twl_str_ends_with("123", "123") == true);
}

void	suite_twl_str_ends_with(t_suite *suite)
{
	SUITE_ADD_TEST(suite, success);
	SUITE_ADD_TEST(suite, success_empty_str);
	SUITE_ADD_TEST(suite, success_one_char);
	SUITE_ADD_TEST(suite, not_equal);
	SUITE_ADD_TEST(suite, full_string);
}
