#include "twl_lst.h"
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char *s1 = strdup("hello");
	char *s2 = strdup("coucou");
	
	lst = twl_lst_new();

	twl_lst_push(lst, twl_lst_create_elem__(s1));
	twl_lst_push(lst, twl_lst_create_elem__(s2));

	twl_lst_clear__(lst, NULL);

	mt_assert(twl_lst_len(lst) == 0);
	free(s1);
	free(s2);
}

void	suite_twl_lst_clear__(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
