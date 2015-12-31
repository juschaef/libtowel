#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("1"));
	twl_lst_push(lst, strdup("2"));
	twl_lst_push(lst, strdup("3"));
	twl_lst_push(lst, strdup("4"));
	twl_lst_push(lst, strdup("5"));

	twl_lst_remove_mult(lst, 1, 4, free);
	mt_assert(strcmp(twl_lst_get(lst, 0), "1") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "5") == 0);
	mt_assert(twl_lst_len(lst) == 2);

	twl_lst_del(lst, free);
}

static void head_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("1"));
	twl_lst_push(lst, strdup("2"));
	twl_lst_push(lst, strdup("3"));
	twl_lst_push(lst, strdup("4"));
	twl_lst_push(lst, strdup("5"));

	twl_lst_remove_mult(lst, 0, 3, free);
	mt_assert(strcmp(twl_lst_get(lst, 0), "4") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "5") == 0);
	mt_assert(twl_lst_len(lst) == 2);

	twl_lst_del(lst, free);
}

static void tail_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("1"));
	twl_lst_push(lst, strdup("2"));
	twl_lst_push(lst, strdup("3"));
	twl_lst_push(lst, strdup("4"));
	twl_lst_push(lst, strdup("5"));

	twl_lst_remove_mult(lst, 2, 5, free);
	mt_assert(strcmp(twl_lst_get(lst, 0), "1") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "2") == 0);
	mt_assert(twl_lst_len(lst) == 2);

	twl_lst_del(lst, free);
}

void	suite_twl_lst_remove_mult(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, head_test);
	SUITE_ADD_TEST(suite, tail_test);
}
