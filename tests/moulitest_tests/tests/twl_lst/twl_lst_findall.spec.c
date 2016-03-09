#include <project.h>
#include "twl_lst.h"

bool find_fn(void *data, void *context)
{
	char *str1;
	char *str2;

	str1 = data;
	str2 = context;
	if (*str1 == *str2)
		return (1);
	return (0);
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	t_lst	*matches;

	lst = twl_lst_new();
	twl_lst_push_back(lst, "aaa");
	twl_lst_push_back(lst, "bbb");
	twl_lst_push_back(lst, "abc");
	twl_lst_push_back(lst, "azz");
	twl_lst_push_back(lst, "zzz");

	matches = twl_lst_findall(lst, find_fn, "a");
	mt_assert(strcmp(twl_lst_get(matches, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(matches, 1), "abc") == 0);
	mt_assert(strcmp(twl_lst_get(matches, 2), "azz") == 0);
	mt_assert(twl_lst_len(matches) == 3);
	free(lst);
}

void	suite_twl_lst_findall(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
