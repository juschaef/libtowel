#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 1);
	node2 = twl_jnode_new_prim(JSON_NUMBER, 2);
	seq_node = twl_jnode_new_seq(JSON_ARRAY);
	twl_jnode_seq_push(seq_node, node1);
	twl_jnode_seq_push(seq_node, node2);
	mt_assert(twl_lst_len(seq_node->value.seq) == 2);
	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

static void simple_test2(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 1);
	seq_node = twl_jnode_new_seq(JSON_ARRAY);
	twl_jnode_seq_push(seq_node, node1);
	twl_jnode_seq_push(seq_node, node1);
	twl_jnode_seq_push(seq_node, node1);
	twl_jnode_seq_push(seq_node, node1);
	mt_assert(twl_lst_len(seq_node->value.seq) == 4);
	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
}

void	suite_twl_jnode_seq_push(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
