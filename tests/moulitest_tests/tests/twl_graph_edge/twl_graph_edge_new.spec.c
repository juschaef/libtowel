#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph_node	*node0;
	t_graph_node	*node1;
	t_graph_edge	*edge;

	node0 = twl_graph_node_new(0, "A");
	node1 = twl_graph_node_new(1, "B");
	edge = twl_graph_edge_new(0, node0, node1, NULL);
	mt_assert(edge->left_node_->id_ == node0->id_);
	mt_assert(edge->right_node_->id_ == node1->id_);
}

void	suite_twl_graph_edge_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
