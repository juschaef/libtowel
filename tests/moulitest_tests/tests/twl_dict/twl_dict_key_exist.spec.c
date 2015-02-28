#include <project.h>
#include <twl_dict.h>
#include <stdbool.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_dict_add(lst, "key1", "data1");
	twl_dict_add(lst, "key2", NULL);
	twl_dict_add(lst, "key3", "data3");

	mt_assert(twl_dict_key_exist(lst, "key1") == true);
	mt_assert(twl_dict_key_exist(lst, "key2") == true);
	mt_assert(twl_dict_key_exist(lst, "key3") == true);
	mt_assert(twl_dict_key_exist(lst, "not exist") == false);
}

void	suite_twl_dict_key_exist(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
