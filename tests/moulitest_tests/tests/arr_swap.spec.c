#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = arr_init(3);
	arr_push(arr, "aaa");
	arr_push(arr, "bbb");
	arr_push(arr, "ccc");

	arr_swap(arr, 0, 2);
	mt_assert(strcmp(arr[0], "ccc") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "aaa") == 0);
	mt_assert(arr[3] == NULL);
}

void	suite_arr_swap(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
