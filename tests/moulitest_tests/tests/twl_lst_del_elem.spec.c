#include <twl_lst.h>
#include <project.h>
#include <ldict.h>

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}


// static void simple_test(t_test *test)
// {
// 	char *str;
// 	t_twl_lstelem	*elem;

// 	str = strdup("abc");
// 	elem = twl_lstcreate_elem_(str);


// 	mt_assert(elem != NULL);
// 	mt_assert(str != NULL);

// 	lstelem_del(elem, del_data);

// 	mt_assert(elem->data == NULL);
// 	mt_assert(elem->key == NULL);
// 	mt_assert(elem->prev == NULL);
// 	mt_assert(elem->next == NULL);
// 	mt_assert(elem->parent == NULL);
// }

static void test_relink(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("ccc"));
	mt_assert(twl_lst_len(lst) == 3);

	twl_lst_del_elem(lst, 1, del_data);

	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "aaa") == 0);
	mt_assert(strcmp(twl_lst_get_(lst, 1)->data, "ccc") == 0);
	mt_assert(twl_lst_len(lst) == 2);
}

static void test_del_first(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));

	twl_lst_del_elem(lst, 0, del_data);

	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "bbb") == 0);
	mt_assert(twl_lst_len(lst) == 1);
}

static void test_del_last(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("bbb"));

	twl_lst_del_elem(lst, 1, del_data);

	mt_assert(strcmp(twl_lst_get_(lst, 0)->data, "aaa") == 0);
	mt_assert(twl_lst_len(lst) == 1);
}

void	suite_twl_lst_del_elem(t_suite *suite)
{
	// SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_relink);
	SUITE_ADD_TEST(suite, test_del_first);
	SUITE_ADD_TEST(suite, test_del_last);
}
