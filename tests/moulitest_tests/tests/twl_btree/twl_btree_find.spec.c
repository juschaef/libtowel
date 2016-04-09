#include <project.h>
#include "twl_btree.h"

static int			cmp_fn(void *data1, void *data2)
{
	return (strcmp(data1, data2));
}

static void simple_test(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new(cmp_fn);
	twl_btree_insert(btree, "A");
	twl_btree_insert(btree, "B");
	twl_btree_insert(btree, "C");
	twl_btree_insert(btree, "D");
	mt_assert(strcmp(twl_btree_find(btree, "A"), "A") == 0);
	mt_assert(strcmp(twl_btree_find(btree, "B"), "B") == 0);
	twl_btree_del(btree);
}

static void simple_test2(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new(cmp_fn);
	twl_btree_insert(btree, "A");
	twl_btree_insert(btree, "B");
	twl_btree_insert(btree, "C");
	twl_btree_insert(btree, "D");
	mt_assert(twl_btree_find(btree, "V") == NULL);
	twl_btree_del(btree);
}

static void simple_test3(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new(cmp_fn);
	mt_assert(twl_btree_find(btree, "A") == NULL);
	twl_btree_del(btree);
}


void	suite_twl_btree_find(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
	SUITE_ADD_TEST(suite, simple_test3);
}
