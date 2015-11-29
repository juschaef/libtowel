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

static void simple_object(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 21);
	node2 = twl_jnode_new_prim(JSON_NUMBER, 42);
	seq_node = twl_jnode_new_object();
	twl_jnode_object_add(seq_node, node1, "key1");
	twl_jnode_object_add(seq_node, node2, "key2");
	mt_assert(strcmp(twl_json_dump(seq_node), "{\"key1\":21,\"key2\":42}") == 0);

	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

static void simple_object_with_array(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*object1;
	t_jnode		*object2;
	t_jnode		*inner_array;

	node1 = twl_jnode_new_prim(JSON_NUMBER, 21);
	node2 = twl_jnode_new_prim(JSON_NUMBER, 42);
	inner_array = twl_jnode_new_array();
	object1 = twl_jnode_new_object();
	object2 = twl_jnode_new_object();
	twl_jnode_array_push(inner_array, node1);
	twl_jnode_object_add(object1, inner_array, "key1");
	twl_jnode_object_add(object1, object2, "key2");
	twl_jnode_object_add(object2, node2, "key3");
	mt_assert(strcmp(twl_json_dump(object1), "{\"key1\":[21],\"key2\":{\"key3\":42}}") == 0);

	twl_jnode_del(object1);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

static void simple_test_bool(t_test *test)
{
	t_jnode		*node1;
	t_jnode		*node2;
	t_jnode		*seq_node;

	node1 = twl_jnode_new_prim(JSON_BOOL, true);
	node2 = twl_jnode_new_prim(JSON_BOOL, false);
	seq_node = twl_jnode_new_array();
	twl_jnode_array_push(seq_node, node1);
	twl_jnode_array_push(seq_node, node2);
	mt_assert(strcmp(twl_json_dump(seq_node), "[true,false]") == 0);

	twl_jnode_del(seq_node);
	twl_jnode_del(node1);
	twl_jnode_del(node2);
}

void	suite_twl_json_dump(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test_2levels_array);
	SUITE_ADD_TEST(suite, simple_object);
	SUITE_ADD_TEST(suite, simple_object_with_array);
	SUITE_ADD_TEST(suite, simple_test_bool);
}
