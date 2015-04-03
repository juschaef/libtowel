#include <project.h>
#include "twl_printf.h"

static void success(t_test *test)
{
	mt_assert(twl_strnequ("abd", "abc", 2) == true);
}

static void not_equal(t_test *test)
{
	mt_assert(twl_strnequ("abdee", "abcee", 3) == false);
}

void	suite_twl_strnequ(t_suite *suite)
{
	SUITE_ADD_TEST(suite, success);
	SUITE_ADD_TEST(suite, not_equal);
}
