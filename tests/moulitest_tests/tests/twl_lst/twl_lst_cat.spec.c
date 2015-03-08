#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst_dest;
	t_lst *lst_src;

	lst_dest = twl_lst_new();
	lst_src = twl_lst_new();

	twl_lst_push(lst_dest, strdup("111"));
	twl_lst_push(lst_dest, strdup("222"));
	twl_lst_push(lst_dest, strdup("333"));
	twl_lst_push(lst_src, strdup("444"));
	twl_lst_push(lst_src, strdup("555"));

	twl_lst_cat(lst_dest, lst_src);

	mt_assert(strcmp(twl_lst_get(lst_dest, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 1), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 2), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 3), "444") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 4), "555") == 0);

	lst_src->head = NULL;
	twl_lst_del(lst_src, free);
	twl_lst_del(lst_dest, free);
}

static void head_test(t_test *test)
{
	t_lst *lst_dest;
	t_lst *lst_src;

	lst_dest = twl_lst_new();
	lst_src = twl_lst_new();

	twl_lst_push(lst_src, strdup("111"));
	twl_lst_push(lst_src, strdup("222"));

	twl_lst_cat(lst_dest, lst_src);

	mt_assert(strcmp(twl_lst_get(lst_dest, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 1), "222") == 0);

	lst_src->head = NULL;
	twl_lst_del(lst_src, free);
	twl_lst_del(lst_dest, free);
}

void	suite_twl_lst_cat(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, head_test);
}
