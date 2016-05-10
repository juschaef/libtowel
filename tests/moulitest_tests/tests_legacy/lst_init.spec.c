#include "project.h"

UT_TEST(twl_lst_new)
{
	t_lst	*lst;
	lst = twl_lst_new();

	UT_ASSERT(lst->len == 0);
	UT_ASSERT(lst->elems == NULL);
}
