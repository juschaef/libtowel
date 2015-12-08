#include <project.h>
#include "twl_xstring.h"
#include "twl_string.h"

static void simple_strpos(t_test *test)
{
	char *str;

	str = twl_strdup("abcdefghi");
	mt_assert(twl_strpos(str, 'b') == 2);
	mt_assert(twl_strpos(str, 'i') == 9);
	mt_assert(twl_strpos(str, 0) == -1);
	mt_assert(twl_strpos(str, 'p') == -1);
}

void	suite_twl_strsplit(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_strpos);
}
