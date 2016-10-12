#include <project.h>
#include "twl_xstring.h"

#define DEBUG

#ifdef DEBUG
#define mt_test_str_replace_first(name, str, old, new, expected) \
static void	test_## name(t_test *test) \
{ \
	char	*actual = twl_str_replace_first(str, old, new); \
	printf("===== %s s/%s/%s/\n", str, old, new); \
	printf("actual   %s\n", actual); \
	printf("expected %s\n", expected); \
	mt_assert(strcmp(actual, expected) == 0); \
	free(actual); \
}
#else
#define mt_test_str_replace_first(name, str, old, new, expected) \
static void	test_## name(t_test *test) \
{ \
	char	*actual = twl_str_replace_first(str, old, new); \
	mt_assert(strcmp(actual, expected) == 0); \
	free(actual); \
}
#endif

mt_test_str_replace_first(num01, "Bonjour", "jour", "soir", "Bonsoir");
mt_test_str_replace_first(num02, "Bonjour", "o", "a", "Banjour");
mt_test_str_replace_first(num03, "Bonjour", "jour", "", "Bon");
mt_test_str_replace_first(num04, "Bonjour", "", "jour", "jourBonjour");
mt_test_str_replace_first(num05, "Bonjour", "nj", "asdasdasdasdasdasdasd", "Boasdasdasdasdasdasdasdour");

void	suite_twl_str_replace_first(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
}
