#include <project.h>
#include "twl_xstring.h"
#include "twl_xstdio.h"

static void test_simple(t_test *test)
{
	char			cmd[500];
	char			*control_str = "abc1234242";
	char			*filename = "/tmp/twl_file_to_str.test_file";

	sprintf(cmd, "echo '%s' > %s", control_str, filename);
	system(cmd);
	mt_assert(strcmp(twl_strtrim(twl_file_to_str(filename)), control_str) == 0);
}

static void test_error(t_test *test)
{
	mt_assert(twl_file_to_str("/tmp/blablabla_not_exist") == 0);
}

void	suite_twl_file_to_str(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_error);
}
