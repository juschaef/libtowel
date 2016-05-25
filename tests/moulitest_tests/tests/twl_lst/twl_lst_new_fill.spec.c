#include "twl_lst.h"
#include "project.h"

typedef struct		s_testobj
{
	int				value;
}					t_testobj;

t_testobj			*testobj_new(int value)
{
	t_testobj		*obj;

	obj = malloc(sizeof(t_testobj));
	obj->value = value;
	return (obj);
}

void				*testobj_new_void(void)
{
	return (testobj_new(0));
}

static void simple_test(t_test *test)
{
	t_lst			*lst;

	lst = twl_lst_new_fill(10, testobj_new_void);

	t_testobj		*testobj;
	testobj = twl_lst_first(lst);
	mt_assert(testobj->value == 0);
	testobj = twl_lst_get(lst, 4);
	mt_assert(testobj->value == 0);
	testobj = twl_lst_last(lst);
	mt_assert(testobj->value == 0);
	mt_assert(twl_lst_len(lst) == 10);
	twl_lst_del(lst, free);
}

void	suite_twl_lst_new_fill(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
