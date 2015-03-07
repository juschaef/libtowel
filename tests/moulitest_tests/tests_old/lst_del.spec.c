#include "project.h"
#include <assert.h>

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}

UT_TEST(twl_lst_del)
{
	t_lst *lst;
	char *str1;
	char *str2;
	t_lst_elem *elem1;
	t_lst_elem *elem2;

	lst = twl_lst_new();
	str1 = strdup("aaa");
	str2 = strdup("bbb");
	elem1 = twl_lst_create_elem(str1);
	elem2 = twl_lst_create_elem(str2);
	twl_lst_push(lst, elem1);
	twl_lst_push(lst, elem2);

	UT_ASSERT(twl_lst_len(lst) == 2);

	twl_lst_del(lst, del_data);

	UT_ASSERT_W(!"test free");
}
