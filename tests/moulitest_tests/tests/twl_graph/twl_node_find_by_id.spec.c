#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	twl_graph		*graph;
	twl_graph_node		*node0;

	graph = twl_graph_new();
	node0 = twl_graph_node_new(strdup("A"));
	twl_graph_add(graph, node0);
	mt_assert(twl_node_find_by_id(graph->nodes_, node0->id_)->id_ == node0->id_);
}

void	suite_twl_node_find_by_id(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
