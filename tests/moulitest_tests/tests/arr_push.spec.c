#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char *arr[4];

	arr[0] = strdup("aaa");
	arr[2] = NULL;

	arr_push(arr, "bbb");
	arr_push(arr, "ccc");
	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	mt_assert(arr[3] == NULL);
}

static void simple_push_empty_arr(t_test *test)
{
	char **arr;

	arr = arr_init(3);
	arr_push(arr, "aaa");
	arr_push(arr, "bbb");

	mt_assert(arr[3] == NULL);
	mt_assert(arr_len(arr) == 2);
}

void	suite_arr_push(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_push_empty_arr);
}
