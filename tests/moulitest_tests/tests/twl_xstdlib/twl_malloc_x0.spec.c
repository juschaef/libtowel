#include <project.h>
#include <twl_xstdlib.h>
#include <string.h>

static void simple_test(t_test *test)
{
	char *str;
	char control[10];

	bzero(control, 10);
	str = twl_malloc_x0(10);
	mt_assert(memcmp(str, control, 10) == 0);
	free(str);
}

void	suite_twl_malloc_x0(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
