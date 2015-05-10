#include <project.h>
#include "twl_printf.h"

static void test_simple(t_test *test)
{
	mt_assert(strcmp(twl_str_split_get("aa bb cc", ' ', 1), "bb") == 0);
}

static void test_empty_str(t_test *test)
{
	mt_assert(twl_str_split_get("", ' ', 0) == NULL);
}

static void test_index_too_big(t_test *test)
{
	mt_assert(twl_str_split_get("aa bb cc", ' ', 42) == NULL);
}

static void test_negative_index(t_test *test)
{
	mt_assert(twl_str_split_get("aa bb cc", ' ', -1) == NULL);
}

static void test_index_zero(t_test *test)
{
	mt_assert(strcmp(twl_str_split_get("aa bb cc", ' ', 0), "aa") == 0);
}

static void test_last_index(t_test *test)
{
	mt_assert(strcmp(twl_str_split_get("aa bb cc", ' ', 2), "cc") == 0);
}

static void test_after_last_index(t_test *test)
{
	mt_assert(twl_str_split_get("aa bb cc", ' ', 3) == NULL);
}

void	suite_twl_str_split_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_empty_str);
	SUITE_ADD_TEST(suite, test_index_too_big);
	SUITE_ADD_TEST(suite, test_negative_index);
	SUITE_ADD_TEST(suite, test_index_zero);
	SUITE_ADD_TEST(suite, test_last_index);
	SUITE_ADD_TEST(suite, test_after_last_index);
}
