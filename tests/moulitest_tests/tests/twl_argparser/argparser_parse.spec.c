#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

static void simple_test(t_test *test)
{
	t_argparser		*argparser;

	argparser = argparser_new("42sh");
	argparser_add_argument(argparser, argparser_argument_new('n', NULL, "No newline", 0));
	argparser_add_argument(argparser, argparser_argument_new('m', NULL, "M opt", 0));
	// argparser_print_help(argparser);

	t_lst *segs = twl_str_split_to_lst("echo -n -m abc", " ");
	t_argparser_result *result = argparser_parse(argparser, segs);
	mt_assert(twl_lst_len(result->result_items) == 2);
	mt_assert(argparser_result_char_opt_is_set(result, 'n') == true);
	mt_assert(argparser_result_char_opt_is_set(result, 'm') == true);
	mt_assert(argparser_result_char_opt_is_set(result, 'y') == false);
	mt_assert(argparser_result_char_opt_is_set(result, 'z') == false);
}

void	suite_argparser_parse(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
