#include <project.h>
#include "twl_dict.h"

static void del(void *data)
{
	free(data);
}

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_dict_set(lst, "key1", strdup("data1"), del);
	twl_dict_set(lst, "key2", strdup("data2"), del);
	twl_dict_set(lst, "key3", strdup("data3"), del);
	mt_assert(twl_lst_len(lst) == 3);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->key, "key1") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "data1") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 1)->key, "key2") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 2)->key, "key3") == 0);
}

static void test_set_multiple_times(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_dict_set(lst, "key1", strdup("data1"), del);
	twl_dict_set(lst, "key2", strdup("data2"), del);
	mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "data1") == 0);
	mt_assert(twl_lst_len(lst) == 2);
	twl_dict_set(lst, "key1", strdup("new data1"), del);
	// mt_assert(strcmp(twl_lst_get_elem__(lst, 0)->data, "new data1") == 0);
	// mt_assert(twl_lst_len(lst) == 2);
}

void	suite_twl_dict_set(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_set_multiple_times);
}
