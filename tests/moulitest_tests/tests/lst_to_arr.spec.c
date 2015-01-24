#include <lst.h>
#include <twl_arr.h>
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char	**arr;

	lst = lst_init();

	lst_push(lst, twl_strdup("aaa"));
	lst_push(lst, twl_strdup("bbb"));
	lst_push(lst, twl_strdup("ccc"));

	arr = (char **)lst_to_twl_arr_(lst);

	mt_assert(strcmp(arr[0], "aaa") == 0);
	mt_assert(strcmp(arr[1], "bbb") == 0);
	mt_assert(strcmp(arr[2], "ccc") == 0);
	mt_assert(arr[3] == 0);
}

void	suite_lst_to_arr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}