#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));

	t_graph_edge_id edge_id = twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	t_graph_node  *nodeA = twl_graph_node_mgr_find_by_id(graph->nodes_, nodeA_id);
	mt_assert(strcmp(nodeA->data_, "A") == 0);
	mt_assert(twl_lst_len(nodeA->edges_) == 1);
	(void)edge_id;
	twl_graph_del(graph, free, free);
}

static void test_error_same_node(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));

	t_graph_edge_id edge_id = twl_graph_add_edge(graph, nodeA_id, nodeA_id, NULL);
	mt_assert(edge_id == -1);
	twl_graph_del(graph, free, free);
}

static void test_multiple_edges_for_same_nodes(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));

	t_graph_edge_id edge1_id = twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	t_graph_edge_id edge2_id = twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	mt_assert(edge1_id != edge2_id);
	twl_graph_del(graph, free, free);
}

void	suite_twl_graph_add_edge(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_error_same_node);
	SUITE_ADD_TEST(suite, test_multiple_edges_for_same_nodes);
}
