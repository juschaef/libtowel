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
	char *arr[4];
	char **arr2;

	arr[0] = strdup("aaa");
	arr[1] = strdup("abc");
	arr[2] = strdup("bbb");
	arr[3] = strdup("bcc");
	arr[4] = NULL;

	arr2 = twl_arr_filter(arr, filter_fn, NULL);

	mt_assert(strcmp(arr2[0], "bbb") == 0);
	mt_assert(strcmp(arr2[1], "bcc") == 0);
	mt_assert(arr2[2] == 0);
}

void	suite_twl_arr_filter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
