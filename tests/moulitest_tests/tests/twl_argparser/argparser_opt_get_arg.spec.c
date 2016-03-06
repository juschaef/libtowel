#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

#define mt_test_arg_parse_result_get_arg(test_name, input, tested_opt, expected_result, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_argparser		*argparser; \
		argparser = argparser_new("42sh"); \
		argparser_add_argument(argparser, argparser_argument_new('n', "newline", "No newline", 0)); \
		argparser_add_argument(argparser, argparser_argument_new('m', "module", "M opt", ARGP_HAS_OPTION_ARGUMENT)); \
		t_lst *segs = twl_str_split_to_lst(input, " "); \
		t_argparser_result *result = argparser_parse(argparser, segs); \
		if (debug) \
		{ \
			printf("=== help ===================================================\n"); \
			argparser_print_help(argparser); \
			printf("=== result =================================================\n"); \
			argparser_result_print_debug(result); \
			printf("============================================================\n"); \
		} \
		char *arg = argparser_result_opt_get_arg(result, tested_opt); \
		if (arg) \
		{ \
			mt_assert(strcmp(arg, expected_result) == 0); \
		} \
		else \
		{ \
			mt_assert(arg == expected_result); \
		} \
		argparser_del(argparser); \
		argparser_result_del(result); \
	}

mt_test_arg_parse_result_get_arg(01, "echo -n -m abc 123", "m", "abc", false);
mt_test_arg_parse_result_get_arg(02, "echo -m aaa -m bbb", "m", "aaa", false);

void	suite_argparser_opt_get_arg(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
