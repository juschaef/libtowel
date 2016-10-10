#include <project.h>
#include "twl_string.h"

static void test_all(t_test *test)
{
	char	*actual;
	char	*expected;

	for (int signum = 0; signum < 40; signum += 1)
	{
		actual = twl_strsignal(signum);
		expected = strsignal(signum);
		mt_assert(strcmp(actual, expected) == 0);
	}
}

void	suite_twl_strsignal(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_all);
}
