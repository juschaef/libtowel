#include "project.h"

UT_TEST(twl_lst_len)
{
	t_lst	*lst;
	lst = twl_lst_new();

	UT_ASSERT(twl_lst_len(lst) == 0);
	twl_lst_push_back(lst, twl_lst_create_elem("aaa"));
	UT_ASSERT(twl_lst_len(lst) == 1);
	twl_lst_push_back(lst, twl_lst_create_elem("bbb"));
	UT_ASSERT(twl_lst_len(lst) == 2);
	twl_lst_push_back(lst, twl_lst_create_elem("ccc"));
	UT_ASSERT(twl_lst_len(lst) == 3);
}
