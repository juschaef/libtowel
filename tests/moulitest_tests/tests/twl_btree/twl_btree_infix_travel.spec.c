#include <project.h>
#include "twl_btree.h"

static void			travl_fn(void *str_, void *accumulator_)
{
	char			*accumulator;
	char			*str;

	accumulator = accumulator_;
	str = str_;
	while (*accumulator)
		accumulator++;
	*accumulator = *str;
}

static int			cmp_fn(void *data1, void *data2)
{
	return (strcmp(data1, data2));
}

static void simple_test(t_test *test)
{
	t_btree			*btree;
	char			str[30];

	*str = 0;
	btree = twl_btree_new(cmp_fn);
	twl_btree_insert(btree, "A");
	twl_btree_insert(btree, "B");
	twl_btree_insert(btree, "C");
	twl_btree_insert(btree, "D");
	twl_btree_infix_travel(btree, travl_fn, str);
	mt_assert(strcmp(str, "ABCD") == 0);
	twl_btree_del(btree);
}

void	suite_twl_btree_infix_travel(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
