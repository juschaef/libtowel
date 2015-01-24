#include <project.h>
#include <twl_xstring.h>

static void simple_test(t_test *test)
{
	// test->debug = 1;
	mt_assert(twl_strlen("123") == 3);
}

static void simple_test2(t_test *test)
{
	// test->debug = 1;
	mt_assert(twl_strlen("abcdefg") == 7);
}

static void empty_string(t_test *test)
{
	// test->debug = 1;
	mt_assert(twl_strlen("") == 0);
}

// static void null_should_abort(t_test *test)
// {
// 	// test->debug = 1;
// 	mt_assert_signal(twl_strlen(NULL), SIGABRT);
// }

static void more_than_twl_strlen_max_len(t_test *test)
{
	// test->debug = 1;
	mt_assert(twl_strlen(twl_strnewc(FT_STRLEN_MAX_LEN, 'z')));
}

// static void more_than_twl_strlen_max_len_plus_one(t_test *test)
// {
// 	// test->debug = 1;
// 	char *s;

// 	s = twl_strnewc(FT_STRLEN_MAX_LEN + 42, 'z');
// 	mt_assert_signal(twl_strlen(s), SIGABRT);
// }

void	suite_twl_strlen(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
	SUITE_ADD_TEST(suite, empty_string);
	// SUITE_ADD_TEST(suite, null_should_abort);
	SUITE_ADD_TEST(suite, more_than_twl_strlen_max_len);
	// SUITE_ADD_TEST(suite, more_than_twl_strlen_max_len_plus_one);
}
