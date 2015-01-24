#include <project.h>
#include <twl_arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_init(3);
	twl_arr_push(arr, "aaa");
	twl_arr_push(arr, "bbb");
	twl_arr_push(arr, "ccc");

	twl_arr_swap(arr, 0, 2);
	mt_assert(strcmp(arr[0], "ccc") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "aaa") == 0);
	mt_assert(arr[3] == NULL);
}

void	suite_twl_arr_swap(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
