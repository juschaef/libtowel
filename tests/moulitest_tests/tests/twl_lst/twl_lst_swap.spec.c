#include "project.h"
#include "twl_lst.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("ddd"));
	twl_lst_push_back(lst, strdup("eee"));

	twl_lst_swap(lst, 1, 3);

	mt_assert(strcmp(twl_lst_get(lst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "ddd") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 3), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 4), "eee") == 0);
}

static void simple_test_extrem_begin(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("ddd"));
	twl_lst_push_back(lst, strdup("eee"));

	twl_lst_swap(lst, 0, 3);

	mt_assert(strcmp(twl_lst_get(lst, 0), "ddd") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 3), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 4), "eee") == 0);
}

static void simple_test_extrem_nearby(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("ddd"));
	twl_lst_push_back(lst, strdup("eee"));

	twl_lst_swap(lst, 0, 1);

	mt_assert(strcmp(twl_lst_get(lst, 0), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 3), "ddd") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 4), "eee") == 0);
}

static void simple_test_extrem_end(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("ddd"));
	twl_lst_push_back(lst, strdup("eee"));

	twl_lst_swap(lst, 0, 4);

	mt_assert(strcmp(twl_lst_get(lst, 0), "eee") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 3), "ddd") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 4), "aaa") == 0);
}

void	suite_twl_lst_swap(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_extrem_begin);
	SUITE_ADD_TEST(suite, simple_test_extrem_nearby);
	SUITE_ADD_TEST(suite, simple_test_extrem_end);
}
