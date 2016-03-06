#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

#define mt_test_arg_parse_result_is_set(test_name, input, tested_opt, expected_result, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_argparser		*argparser; \
		argparser = argparser_new("42sh"); \
		argparser_add_argument(argparser, argparser_argument_new('n', "newline", "No newline", 0)); \
		argparser_add_argument(argparser, argparser_argument_new('m', "module", "M opt", 0)); \
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
		mt_assert(argparser_result_opt_is_set(result, tested_opt) == expected_result); \
	}

mt_test_arg_parse_result_is_set(01, "echo -n -m abc", "n", true, false);
mt_test_arg_parse_result_is_set(02, "echo -n -m abc", "m", true, false);
mt_test_arg_parse_result_is_set(03, "echo -n -m abc", "y", false, false);
mt_test_arg_parse_result_is_set(04, "echo -n -m abc", "z", false, false);
mt_test_arg_parse_result_is_set(05, "echo -n -m abc", "newline", true, false);
mt_test_arg_parse_result_is_set(06, "echo -n -m abc", "module", true, false);
mt_test_arg_parse_result_is_set(07, "echo -n -m abc", "not_exist", false, false);
mt_test_arg_parse_result_is_set(08, "echo --module", "m", true, false);
mt_test_arg_parse_result_is_set(09, "echo --module", "module", true, false);
mt_test_arg_parse_result_is_set(10, "echo ---module", "module", false, false);
mt_test_arg_parse_result_is_set(11, "echo -- --module", "module", false, false);
mt_test_arg_parse_result_is_set(12, "echo -n -- --module", "n", true, false);
mt_test_arg_parse_result_is_set(13, "echo -n -- --module", "module", false, false);
mt_test_arg_parse_result_is_set(14, "echo -n --module", "module", true, false);

void	suite_argparser_opt_is_set(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
	SUITE_ADD_TEST(suite, test_07);
	SUITE_ADD_TEST(suite, test_08);
	SUITE_ADD_TEST(suite, test_09);
	SUITE_ADD_TEST(suite, test_10);
	SUITE_ADD_TEST(suite, test_11);
	SUITE_ADD_TEST(suite, test_12);
	SUITE_ADD_TEST(suite, test_13);
	SUITE_ADD_TEST(suite, test_14);
}
