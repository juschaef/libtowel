#include <project.h>
#include "twl_xunistd.h"
#include "twl_xstring.h"
#include "twl_arr.h"

static char			*get_opt_testable_result(
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
		expected = get_opt_testable_result(getopt, &optind, argv_str, optstring); \
		actual = get_opt_testable_result(twl_getopt, &g_twl_optind, argv_str, optstring); \
		if (debug) \
		{ \
			printf("argv_str {%s}\n", argv_str); \
			printf("expected {%s}\n", expected); \
			printf("actual   {%s}\n", actual); \
		} \
		mt_assert(twl_strcmp(expected, actual) == 0); \
		free(actual); \
		free(expected); \
	}

get_opt_test_macro(simple_test, "ls -l -a abc", "la", false);

void	suite_twl_getopt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

