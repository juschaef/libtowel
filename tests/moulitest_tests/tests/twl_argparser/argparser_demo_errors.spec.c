#include <project.h>
#include "twl_arr2.h"

#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

static void demo_errors(t_test *test)
{
	t_argparser		*argparser;
	t_lst *segs;
	t_argparser_result *result;

	argparser = argparser_new("42sh");
	argparser_add_argument(argparser, argparser_argument_new('e', "enabled", "Enabled", 0));
	argparser_add_argument(argparser, argparser_argument_new('d', "date", "Set date", ARGP_HAS_OPTION_ARGUMENT));

	/*
		error result is store in `result->err_msg`
		the value is NULL if there is no error
	*/

	/* illegal option */

	segs = twl_str_split_to_lst("-m -e", " ");
	result = argparser_parse(argparser, segs);
	mt_assert(strcmp(result->err_msg, "illegal option: m") == 0);
	twl_lst_del(segs, free);

	/* missing option */
	segs = twl_str_split_to_lst("-d", " ");
	result = argparser_parse(argparser, segs);
	mt_assert(strcmp(result->err_msg, "value required: d") == 0);

	twl_lst_del(segs, free);
	argparser_del(argparser);
	argparser_result_del(result);
}

void	suite_argparser_demo_errors(t_suite *suite)
{
	SUITE_ADD_TEST(suite, demo_errors);
}
