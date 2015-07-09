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

static void test_edges_added_to_nodes(t_test *test)
{
	t_graph_node	*node0;
	t_graph_node	*node1;
	t_graph_edge	*edge;

	node0 = twl_graph_node_new(0, "A");
	node1 = twl_graph_node_new(1, "B");
	edge = twl_graph_edge_new(0, node0, node1, NULL);

	t_graph_edge	*edge_from_node0 = twl_lst_first(node0->edges_);
	t_graph_edge	*edge_from_node1 = twl_lst_first(node1->edges_);
	mt_assert(twl_lst_len(node0->edges_) == 1);
	mt_assert(edge_from_node0->id_ == 0);
	mt_assert(twl_lst_len(node1->edges_) == 1);
	mt_assert(edge_from_node1->id_ == 0);
}

void	suite_twl_graph_edge_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_edges_added_to_nodes);
}
