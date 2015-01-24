#include <project.h>
#include <ft_sys.h>

static void simple_test(t_test *test)
{
	mt_assert(strcmp(ft_sys_joinpath("dir", "file"), "dir/file") == 0);
}

void	suite_ft_sys_joinpath(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
