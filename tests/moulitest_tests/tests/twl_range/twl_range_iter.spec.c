#include <project.h>
#include <twl_range.h>
#include <twl_xstring.h>

void	range_fn(int i, void *context)
{
	char *arr;

	arr = context;
	arr[i] = i + '0';
}

static void test_simple(t_test *test)
{
	char arr[11];

	bzero(arr, 11);
	twl_range_iter(0, 10, range_fn, arr);
	mt_assert(strcmp("0123456789", arr) == 0);
}

void	suite_twl_range_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
