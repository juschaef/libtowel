#include <project.h>
#include "twl_lst.h"

static bool find_nbr(void *data, void *ctx1, void *ctx2)
{
	int *nbr_p1;
	int *nbr_p2;

	nbr_p1 = data;
	nbr_p2 = ctx1;
	if (*nbr_p1 == *nbr_p2)
		return (1);
	return (0);
	(void)ctx2;
}

static void simple_test(t_test *test)
{
	// test->debug = 1;
	t_lst	*lst;
	lst = twl_lst_new();
	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 3;
	int nbr4 = 4;
	int *nbr_p;

	twl_lst_push(lst, &nbr1);
	twl_lst_push(lst, &nbr2);
	twl_lst_push(lst, &nbr3);
	twl_lst_push(lst, &nbr4);

	nbr_p = (int *)(twl_lst_find2(lst, find_nbr, &nbr3, NULL));
	mt_assert(*nbr_p == 3);

	nbr_p = (int *)(twl_lst_find2(lst, find_nbr, &nbr2, NULL));
	mt_assert(*nbr_p == 2);

	nbr_p = (int *)(twl_lst_find2(lst, find_nbr, &nbr1, NULL));
	mt_assert(*nbr_p == 1);

	free(lst);
}

void	suite_twl_lst_find2(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
