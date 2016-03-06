#include <project.h>
#include "twl_arr2.h"

#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

static void demo_working_case(t_test *test)
{
	t_argparser		*argparser;

	argparser = argparser_new("some_command");
	argparser_add_argument(argparser, argparser_argument_new('e', NULL, "Enabled", 0));
	argparser_add_argument(argparser, argparser_argument_new(0, "dry-run", "Dry Run", 0));
	argparser_add_argument(argparser, argparser_argument_new('f', "force", "Force", 0));
	argparser_add_argument(argparser, argparser_argument_new('t', "time", "Set time", 0));
	argparser_add_argument(argparser, argparser_argument_new('d', "date", "Set date", ARGP_HAS_OPTION_ARGUMENT));

	/*
		To print help:
		argparser_print_help(argparser);
	*/

	mt_assert(strcmp(argparser_get_help_str(argparser),
		"usage: some_command [-eftd]\n"
		"  -e                            Enabled\n"
		"  --dry-run                     Dry Run\n"
		"  -f, --force                   Force\n"
		"  -t, --time                    Set time\n"
        "  -d arg, --date arg            Set date\n") == 0);

	t_lst *segs = twl_str_split_to_lst("echo -e --dry-run -d 01-01-2042 arg1 arg2 arg3", " ");
	t_argparser_result *result = argparser_parse(argparser, segs);

	mt_assert(argparser_result_opt_is_set(result, "e") == true);
	mt_assert(argparser_result_opt_is_set(result, "E") == false);
	mt_assert(argparser_result_opt_is_set(result, "dry-run") == true);
	mt_assert(strcmp(argparser_result_opt_get_arg(result, "date"), "01-01-2042") == 0);

	char *remainders_str = twl_lst_strjoin(result->remainders, ",");
	mt_assert(strcmp(remainders_str, "arg1,arg2,arg3") == 0);

	twl_lst_del(segs, free);
	argparser_del(argparser);
	argparser_result_del(result);
}

void	suite_argparser_demo(t_suite *suite)
{
	SUITE_ADD_TEST(suite, demo_working_case);
}
