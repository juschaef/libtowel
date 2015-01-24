#include "project.h"

UT_TEST(lst_get)
{
	t_lst	*lst;
	lst = lst_init();

	lst_push(lst, lst_create_elem("aaa"));
	lst_push(lst, lst_create_elem("bbb"));
	lst_push(lst, lst_create_elem("ccc"));
	UT_ASSERT(strequ(lst_get(lst, 0)->data, "aaa"));
	UT_ASSERT(strequ(lst_get(lst, 1)->data, "bbb"));
	UT_ASSERT(strequ(lst_get(lst, 2)->data, "ccc"));
	UT_ASSERT(lst_get(lst, 3) == NULL);
}
