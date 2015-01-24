#include <project.h>
#include <ldict.h>

static void simple_test(t_test *test)
{
	t_lst *lst;

	lst = lst_init();
	ldict_add(lst, "key1", "data1");
	ldict_add(lst, "key2", "data2");
	ldict_add(lst, "key3", "data3");

	char *s;
	s = ldict_get(lst, "key1");
	mt_assert(strcmp(s, "data1") == 0);
	s = ldict_get(lst, "key2");
	mt_assert(strcmp(s, "data2") == 0);
	s = ldict_get(lst, "key3");
	mt_assert(strcmp(s, "data3") == 0);
}

void	suite_ldict_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
