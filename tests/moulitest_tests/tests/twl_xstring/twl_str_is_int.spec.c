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
static void large_nbr(t_test *test)
{
	mt_assert(twl_str_is_int("979456456456456") == true);
}

void	suite_twl_str_is_int(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, empty_str);
	SUITE_ADD_TEST(suite, negative_nbr);
	SUITE_ADD_TEST(suite, large_nbr);
}
