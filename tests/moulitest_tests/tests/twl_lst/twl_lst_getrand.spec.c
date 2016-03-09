#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tata"));
	twl_lst_push_back(lst, strdup("tata"));
	mt_assert(!!twl_lst_get_rand(lst));

}

void	suite_twl_lst_getrand(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
