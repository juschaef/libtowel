#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char	*s;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));

	s = twl_lst_pop_front(lst);
	mt_assert(strcmp(s, "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 0), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "ccc") == 0);
	mt_assert(twl_lst_get(lst, 2) == NULL);
	free(s);
}

void	suite_twl_lst_pop_front(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
