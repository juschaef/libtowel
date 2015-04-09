#include <project.h>
#include "twl_printf.h"

static void simple_test(t_test *test)
{
	// const char *arr[] = {"aaa", "bbb", "ccc", NULL};
	// char *output;

	// output = twl_strjoinarr(arr, " ");
	// mt_assert(str
	// cmp(output, "aaa bbb ccc") == 0);
	mt_assert(0);
}

void	suite_twl_strjoinarr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
