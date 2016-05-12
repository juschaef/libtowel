#include <project.h>
#include "twl_printf.h"

static void test_null(t_test *test)
{
	mt_assert(twl_strdup_or_null(NULL) == NULL);
}

static void test_string(t_test *test)
{
	mt_assert(strcmp(twl_strdup_or_null("ABC"), "ABC") == 0);
}

void	suite_twl_strdup_or_null(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_null);
	SUITE_ADD_TEST(suite, test_string);
}
