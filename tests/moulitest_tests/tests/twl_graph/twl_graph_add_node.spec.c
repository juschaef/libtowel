#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph			*graph;
	t_node_id		node_id;

	graph = twl_graph_new();
	node_id = twl_graph_add_node(graph, strdup("A"));
	mt_assert(twl_graph_node_count(graph) == 1);
	twl_graph_add_node(graph, strdup("B"));
	twl_graph_add_node(graph, strdup("C"));
	twl_graph_add_node(graph, strdup("D"));
	mt_assert(twl_graph_node_count(graph) == 4);
}

void	suite_twl_graph_add_node(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
