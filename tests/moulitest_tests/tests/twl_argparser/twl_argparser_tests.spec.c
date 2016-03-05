#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"

static void simple_test(t_test *test)
{
	t_argparser		*argparser;
	t_lst			*segs;

	segs = twl_str_split_to_lst("echo -n abc", " ");
	argparser = argparser_new(segs);
	argparser_add_item(argparser, argparser_item_new('t', "time", "This is time"));
	mt_assert(10 == 25);
	twl_lst_del(segs, free);
}

void	suite_twl_argparser_tests(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
