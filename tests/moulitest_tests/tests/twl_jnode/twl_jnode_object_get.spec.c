#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*node1b;
	t_jnode		*node2b;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_primitive(JSON_NUMBER, 21);
	node2 = twl_jnode_new_primitive(JSON_NUMBER, 42);
	seq_node = twl_jnode_new_array();
	twl_jnode_object_add(seq_node, node1, "key1");
	twl_jnode_object_add(seq_node, node2, "key2");
	mt_assert(twl_lst_len(seq_node->value.object) == 2);
	node1b = twl_jnode_object_get(seq_node, "key1");
	node2b = twl_jnode_object_get(seq_node, "key2");
	mt_assert(twl_jnode_get_primitive(node1b) == 21);
	mt_assert(twl_jnode_get_primitive(node2b) == 42);

	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

void	suite_twl_jnode_object_get(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
