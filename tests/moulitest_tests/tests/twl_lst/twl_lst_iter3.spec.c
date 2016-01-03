#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, void *ctx1_, void *ctx2_, void *ctx3_)
{
	char *str;
	char *ctx1;
	char *ctx2;
	char *ctx3;

	ctx1 = ctx1_;
	ctx2 = ctx2_;
	ctx3 = ctx3_;
	str = data;
	str[0] = *ctx1;
	str[1] = *ctx2;
	str[2] = *ctx3;
}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaaa"));
	twl_lst_push(lst, strdup("bbbb"));
	twl_lst_push(lst, strdup("cccc"));

	char *c1 = "x";
	char *c2 = "y";
	char *c3 = "z";
	twl_lst_iter3(lst, replace_first_letter, c1, c2, c3);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "xyza") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "xyzb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "xyzc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iter3(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
