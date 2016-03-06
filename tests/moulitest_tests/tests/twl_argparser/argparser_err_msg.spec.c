#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

#define mt_test_arg_parse_result_is_set(test_name, input, expected_err_msg, debug) \
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
			argparser_result_print(result); \
			printf("============================================================\n"); \
		} \
		if (result->err_msg) \
		{ \
			mt_assert(strcmp(result->err_msg, expected_err_msg) == 0); \
		} \
		else \
		{ \
			mt_assert(result->err_msg == expected_err_msg); \
		} \
		twl_lst_del(segs, free); \
	}

mt_test_arg_parse_result_is_set(01, "echo -n -m abc", NULL, false);
mt_test_arg_parse_result_is_set(02, "echo -n -m abc -z --zoo abc", "illegal option: z", false);
mt_test_arg_parse_result_is_set(03, "echo -nma", "illegal option: a", false);
mt_test_arg_parse_result_is_set(04, "echo ---abc", "illegal option: -abc", false);
mt_test_arg_parse_result_is_set(05, "echo -module", "illegal option: o", false);
mt_test_arg_parse_result_is_set(06, "echo -m", "value required: m", false);
mt_test_arg_parse_result_is_set(07, "echo -m -n", "value required: m", false);

void	suite_argparser_err_msg(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	// SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
	SUITE_ADD_TEST(suite, test_07);
}
