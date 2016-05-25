#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id node0_id = twl_graph_add_node(graph, strdup("0"));
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_node_id nodeC_id = twl_graph_add_node(graph, strdup("C"));

	twl_graph_add_edge(graph, node0_id, nodeA_id, NULL);
	twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	twl_graph_add_edge(graph, nodeB_id, nodeC_id, NULL);
	mt_assert(twl_graph_node_count(graph) == 4);
	mt_assert(twl_graph_edge_count(graph) == 3);
	twl_graph_clear_remove_node(graph, nodeA_id);
	mt_assert(twl_graph_node_count(graph) == 3);
	mt_assert(twl_graph_edge_count(graph) == 1);
	t_graph_node	*nodeB = twl_graph_get_node(graph, nodeB_id);
	t_graph_node	*nodeC = twl_graph_get_node(graph, nodeC_id);
	mt_assert(twl_lst_len(twl_graph_node_get_edges(nodeB)) == 1);
	mt_assert(twl_lst_len(twl_graph_node_get_edges(nodeC)) == 1);
	twl_graph_del(graph, free, free);
}

void	suite_twl_graph_clear_remove_node(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
