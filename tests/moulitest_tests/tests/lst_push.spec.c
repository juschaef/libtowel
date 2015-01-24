#include <project.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = lst_init();

	lst_push(lst, twl_strdup("tata"));
	lst_push(lst, twl_strdup("tutu"));
	lst_push(lst, twl_strdup("toto"));

	mt_assert(strcmp(lst_get_(lst, 0)->data, "tata") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "tutu") == 0);
	mt_assert(strcmp(lst_get_(lst, 2)->data, "toto") == 0);

}

void	suite_lst_push(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
