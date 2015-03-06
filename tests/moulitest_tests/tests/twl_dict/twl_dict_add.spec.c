#include <project.h>
#include "twl_dict.h"

static void simple_test(t_test *test)
{
	t_dict *dict;

	dict = twl_lst_new();
	twl_dict_add(dict, "key1", "data1");
	twl_dict_add(dict, "key2", "data2");
	twl_dict_add(dict, "key3", "data3");
	mt_assert(twl_lst_len(dict) == 3);
	mt_assert(strcmp((char *)twl_lst_get_elem__(dict, 0)->data, "data1") == 0);
	mt_assert(strcmp((char *)twl_lst_get_elem__(dict, 1)->data, "data2") == 0);
	mt_assert(strcmp((char *)twl_lst_get_elem__(dict, 2)->data, "data3") == 0);
}

void	suite_twl_dict_add(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
