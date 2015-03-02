#include "project.h"
#include "twl_lst.h"

UT_TEST(twl_lst_push)
{
	t_lst	*lst;
	lst = twl_lst_new();

	char *str1;
	str1 = "aaa";
	twl_lst_push(lst, (str1));
	UT_ASSERT(strequ(lst->elems->data, "aaa"));
	UT_ASSERT(str1 == lst->elems->data);

	lst = twl_lst_new();
	twl_lst_push(lst, "aaa");
	twl_lst_push(lst, "bbb");
	twl_lst_push(lst, "ccc");
	UT_ASSERT(strequ(twl_lst_get(lst, 0)->data, "aaa"));
	UT_ASSERT(strequ(twl_lst_get(lst, 1)->data, "bbb"));
	UT_ASSERT(strequ(twl_lst_get(lst, 2)->data, "ccc"));
	UT_ASSERT(twl_lst_get(lst, 3) == NULL);

	UT_ASSERT(strequ(twl_lst_get(lst, 0)->next->data, "bbb"));
	UT_ASSERT(strequ(twl_lst_get(lst, 1)->next->data, "ccc"));
	UT_ASSERT(twl_lst_get(lst, 2)->next == NULL);

	UT_ASSERT(twl_lst_get(lst, 0)->prev == NULL);
	UT_ASSERT(strequ(twl_lst_get(lst, 1)->prev->data, "aaa"));
	UT_ASSERT(strequ(twl_lst_get(lst, 2)->prev->data, "bbb"));

	lst = twl_lst_new();
	int nbr = 3;
	twl_lst_push(lst, &nbr);
	UT_ASSERT(*((int *)twl_lst_get(lst, 0)->data) == nbr);

	lst = twl_lst_new();
	twl_lst_push(lst, "aaa");

	UT_ASSERT(twl_lst_get(lst, 0)->parent == lst);
}
