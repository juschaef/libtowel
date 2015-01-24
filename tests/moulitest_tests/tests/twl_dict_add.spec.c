#include <project.h>
#include <twl_dict.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();
	twl_dict_add(lst, "key1", "data1");
	twl_dict_add(lst, "key2", "data2");
	twl_dict_add(lst, "key3", "data3");
	mt_assert(twl_lst_len(lst) == 3);
	mt_assert(strcmp((char *)twl_lst_get_(lst, 0)->data, "data1") == 0);
	mt_assert(strcmp((char *)twl_lst_get_(lst, 1)->data, "data2") == 0);
	mt_assert(strcmp((char *)twl_lst_get_(lst, 2)->data, "data3") == 0);
}

void	suite_twl_dict_add(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
