#include <project.h>
#include "twl_malloc.h"

static void simple_test(t_test *test)
{
	char *str;

	str = twl_malloc(sizeof(char) * 5);
	strcpy(str, "1234");
	mt_assert(strcmp(str, "1234") == 0);
	// twl_show_alloc_mem();
}

void	suite_twl_malloc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
