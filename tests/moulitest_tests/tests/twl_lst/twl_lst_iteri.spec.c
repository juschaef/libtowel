#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, int i, void *context)
{
	char *str;
	str = data;
	*str = i + '0';
	(void)context;
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	twl_lst_iteri(lst, replace_first_letter, NULL);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "0aa") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "1bb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "2cc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iteri(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
