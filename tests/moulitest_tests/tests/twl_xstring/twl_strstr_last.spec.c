#include <project.h>
#include "twl_printf.h"
#include "twl_xstring.h"

static void simple(t_test *test)
{
	char			*s1 = "aa bb cc";
	mt_assert(twl_strstr_last(s1, "bb") == s1 + 3);
}

static void simple_two(t_test *test)
{
	char			*s1 = "aa bb cc bb dd";
	mt_assert(twl_strstr_last(s1, "bb") == s1 + 9);
}

static void empty_string(t_test *test)
{
	mt_assert(twl_strstr_last("", "bb") == NULL);
}

static void empty_needle(t_test *test)
{
	char			*s1 = "";
	mt_assert(twl_strstr_last(s1, "") == s1);
}

static void simple_three(t_test *test)
{
	char			*s1 = "aabbccbbddbbee";
	mt_assert(twl_strstr_last(s1, "bb") == s1 + 10);
}

void	suite_twl_strstr_last(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, simple_two);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, empty_needle);
	SUITE_ADD_TEST(suite, simple_three);
}
