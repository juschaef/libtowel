#include <project.h>
#include "twl_printf.h"

static void test_some_occurences(t_test *test)
{
	mt_assert(twl_str_count_char("ababab", 'a') == 3);
}

static void test_zero_occurence(t_test *test)
{
	mt_assert(twl_str_count_char("ababab", 'c') == 0);
}

static void test_empty_string(t_test *test)
{
	mt_assert(twl_str_count_char("", 'c') == 0);
}

static void test_single_char(t_test *test)
{
	mt_assert(twl_str_count_char("c", 'c') == 1);
}

static void test_many_same_char(t_test *test)
{
	mt_assert(twl_str_count_char("zzzzzzzzzz", 'z') == 10);
}

void	suite_twl_str_count_char(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_some_occurences);
	SUITE_ADD_TEST(suite, test_zero_occurence);
	SUITE_ADD_TEST(suite, test_empty_string);
	SUITE_ADD_TEST(suite, test_single_char);
	SUITE_ADD_TEST(suite, test_many_same_char);
}
