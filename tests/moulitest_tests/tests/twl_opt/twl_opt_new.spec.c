#include "project.h"
#include "twl_opt.h"

static void test_simple(t_test *test)
{
	char *argv[] = {"ls", "-l", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "la");
	
	mt_assert(strcmp(twl_opt->cmd, "ls") == 0);
	twl_opt_del(twl_opt);
}

static void test_simple_one_opt(t_test *test)
{
	char *argv[] = {"ls", "-l", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "a");
	
	mt_assert(strcmp(twl_opt->cmd, "ls") == 0);
	twl_opt_del(twl_opt);
}

static void test_non_opt_arguments(t_test *test)
{
	char *argv[] = {"ls", "-l", "file1", "dir1",  NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "ls");
	mt_assert(strcmp(twl_lst_get(twl_opt->non_opt_args, 0), "file1") == 0);
	mt_assert(strcmp(twl_lst_get(twl_opt->non_opt_args, 1), "dir1") == 0);
	mt_assert(twl_lst_len(twl_opt->non_opt_args) == 2);
	twl_opt_del(twl_opt);
}

static void test_double_dash(t_test *test)
{
	char *argv[] = {"ls", "--", "-file_starting_with_hyphen", "file1", "file2", "file3", NULL};
	t_opt *twl_opt;

	twl_opt = twl_opt_new(argv, "la");
	mt_assert(strcmp(twl_lst_get(twl_opt->non_opt_args, 0), "-file_starting_with_hyphen") == 0);
	mt_assert(strcmp(twl_lst_get(twl_opt->non_opt_args, 1), "file1") == 0);
	mt_assert(twl_lst_len(twl_opt->non_opt_args) == 4);
	twl_opt_del(twl_opt);
}

void	suite_twl_opt_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_simple_one_opt);
	SUITE_ADD_TEST(suite, test_non_opt_arguments);
	SUITE_ADD_TEST(suite, test_double_dash);
}
