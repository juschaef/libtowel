#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 21);
	node2 = twl_jnode_new_prim(JSON_NUMBER, 42);
	seq_node = twl_jnode_new_array();
	twl_jnode_array_push(seq_node, node1);
	twl_jnode_array_push(seq_node, node2);
	mt_assert(twl_jnode_array_get(seq_node, 0)->value.prim == 21);
	mt_assert(twl_jnode_array_get(seq_node, 1)->value.prim == 42);
	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

void	suite_twl_jnode_array_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
