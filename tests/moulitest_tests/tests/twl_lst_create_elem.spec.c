#include <project.h>
#include <twl_dict.h>

static void simple_test(t_test *test)
{
	t_twl_lst_elem	*elem1;
	t_twl_lst_elem	*elem2;

	elem1 = twl_lst_create_elem_(strdup("aaa"));
	elem2 = twl_lst_create_elem_(strdup("bbb"));
	
	mt_assert(strcmp(elem1->data, "aaa") == 0);
	mt_assert(strcmp(elem2->data, "bbb") == 0);

}

static void check_initial_values(t_test *test)
{
	t_twl_lst_elem	*elem;

	elem = twl_lst_create_elem_(strdup("aaa"));
	mt_assert(elem->data != NULL);
	mt_assert(elem->next == NULL);
	mt_assert(elem->prev == NULL);
	mt_assert(elem->parent == NULL);
	mt_assert(elem->key == NULL);
}

void	suite_twl_lst_create_elem(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, check_initial_values);
}
