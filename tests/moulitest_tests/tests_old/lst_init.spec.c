#include "project.h"

UT_TEST(lst_init)
{
	t_lst	*lst;
	lst = lst_init();

	UT_ASSERT(lst->len == 0);
	UT_ASSERT(lst->elems == NULL);
}
