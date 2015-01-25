#include <project.h>
#include <twl_xstring.h>

static void simple_test(t_test *test)
{
	char s[] = "jambonbon";

	twl_str_replace_char(s, 'n', 'm');
	twl_str_replace_char(s, 'o', '0');

	mt_assert(strcmp(s, "jamb0mb0m") == 0);
}

void	suite_twl_str_replace_char(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
