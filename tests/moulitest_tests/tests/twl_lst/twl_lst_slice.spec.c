#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;
	t_lst *lst_new;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("111"));
	twl_lst_push(lst, strdup("222"));
	twl_lst_push(lst, strdup("333"));
	twl_lst_push(lst, strdup("444"));
	twl_lst_push(lst, strdup("555"));

	lst_new = twl_lst_slice(lst, 1, 4);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 2), "444") == 0);
	mt_assert(twl_lst_len(lst_new) == 3);

	lst->head = NULL;
	twl_lst_del(lst_new, free);
	twl_lst_del(lst, free);
}

static void head_test(t_test *test)
{
	t_lst *lst;
	t_lst *lst_new;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("111"));
	twl_lst_push(lst, strdup("222"));
	twl_lst_push(lst, strdup("333"));
	twl_lst_push(lst, strdup("444"));
	twl_lst_push(lst, strdup("555"));

	lst_new = twl_lst_slice(lst, 0, 2);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "222") == 0);
	mt_assert(twl_lst_len(lst_new) == 2);

	lst->head = NULL;
	twl_lst_del(lst_new, free);
	twl_lst_del(lst, free);
}

static void full_test(t_test *test)
{
	t_lst *lst;
	t_lst *lst_new;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("111"));
	twl_lst_push(lst, strdup("222"));
	twl_lst_push(lst, strdup("333"));
	twl_lst_push(lst, strdup("444"));
	twl_lst_push(lst, strdup("555"));

	lst_new = twl_lst_slice(lst, 0, 5);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 2), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 3), "444") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 4), "555") == 0);
	mt_assert(twl_lst_len(lst_new) == 5);

	lst->head = NULL;
	twl_lst_del(lst_new, free);
	twl_lst_del(lst, free);
}

void	suite_twl_lst_slice(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, head_test);
	SUITE_ADD_TEST(suite, full_test);
}
