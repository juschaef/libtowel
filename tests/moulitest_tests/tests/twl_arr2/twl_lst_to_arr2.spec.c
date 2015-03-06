#include <project.h>
#include "twl_arr2.h"
#include "twl_lst.h"

static void simple_test(t_test *test)
{
	char ***arr;
	t_lst *lst;

	lst = twl_lst_new();
	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));
	twl_lst_push(lst, strdup("ddd"));
	twl_lst_push(lst, strdup("eee"));

	arr = twl_lst_to_arr2(lst, 3);
	mt_assert(strcmp(arr[0][0], "aaa") == 0);
	mt_assert(strcmp(arr[0][1], "bbb") == 0);
	mt_assert(strcmp(arr[0][2], "ccc") == 0);
	mt_assert(strcmp(arr[1][0], "ddd") == 0);
	mt_assert(strcmp(arr[1][1], "eee") == 0);
}

void	suite_twl_lst_to_arr2(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
