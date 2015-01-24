#include "project.h"

static t_lst_elem *catHello(t_lst_elem *elem)
{
	char *str;

	str = twl_strdup(elem->data);
	*str = *str + 1;
	return (lst_create_elem(str));
}

UT_TEST(lst_map)
{
	t_lst	*lst;
	lst = lst_init();

	lst_push(lst, lst_create_elem(twl_strdup("a")));
	lst_push(lst, lst_create_elem(twl_strdup("b")));
	lst_push(lst, lst_create_elem(twl_strdup("c")));

	t_lst	*new_lst;
	new_lst = lst_map(lst, catHello);

	UT_ASSERT(strequ(lst_get(lst, 0)->data, "a"));
	UT_ASSERT(strequ(lst_get(lst, 1)->data, "b"));
	UT_ASSERT(strequ(lst_get(lst, 2)->data, "c"));
	UT_ASSERT(lst_get(lst, 3) == NULL);
	UT_ASSERT(strequ(lst_get(new_lst, 0)->data, "b"));
	UT_ASSERT(strequ(lst_get(new_lst, 1)->data, "c"));
	UT_ASSERT(strequ(lst_get(new_lst, 2)->data, "d"));
	UT_ASSERT(lst_get(new_lst, 3) == NULL);
}
