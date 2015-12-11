#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char	*s;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	s = twl_lst_strjoin(lst, "|");
	mt_assert(strcmp(s, "aaa|bbb|ccc") == 0);
	free(s);
}

static void test_empty_strings(t_test *test)
{
	t_lst	*lst;
	char	*s;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup(""));
	twl_lst_push(lst, strdup(""));
	twl_lst_push(lst, strdup(""));

	s = twl_lst_strjoin(lst, "|");
	mt_assert(strcmp(s, "||") == 0);
	free(s);
}

static void test_empty_list(t_test *test)
{
	t_lst	*lst;
	char	*s;

	lst = twl_lst_new();

	s = twl_lst_strjoin(lst, "|");
	mt_assert(strcmp(s, "") == 0);
	free(s);
}

void	suite_twl_lst_strjoin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_empty_strings);
	SUITE_ADD_TEST(suite, test_empty_list);
}
