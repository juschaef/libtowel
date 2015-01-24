#include "project.h"

UT_TEST(lst_unshift)
{
	t_lst	*lst;
	t_lst_elem *elem;
	lst = lst_init();

	lst_push(lst, lst_create_elem("aaa"));
	lst_push(lst, lst_create_elem("bbb"));
	lst_unshift(lst, lst_create_elem("ccc"));

	elem = lst_get(lst, 0);
	UT_ASSERT(elem && strequ(elem->data, "ccc"));
	UT_ASSERT(elem && elem->next && strequ(elem->next->data, "aaa"));

	elem = lst_get(lst, 1);
	UT_ASSERT(elem && elem->prev && strequ(elem->prev->data, "ccc"));

	lst = lst_init();
	lst_unshift(lst, lst_create_elem("111"));
	elem = lst_get(lst, 0);
	UT_ASSERT(elem && strequ(elem->data, "111"));
}
