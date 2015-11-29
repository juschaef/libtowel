#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_primitive(JSON_NUMBER, 1);
	node2 = twl_jnode_new_primitive(JSON_NUMBER, 2);
	seq_node = twl_jnode_new_array();
	twl_jnode_object_add(seq_node, node1, "key1");
	twl_jnode_object_add(seq_node, node2, "key2");
	mt_assert(twl_lst_len(seq_node->value.object) == 2);
	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

static void simple_test_parent(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_primitive(JSON_NUMBER, 1);
	node2 = twl_jnode_new_primitive(JSON_NUMBER, 2);
	seq_node = twl_jnode_new_array();
	twl_jnode_object_add(seq_node, node1, "key1");
	twl_jnode_object_add(seq_node, node2, "key2");
	mt_assert(node1->parent == seq_node);
	mt_assert(node2->parent == seq_node);
	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

void	suite_twl_jnode_object_add(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_parent);
}
