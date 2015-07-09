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
}

void	suite_twl_graph_add_edge(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
