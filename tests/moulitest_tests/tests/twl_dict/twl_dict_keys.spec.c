#include <project.h>
#include "twl_dict.h"

static void simple_test(t_test *test)
{
	t_dict *dict;

	dict = twl_dict_new();
	twl_dict_add(dict, "key1", "data1");
	twl_dict_add(dict, "key2", "data2");
	twl_dict_add(dict, "key3", "data3");

	t_lst *keys;
	keys = twl_dict_keys(dict);

	mt_assert(strcmp(twl_lst_get(keys, 0), "key1") == 0);
	mt_assert(strcmp(twl_lst_get(keys, 1), "key2") == 0);
	mt_assert(strcmp(twl_lst_get(keys, 2), "key3") == 0);
	mt_assert(twl_lst_len(keys) == 3);
}

void	suite_twl_dict_keys(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
