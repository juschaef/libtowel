#include <arr.h>
#include "project.h"
#include <lst.h>

static void simple_test(t_test *test)
{
	char **arr;
	t_lst *lst;

	arr = arr_init(99);
	arr_push(arr, strdup("zaa"));
	arr_push(arr, strdup("zbb"));
	arr_push(arr, strdup("zcc"));

	lst = arr_to_lst(arr);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "zaa") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "zbb") == 0);
	mt_assert(strcmp(lst_get_(lst, 2)->data, "zcc") == 0);
	mt_assert(lst_get_(lst, 3) == NULL);
}

void	suite_arr_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}