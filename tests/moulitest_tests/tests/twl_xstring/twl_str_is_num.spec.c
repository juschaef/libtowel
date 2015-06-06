#include <project.h>
#include "twl_printf.h"

static void simple(t_test *test)
{
	mt_assert(twl_str_is_num("11") == true);
}

static void zero(t_test *test)
{
	mt_assert(twl_str_is_num("0") == true);
}

static void one(t_test *test)
{
	mt_assert(twl_str_is_num("1") == true);
}

static void empty_str(t_test *test)
{
	mt_assert(twl_str_is_num("") == false);
}

static void double_neg(t_test *test)
{
	mt_assert(twl_str_is_num("--42") == false);
}

static void negative_nbr(t_test *test)
{
	mt_assert(twl_str_is_num("-42") == true);
}

static void large_nbr(t_test *test)
{
	mt_assert(twl_str_is_num("97944654545656456456456456456445645645645656456456456") == true);
}

static void large_neg_nbr(t_test *test)
{
	mt_assert(twl_str_is_num("-97944654545656456456456456456445645645645656456456456") == true);
}

void	suite_twl_str_is_num(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, zero);
	SUITE_ADD_TEST(suite, one);
	SUITE_ADD_TEST(suite, empty_str);
	SUITE_ADD_TEST(suite, double_neg);
	SUITE_ADD_TEST(suite, negative_nbr);
	SUITE_ADD_TEST(suite, large_nbr);
	SUITE_ADD_TEST(suite, large_neg_nbr);
}
