#include <project.h>
#include <twl_arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_new(3);
	twl_arr_push(arr, "aaa");
	twl_arr_push(arr, "bbb");
	twl_arr_push(arr, "ccc");

	mt_assert(twl_arr_len(arr) == 3);
	twl_arr_delone(arr, 0);
	mt_assert(twl_arr_len(arr) == 2);
	mt_assert(strcmp(arr[0], "bbb") == 0);
	mt_assert(strcmp(arr[1], "ccc") == 0);
	mt_assert(arr[2] == NULL);
}

static void simple_test2(t_test *test)
{
	char **arr;

	arr = twl_arr_new(1);
	twl_arr_push(arr, "aaa");

	twl_arr_delone(arr, 0);

	mt_assert(arr[0] == NULL);
}

void	suite_twl_arr_delone(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
