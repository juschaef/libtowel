#include <project.h>
#include "twl_printf.h"
#include "twl_arr.h"

static void simple_split(t_test *test)
{
	char **segs;

	segs = twl_strsplit_mul("1+2-3+4", "+-");
	mt_assert(strcmp(segs[0], "1") == 0);
	mt_assert(strcmp(segs[1], "2") == 0);
	mt_assert(strcmp(segs[2], "3") == 0);
	mt_assert(strcmp(segs[3], "4") == 0);
}

static void simple_split_border(t_test *test)
{
	char **segs;

	segs = twl_strsplit_mul("-1+2+", "+-");
	mt_assert(strcmp(segs[0], "1") == 0);
	mt_assert(strcmp(segs[1], "2") == 0);
	mt_assert(segs[2] == 0);
}

static void simple_split_border_end(t_test *test)
{
	char **segs;

	segs = twl_strsplit_mul("tout tout ", " \t");
	mt_assert(strcmp(segs[0], "tout") == 0);
	mt_assert(strcmp(segs[1], "tout") == 0);
	mt_assert(segs[2] == 0);
	mt_assert(twl_arr_len(segs) == 2);
	twl_arr_str_print(segs, "+");
}

void	suite_twl_strsplit_mul(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_split);
	SUITE_ADD_TEST(suite, simple_split_border);
	SUITE_ADD_TEST(suite, simple_split_border_end);
}
