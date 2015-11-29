#include <project.h>
#include "twl_printf.h"

static void test_simple(t_test *test)
{
	mt_assert(strcmp(twl_str_before_any_char("abcde", "c"), "ab") == 0);
}

static void test_empty(t_test *test)
{
	mt_assert(strcmp(twl_str_before_any_char("abcde", ""), "") == 0);
}

static void test_empty_empty(t_test *test)
{
	mt_assert(strcmp(twl_str_before_any_char("", ""), "") == 0);
}

static void test_empty_source(t_test *test)
{
	mt_assert(twl_str_before_any_char("", "abc") == NULL);
}

static void test_complex(t_test *test)
{
	mt_assert(strcmp(twl_str_before_any_char("abcde", "dce"), "ab") == 0);
}

void	suite_twl_str_before_any_char(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_empty);
	SUITE_ADD_TEST(suite, test_empty_empty);
	SUITE_ADD_TEST(suite, test_empty_source);
	SUITE_ADD_TEST(suite, test_complex);
}
