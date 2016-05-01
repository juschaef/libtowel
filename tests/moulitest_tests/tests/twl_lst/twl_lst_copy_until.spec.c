#include "project.h"
#include "twl_lst.h"
#include <stdbool.h>
#include <string.h>

static void *copy_fn(void *data)
{
	return (strdup(data));
}

static void test_copy_stop_middle(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();
	char	*sentinel;

	sentinel = "ccc";
	twl_lst_push_back(lst, "aaa");
	twl_lst_push_back(lst, "bbb");
	twl_lst_push_back(lst, sentinel);
	twl_lst_push_back(lst, "ddd");

	lst_new = twl_lst_copy_until(lst, copy_fn, sentinel);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "bbb") == 0);
	mt_assert(twl_lst_len(lst_new) == 2);
	twl_lst_del(lst, NULL);
	twl_lst_del(lst_new, free);
}

static void test_sentinel_is_last_elem(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();
	char	*sentinel;

	sentinel = "ccc";
	twl_lst_push_back(lst, "aaa");
	twl_lst_push_back(lst, "bbb");
	twl_lst_push_back(lst, sentinel);

	lst_new = twl_lst_copy_until(lst, copy_fn, sentinel);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "bbb") == 0);
	mt_assert(twl_lst_len(lst_new) == 2);
	twl_lst_del(lst, NULL);
	twl_lst_del(lst_new, free);
}

static void test_empty(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();
	char	*sentinel;

	sentinel = "ccc";

	lst_new = twl_lst_copy_until(lst, copy_fn, sentinel);

	mt_assert(twl_lst_len(lst_new) == 0);
	twl_lst_del(lst, NULL);
	twl_lst_del(lst_new, free);
}

static void test_sentinel_not_in_list(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();
	char	*sentinel;

	sentinel = "ddd";
	twl_lst_push_back(lst, "aaa");
	twl_lst_push_back(lst, "bbb");
	twl_lst_push_back(lst, "ccc");

	lst_new = twl_lst_copy_until(lst, copy_fn, sentinel);

	mt_assert(strcmp(twl_lst_get(lst_new, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst_new, 2), "ccc") == 0);
	mt_assert(twl_lst_len(lst_new) == 3);
	twl_lst_del(lst, NULL);
	twl_lst_del(lst_new, free);
}

static void test_copy_until_first(t_test *test)
{
	t_lst	*lst;
	t_lst	*lst_new;
	lst = twl_lst_new();
	char	*sentinel;

	sentinel = "aaa";
	twl_lst_push_back(lst, sentinel);
	twl_lst_push_back(lst, "bbb");
	twl_lst_push_back(lst, "ccc");

	lst_new = twl_lst_copy_until(lst, copy_fn, sentinel);

	mt_assert(twl_lst_len(lst_new) == 0);
	twl_lst_del(lst, NULL);
	twl_lst_del(lst_new, free);
}

void	suite_twl_lst_copy_until(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_copy_stop_middle);
	SUITE_ADD_TEST(suite, test_sentinel_is_last_elem);
	SUITE_ADD_TEST(suite, test_empty);
	SUITE_ADD_TEST(suite, test_sentinel_not_in_list);
	SUITE_ADD_TEST(suite, test_copy_until_first);
}
