#include <project.h>
#include "twl_printf.h"

static void simple_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrim_chars("  hello  ", " "), "hello") == 0);
}

static void complex_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrim_chars("\t AACACBCCBB hello  AACAC\tBCCBB ", " \tABC"), "hello") == 0);
}

static void trim_one_char(t_test *test)
{
	mt_assert(strcmp(twl_strtrim_chars("a", " \t\n"), "a") == 0);
}


static void trim_all_chars_trimed(t_test *test)
{
	mt_assert(strcmp(twl_strtrim_chars("   \t\t   ", " \t\n"), "") == 0);
}

void	suite_twl_strtrim_chars(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_trim);
	SUITE_ADD_TEST(suite, complex_trim);
	SUITE_ADD_TEST(suite, trim_one_char);
	SUITE_ADD_TEST(suite, trim_all_chars_trimed);
}
