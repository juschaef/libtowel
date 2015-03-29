#include "project.h"
#include "twl_opt.h"

static void test_simple(t_test *test)
{
	char *argv[] = {"ls", "-l", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "a");
	mt_assert(strcmp(twl_opt_check_invalid_opts(twl_opt), "l") == 0);
	twl_opt_del(twl_opt);
}

static void test_simple2(t_test *test)
{
	char *argv[] = {"ls", "-m", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "a");
	mt_assert(strcmp(twl_opt_check_invalid_opts(twl_opt), "m") == 0);
	twl_opt_del(twl_opt);
}

void	suite_twl_opt_check_invalid_opts(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_simple2);
}
