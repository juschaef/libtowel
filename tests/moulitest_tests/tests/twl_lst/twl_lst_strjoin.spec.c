#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char	*s;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	s = twl_lst_strjoin(lst, "|");
	mt_assert(strcmp(s, "aaa|bbb|ccc") == 0);
	free(s);
}

void	suite_twl_lst_strjoin(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
