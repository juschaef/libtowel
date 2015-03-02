#include <project.h>
#include "twl_xstdlib.h"

static void simple_test(t_test *test)
{
	mt_assert(strcmp(twl_joinpath("dir", "file"), "dir/file") == 0);
}

void	suite_twl_sys_joinpath(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
