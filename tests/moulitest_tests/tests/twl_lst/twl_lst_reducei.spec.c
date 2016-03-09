#include <project.h>

static int sum(void *data, int memo)
{
	int *n1_ptr;

	n1_ptr = data;
	return (*n1_ptr + memo);
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

	mt_assert(twl_lst_reducei(lst, sum, memo) == 10);
	free(lst);
}

void	suite_twl_lst_reducei(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
