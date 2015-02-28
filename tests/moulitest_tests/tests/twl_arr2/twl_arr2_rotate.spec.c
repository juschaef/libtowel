#include <project.h>
#include <twl_arr2.h>
#include <twl_matrix.h>

static void simple_test(t_test *test)
{
	char ***arr;
	char ***arr_new;

	arr = malloc(sizeof(char **) * 3);
	arr[0] = malloc(sizeof(char *) * 3);
	arr[1] = malloc(sizeof(char *) * 3);
	arr[0][0] = strdup("a");
	arr[0][1] = strdup("b");
	arr[0][2] = NULL;
	arr[1][0] = strdup("c");
	arr[1][1] = strdup("d");
	arr[1][2] = NULL;
	arr[2] = NULL;

	arr_new = twl_arr2_rotate(arr, 0);

	mt_assert(strcmp(arr_new[0][0], "c") == 0);
	mt_assert(strcmp(arr_new[0][1], "a") == 0);
	mt_assert(strcmp(arr_new[1][0], "d") == 0);
	mt_assert(strcmp(arr_new[1][1], "b") == 0);
	mt_assert(arr_new[0][2] == NULL);
	mt_assert(arr_new[1][2] == NULL);
}

static void *new_fn(int y, int x, void *context)
{
	char *buf;
	asprintf(&buf, "(%d,%d)", y, x);
	(void)context;
	return (buf);
}

static void harder_test(t_test *test)
{
	char ***arr;
	char ***rotated_arr;

	arr = twl_arr2_new(2, 3, new_fn, NULL);
	rotated_arr = twl_arr2_rotate(arr, 1);

	mt_assert(strcmp(rotated_arr[0][0], "(1,0)") == 0);
	mt_assert(strcmp(rotated_arr[0][1], "(0,0)") == 0);
	mt_assert(rotated_arr[0][2] == NULL);
	mt_assert(strcmp(rotated_arr[1][0], "(1,1)") == 0);
	mt_assert(strcmp(rotated_arr[1][1], "(0,1)") == 0);
	mt_assert(rotated_arr[1][2] == NULL);
	mt_assert(strcmp(rotated_arr[2][0], "(1,2)") == 0);
	mt_assert(strcmp(rotated_arr[2][1], "(0,2)") == 0);
	mt_assert(rotated_arr[2][2] == NULL);
	mt_assert(rotated_arr[3] == NULL);
}

void	suite_twl_arr2_rotate(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, harder_test);
}
