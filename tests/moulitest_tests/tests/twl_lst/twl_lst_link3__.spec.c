#include <project.h>
#include "twl_dict.h"

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push(lst, "111");
	twl_lst_push(lst, "333");
	twl_lst_link3__(twl_lst_get_elem__(lst, 0), twl_lst_create_elem__(strdup("222")), twl_lst_get_elem__(lst, 1));
	mt_assert(strcmp(twl_lst_get(lst, 0), "111") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "222") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "333") == 0);
}

void	suite_twl_lst_link3__(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
