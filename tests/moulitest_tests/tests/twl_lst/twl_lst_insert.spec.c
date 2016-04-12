#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("111"));
	twl_lst_push_back(lst, strdup("333"));
	twl_lst_push_back(lst, strdup("555"));

	twl_lst_insert(lst, 1, strdup("222"));
	twl_lst_insert(lst, 3, strdup("444"));

	mt_assert(strcmp(twl_lst_get(lst, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 3), "444") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 4), "555") == 0);
}

static void head_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("111"));
	twl_lst_insert(lst, 0, strdup("222"));

	mt_assert(strcmp(twl_lst_get(lst, 0), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "111") == 0);
	mt_assert(twl_lst_get_elem__(lst, 0)->prev == 0);
}

void	suite_twl_lst_insert(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, head_test);
}
