#include <project.h>
#include "twl_stdio.h"

static void test_string(t_test *test)
{
	char *s;

	twl_asprintf(&s, "hello %s", "world!");
	mt_assert(strcmp(s, "hello world!") == 0);
}

static void test_digit(t_test *test)
{
	char *s;

	twl_asprintf(&s, "{%15.6d}", 1234);
	mt_assert(strcmp(s, "{         001234}") == 0);
}

static void test_mixed(t_test *test)
{
	char *s;

	twl_asprintf(&s, "%s%p%d%d%p%s%p%p%s",
		"a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	mt_assert(strcmp(s, "a0x7fff9f823ec7120x7fff9f8210b2b0x7fff9f823ec70x7fff9f8210b2c") == 0);
}

void	suite_twl_asprintf(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_string);
	SUITE_ADD_TEST(suite, test_digit);
	SUITE_ADD_TEST(suite, test_mixed);
}
