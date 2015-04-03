#include <project.h>
#include "twl_printf.h"

static void success(t_test *test)
{
	mt_assert(twl_str_starts_with("abd", "ab") == true);
}

static void not_equal(t_test *test)
{
	mt_assert(twl_str_starts_with("abdee", "z") == false);
}

void	suite_twl_str_starts_with(t_suite *suite)
{
	SUITE_ADD_TEST(suite, success);
	SUITE_ADD_TEST(suite, not_equal);
}
