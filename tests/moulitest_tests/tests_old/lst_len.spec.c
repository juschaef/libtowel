#include "project.h"

UT_TEST(lst_len)
{
	t_lst	*lst;
	lst = lst_init();

	UT_ASSERT(lst_len(lst) == 0);
	lst_push(lst, lst_create_elem("aaa"));
	UT_ASSERT(lst_len(lst) == 1);
	lst_push(lst, lst_create_elem("bbb"));
	UT_ASSERT(lst_len(lst) == 2);
	lst_push(lst, lst_create_elem("ccc"));
	UT_ASSERT(lst_len(lst) == 3);
}
