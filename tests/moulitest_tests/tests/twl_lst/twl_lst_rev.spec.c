#include "project.h"
#include "twl_lst.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	twl_lst_rev(lst);

	mt_assert(strcmp(twl_lst_get(lst, 0), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "aaa") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
	mt_assert(lst->head->prev == NULL);
	mt_assert(twl_lst_get_elem__(lst, -1)->next == NULL);
}

void	suite_twl_lst_rev(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
