#include "project.h"

UT_TEST(lst_push)
{
	t_lst	*lst;
	lst = lst_init();

	char *str1;
	str1 = "aaa";
	lst_push(lst, lst_create_elem(str1));
	UT_ASSERT(strequ(lst->elems->data, "aaa"));
	UT_ASSERT(str1 == lst->elems->data);

	lst = lst_init();
	lst_push(lst, lst_create_elem("aaa"));
	lst_push(lst, lst_create_elem("bbb"));
	lst_push(lst, lst_create_elem("ccc"));
	UT_ASSERT(strequ(lst_get(lst, 0)->data, "aaa"));
	UT_ASSERT(strequ(lst_get(lst, 1)->data, "bbb"));
	UT_ASSERT(strequ(lst_get(lst, 2)->data, "ccc"));
	UT_ASSERT(lst_get(lst, 3) == NULL);

	UT_ASSERT(strequ(lst_get(lst, 0)->next->data, "bbb"));
	UT_ASSERT(strequ(lst_get(lst, 1)->next->data, "ccc"));
	UT_ASSERT(lst_get(lst, 2)->next == NULL);

	UT_ASSERT(lst_get(lst, 0)->prev == NULL);
	UT_ASSERT(strequ(lst_get(lst, 1)->prev->data, "aaa"));
	UT_ASSERT(strequ(lst_get(lst, 2)->prev->data, "bbb"));

	lst = lst_init();
	int nbr = 3;
	lst_push(lst, lst_create_elem(&nbr));
	UT_ASSERT(*((int *)lst_get(lst, 0)->data) == nbr);

	lst = lst_init();
	lst_push(lst, lst_create_elem("aaa"));

	UT_ASSERT(lst_get(lst, 0)->parent == lst);
}
