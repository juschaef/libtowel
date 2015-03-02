#include <project.h>
#include "twl_arr.h"

static void iter_fn(void *elem, void *context)
{
	char *str;

	str = elem;
	*str = *str + 1;
	(void)context;
}

static void simple_test(t_test *test)
{
	char *arr[4];

	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	twl_arr_iter(arr, iter_fn, NULL);

	mt_assert(strcmp(arr[0], "baa") == 0);
	mt_assert(strcmp(arr[1], "cbb") == 0);
	mt_assert(strcmp(arr[2], "dcc") == 0);
	mt_assert(arr[3] == 0);
}

void	suite_twl_arr_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
