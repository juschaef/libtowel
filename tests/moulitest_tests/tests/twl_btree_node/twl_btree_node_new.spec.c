#include <project.h>
#include "twl_btree.h"

static void simple_test(t_test *test)
{
	t_btree_node	*node;

	node = twl_btree_node_new("coucou");
	mt_assert(strcmp(node->data, "coucou") == 0);
	mt_assert(node->left == NULL);
	mt_assert(node->right == NULL);
}

void	suite_twl_btree_node_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
