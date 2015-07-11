#include <project.h>
#include "twl_btree.h"


static int			cmp_fn(void *data1, void *data2)
{
	return (strcmp(data1, data2));
}

static void simple_test(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new();
	twl_btree_insert(btree, "A", cmp_fn);
	twl_btree_insert(btree, "B", cmp_fn);
	twl_btree_insert(btree, "C", cmp_fn);
	twl_btree_insert(btree, "D", cmp_fn);
	mt_assert(twl_btree_size(btree) == 4);
	free(btree);
}

static void simple_test2(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new();
	mt_assert(twl_btree_size(btree) == 0);
	free(btree);
}

void	suite_twl_btree_size(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
