#include <project.h>
#include "twl_string.h"

#define mt_test_strrchr(name, str_, c, debug)	\
static void test_## name(t_test *test)			\
{												\
	char	*str = str_;						\
	char	*actual = twl_strrchr(str, c);		\
	char	*expected = strrchr(str, c);		\
	if (debug)									\
	{											\
		printf("case: %s find %i (%c)\n", str, c, c);	\
		printf("actual: %s\n", actual);			\
		printf("expected: %s\n", expected);		\
	}											\
	mt_assert(actual == expected);				\
}

mt_test_strrchr(num1, "abcdefghijklmnopqrstuvwxyz", '\0', false);
mt_test_strrchr(num2, "abcdefghijklmnopqrstuvwxyz", 'z', false);
mt_test_strrchr(num3, "abcdefghijklmnopqrstuvwxyz", 'a', false);
mt_test_strrchr(num4, "abcdefghijklmnopqrstuvwxyz", '0', false);
mt_test_strrchr(num5, "0123" + 1, '0', false);

void	suite_twl_strrchr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
}
