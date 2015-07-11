#include <project.h>
#include "twl_btree.h"

static void			travl_fn(void *str_, void *count_ptr_)
{
	int				*count_ptr;

	count_ptr = count_ptr_;
	*count_ptr += 1;
	(void)str_;
}

static int			cmp_fn(void *data1, void *data2)
{
	return (strcmp(data1, data2));
}

static void simple_test(t_test *test)
{
	t_btree			*btree;
	int				count;

	count = 0;

	btree = twl_btree_new();
	twl_btree_insert(btree, "A", cmp_fn);
	twl_btree_insert(btree, "B", cmp_fn);
	twl_btree_insert(btree, "C", cmp_fn);
	twl_btree_insert(btree, "D", cmp_fn);
	twl_btree_infix_travel(btree, travl_fn, &count);
	mt_assert(count == 4);
	twl_btree_del(btree);
}

void	suite_twl_btree_infix_travel(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
