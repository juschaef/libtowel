#include <project.h>
#include "twl_printf.h"

static void simple_split(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_once_to_lst("aaa bbb ccc", " ");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "bbb ccc") == 0);
	mt_assert(twl_lst_len(segs) == 2);
	twl_lst_del(segs, free);
}

static void simple2_split(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_once_to_lst("aaa   bbb   ccc  ", " ");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "  bbb   ccc  ") == 0);
	mt_assert(twl_lst_len(segs) == 2);
	twl_lst_del(segs, free);
}

static void simple_equal_split(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_once_to_lst("aaa=bbb=ccc", "=");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "bbb=ccc") == 0);
	mt_assert(twl_lst_len(segs) == 2);
	twl_lst_del(segs, free);
}

static void simple_multi_split(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_once_to_lst("aaa/bbb=ccc", "=/");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "bbb=ccc") == 0);
	mt_assert(twl_lst_len(segs) == 2);
	twl_lst_del(segs, free);
}

static void simple_nothing(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_once_to_lst("/", " ");
	mt_assert(segs == NULL);
}

void	suite_twl_str_split_once_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_split);
	SUITE_ADD_TEST(suite, simple2_split);
	SUITE_ADD_TEST(suite, simple_equal_split);
	SUITE_ADD_TEST(suite, simple_multi_split);
	SUITE_ADD_TEST(suite, simple_nothing);
}
