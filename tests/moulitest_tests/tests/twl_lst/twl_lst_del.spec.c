#include "project.h"
#include "twl_lst.h"
#include <stdbool.h>
#include <string.h>

static int del_counter;

static void delfn(void *str_)
{
	del_counter++;
	free(str_);
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();
	
	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));
	twl_lst_push(lst, strdup("bbb"));

	del_counter = 0;
	twl_lst_del(lst, delfn);

	mt_assert(twl_lst_len(lst) == 0);
	mt_assert(del_counter == 4);
}

void	suite_twl_lst_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
