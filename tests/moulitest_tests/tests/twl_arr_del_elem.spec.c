#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_init(3);
	twl_arr_push(arr, "aaa");
	twl_arr_push(arr, "bbb");
	twl_arr_push(arr, "ccc");

	mt_assert(twl_arr_len(arr) == 3);
	twl_arr_del_elem(arr, 0);
	mt_assert(twl_arr_len(arr) == 2);
}

void	suite_twl_arr_del_elem(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
