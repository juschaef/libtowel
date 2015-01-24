#include "project.h"

UT_TEST(twl_lst_unshift)
{
	t_lst	*lst;
	t_twl_lst_elem *elem;
	lst = twl_lst_init();

	twl_lst_push(lst, twl_lst_create_elem("aaa"));
	twl_lst_push(lst, twl_lst_create_elem("bbb"));
	twl_lst_unshift(lst, twl_lst_create_elem("ccc"));

	elem = twl_lst_get(lst, 0);
	UT_ASSERT(elem && strequ(elem->data, "ccc"));
	UT_ASSERT(elem && elem->next && strequ(elem->next->data, "aaa"));

	elem = twl_lst_get(lst, 1);
	UT_ASSERT(elem && elem->prev && strequ(elem->prev->data, "ccc"));

	lst = twl_lst_init();
	twl_lst_unshift(lst, twl_lst_create_elem("111"));
	elem = twl_lst_get(lst, 0);
	UT_ASSERT(elem && strequ(elem->data, "111"));
}
