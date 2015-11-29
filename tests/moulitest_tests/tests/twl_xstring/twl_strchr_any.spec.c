#include <project.h>
#include "twl_printf.h"

static void simple_test(t_test *test)
{
	char			*s1 = "123";
	char			*s2 = "2";
	mt_assert(twl_strchr_any(s1, s2) == s1 + 1);
}

static void not_found(t_test *test)
{
	char			*s1 = "123";
	char			*s2 = "5";
	mt_assert(twl_strchr_any(s1, s2) == NULL);
}

static void test3(t_test *test)
{
	char			*s1 = "12345";
	char			*s2 = "53";
	mt_assert(twl_strchr_any(s1, s2) == s1 + 2);
}

static void test_empty_needles(t_test *test)
{
	char			*s1 = "12345";
	char			*s2 = "";
	mt_assert(twl_strchr_any(s1, s2) == s1);
}

static void test_empty_haystack(t_test *test)
{
	char			*s1 = "";
	char			*s2 = "123";
	mt_assert(twl_strchr_any(s1, s2) == NULL);
}

static void test_empty_haystack_and_needles(t_test *test)
{
	char			*s1 = "";
	char			*s2 = "";
	mt_assert(twl_strchr_any(s1, s2) == s1);
}

void	suite_twl_strchr_any(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, not_found);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test_empty_needles);
	SUITE_ADD_TEST(suite, test_empty_haystack);
	SUITE_ADD_TEST(suite, test_empty_haystack_and_needles);
}
