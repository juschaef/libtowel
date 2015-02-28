#include <project.h>
#include <twl_arr2.h>
#include <twl_matrix.h>

static void iter_fn(void *data_, void *context)
{
	char *data;

	data = data_;
	if (*data == 'a')
		*data = 'A';
	(void)context;
}

static void simple_test(t_test *test)
{
	char ***arr;

	arr = malloc(sizeof(char **) * 3);
	arr[0] = malloc(sizeof(char *) * 3);
	arr[1] = malloc(sizeof(char *) * 3);
	arr[0][0] = strdup("abcdefghabcdefghabcdefghabcdefgh");
	arr[0][1] = strdup("abcdefghabcdefghabcdefghabcdefgh");
	arr[0][2] = NULL;
	arr[1][0] = strdup("a");
	arr[1][1] = strdup("b");
	arr[1][2] = NULL;
	arr[2] = NULL;

	twl_arr2_iter(arr, iter_fn, arr);

	mt_assert(strcmp(arr[0][1], "Abcdefghabcdefghabcdefghabcdefgh") == 0);
	mt_assert(strcmp(arr[0][0], "Abcdefghabcdefghabcdefghabcdefgh") == 0);
	mt_assert(arr[0][2] == NULL);
	mt_assert(strcmp(arr[1][0], "A") == 0);
	mt_assert(strcmp(arr[1][1], "b") == 0);
	mt_assert(arr[1][2] == NULL);
}

void	suite_twl_arr2_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
