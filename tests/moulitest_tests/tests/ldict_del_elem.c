#include <project.h>
#include <ldict.h>

static void	del_data(char *str)
{
	free(str);
	str = NULL;
	(void)str;
}

static void test_del_first(t_test *test)
{
	t_lst *lst;

	lst = lst_init();
	ldict_add(lst, "key1", strdup("data1"));
	ldict_add(lst, "key2", strdup("data2"));
	ldict_add(lst, "key3", strdup("data3"));

	ldict_del_elem(lst, "key1", del_data);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "data2") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "data3") == 0);
	mt_assert(lst_len(lst) == 2);
}

static void test_del_middle(t_test *test)
{
	t_lst *lst;

	lst = lst_init();
	ldict_add(lst, "key1", strdup("data1"));
	ldict_add(lst, "key2", strdup("data2"));
	ldict_add(lst, "key3", strdup("data3"));

	ldict_del_elem(lst, "key2", del_data);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "data1") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "data3") == 0);
	mt_assert(lst_len(lst) == 2);
}

static void test_del_last(t_test *test)
{
	t_lst *lst;

	lst = lst_init();
	ldict_add(lst, "key1", strdup("data1"));
	ldict_add(lst, "key2", strdup("data2"));
	ldict_add(lst, "key3", strdup("data3"));

	ldict_del_elem(lst, "key3", del_data);

	mt_assert(strcmp(lst_get_(lst, 0)->data, "data1") == 0);
	mt_assert(strcmp(lst_get_(lst, 1)->data, "data2") == 0);
	mt_assert(lst_len(lst) == 2);
}

void	suite_ldict_del_elem(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_del_first);
	SUITE_ADD_TEST(suite, test_del_middle);
	SUITE_ADD_TEST(suite, test_del_last);
}
