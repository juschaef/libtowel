#include "project.h"
#include "twl_opt.h"
#include "twl_lst.h"
#include <stdbool.h>

static void test_opt_cmd(t_test *test)
{
	char *argv[] = {"ls", "-l", "ab", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "lbsz");
	
	mt_assert(twl_opt_exist(twl_opt, "l") == true);
	mt_assert(twl_opt_exist(twl_opt, "b") == false);
	mt_assert(twl_opt_exist(twl_opt, "ls") == false);
	mt_assert(twl_opt_exist(twl_opt, "z") == false);
	// twl_opt_del(twl_opt);
}

static void test_opt_cmd_harder(t_test *test)
{
	char *argv[] = {"ls", "-la", "-ul", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "laus");
	
	mt_assert(twl_opt_exist(twl_opt, "l") == true);
	mt_assert(twl_opt_exist(twl_opt, "a") == true);
	mt_assert(twl_opt_exist(twl_opt, "u") == true);
	mt_assert(twl_lst_len(twl_opt->opts) == 4);
	// twl_opt_del(twl_opt);
}

// static void test_opt_cmd_harder2(t_test *test)
// {
// 	char *argv[] = {"ls", "-la", NULL};
// 	t_opt *twl_opt;

// 	twl_opt = twl_opt_new(argv);
	
// 	mt_assert(twl_opt_exist(twl_opt, "l") == true);
// 	mt_assert(twl_opt_exist(twl_opt, "a") == true);
// }

void	suite_twl_opt_exist(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_opt_cmd);
	SUITE_ADD_TEST(suite, test_opt_cmd_harder);
	// SUITE_ADD_TEST(suite, test_opt_cmd_harder2);
}
