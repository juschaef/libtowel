#include <project.h>
#include <math.h>

#include "twl_math.h"

static void test_simple(t_test *test)
{
	mt_assert(twl_sqrt(25.0) == 5.0);
}

static void test_sqrt_2(t_test *test)
{
	mt_assert(fabs(twl_sqrt(2.0) - sqrt(2.0)) < 0.0000000001);
}


static void test_sqrt_dec(t_test *test)
{
	// printf("%.20lf\n%.20lf\n%.20lf\n", twl_sqrt(154.56), sqrt(154.56), twl_sqrt(154.56) - sqrt(154.56));
	mt_assert(fabs(twl_sqrt(154.56) - sqrt(154.56)) < 0.0000000001);
}

void	suite_twl_sqrt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_sqrt_2);
	SUITE_ADD_TEST(suite, test_sqrt_dec);
}
