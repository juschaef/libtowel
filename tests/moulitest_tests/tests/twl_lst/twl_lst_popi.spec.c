#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char *str;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	str = twl_lst_popi(lst, 1);
	mt_assert(strcmp(str, "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "ccc") == 0);
	mt_assert(twl_lst_get(lst, 2) == NULL);
	twl_lst_del(lst, free);
	twl_free(str);
}

void	suite_twl_lst_popi(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
