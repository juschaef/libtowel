#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, void *next_, void *ctx1_, void *ctx2_)
{
	char *str;
	char *ctx1;
	char *ctx2;
	char *next;

	ctx1 = ctx1_;
	ctx2 = ctx2_;
	str = data;
	next = next_;
	str[0] = *ctx1;
	str[1] = *ctx2;
	if (next)
		str[2] = next[2];
	else
		str[2] = '.';
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaaa"));
	twl_lst_push_back(lst, strdup("bbbb"));
	twl_lst_push_back(lst, strdup("cccc"));

	char *c1 = "y";
	char *c2 = "z";
	twl_lst_iter2n(lst, replace_first_letter, c1, c2);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "yzba") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "yzcb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "yz.c") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iter2n(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
