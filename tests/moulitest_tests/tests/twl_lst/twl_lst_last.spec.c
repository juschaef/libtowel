#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, strdup("tata"));
	twl_lst_push(lst, strdup("tutu"));
	twl_lst_push(lst, strdup("toto"));

	mt_assert(strcmp(twl_lst_last(lst), "toto") == 0);

}

void	suite_twl_lst_last(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
