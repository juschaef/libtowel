#include "twl_lst.h"
#include "project.h"
#include "twl_stdio.h"

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("0"));
	twl_lst_push(lst, strdup("1"));
	twl_lst_push(lst, strdup("2"));
	twl_lst_push(lst, strdup("3"));
	twl_lst_push(lst, strdup("4"));
	twl_lst_push(lst, strdup("5"));
	twl_lst_push(lst, strdup("6"));
	twl_lst_push(lst, strdup("7"));
	twl_lst_push(lst, strdup("8"));
	twl_lst_push(lst, strdup("9"));

	twl_lst_shuffle(lst);
	// twl_lst_putstr(lst, "\n");
	// twl_printf("\n");

	mt_assert(1);
}

void	suite_twl_lst_shuffle(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
/*
8
1
3
9
6
5
4
2
0
7
*/
