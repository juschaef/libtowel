#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, void *prev_data, void *context_)
{
	char *str;
	char *context;
	char *prev_str;

	context = context_;
	str = data;
	prev_str = prev_data;
	*str = *context;
	if (prev_data)
		*(str + 1) = *(prev_str + 2);
	else
		*(str + 1) = 'z';


}

static void simple_test(t_test *test)
{
	t_lst	*lst;
	lst = twl_lst_new();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));

	char *c = "z";
	twl_lst_iterp(lst, replace_first_letter, c);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "zza") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "zab") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "zbc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iterp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
