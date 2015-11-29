#include <project.h>
#include "twl_printf.h"

static void simple_test(t_test *test)
{
	char *s;

	s = twl_strndup("abcd", 2);
	mt_assert(strcmp(s, "ab") == 0);
	free(s);
}

static void simple_test2(t_test *test)
{
	char *s;

	s = twl_strndup("abcd", 4);
	mt_assert(strcmp(s, "abcd") == 0);
	free(s);
}

static void test_border(t_test *test)
{
	char *s;

	s = twl_strndup("abcd", 5);
	mt_assert(strcmp(s, "abcd") == 0);
	free(s);
}

static void test_large(t_test *test)
{
	char *s;

	s = twl_strndup("abcd", 10);
	mt_assert(strcmp(s, "abcd") == 0);
	free(s);
}

static void test_zero(t_test *test)
{
	char *s;

	s = twl_strndup("abcd", 0);
	mt_assert(strcmp(s, "") == 0);
	free(s);
}

void	suite_twl_strndup(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
	SUITE_ADD_TEST(suite, test_border);
	SUITE_ADD_TEST(suite, test_large);
	SUITE_ADD_TEST(suite, test_zero);
}
