#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tutu"));
	twl_lst_push_back(lst, strdup("toto"));

	mt_assert(strcmp(twl_lst_get(lst, 0), "tata") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "tutu") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "toto") == 0);

}

static void negative_index(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tutu"));
	twl_lst_push_back(lst, strdup("toto"));

	mt_assert(strcmp(twl_lst_get(lst, -3), "tata") == 0);
	mt_assert(strcmp(twl_lst_get(lst, -2), "tutu") == 0);
	mt_assert(strcmp(twl_lst_get(lst, -1), "toto") == 0);

}

static void non_existing_index(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tutu"));
	twl_lst_push_back(lst, strdup("toto"));

	mt_assert(twl_lst_get(lst, 10) == NULL);
}

void	suite_twl_lst_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, negative_index);
	SUITE_ADD_TEST(suite, non_existing_index);
}
