#include <project.h>
#include "twl_dict.h"
#include "twl_xstring.h"

static void simple_test(t_test *test)
{
	t_dict *dict = twl_lst_new();
	t_dict *copy = twl_lst_new();
	twl_dict_add(dict, "key1", "data1");
	twl_dict_add(dict, "key2", "data2");
	twl_dict_add(dict, "key3", "data3");

	copy = twl_dict_copy(dict, twl_strdup_void);
	mt_assert(twl_lst_len(copy) == 3);
	mt_assert(strcmp(twl_dict_get(copy, "key1"), "data1") == 0);
	mt_assert(strcmp(twl_dict_get(copy, "key2"), "data2") == 0);
	mt_assert(strcmp(twl_dict_get(copy, "key3"), "data3") == 0);
}

static void write_old_values_test(t_test *test)
{
	t_dict *dict = twl_lst_new();
	t_dict *copy = twl_lst_new();
	twl_dict_add(dict, "key1", twl_strdup("data1"));
	twl_dict_add(dict, "key2", twl_strdup("data2"));
	twl_dict_add(dict, "key3", twl_strdup("data3"));

	copy = twl_dict_copy(dict, twl_strdup_void);
	*(char *)twl_dict_get(dict, "key1") = 'z';
	*(char *)twl_dict_get(dict, "key2") = 'b';

	mt_assert(strcmp(twl_dict_get(dict, "key1"), "zata1") == 0);
	mt_assert(strcmp(twl_dict_get(dict, "key2"), "bata2") == 0);
	mt_assert(strcmp(twl_dict_get(copy, "key1"), "data1") == 0);
	mt_assert(strcmp(twl_dict_get(copy, "key2"), "data2") == 0);
	mt_assert(strcmp(twl_dict_get(copy, "key3"), "data3") == 0);
}

void	suite_twl_dict_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, write_old_values_test);
}
