#include "twl_lst.h"
#include "project.h"

static void replace_first_letter(void *data, void *prev_data,
	void *next_data, void *context_)
{
	char *str;
	char *context;
	char *next_str;
	char *prev_str;

	context = context_;
	str = data;
	next_str = next_data;
	prev_str = prev_data;
	if (prev_data)
		*str = *prev_str;
	if (next_data)
		*(str + 1) = *next_str;
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
	twl_lst_iternp(lst, replace_first_letter, c);

	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "aba") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->data, "acb") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->data, "azc") == 0);
	mt_assert(twl_lst_get_elem__(lst, 3) == NULL);
}

void	suite_twl_lst_iternp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
