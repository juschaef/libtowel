#include <project.h>
#include <twl_arr2.h>
#include <twl_matrix.h>

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

	arr = twl_arr2_new(2, 2, new_fn, NULL);

	mt_assert(strcmp(arr[0][0], "(0,0)") == 0);
	mt_assert(strcmp(arr[0][1], "(0,1)") == 0);
	mt_assert(arr[0][2] == NULL);
	mt_assert(strcmp(arr[1][0], "(1,0)") == 0);
	mt_assert(strcmp(arr[1][1], "(1,1)") == 0);
	mt_assert(arr[1][2] == NULL);
	mt_assert(arr[2] == NULL);
}

void	suite_twl_arr2_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
