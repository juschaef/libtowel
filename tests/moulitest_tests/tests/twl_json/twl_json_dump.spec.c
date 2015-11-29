#include <project.h>
#include "twl_json.h"

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
	mt_assert(strcmp(twl_json_dump(seq_node), "[21,42]") == 0);

	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

static void simple_test_2levels_array(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*root_array;
	t_jnode		*inner_array;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 21);
	node2 = twl_jnode_new_prim(JSON_NUMBER, 42);
	inner_array = twl_jnode_new_array();
	root_array = twl_jnode_new_array();
	twl_jnode_array_push(root_array, inner_array);
	twl_jnode_array_push(inner_array, node1);
	twl_jnode_array_push(root_array, node2);

	mt_assert(strcmp(twl_json_dump(root_array), "[[21],42]") == 0);

	twl_jnode_del(root_array);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

void	suite_twl_json_dump(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_2levels_array);
}
