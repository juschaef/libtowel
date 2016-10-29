#include <project.h>
#include "twl_btree.h"

int counter;

static void			del_fn(void *data)
{
	counter++;
	free(data);
}

static void simple_test(t_test *test)
{
	t_btree_node	*node;
	counter = 0;

	node = twl_btree_node_new(strdup("coucou"));
	mt_assert(strcmp(node->data, "coucou") == 0);
	mt_assert(node->left == NULL);
	mt_assert(node->right == NULL);
	twl_btree_node_del(node, del_fn);
	mt_assert(counter == 1);
}

void	suite_twl_btree_node_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
