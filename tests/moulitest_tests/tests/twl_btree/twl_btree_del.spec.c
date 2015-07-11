#include <project.h>
#include "twl_btree.h"

static void simple_test(t_test *test)
{
	t_btree			*btree;

	btree = twl_btree_new();
	mt_assert(btree->head == NULL);
	twl_btree_del(btree);
}

void	suite_twl_btree_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
