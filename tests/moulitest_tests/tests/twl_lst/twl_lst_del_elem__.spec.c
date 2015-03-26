#include "twl_lst.h"
#include <project.h>
#include "twl_dict.h"

static void	del_data(char *str)
{
	twl_free(str);
	str = NULL;
	(void)str;
}

static void test_relink(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));
	mt_assert(twl_lst_len(lst) == 3);

	twl_lst_del_elem__(lst, lst->head->next, del_data);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "ccc") == 0);
	mt_assert(twl_lst_len(lst) == 2);
}

static void test_del_first(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));

	twl_lst_del_elem__(lst, lst->head, del_data);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "bbb") == 0);
	mt_assert(twl_lst_len(lst) == 1);
}

static void test_del_last(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));

	twl_lst_del_elem__(lst, lst->head->next, del_data);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "aaa") == 0);
	mt_assert(twl_lst_len(lst) == 1);
}

void	suite_twl_lst_del_elem__(t_suite *suite)
{
	// SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_relink);
	SUITE_ADD_TEST(suite, test_del_first);
	SUITE_ADD_TEST(suite, test_del_last);
}
