#include <project.h>
#include "twl_unistd.h"
#include "twl_xstring.h"
#include "twl_arr.h"

static char			*get_opt_testable_result(
	t_test *test,
	int (getopt_fn)(int argc, char * const argv[], const char *optstring),
	int				*optind_ptr,
	int				*optopt_ptr,
	char			**optarg_ptr,
	char *argv_str, char *optstring)
{
	char			**argv;
	char			**remain;
	int				argc;
	char			getopt_c;
	char			*result;
	char			*tmp;

	argv = twl_strsplit(argv_str, ' ');
	argc = twl_arr_len(argv) - 1;
	result = twl_strdup(argv[0]);
	while ((getopt_c = getopt_fn(argc, argv, optstring)) != -1)
	{
		tmp = result;
		asprintf(&result, "%s   -%c", tmp, getopt_c);
		free(tmp);
		tmp = result;
		asprintf(&result, "%s(opt=%c)", tmp, *optopt_ptr);
		free(tmp);
		if (*optarg_ptr)
		{
			tmp = result;
			asprintf(&result, "%s(arg=%s)", tmp, *optarg_ptr);
			free(tmp);
		}
	}
	remain = argv + *optind_ptr;
	while (*remain)
	{
		tmp = result;
		asprintf(&result, "%s   %s", tmp, *remain);
		free(tmp);
		remain++;
	}
	twl_arr_del(argv, free);
	return (result);
}

#define get_opt_test_macro(testname, argv_str, optstring, debug) \
	static void			testname(t_test *test) \
	{ \
		char			*expected; \
		char			*actual; \
		optind = 1; \
		g_twl_optind = 0; \
		g_twl_opterr = opterr = 0; \
		if (debug) \
			printf("\n======= %s\n", #testname); \
		expected = get_opt_testable_result(test, getopt,     &optind,       &optopt,       &optarg,       argv_str, optstring); \
		actual = get_opt_testable_result(test,   twl_getopt, &g_twl_optind, &g_twl_optopt, &g_twl_optarg, argv_str, optstring); \
		if (debug) \
		{ \
			printf("input        {%s}\n", argv_str); \
			printf("expected     {%s}\n", expected); \
			printf("actual       {%s}\n", actual); \
			printf("optind       expected: %d       actual: %d\n", optind, g_twl_optind); \
			printf("optopt       expected: %c       actual: %c\n", optopt, g_twl_optopt); \
		} \
		mt_assert(twl_strcmp(expected, actual) == 0 \
			&& (g_twl_optind == optind)); \
		free(actual); \
		free(expected); \
	}

get_opt_test_macro(test_opt, "ls -l -a", "la", true);
get_opt_test_macro(test_opt_and_optarg, "ls -l -a arg1 arg2", "la", true);
get_opt_test_macro(test_optarg, "ls arg1 arg2", "la", true);
get_opt_test_macro(test_grouped_opt, "ls -s -sasb arg1 arg2", "abs", true);
get_opt_test_macro(test_double_dash, "ls -s -- -a arg1", "abs", true);
get_opt_test_macro(test_double_dash_end, "ls -s --", "abs", true);
get_opt_test_macro(test_double_dash_alone, "ls --", "abs", true);
get_opt_test_macro(test_no_args, "ls", "abs", true);
get_opt_test_macro(test_opt_after_no_opt, "ls -a b -a", "abs", true);
get_opt_test_macro(test_invalid_opt, "ls -a -xyz arg1 arg2", "abc", true);
get_opt_test_macro(test_opt_arg, "ls -a arg1 arg2", "a:bs", true);
get_opt_test_macro(test_opt_arg_second, "ls -b -a arg1 arg2", "a:bs", true);
get_opt_test_macro(test_opt_arg_middle, "ls -b -bas arg1 arg2", "a:bs", true);
get_opt_test_macro(test_opt_arg_middle2, "ls -b -ba arg1 arg2", "a:bs", true);
get_opt_test_macro(test_opt_arg_attached, "ls -a123 arg1 arg2", "a:bs", true);
get_opt_test_macro(test_opt_arg_missing, "ls -a -b", "a:b:s", true);
get_opt_test_macro(test_opt_arg_missing_a, "ls -a", "a:", true);
get_opt_test_macro(test_opt_arg_missing_aa, "ls -a -a", "a:", true);
get_opt_test_macro(test_opt_arg_missing_aaa, "ls -a -a -a", "a:", true);
get_opt_test_macro(test_opt_arg_missing_colon, "ls -b -a", ":a:b:s", true);
get_opt_test_macro(test_opt_arg_missing_colon2, "ls -b -a arg1", ":ab:s", true);
get_opt_test_macro(test_opt_arg_missing_double_hyphen, "ls -b --", "b:", true);
get_opt_test_macro(test_opt_arg_missing_double_hyphen2, "ls -b --", ":b:", true);
get_opt_test_macro(test_opt_arg_hyphen_folows, "ls -a -b arg1 arg2", "a:bs", true);
get_opt_test_macro(test_posix_example1, "cmd -ao arg path path", ":abf:o:", true);
get_opt_test_macro(test_posix_example2, "cmd -a -o arg path path", ":abf:o:", true);
get_opt_test_macro(test_posix_example3, "cmd -o arg -a path path", ":abf:o:", true);
get_opt_test_macro(test_posix_example4, "cmd -a -o arg -- path path", ":abf:o:", true);
get_opt_test_macro(test_posix_example5, "cmd -a -oarg path path", ":abf:o:", true);
get_opt_test_macro(test_posix_example6, "cmd -aoarg path path", ":abf:o:", true);
get_opt_test_macro(test_digit_opt, "cmd -1 -2 -3 args", "123", true);
get_opt_test_macro(test_digit_multi_opt, "cmd -11 -22 -33 args", "123", true);
get_opt_test_macro(test_vendor_W, "cmd -Wextra arg1", "W:", true);

void	suite_twl_getopt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_opt);
	SUITE_ADD_TEST(suite, test_opt_and_optarg);
	SUITE_ADD_TEST(suite, test_optarg);
	SUITE_ADD_TEST(suite, test_grouped_opt);
	SUITE_ADD_TEST(suite, test_double_dash);
	SUITE_ADD_TEST(suite, test_double_dash_end);
	SUITE_ADD_TEST(suite, test_double_dash_alone);
	SUITE_ADD_TEST(suite, test_no_args);
	SUITE_ADD_TEST(suite, test_opt_after_no_opt);
	SUITE_ADD_TEST(suite, test_invalid_opt);
	SUITE_ADD_TEST(suite, test_opt_arg);
	SUITE_ADD_TEST(suite, test_opt_arg_second);
	SUITE_ADD_TEST(suite, test_opt_arg_middle);
	SUITE_ADD_TEST(suite, test_opt_arg_middle2);
	SUITE_ADD_TEST(suite, test_opt_arg_attached);
	SUITE_ADD_TEST(suite, test_opt_arg_missing);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_a);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_aa);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_aaa);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_colon);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_colon2);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_double_hyphen);
	SUITE_ADD_TEST(suite, test_opt_arg_missing_double_hyphen2);
	SUITE_ADD_TEST(suite, test_opt_arg_hyphen_folows);
	SUITE_ADD_TEST(suite, test_posix_example1);
	SUITE_ADD_TEST(suite, test_posix_example2);
	SUITE_ADD_TEST(suite, test_posix_example3);
	SUITE_ADD_TEST(suite, test_posix_example4);
	SUITE_ADD_TEST(suite, test_posix_example5);
	SUITE_ADD_TEST(suite, test_posix_example6);
	SUITE_ADD_TEST(suite, test_digit_opt);
	SUITE_ADD_TEST(suite, test_digit_multi_opt);
	SUITE_ADD_TEST(suite, test_vendor_W);
}
