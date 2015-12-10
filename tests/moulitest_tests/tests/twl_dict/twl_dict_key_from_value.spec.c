#include <project.h>
#include "twl_dict.h"
#include <stdbool.h>

static bool			cmp_value(void *data_, void *value_) {

	char	*data;
	char	*value;

	data = data_;
	value = value_;

	if (value == NULL)
		return(data == value);
	return (twl_strcmp(data, value) == 0);
}

static void simple_test(t_test *test)
{
	t_lst *lst;

	(void)test;
	lst = twl_lst_new();
	twl_dict_add(lst, "key1", "data1");
	twl_dict_add(lst, "key3", "data3");
	twl_dict_add(lst, "key2", NULL);
	twl_dict_add(lst, "key4", "data4");

	mt_assert(strcmp(twl_dict_key_from_value(lst, cmp_value, "data3"), "key3") == 0);
	mt_assert(strcmp(twl_dict_key_from_value(lst, cmp_value, NULL), "key2") == 0);
	mt_assert(strcmp(twl_dict_key_from_value(lst, cmp_value, "data1"),"key1") == 0);
	mt_assert(strcmp(twl_dict_key_from_value(lst, cmp_value, "data4"),"key4") == 0);
}

void	suite_twl_dict_key_from_value(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
