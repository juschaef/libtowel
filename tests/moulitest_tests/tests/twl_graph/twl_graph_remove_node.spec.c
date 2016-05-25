#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));

	mt_assert(twl_graph_node_count(graph) == 2);
	twl_graph_remove_node(graph, nodeA_id);
	mt_assert(twl_graph_node_count(graph) == 1);
	(void)nodeB_id;
	twl_graph_del(graph, free, free);
}

void	suite_twl_graph_remove_node(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
