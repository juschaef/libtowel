#include <project.h>
#include "twl_arr.h"

static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_new(3);
	twl_arr_push(arr, "aaa");
	twl_arr_push(arr, "bbb");
	twl_arr_push(arr, "ccc");

	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	mt_assert(arr[3] == NULL);
	twl_arr_del(arr, NULL);
}

void	suite_twl_arr_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
