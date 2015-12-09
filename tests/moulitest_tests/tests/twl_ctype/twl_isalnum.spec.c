#include <project.h>
#include "twl_ctype.h"

static void	tests_simple(t_test *test)
{
	int		c;

	c = 0;
	while (c < 0x80)
	{
		mt_assert((twl_isalnum(c) != 0) == (isalnum(c) != 0));
		c++;
	}
}

void		suite_twl_isalnum(t_suite *suite)
{
	SUITE_ADD_TEST(suite, tests_simple);
}
