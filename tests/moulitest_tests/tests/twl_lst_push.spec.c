#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();

	twl_lst_push(lst, twl_strdup("tata"));
	twl_lst_push(lst, twl_strdup("tutu"));
	twl_lst_push(lst, twl_strdup("toto"));

	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "tata") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 1)->data, "tutu") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 2)->data, "toto") == 0);

}

void	suite_twl_lst_push(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
