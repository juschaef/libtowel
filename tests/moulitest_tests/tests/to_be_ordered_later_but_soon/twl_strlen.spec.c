#include <project.h>
#include "twl_xstring.h"
#include "twl_string.h"

# define FT_STRLEN_MAX_LEN 1 * 1000 * 1000

static void simple_test(t_test *test)
{
	mt_assert(twl_strlen("123") == 3);
}

static void simple_test2(t_test *test)
{
	mt_assert(twl_strlen("abcdefg") == 7);
}

static void empty_string(t_test *test)
{
	mt_assert(twl_strlen("") == 0);
}

static void more_than_twl_strlen_max_len(t_test *test)
{
	mt_assert(twl_strlen(twl_strnewc(FT_STRLEN_MAX_LEN, 'z')));
}

void	suite_twl_strlen(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, more_than_twl_strlen_max_len);
}
