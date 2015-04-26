#include <project.h>
#include "twl_printf.h"

static void test_contains_only_multiple_chars(t_test *test)
{
	mt_assert(twl_str_contains_only("aabbccdd", "abcd") == true);
}

static void test_contains_only_multiple_chars_false(t_test *test)
{
	mt_assert(twl_str_contains_only("aabbccdd", "abc") == false);
}

static void test_one_target_chars(t_test *test)
{
	mt_assert(twl_str_contains_only("aaaaaa", "a") == true);
}

static void test_one_target_chars_false(t_test *test)
{
	mt_assert(twl_str_contains_only("aaaaaab", "a") == false);
}

static void test_empty_target_chars(t_test *test)
{
	mt_assert(twl_str_contains_only("", "") == true);
}

static void test_empty_target_chars_false(t_test *test)
{
	mt_assert(twl_str_contains_only("a", "") == false);
}

static void test_empty_source_string_false(t_test *test)
{
	mt_assert(twl_str_contains_only("", "a") == true);
}

void	suite_twl_str_contains_only(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_contains_only_multiple_chars);
	SUITE_ADD_TEST(suite, test_contains_only_multiple_chars_false);
	SUITE_ADD_TEST(suite, test_one_target_chars);
	SUITE_ADD_TEST(suite, test_one_target_chars_false);
	SUITE_ADD_TEST(suite, test_empty_target_chars);
	SUITE_ADD_TEST(suite, test_empty_target_chars_false);
	SUITE_ADD_TEST(suite, test_empty_source_string_false);
}
