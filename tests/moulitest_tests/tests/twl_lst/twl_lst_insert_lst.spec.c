#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst_dest;
	t_lst *lst_src;

	lst_dest = twl_lst_new();
	lst_src = twl_lst_new();

	twl_lst_push_back(lst_dest, strdup("111"));
	twl_lst_push_back(lst_dest, strdup("444"));
	twl_lst_push_back(lst_dest, strdup("555"));
	twl_lst_push_back(lst_src, strdup("222"));
	twl_lst_push_back(lst_src, strdup("333"));

	twl_lst_insert_lst(lst_dest, 1, lst_src);

	mt_assert(strcmp(twl_lst_get(lst_dest, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 1), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 2), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 3), "444") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 4), "555") == 0);

	twl_lst_del(lst_src, NULL);
	twl_lst_del(lst_dest, free);
}

static void head_test(t_test *test)
{
	t_lst *lst_dest;
	t_lst *lst_src;

	lst_dest = twl_lst_new();
	lst_src = twl_lst_new();

	twl_lst_push_back(lst_dest, strdup("222"));
	twl_lst_push_back(lst_dest, strdup("333"));
	twl_lst_push_back(lst_dest, strdup("444"));
	twl_lst_push_back(lst_src, strdup("000"));
	twl_lst_push_back(lst_src, strdup("111"));

	twl_lst_insert_lst(lst_dest, 0, lst_src);

	mt_assert(strcmp(twl_lst_get(lst_dest, 0), "000") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 1), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 2), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 3), "333") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dest, 4), "444") == 0);

	twl_lst_del(lst_src, NULL);
	twl_lst_del(lst_dest, free);
}

void	suite_twl_lst_insert_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, head_test);
}
