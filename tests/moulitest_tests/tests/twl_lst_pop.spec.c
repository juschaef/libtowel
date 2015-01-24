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
	lst = twl_lst_init();

	twl_lst_push(lst, twl_strdup("aaa"));
	twl_lst_push(lst, twl_strdup("bbb"));
	twl_lst_push(lst, twl_strdup("ccc"));

	twl_lst_pop(lst, del_data);
	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 1)->data, "bbb") == 0);
	mt_assert(twl_lst_get_(lst, 2) == NULL);
}

void	suite_twl_lst_pop(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
