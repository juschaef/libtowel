#include <project.h>
#include "twl_printf.h"

static void test_some_occurences(t_test *test)
{
	mt_assert(twl_str_ncount_char("ababab", 'a', 100) == 3);
}

static void test_zero_occurence(t_test *test)
{
	mt_assert(twl_str_ncount_char("ababab", 'c', 100) == 0);
}

static void test_empty_string(t_test *test)
{
	mt_assert(twl_str_ncount_char("", 'c', 100) == 0);
}

static void test_single_char(t_test *test)
{
	mt_assert(twl_str_ncount_char("c", 'c', 100) == 1);
}

static void test_many_same_char(t_test *test)
{
	mt_assert(twl_str_ncount_char("zzzzzzzzzz", 'z', 100) == 10);
}

static void test_n(t_test *test)
{
	mt_assert(twl_str_ncount_char("zzzzzzzzzz", 'z', 3) == 3);
}

static void test_n1(t_test *test)
{
	mt_assert(twl_str_ncount_char("zazbzc", 'z', 3) == 2);
}

static void test_n2(t_test *test)
{
	mt_assert(twl_str_ncount_char("zazbzc", 'z', 4) == 2);
}

static void test_n_exact(t_test *test)
{
	mt_assert(twl_str_ncount_char("zzzz", 'z', 4) == 4);
}

void	suite_twl_str_ncount_char(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_some_occurences);
	SUITE_ADD_TEST(suite, test_zero_occurence);
	SUITE_ADD_TEST(suite, test_empty_string);
	SUITE_ADD_TEST(suite, test_single_char);
	SUITE_ADD_TEST(suite, test_many_same_char);
	SUITE_ADD_TEST(suite, test_n);
	SUITE_ADD_TEST(suite, test_n1);
	SUITE_ADD_TEST(suite, test_n2);
	SUITE_ADD_TEST(suite, test_n_exact);
}
