#include <project.h>
#include <twl_stdio.h>

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

void	suite_twl_asprintf(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_string);
	SUITE_ADD_TEST(suite, test_digit);
}
