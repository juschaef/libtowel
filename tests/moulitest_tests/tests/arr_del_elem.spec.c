#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char **arr;

	arr = arr_init(3);
	arr_push(arr, "aaa");
	arr_push(arr, "bbb");
	arr_push(arr, "ccc");

	mt_assert(arr_len(arr) == 3);
	arr_del_elem(arr, 0);
	mt_assert(arr_len(arr) == 2);
}

void	suite_arr_del_elem(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
