#include <project.h>
#include <twl_printf.h>

static void simple_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrim("  hello  "), "hello") == 0);
}

static void complex_trim(t_test *test)
{
	mt_assert(strcmp(twl_strtrim(" \n\t\n hello \n\n\n\t  "), "hello") == 0);
}

void	suite_twl_strtrim(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_trim);
	SUITE_ADD_TEST(suite, complex_trim);
}
