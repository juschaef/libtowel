#include <project.h>
#include <twl_dict.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_dict_add(lst, "key1", "data1");
	twl_dict_add(lst, "key2", "data2");
	twl_dict_add(lst, "key3", "data3");

	char *s;
	s = twl_dict_get(lst, "key1");
	mt_assert(strcmp(s, "data1") == 0);
	s = twl_dict_get(lst, "key2");
	mt_assert(strcmp(s, "data2") == 0);
	s = twl_dict_get(lst, "key3");
	mt_assert(strcmp(s, "data3") == 0);
}

void	suite_twl_dict_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
