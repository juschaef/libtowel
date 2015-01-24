#include "project.h"

UT_TEST(twl_lst_init)
{
	t_lst	*lst;
	lst = twl_lst_init();

	UT_ASSERT(lst->len == 0);
	UT_ASSERT(lst->elems == NULL);
}
