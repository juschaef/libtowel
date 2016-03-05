#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"

static void simple_test(t_test *test)
{
	t_argparser		*argparser;

	// segs = twl_str_split_to_lst("echo -n abc", " ");
	argparser = argparser_new("42sh");
	argparser_add_argument(argparser, argparser_argument_new('f', "force", "Force", 0));
	argparser_add_argument(argparser, argparser_argument_new('t', "time", "Set time", 0));
	argparser_add_argument(argparser, argparser_argument_new('d', "date", "Set date", 0));
	// mt_assert(twl_lst_len(argparser->arguments) == 2);
	argparser_print_help(argparser);
	mt_assert(strcmp(argparser_get_help_str(argparser),
		"usage: 42sh [-td]\n"
		"  -f, --force                   Force\n"
		"  -t, --time                    Set time\n"
        "  -d, --date                    Set date\n") == 0);
}

void	suite_twl_argparser_tests(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
