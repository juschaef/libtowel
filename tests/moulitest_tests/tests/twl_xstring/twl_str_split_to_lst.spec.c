#include <project.h>
#include "twl_printf.h"

static void simple_split(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_to_lst("aaa bbb", ' ');
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "bbb") == 0);
}

static void simple_nothing(t_test *test)
{
	t_lst			*segs;

	segs = twl_str_split_to_lst("/", ' ');
	mt_assert(strcmp(twl_lst_get(segs, 0), "/") == 0);
}

void	suite_twl_str_split_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_split);
	SUITE_ADD_TEST(suite, simple_nothing);
}
