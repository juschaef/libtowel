#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char *str;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));

	str = twl_lst_pop_back(lst);
	mt_assert(strcmp(str, "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "bbb") == 0);
	mt_assert(twl_lst_get(lst, 2) == NULL);
	twl_lst_del(lst, free);
	free(str);
}

static void pop_empty_list(t_test *test)
{
	t_lst	*lst;

	lst = twl_lst_new();
	mt_assert(twl_lst_pop_back(lst) == NULL);
	twl_lst_del(lst, free);
}

void	suite_twl_lst_pop_back(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, pop_empty_list);
}
