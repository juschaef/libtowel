#include <twl_lst.h>
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
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	char *c = "z";
	twl_lst_iter(lst, replace_first_letter, c);

	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "zaa") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 1)->data, "zbb") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 2)->data, "zcc") == 0);
	mt_assert(twl_lst_get_(lst, 3) == NULL);
}

void	suite_twl_lst_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
