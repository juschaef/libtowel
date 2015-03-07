#include <project.h>
#include "twl_dict.h"

static void simple_test(t_test *test)
{
	t_lst_elem *elem1;
	t_lst_elem *elem2;

	elem1 = twl_lst_create_elem__("111");
	elem2 = twl_lst_create_elem__("222");
	twl_lst_link__(elem1, elem2);
	mt_assert(elem1->next && strcmp(elem1->next->data, "222") == 0);
	mt_assert(elem2->prev && strcmp(elem2->prev->data, "111") == 0);
	mt_assert(elem1->prev == NULL);
	mt_assert(elem2->next == NULL);
}

static void test_relink_null_left(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_lst_push(lst, twl_lst_create_elem__("111"));
	twl_lst_push(lst, twl_lst_create_elem__("222"));
	mt_assert(twl_lst_len(lst) == 2);
	twl_lst_link__(NULL, twl_lst_get_elem__(lst, 0));
	mt_assert(twl_lst_get_elem__(lst, 0)->next != NULL);
	mt_assert(twl_lst_get_elem__(lst, 0)->prev == NULL);
	twl_lst_link__(NULL, twl_lst_get_elem__(lst, 1));
	mt_assert(twl_lst_get_elem__(lst, 1)->next == NULL);
	mt_assert(twl_lst_get_elem__(lst, 1)->prev == NULL);
}

static void test_relink_null_right(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_lst_push(lst, twl_lst_create_elem__("111"));
	twl_lst_push(lst, twl_lst_create_elem__("222"));
	mt_assert(twl_lst_len(lst) == 2);
	twl_lst_link__(twl_lst_get_elem__(lst, 0), NULL);
	mt_assert(twl_lst_get_elem__(lst, 0)->next == NULL);
	mt_assert(twl_lst_len(lst) == 1);
}

void	suite_twl_lst_link__(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_relink_null_left);
	SUITE_ADD_TEST(suite, test_relink_null_right);
}
