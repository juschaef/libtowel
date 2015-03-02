#include <project.h>
#include "twl_printf.h"

static void simple_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrimc("  hello  ", " "), "hello") == 0);
}

static void complex_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrimc("\t AACACBCCBB hello  AACAC\tBCCBB ", " \tABC"), "hello") == 0);
}

static void trim_one_char(t_test *test)
{
	mt_assert(strcmp(twl_strtrimc("a", " \t\n"), "a") == 0);
}

void	suite_twl_strtrimc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_trim);
	SUITE_ADD_TEST(suite, complex_trim);
	SUITE_ADD_TEST(suite, trim_one_char);
}
