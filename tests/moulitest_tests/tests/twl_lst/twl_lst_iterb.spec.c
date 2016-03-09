#include "twl_lst.h"
#include "project.h"

static void cat_str(void *data_, void *context)
{
	char 			*ctx;
	char			*data;

	ctx = context;
	data = data_;
	strcat(ctx, data);
}

static void simple_test(t_test *test)
{
	t_lst			*lst;
	char			str[4];

	bzero(str, 4);
	lst = twl_lst_new();
	twl_lst_push_back(lst, strdup("a"));
	twl_lst_push_back(lst, strdup("b"));
	twl_lst_push_back(lst, strdup("c"));

	twl_lst_iterb(lst, cat_str, str);
	mt_assert(strcmp(str, "cba") == 0);
}

void	suite_twl_lst_iterb(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
