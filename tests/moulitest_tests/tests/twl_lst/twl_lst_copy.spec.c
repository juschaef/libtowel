#include "project.h"
#include "twl_lst.h"
#include <stdbool.h>
#include <string.h>

static void *copy_fn(void *data)
{
	return (strdup(data));
}

static void test_data(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("ddd"));

	lst_new = twl_lst_copy(lst, copy_fn);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 3), "ddd") == 0);
	mt_assert(twl_lst_len(lst_new) == 4);
}

static void test_deep_copy(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));

	lst_new = twl_lst_copy(lst, copy_fn);

	mt_assert(lst_new != lst);
	mt_assert(twl_lst_get(lst_new, 0) != twl_lst_get(lst, 0));
	mt_assert(twl_lst_get(lst_new, 1) != twl_lst_get(lst, 1));
}

static void test_shallow_copy(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("bbb"));

	lst_new = twl_lst_copy(lst, NULL);

	mt_assert(lst_new != lst);
	mt_assert(twl_lst_get(lst_new, 0) == twl_lst_get(lst, 0));
	mt_assert(twl_lst_get(lst_new, 1) == twl_lst_get(lst, 1));
}

void	suite_twl_lst_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_data);
	SUITE_ADD_TEST(suite, test_deep_copy);
	SUITE_ADD_TEST(suite, test_shallow_copy);
}
