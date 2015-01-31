#include <twl_lst.h>
#include "project.h"
#include <twl_bool.h>
#include <string.h>

static t_bool filter_fn(void *data, void *context_)
{
	char *str;
	char *context;

	context = context_;
	str = data;
	if (strcmp(str, context) == 0)
		return (FALSE);
	return (TRUE);
}

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
	twl_lst_filter(lst, filter_fn, "bbb", delfn);

	mt_assert(strcmp(twl_lst_get(lst, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "ccc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 2) == NULL);
	mt_assert(del_counter == 2);
}

void	suite_twl_lst_filter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
