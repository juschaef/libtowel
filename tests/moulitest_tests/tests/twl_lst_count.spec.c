#include <project.h>
#include <twl_dict.h>

// size_t		twl_lstcount(t_lst *lst, void *(*f)(void *));


void 	*twl_count_chars_3(void *s)
{
	if (strlen(s) == 3)
		return (s);
	return (0);

}


static void test_simple_count(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_init();

	twl_lst_push(lst, strdup("aaa"));
	twl_lst_push(lst, strdup("4444444"));
	twl_lst_push(lst, strdup("bbb"));
	twl_lst_push(lst, strdup("0"));
	twl_lst_push(lst, strdup("1111"));
	twl_lst_push(lst, strdup("ccc"));

	mt_assert(twl_lst_count(lst, twl_count_chars_3) == 3);
}

void	suite_twl_lst_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_count);
}
