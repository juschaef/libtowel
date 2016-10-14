#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;
	char *str1;
	char *str2;
	char *str3;

	lst = twl_lst_new();

	str1 = strdup("1");
	str2 = strdup("2");
	str3 = strdup("3");
	twl_lst_push_back(lst, str1);
	twl_lst_push_back(lst, str2);
	twl_lst_push_back(lst, str3);

	twl_lst_remove(lst, str2, free);
	mt_assert(strcmp(twl_lst_get(lst, 0), "1") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "3") == 0);
	mt_assert(twl_lst_len(lst) == 2);

	twl_lst_del(lst, free);
}

static void remove_all_test(t_test *test)
{
	t_lst *lst;
	char *str1;
	char *str2;
	char *str3;

	lst = twl_lst_new();

	str1 = strdup("1");
	str2 = strdup("2");
	str3 = strdup("3");
	twl_lst_push_back(lst, str1);
	twl_lst_push_back(lst, str2);
	twl_lst_push_back(lst, str3);

	twl_lst_remove(lst, str1, free);
	twl_lst_remove(lst, str2, free);
	twl_lst_remove(lst, str3, free);
	mt_assert(twl_lst_len(lst) == 0);

	twl_lst_del(lst, free);
}

void	suite_twl_lst_remove(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, remove_all_test);
}
