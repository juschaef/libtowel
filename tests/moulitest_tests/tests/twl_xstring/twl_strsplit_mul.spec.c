#include <project.h>
#include "twl_printf.h"

static void simple_split(t_test *test)
{
	char **segs;

	segs = twl_strsplit_mul("1+2-3+4", "+-");
	mt_assert(strcmp(segs[0], "1") == 0);
	mt_assert(strcmp(segs[1], "2") == 0);
	mt_assert(strcmp(segs[2], "3") == 0);
	mt_assert(strcmp(segs[3], "4") == 0);
}

void	suite_twl_strsplit_mul(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_split);
}
