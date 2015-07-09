#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;
	t_graph_node	*node0;
	t_graph_node	*node1;
	t_graph_node	*node2;
	t_graph_node	*node3;
	t_graph_node	*node4;

	graph = twl_graph_new();
	node0 = twl_graph_node_new(strdup("A"));
	node1 = twl_graph_node_new(strdup("B"));
	node2 = twl_graph_node_new(strdup("C"));
	node3 = twl_graph_node_new(strdup("D"));
	node4 = twl_graph_node_new(strdup("E"));
	twl_graph_add(graph, node0);
	twl_graph_add(graph, node1);
	twl_graph_add(graph, node2);
	twl_graph_add(graph, node3);
	twl_graph_add(graph, node4);
	twl_graph_link(graph, node0, node1);
	twl_graph_link(graph, node1, node2);
	twl_graph_link(graph, node2, node3);
	twl_graph_link(graph, node3, node4);
	mt_assert(twl_graph_size(graph) == 5);
}

void	suite_twl_graph_size(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
