#include "project.h"
#include <twl_opt.h>

static void test_simple(t_test *test)
{
	char *argv[] = {"ls", "-l", NULL};
	t_twl_opt *twl_opt;

	twl_opt = twl_opt_new(argv);
	
	mt_assert(strcmp(twl_opt->cmd, "ls") == 0);
}

void	suite_twl_opt_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
