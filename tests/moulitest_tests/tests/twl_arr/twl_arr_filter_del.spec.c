#include <project.h>
#include "twl_arr.h"
#include <stdbool.h>
#include "twl_arr.h"

static bool filter_fn(void *elem, void *context)
{
	(void)context;
	return (*(char *)elem == 'b');
}

static int counter;

static void del_fn(void *elem)
{
	counter++;
	free(elem);
}

static void simple_test(t_test *test)
{
	char **arr;
	char **arr2;

	arr = twl_arr_new(4);
	twl_arr_push(arr, strdup("aaa"));
	twl_arr_push(arr, strdup("abc"));
	twl_arr_push(arr, strdup("bbb"));
	twl_arr_push(arr, strdup("bcc"));

	counter = 0;
	arr2 = twl_arr_filter_del(arr, filter_fn, NULL, del_fn);

	mt_assert(strcmp(arr2[0], "bbb") == 0);
	mt_assert(strcmp(arr2[1], "bcc") == 0);
	mt_assert(arr2[2] == 0);
}

void	suite_twl_arr_filter_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
