#include <project.h>
#include "twl_arr.h"

static void simple_test(t_test *test)
{
	char **arr;
	char **new_arr;

	arr = twl_arr_new(3);
	twl_arr_push(arr, "aaa");
	twl_arr_push(arr, "bbb");
	twl_arr_push(arr, "ccc");

	new_arr = twl_arr_cpy(arr);
	mt_assert(strcmp(new_arr[0], "aaa") == 0);
	mt_assert(strcmp(new_arr[1], "bbb") == 0);
	mt_assert(strcmp(new_arr[2], "ccc") == 0);
	mt_assert(twl_arr_len(new_arr) == 3);
}

void	suite_twl_arr_cpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
