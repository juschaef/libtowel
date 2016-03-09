#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tutu"));
	twl_lst_push_back(lst, strdup("toto"));

	mt_assert(strcmp(twl_lst_first(lst), "tata") == 0);

}

void	suite_twl_lst_first(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
