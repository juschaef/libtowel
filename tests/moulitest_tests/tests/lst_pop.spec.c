#include <lst.h>
#include "project.h"

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}


static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = lst_init();

	lst_push(lst, ft_strdup("aaa"));
	lst_push(lst, ft_strdup("bbb"));
	lst_push(lst, ft_strdup("ccc"));

	lst_pop(lst, del_data);
	mt_assert(strcmp(lst_get_(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "bbb") == 0);
	mt_assert(lst_get_(lst, 2) == NULL);
}

void	suite_lst_pop(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
