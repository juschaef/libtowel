#include "project.h"
#include <assert.h>

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}

UT_TEST(lst_del)
{
	t_lst *lst;
	char *str1;
	char *str2;
	t_lst_elem *elem1;
	t_lst_elem *elem2;

	lst = lst_init();
	str1 = strdup("aaa");
	str2 = strdup("bbb");
	elem1 = lst_create_elem(str1);
	elem2 = lst_create_elem(str2);
	lst_push(lst, elem1);
	lst_push(lst, elem2);

	UT_ASSERT(lst_len(lst) == 2);

	lst_del(lst, del_data);

	UT_ASSERT_W(!"test free");
}
