#include "project.h"
#include "twl_lst.h"

static void simple(t_test *test)
{
	t_lst	*lst_dst;
	t_lst	*lst_src;

	lst_dst = twl_lst_new();
	twl_lst_push_back(lst_dst, strdup("aaa"));
	twl_lst_push_back(lst_dst, strdup("bbb"));

	lst_src = twl_lst_new();
	twl_lst_push_back(lst_src, strdup("ccc"));
	twl_lst_push_back(lst_src, strdup("ddd"));

	twl_lst_extend_front(lst_dst, lst_src);

	mt_assert(twl_lst_len(lst_dst) == 4);
	mt_assert(strcmp(twl_lst_get(lst_dst, 0), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 1), "ddd") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 2), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 3), "bbb") == 0);
}

static void simple2(t_test *test)
{
	t_lst	*lst_dst;
	t_lst	*lst_src;

	lst_dst = twl_lst_new();

	lst_src = twl_lst_new();
	twl_lst_push_back(lst_src, strdup("aaa"));
	twl_lst_push_back(lst_src, strdup("bbb"));
	twl_lst_push_back(lst_src, strdup("ccc"));
	twl_lst_push_back(lst_src, strdup("ddd"));

	twl_lst_extend_front(lst_dst, lst_src);

	mt_assert(twl_lst_len(lst_dst) == 4);
	mt_assert(strcmp(twl_lst_get(lst_dst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 3), "ddd") == 0);
}

static void simple3(t_test *test)
{
	t_lst	*lst_dst;
	t_lst	*lst_src;

	lst_dst = twl_lst_new();
	twl_lst_push_back(lst_dst, strdup("aaa"));
	twl_lst_push_back(lst_dst, strdup("bbb"));
	twl_lst_push_back(lst_dst, strdup("ccc"));
	twl_lst_push_back(lst_dst, strdup("ddd"));

	lst_src = twl_lst_new();

	twl_lst_extend_front(lst_dst, lst_src);

	mt_assert(twl_lst_len(lst_dst) == 4);
	mt_assert(strcmp(twl_lst_get(lst_dst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 2), "ccc") == 0);
	mt_assert(strcmp(twl_lst_get(lst_dst, 3), "ddd") == 0);
}

void	suite_twl_lst_extend_front(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, simple2);
	SUITE_ADD_TEST(suite, simple3);
}
