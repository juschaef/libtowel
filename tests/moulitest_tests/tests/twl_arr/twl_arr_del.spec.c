#include <project.h>
#include "twl_arr.h"

int counter;

static void del_fn(void *elem)
{
	counter++;
	free(elem);
}

static void simple_test(t_test *test)
{
	char **arr = twl_arr_new(3);
	char *s1 = strdup("aaa");
	char *s2 = strdup("bbb");
	twl_arr_push(arr, s1);
	twl_arr_push(arr, s2);

	counter = 0;
	twl_arr_del(arr, del_fn);
	mt_assert(counter == 2);
}

void	suite_twl_arr_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
