#include <project.h>
#include "twl_arr2.h"

static int counter;

static void del_fn(void *elem)
{
	counter++;
	free(elem);
}

static void *new_fn(int y, int x, void *context)
{
	char *buf;
	asprintf(&buf, "(%d,%d)", y, x);
	(void)context;
	return (buf);
}

static void simple_test(t_test *test)
{
	char ***arr;

	arr = twl_arr2_new(5, 5, new_fn, NULL);

	counter = 0;
	twl_arr2_del(arr, del_fn);
	mt_assert(counter == 25);
}

void	suite_twl_arr2_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
