#include "project.h"

static void *sum(void *data, void *memo)
{
	*(int *)memo = *(int *)data + *(int *)memo;
	return (memo);
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();
	int memo = 0;
	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 3;
	int nbr4 = 4;

	twl_lst_push_back(lst, &nbr1);
	twl_lst_push_back(lst, &nbr2);
	twl_lst_push_back(lst, &nbr3);
	twl_lst_push_back(lst, &nbr4);

	twl_lst_reduce(lst, sum, &memo);

	mt_assert(memo == 10);
	free(lst);
}

void	suite_twl_lst_reduce(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
