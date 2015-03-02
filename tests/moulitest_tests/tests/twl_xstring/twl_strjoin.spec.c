#include <project.h>
#include "twl_printf.h"

static void simple_test(t_test *test)
{
	char *s;

	s = "aaa";
	s = twl_strjoin(s, "bbb");
	s = twl_strjoin(s, "ccc");
	mt_assert(strcmp(s, "aaabbbccc") == 0);
}

void	suite_twl_strjoin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
