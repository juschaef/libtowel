#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	twl_graph		*graph;
	twl_graph_node		*node0;

	graph = twl_graph_new();
	node0 = twl_graph_node_new(strdup("A"));
	twl_graph_add(graph, node0);
	mt_assert(twl_lst_len(graph->nodes_) == 1);
	twl_graph_add(graph, twl_graph_node_new(strdup("B")));
	twl_graph_add(graph, twl_graph_node_new(strdup("C")));
	twl_graph_add(graph, twl_graph_node_new(strdup("D")));
	mt_assert(twl_lst_len(graph->nodes_) == 4);
}

void	suite_twl_graph_add(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
