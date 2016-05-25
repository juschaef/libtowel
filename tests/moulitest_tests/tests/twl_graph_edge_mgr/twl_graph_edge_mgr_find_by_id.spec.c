#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph			*graph;
	t_graph_node_id		nodeA_id;
	t_graph_node_id		nodeB_id;

	graph = twl_graph_new();
	nodeA_id = twl_graph_add_node(graph, strdup("A"));
	nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_edge_id edge_id = twl_graph_add_edge(graph, nodeA_id, nodeB_id, strdup("edge data"));
	t_graph_edge *edge = twl_graph_edge_mgr_find_by_id(graph->edges_, edge_id);
	mt_assert(strcmp(edge->data_, "edge data") == 0);
	twl_graph_del(graph, free, free);
}

static void test_not_found(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	mt_assert(twl_graph_edge_mgr_find_by_id(graph->edges_, 4200) == NULL);
	twl_graph_del(graph, free, free);
}

void	suite_twl_graph_edge_mgr_find_by_id(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_not_found);
}
