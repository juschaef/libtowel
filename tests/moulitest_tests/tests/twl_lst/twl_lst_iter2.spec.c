#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, void *ctx1_, void *ctx2_)
{
	char *str;
	char *ctx1;
	char *ctx2;

	ctx1 = ctx1_;
	ctx2 = ctx2_;
	str = data;
	str[0] = *ctx1;
	str[1] = *ctx2;
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	char *c1 = "y";
	char *c2 = "z";
	twl_lst_iter2(lst, replace_first_letter, c1, c2);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "yza") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "yzb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "yzc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iter2(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
