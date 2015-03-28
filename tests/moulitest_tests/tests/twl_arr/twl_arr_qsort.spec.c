#include <project.h>
#include "twl_arr.h"

bool 		strcmp_fn(void *item1, void *item2)
{
	char *s1 = item1;
	char *s2 = item2;
	return (strcmp(s1, s2) < 0);
}

static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_new(99);
	twl_arr_push(arr, strdup("ccc"));
	twl_arr_push(arr, strdup("aaa"));
	twl_arr_push(arr, strdup("bbb"));

	twl_arr_qsort(arr, strcmp_fn);

	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	twl_arr_del(arr, free);
}

void	suite_twl_arr_qsort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
