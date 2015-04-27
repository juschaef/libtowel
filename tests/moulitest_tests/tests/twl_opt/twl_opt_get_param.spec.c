#include "project.h"
#include "twl_opt.h"

static void test_simple(t_test *test)
{
	char *argv[] = {"ls", "-l", "l_opt_param", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "sl:");
	mt_assert(strcmp(twl_opt_get_param(twl_opt, "l"), "l_opt_param") == 0);
	twl_opt_del(twl_opt);
}

static void test_simple2(t_test *test)
{
	char *argv[] = {"ls", "-l", "l_opt_param", "-a", "a_opt_param", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "sl:a:");
	mt_assert(strcmp(twl_opt_get_param(twl_opt, "l"), "l_opt_param") == 0);
	mt_assert(strcmp(twl_opt_get_param(twl_opt, "a"), "a_opt_param") == 0);
	twl_opt_del(twl_opt);
}

static void test_simple3(t_test *test)
{
	char *argv[] = {"ls", "-l", "l_opt_param", "-a", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "sl:a");
	mt_assert(strcmp(twl_opt_get_param(twl_opt, "l"), "l_opt_param") == 0);
	mt_assert(twl_opt_exist(twl_opt, "a") == true);
	mt_assert(twl_opt_exist(twl_opt, "l") == true);
	twl_opt_del(twl_opt);
}

static void test_simple4(t_test *test)
{
	char *argv[] = {"ls", "-l", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "sl:a");
	mt_assert(twl_opt_get_param(twl_opt, "l") == NULL);
	mt_assert(twl_opt_exist(twl_opt, "l") == true);
	twl_opt_del(twl_opt);
}

static void test_opt_that_does_not_exist(t_test *test)
{
	char *argv[] = {"ls", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "l");
	mt_assert(twl_opt_get_param(twl_opt, "l") == NULL);
	twl_opt_del(twl_opt);
}

void	suite_twl_opt_get_param(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_simple2);
	SUITE_ADD_TEST(suite, test_simple3);
	SUITE_ADD_TEST(suite, test_simple4);
	SUITE_ADD_TEST(suite, test_opt_that_does_not_exist);
}
