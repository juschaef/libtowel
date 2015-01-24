#include <project.h>
#include <arr.h>

static void simple_test(t_test *test)
{
	char *arr[4];

	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	char *last;

	last = (char *)twl_arr_last(arr);
	mt_assert(strcmp(last, "ccc") == 0);
}

void	suite_twl_arr_last(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
