#include <project.h>
#include "twl_printf.h"

static void simple_split(t_test *test)
{
	char **segs;

	segs = twl_strsplit("aaa bbb", ' ');
	mt_assert(strcmp(segs[0], "aaa") == 0);
	mt_assert(strcmp(segs[1], "bbb") == 0);
}

static void simple_nothing(t_test *test)
{
	char **segs;

	segs = malloc(9999);
	bzero(segs, 99999);
	segs = twl_strsplit("/", ' ');
	mt_assert(strcmp(segs[0], "/") == 0);
}

void	suite_twl_strsplit(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_split);
	SUITE_ADD_TEST(suite, simple_nothing);
}
