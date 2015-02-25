#include <twl_lst.h>
#include <twl_arr.h>
#include <string.h>
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char	**arr;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	arr = (char **)twl_lst_to_arr(lst);

	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	mt_assert(arr[3] == 0);
}

void	suite_twl_lst_to_arr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}