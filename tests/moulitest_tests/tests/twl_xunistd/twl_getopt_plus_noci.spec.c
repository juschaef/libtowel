#include <project.h>
#define get_opt_test_macro(testname, argv_str, optstring, expected_optind, expected_optopt, expected, debug) \
	static void			testname(t_test *test) \
	{ \
		char			*actual; \
		optind = 1; \
		g_twl_optind = 0; \
		g_twl_optsign_active = 1; \
		g_twl_opterr = opterr = 0; \
		if (debug) \
			printf("\n======= %s\n", #testname); \
		actual = get_opt_testable_result(twl_getopt, &g_twl_optind, &g_twl_optopt, &g_twl_optarg, argv_str, optstring); \
		g_twl_optsign_active = 0; \
		if (debug) \
		{ \
			printf("input        {%s}\n", argv_str); \
			printf("expected     {%s}\n", expected); \
			printf("actual       {%s}\n", actual); \
			printf("optind       expected: %d       actual: %d\n", expected_optind, g_twl_optind); \
			printf("optopt       expected: %c       actual: %c\n", expected_optopt, g_twl_optopt); \
		} \
		mt_assert(twl_strcmp(expected, actual) == 0 \
			&& (g_twl_optind == expected_optind)); \
		free(actual); \
	}

get_opt_test_macro(test_opt, "ls -l -a arg1 arg2", "la:", 4, 'a',
	"ls   -l(ind=2)(opt=l)   -a(ind=4)(opt=a)(arg=arg1)   arg2", false);
get_opt_test_macro(test_opt_plus, "ls +l +a arg1 arg2", "la:", 4, 'a',
	"ls   +l(ind=2)(opt=l)   +a(ind=4)(opt=a)(arg=arg1)   arg2", false);
get_opt_test_macro(test_opt_o, "ls +o arg1 arg2", "o:", 3, 'a',
	"ls   +o(ind=3)(opt=o)(arg=arg1)   arg2", false);
get_opt_test_macro(test_opt_plus_o_without_arg, "ls +o", "o:", 1, 'a',
	"ls   +o", false);
get_opt_test_macro(test_opt_minus_o_without_arg, "ls -o errexit -o bbb arg", "o:", 5, 'a',
	"ls   -o(ind=3)(opt=o)(arg=errexit)   -o(ind=5)(opt=o)(arg=bbb)   arg", false);
get_opt_test_macro(test_opt_o_one_arg, "ls +o arg1", "o:", 3, 'a',
	"ls   +o(ind=3)(opt=o)(arg=arg1)", false);
get_opt_test_macro(test_hyphen_dashdash, "cmd -a --", ":a:bc", 3, 'a',
	"cmd   -a(ind=3)(opt=a)(arg=--)", false);
get_opt_test_macro(test_multi_missing, "cmd -a -a", "a:", 3, 'a',
	"cmd   -a(ind=3)(opt=a)(arg=-a)", false);
get_opt_test_macro(test_dashdash_as_opt_arg, "cmd -a --", "a:", 3, 'a',
	"cmd   -a(ind=3)(opt=a)(arg=--)", false);

void	suite_twl_getopt_plus_noci(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_opt);
	SUITE_ADD_TEST(suite, test_opt_plus);
	SUITE_ADD_TEST(suite, test_opt_o);
	SUITE_ADD_TEST(suite, test_opt_plus_o_without_arg);
	SUITE_ADD_TEST(suite, test_opt_minus_o_without_arg);
	SUITE_ADD_TEST(suite, test_opt_o_one_arg);

	SUITE_ADD_TEST(suite, test_hyphen_dashdash);
	SUITE_ADD_TEST(suite, test_multi_missing);
	SUITE_ADD_TEST(suite, test_dashdash_as_opt_arg);
}
