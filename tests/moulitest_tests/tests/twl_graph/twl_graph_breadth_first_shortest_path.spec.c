#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_node_id nodeC_id = twl_graph_add_node(graph, strdup("C"));
	t_graph_node_id nodeD_id = twl_graph_add_node(graph, strdup("D"));
	t_graph_node_id nodeE_id = twl_graph_add_node(graph, strdup("E"));

	twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	twl_graph_add_edge(graph, nodeB_id, nodeC_id, NULL);
	twl_graph_add_edge(graph, nodeC_id, nodeD_id, NULL);
	twl_graph_add_edge(graph, nodeA_id, nodeE_id, NULL);
	twl_graph_breadth_first_shortest_path(graph, nodeA_id, nodeC_id);
	mt_assert(false);
}

void	suite_twl_graph_breadth_first_shortest_path(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}

/*


A B C D E

*/
