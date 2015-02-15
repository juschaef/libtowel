#include <project.h>
#include <twl_arr.h>
#include <twl_bool.h>
#include <twl_arr.h>

static t_bool filter_fn(void *elem, void *context)
{
	(void)context;
	return (*(char *)elem == 'b');
}

static void simple_test(t_test *test)
{
	char *arr[5];

	arr[0] = strdup("aaa");
	arr[1] = strdup("abc");
	arr[2] = strdup("bbb");
	arr[3] = strdup("bcc");
	arr[4] = NULL;

	mt_assert(twl_arr_count(arr, filter_fn, NULL) == 2);
}

void	suite_twl_arr_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
