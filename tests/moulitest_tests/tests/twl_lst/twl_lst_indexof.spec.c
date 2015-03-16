#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;
	char	*str1;
	char	*str2;
	char	*str3;

	lst = twl_lst_new();

	str1 = strdup("111");
	twl_lst_push(lst, str1);
	str2 = strdup("222");
	twl_lst_push(lst, str2);
	str3 = strdup("333");
	twl_lst_push(lst, str3);

	mt_assert(twl_lst_indexof(lst, str1) == 0);
	mt_assert(twl_lst_indexof(lst, str2) == 1);
	mt_assert(twl_lst_indexof(lst, str3) == 2);
	mt_assert(twl_lst_indexof(lst, NULL) == -1);
}

void	suite_twl_lst_insert(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
