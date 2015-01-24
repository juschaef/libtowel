#include "project.h"
#include <lst.h>

bool 		sort_twl_strcmp(void *str1, void *str2, void *context)
{
	char *s1;
	char *s2;

	(void)context;
	s1 = str1;
	s2 = str2;
	return (strcmp(s1, s2) < 0);
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = lst_init();

	lst_push(lst, twl_strdup("aaa"));
	lst_push(lst, twl_strdup("ccc"));
	lst_push(lst, twl_strdup("bbb"));

	lst_sort(lst, sort_twl_strcmp, NULL);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "bbb") == 0);
	mt_assert(strcmp(lst_get_(lst, 2)->data, "ccc") == 0);
	mt_assert(lst_get_(lst, 3) == NULL);
}

void	suite_lst_sort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
