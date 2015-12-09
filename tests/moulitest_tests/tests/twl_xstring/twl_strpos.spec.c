#include <project.h>
#include "twl_printf.h"
#include "twl_xstring.h"

static void simple_strpos(t_test *test)
{
	char *str;

	str = strdup("abcdefghi");
	mt_assert(twl_strpos(str, 'b') == 2);
	mt_assert(twl_strpos(str, '\033') == -1);
	mt_assert(twl_strpos(str, 'i') == 9);
	mt_assert(twl_strpos(str, 0) == -1);
	mt_assert(twl_strpos(str, 'p') == -1);
	mt_assert(twl_strpos(str, 'a') == 1);
	free(str);
}

void	suite_twl_strpos(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_strpos);
}
