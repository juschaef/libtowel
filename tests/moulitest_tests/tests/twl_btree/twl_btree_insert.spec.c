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
	mt_assert(strcmp(btree->head->data, "A") == 0);
	mt_assert(strcmp(btree->head->right->data, "B") == 0);
	mt_assert(btree->head->left == NULL);
	twl_btree_del(btree);
}

static void simple_test2(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new();
	twl_btree_insert(btree, "2", cmp_fn);
	twl_btree_insert(btree, "3", cmp_fn);
	twl_btree_insert(btree, "1", cmp_fn);
	mt_assert(strcmp(btree->head->data, "2") == 0);
	mt_assert(strcmp(btree->head->left->data, "1") == 0);
	mt_assert(strcmp(btree->head->right->data, "3") == 0);
	twl_btree_del(btree);
}

static void simple_test3(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new();
	twl_btree_insert(btree, "1", cmp_fn);
	twl_btree_insert(btree, "2", cmp_fn);
	twl_btree_insert(btree, "2", cmp_fn);
	mt_assert(twl_btree_size(btree) == 2);
	twl_btree_del(btree);
}

void	suite_twl_btree_insert(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
	SUITE_ADD_TEST(suite, simple_test3);
}
