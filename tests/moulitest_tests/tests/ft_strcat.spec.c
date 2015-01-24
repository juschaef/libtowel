#include <project.h>

static void simple_test(t_test *test)
{
	// test->debug = 1;
	char s[100];

	strcpy(s, "");
	ft_strcat(s, "abc");
	mt_assert(strcmp(s, "abc") == 0);
}

static void empty_string(t_test *test)
{
	// test->debug = 1;
	char s[100];

	ft_strcpy(s, "");
	ft_strcat(s, "");
	mt_assert(strcmp(s, "") == 0);
}

static void return_value_string(t_test *test)
{
	// test->debug = 1;
	char *s;

	s = malloc(sizeof(char) * 10);
	s = ft_strcat(s, "");
	mt_assert(strcmp(s, "") == 0);
}

static void return_value_same_pointer(t_test *test)
{
	// test->debug = 1;
	char s[100];

	mt_assert((long)s == (long)ft_strcat(s, ""));
}

// static void nullDestination_raiseAbort(t_test *test)
// {
// 	// test->debug = 1;
// 	mt_assert_signal(!!ft_strcat(NULL, ""), SIGABRT);
// }

// static void nullSource_raiseAbort(t_test *test)
// {
// 	// test->debug = 1;
// 	mt_assert_signal(!!ft_strcat(ft_strdup("abc"), NULL), SIGABRT);
// }

// static void nonWritableDest_raiseAbort(t_test *test)
// {
// 	// test->debug = 1;
// 	mt_assert_signal(!!ft_strcat("abc", "abc"), SIGBUS);
// }

void	suite_ft_strcat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, return_value_string);
	SUITE_ADD_TEST(suite, return_value_same_pointer);
	// SUITE_ADD_TEST(suite, nullDestination_raiseAbort);
	// SUITE_ADD_TEST(suite, nullSource_raiseAbort);
	// SUITE_ADD_TEST(suite, nonWritableDest_raiseAbort);
}
