#include <project.h>
#include "twl_stdlib.h"

#define mt_test_atof(test_name, tested_str) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(twl_atof(tested_str) == atof(tested_str)); \
	}

mt_test_atof(num1, "123.45");
mt_test_atof(num2, "999999999999.6666666666");
mt_test_atof(num3, "-42.21");

// static void positive_atof_simple(t_test *test)
// {
// 	mt_assert(twl_atof("123.45") == atof("123.45"));
// }

// static void positive_atof_larg_number(t_test *test)
// {
// 	mt_assert(twl_atof("999999999999.6666666666") == atof("999999999999.6666666666"));
// }

void	suite_twl_atof(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
