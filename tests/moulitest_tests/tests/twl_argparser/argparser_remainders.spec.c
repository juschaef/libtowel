#include <project.h>
#include "twl_arr2.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

#define mt_test_arg_parse_result_is_set(test_name, input, expected_reminder, debug) \
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
			argparser_result_print_debug(result); \
			printf("============================================================\n"); \
		} \
		char *remainders_str = twl_lst_strjoin(result->remainders, "|"); \
		mt_assert(strcmp(remainders_str, expected_reminder) == 0); \
		twl_lst_del(segs, free); \
		argparser_del(argparser); \
		argparser_result_del(result); \
	}

mt_test_arg_parse_result_is_set(01, "echo -n -m aa bb", "aa|bb", false);
mt_test_arg_parse_result_is_set(02, "echo -n -m", "", false);
mt_test_arg_parse_result_is_set(03, "echo bb ccc", "bb|ccc", false);
mt_test_arg_parse_result_is_set(04, "echo -- -n", "-n", false);
mt_test_arg_parse_result_is_set(05, "echo -- aa -m", "aa|-m", false);
mt_test_arg_parse_result_is_set(06, "echo -- -n --zzz xxx", "-n|--zzz|xxx", false);

void	suite_argparser_remainders(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
}
