#include <twl_arr.h>
#include "project.h"
#include <twl_lst.h>
#include <twl_matrix.h>

static void simple_test(t_test *test)
{
	char ***arr;
	int	a[] = {2,2,0};

	arr = twl_matrix_new(a);
	arr[0][0] = "cou";
	mt_assert(strcmp(arr[0][0], "cou") == 0);
}

void	suite_twl_matrix_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}