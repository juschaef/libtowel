#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = arr_init(3);
	arr_push(arr, "aaa");
	arr_push(arr, "bbb");
	arr_push(arr, "ccc");

	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	mt_assert(arr[3] == NULL);
	free(arr);
}

void	suite_arr_init(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
