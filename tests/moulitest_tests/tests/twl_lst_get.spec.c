#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("tata"));
	twl_lst_push(lst, strdup("tutu"));
	twl_lst_push(lst, strdup("toto"));

	mt_assert(strcmp(twl_lst_get(lst, 0), "tata") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "tutu") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "toto") == 0);

}

void	suite_twl_lst_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
