#include <project.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "twl_stdio.h"

void	tests_all(t_test *test)
{
	char	*actual;
	char	*expected;
	int		errnum;

	errnum = 0;
	while (errnum < 100)
	{
		actual = twl_strerror(errnum);
		expected = strerror(errnum);
		mt_assert(strcmp(actual, expected) == 0);
		errnum += 1;
	}
}

void	suite_twl_strerror(t_suite *suite)
{
	SUITE_ADD_TEST(suite, tests_all);
}
