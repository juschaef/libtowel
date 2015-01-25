#include "project.h"

static t_twl_lst_elem *catHello(t_twl_lst_elem *elem)
{
	char *str;

	str = twl_strdup(elem->data);
	*str = *str + 1;
	return (twl_lst_create_elem(str));
}

UT_TEST(twl_lst_map)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, twl_lst_create_elem(twl_strdup("a")));
	twl_lst_push(lst, twl_lst_create_elem(twl_strdup("b")));
	twl_lst_push(lst, twl_lst_create_elem(twl_strdup("c")));

	t_lst	*new_lst;
	new_lst = twl_lst_map(lst, catHello);

	UT_ASSERT(strequ(twl_lst_get(lst, 0)->data, "a"));
	UT_ASSERT(strequ(twl_lst_get(lst, 1)->data, "b"));
	UT_ASSERT(strequ(twl_lst_get(lst, 2)->data, "c"));
	UT_ASSERT(twl_lst_get(lst, 3) == NULL);
	UT_ASSERT(strequ(twl_lst_get(new_lst, 0)->data, "b"));
	UT_ASSERT(strequ(twl_lst_get(new_lst, 1)->data, "c"));
	UT_ASSERT(strequ(twl_lst_get(new_lst, 2)->data, "d"));
	UT_ASSERT(twl_lst_get(new_lst, 3) == NULL);
}
