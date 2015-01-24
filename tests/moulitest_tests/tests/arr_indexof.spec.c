#include <project.h>
#include <arr.h>

static void test1(t_test *test)
{
	char **arr;
	char *s1 = "aaa";
	char *s2 = "bbb";
	char *s3 = "ccc";

	arr = arr_init(3);
	arr_push(arr, s1);
	arr_push(arr, s2);
	arr_push(arr, s3);

	mt_assert(arr_indexof(arr, s1) == 0);
	mt_assert(arr_indexof(arr, s2) == 1);
	mt_assert(arr_indexof(arr, s3) == 2);
	free(arr);
}

static void test2(t_test *test)
{
	char **arr;
	char *s1 = "aaa";
	char *s2 = "bbb";
	char *s3 = "ccc";

	arr = arr_init(3);
	arr_push(arr, s1);
	arr_push(arr, s2);
	arr_push(arr, s3);

	arr_swap(arr, 0, 2);
	mt_assert(arr_indexof(arr, s1) == 2);
	mt_assert(arr_indexof(arr, s2) == 1);
	mt_assert(arr_indexof(arr, s3) == 0);
	free(arr);
}
static void test_not_found(t_test *test)
{
	char **arr;
	char *s1 = "aaa";
	char *s2 = "bbb";

	arr = arr_init(3);
	arr_push(arr, s1);
	arr_push(arr, s2);

	mt_assert(arr_indexof(arr, "not in arr") == -1);
	free(arr);
}

void	suite_arr_indexof(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test_not_found);
}
