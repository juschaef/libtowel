#include <lst.h>
#include "project.h"

static void replace_first_letter(void *data, void *context_)
{
	char *str;
	char *context;

	context = context_;
	str = data;
	*str = *context;
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = lst_init();

	lst_push(lst, ft_strdup("aaa"));
	lst_push(lst, ft_strdup("bbb"));
	lst_push(lst, ft_strdup("ccc"));

	char *c = "z";
	lst_iter(lst, replace_first_letter, c);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "zaa") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "zbb") == 0);
	mt_assert(strcmp(lst_get_(lst, 2)->data, "zcc") == 0);
	mt_assert(lst_get_(lst, 3) == NULL);
}

void	suite_lst_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
