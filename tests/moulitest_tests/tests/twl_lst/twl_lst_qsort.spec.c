#include "project.h"
#include "twl_lst.h"

static bool 		sort_twl_strcmp(void *str1, void *str2)
{
	char *s1;
	char *s2;

	s1 = str1;
	s2 = str2;
	return (strcmp(s1, s2) < 0);
}

static void			simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("ccc"));
	twl_lst_push_back(lst, strdup("bbb"));

	twl_lst_qsort(lst, sort_twl_strcmp);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "bbb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "ccc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void				suite_twl_lst_qsort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
