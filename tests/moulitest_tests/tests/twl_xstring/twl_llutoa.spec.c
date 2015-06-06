#include <project.h>
#include <limits.h>
#include "twl_xstring.h"

static void test1(t_test *test)
{
	mt_assert(strcmp(twl_llutoa(0L), "0") == 0);
}

static void test2(t_test *test)
{
	mt_assert(strcmp(twl_llutoa(1L), "1") == 0);
}

static void test3(t_test *test)
{
	mt_assert(strcmp(twl_llutoa(42L), "42") == 0);
}

static void test4(t_test *test)
{
	mt_assert(strcmp(twl_llutoa(ULLONG_MAX), "18446744073709551615") == 0);
}

void	suite_twl_llutoa(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
}
