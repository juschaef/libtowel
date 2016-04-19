#include <project.h>
#include "twl_arr.h"
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

#define mt_test_arg_parse_result_is_set(test_name, input, tested_opt, expected_result, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_argparser		*argparser; \
		argparser = argparser_new("42sh"); \
		argparser_add_argument(argparser, argparser_argument_new('n', "newline", "No newline", 0)); \
		argparser_add_argument(argparser, argparser_argument_new('m', "module", "m opt", 0)); \
		argparser_add_argument(argparser, argparser_argument_new('o', "order", "o opt", 0)); \
		argparser_add_argument(argparser, argparser_argument_new('c', "command", "c command", 0)); \
		char **segs = twl_strsplit(input, ' '); \
		t_argparser_result *result = argparser_parse_from_arr(argparser, segs); \
		if (debug) \
		{ \
			printf("=== help ===================================================\n"); \
			argparser_print_help(argparser); \
			printf("=== result =================================================\n"); \
			argparser_result_print_debug(result); \
			printf("============================================================\n"); \
		} \
		mt_assert(argparser_result_opt_is_set(result, tested_opt) == expected_result); \
		argparser_del(argparser); \
		argparser_result_del(result); \
		twl_arr_del(segs, free); \
	}

mt_test_arg_parse_result_is_set(01, "echo -n -m abc", "n", true, false);
mt_test_arg_parse_result_is_set(02, "echo -n -m abc", "m", true, false);
mt_test_arg_parse_result_is_set(03, "echo -n -m abc", "y", false, false);
mt_test_arg_parse_result_is_set(04, "echo -n -m abc", "z", false, false);

void	suite_argparser_opt_is_set(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
}
