#include <project.h>
#include "twl_printf.h"

static void simple_test(t_test *test)
{
	t_lst *lst;
	char *output;

	lst = twl_lst_new();
	twl_lst_push(lst, "aaa");
	twl_lst_push(lst, "bbb");
	twl_lst_push(lst, "ccc");

	output = twl_strjoinlst(lst, " ");
	mt_assert(strcmp(output, "aaa bbb ccc") == 0);
}

void	suite_twl_strjoinlst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
