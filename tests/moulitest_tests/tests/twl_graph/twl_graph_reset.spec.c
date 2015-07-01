#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	twl_graph		*graph;
	twl_graph_node	*node0;

	graph = twl_graph_new();
	node0 = twl_graph_node_new(strdup("A"));
	node0->is_visited_ = true;
	twl_graph_add(graph, node0);
	twl_graph_node	*tmp = twl_lst_first(graph->nodes_);
	mt_assert(tmp->is_visited_ == true);
	twl_graph_reset(graph);
	mt_assert(tmp->is_visited_ == false);

}

void	suite_twl_graph_reset(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
