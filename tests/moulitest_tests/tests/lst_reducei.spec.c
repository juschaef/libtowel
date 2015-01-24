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
	lst = lst_init();
	int memo = 0;
	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 3;
	int nbr4 = 4;

	lst_push(lst, &nbr1);
	lst_push(lst, &nbr2);
	lst_push(lst, &nbr3);
	lst_push(lst, &nbr4);

	mt_assert(lst_reducei(lst, sum, memo) == 10);
	free(lst);
}

void	suite_lst_reducei(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
