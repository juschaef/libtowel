#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph			*graph;

	graph = twl_graph_new();
	t_graph_node_id	nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id	nodeB_id = twl_graph_add_node(graph, strdup("B"));
	twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);

	t_graph			*new_graph;

	new_graph = twl_graph_copy(graph);
	mt_assert(twl_graph_node_count(graph) == twl_graph_node_count(new_graph));
	mt_assert(twl_graph_edge_count(graph) == twl_graph_edge_count(new_graph));
	mt_assert(new_graph->nodes_ != graph->nodes_);
	mt_assert(new_graph->edges_ != graph->edges_);
	mt_assert(twl_lst_first(new_graph->nodes_) != twl_lst_first(graph->nodes_));
	mt_assert(twl_lst_first(new_graph->edges_) != twl_lst_first(graph->edges_));
}

void	suite_twl_graph_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
