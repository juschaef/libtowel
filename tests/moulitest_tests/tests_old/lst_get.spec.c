#include "project.h"

UT_TEST(twl_lst_get)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, twl_lst_create_elem("aaa"));
	twl_lst_push(lst, twl_lst_create_elem("bbb"));
	twl_lst_push(lst, twl_lst_create_elem("ccc"));
	UT_ASSERT(strequ(twl_lst_get(lst, 0)->data, "aaa"));
	UT_ASSERT(strequ(twl_lst_get(lst, 1)->data, "bbb"));
	UT_ASSERT(strequ(twl_lst_get(lst, 2)->data, "ccc"));
	UT_ASSERT(twl_lst_get(lst, 3) == NULL);
}
