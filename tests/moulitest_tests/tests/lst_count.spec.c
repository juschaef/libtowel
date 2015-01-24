#include <project.h>
#include <ldict.h>

// size_t		lst_count(t_lst *lst, void *(*f)(void *));


void 	*ft_count_chars_3(void *s)
{
	if (ft_strlen(s) == 3)
		return (s);
	return (0);

}


static void test_simple_count(t_test *test)
{
	t_lst *lst;

	lst = lst_init();

	lst_push(lst, ft_strdup("aaa"));
	lst_push(lst, ft_strdup("4444444"));
	lst_push(lst, ft_strdup("bbb"));
	lst_push(lst, ft_strdup("0"));
	lst_push(lst, ft_strdup("1111"));
	lst_push(lst, ft_strdup("ccc"));

	mt_assert(lst_count(lst, ft_count_chars_3) == 3);
}

void	suite_lst_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_count);
}
