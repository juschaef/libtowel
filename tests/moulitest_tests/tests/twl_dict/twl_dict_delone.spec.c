#include <project.h>
#include <twl_dict.h>

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}

static void test_del_first(t_test *test)
{
	t_dict *dict;

	dict = twl_lst_new();
	twl_dict_add(dict, "key1", strdup("data1"));
	twl_dict_add(dict, "key2", strdup("data2"));
	twl_dict_add(dict, "key3", strdup("data3"));

	twl_dict_delone(dict, "key1", del_data);

	mt_assert(strcmp(twl_lst_get_elem__(dict, 0)->data, "data2") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(dict, 1)->data, "data3") == 0);
	mt_assert(twl_lst_len(dict) == 2);
}

static void test_del_middle(t_test *test)
{
	t_dict *dict;

	dict = twl_lst_new();
	twl_dict_add(dict, "key1", strdup("data1"));
	twl_dict_add(dict, "key2", strdup("data2"));
	twl_dict_add(dict, "key3", strdup("data3"));

	twl_dict_delone(dict, "key2", del_data);

	mt_assert(strcmp(twl_lst_get_elem__(dict, 0)->data, "data1") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(dict, 1)->data, "data3") == 0);
	mt_assert(twl_lst_len(dict) == 2);
}

static void test_del_last(t_test *test)
{
	t_dict *dict;

	dict = twl_lst_new();
	twl_dict_add(dict, "key1", strdup("data1"));
	twl_dict_add(dict, "key2", strdup("data2"));
	twl_dict_add(dict, "key3", strdup("data3"));

	twl_dict_delone(dict, "key3", del_data);

	mt_assert(strcmp(twl_lst_get_elem__(dict, 0)->data, "data1") == 0);
	mt_assert(strcmp(twl_lst_get_elem__(dict, 1)->data, "data2") == 0);
	mt_assert(twl_lst_len(dict) == 2);
}

void	suite_twl_dict_delone(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_del_first);
	SUITE_ADD_TEST(suite, test_del_middle);
	SUITE_ADD_TEST(suite, test_del_last);
}
