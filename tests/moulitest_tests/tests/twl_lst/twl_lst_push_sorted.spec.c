#include <project.h>

static int	cmp_fn(void *data1, void *data2)
{
	return (strcmp(data1, data2));
}

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_sorted(lst, strdup("3"), cmp_fn);
	twl_lst_push_sorted(lst, strdup("1"), cmp_fn);
	twl_lst_push_sorted(lst, strdup("2"), cmp_fn);

	mt_assert(strcmp(twl_lst_get(lst, 0), "1") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 1), "2") == 0);
	mt_assert(strcmp(twl_lst_get(lst, 2), "3") == 0);

}

void	suite_twl_lst_push_sorted(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
