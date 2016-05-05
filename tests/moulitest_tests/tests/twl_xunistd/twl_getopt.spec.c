#include <project.h>
#include "twl_xunistd.h"
#include "twl_xstring.h"
#include "twl_arr.h"

static char			*get_opt_testable_result(
	t_test *test,
	int (getopt_fn)(int argc, char * const argv[], const char *optstring),
	int				*optind_ptr,
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
		asprintf(&result, "%s_-%c", tmp, getopt_c);
		free(tmp);
	}
	remain = argv + *optind_ptr;
	while (*remain)
	{
		tmp = result;
		asprintf(&result, "%s_%s", tmp, *remain);
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
		g_twl_optind = optind = 1; \
		expected = get_opt_testable_result(test, getopt, &optind, argv_str, optstring); \
		actual = get_opt_testable_result(test, twl_getopt, &g_twl_optind, argv_str, optstring); \
		if (debug) \
		{ \
			printf("\n======= case {%s}\n", argv_str); \
			printf("expected     {%s}\n", expected); \
			printf("actual       {%s}\n", actual); \
			printf("g_twl_optind %d\n", g_twl_optind); \
			printf("optind       %d\n", optind); \
			printf("optopt       %c\n", optopt); \
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

void	suite_twl_getopt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_opt);
	SUITE_ADD_TEST(suite, test_opt_and_optarg);
	SUITE_ADD_TEST(suite, test_optarg);
	SUITE_ADD_TEST(suite, test_grouped_opt);
}

