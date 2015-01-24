#include <twl_arr.h>
#include "project.h"
#include <lst.h>

static void simple_test(t_test *test)
{
	char **arr;
	t_lst *lst;

	arr = twl_arr_init(99);
	twl_arr_push(arr, strdup("zaa"));
	twl_arr_push(arr, strdup("zbb"));
	twl_arr_push(arr, strdup("zcc"));

	lst = twl_arr_to_lst(arr);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "zaa") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "zbb") == 0);
	mt_assert(strcmp(lst_get_(lst, 2)->data, "zcc") == 0);
	mt_assert(lst_get_(lst, 3) == NULL);
}

void	suite_twl_arr_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}