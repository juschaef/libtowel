#include <lst.h>
#include "project.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	char *s1 = twl_strdup("hello");
	char *s2 = twl_strdup("coucou");
	
	lst = lst_init();

	lst_push(lst, lst_create_elem_(s1));
	lst_push(lst, lst_create_elem_(s2));

	lst_clear(lst, NULL);

	mt_assert(lst_len(lst) == 0);
	free(s1);
	free(s2);
}

void	suite_lst_clear(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
