#include <project.h>
#include "twl_graph.h"

static int counter;

static void del_string_data_fn(void *elem)
{
	counter++;
	free(elem);
}

static void simple_test(t_test *test)
{
	counter = 0;

	t_graph_node	*node0;
	t_graph_node	*node1;
	t_graph_edge	*edge;

	node0 = twl_graph_node_new(0, strdup("A"));
	node1 = twl_graph_node_new(1, strdup("B"));
	edge = twl_graph_edge_new(0, node0, node1, NULL);
	twl_graph_edge_del(edge, del_string_data_fn);
	mt_assert(counter == 1);

}

static void test_edges_advanced(t_test *test)
{
	t_graph_node	*node0 = twl_graph_node_new(0, "111");
	t_graph_node	*node1 = twl_graph_node_new(1, "222");
	t_graph_node	*node2 = twl_graph_node_new(2, "333");
	t_graph_node	*node3 = twl_graph_node_new(3, "444");

	t_graph_edge *edge0 = twl_graph_edge_new(0, node0, node1, NULL);
	t_graph_edge *edge1 = twl_graph_edge_new(1, node0, node2, NULL);
	t_graph_edge *edge2 = twl_graph_edge_new(2, node0, node3, NULL);

	mt_assert(twl_lst_len(node0->edges_) == 3);

	twl_graph_edge_del(edge0, NULL);
	twl_graph_edge_del(edge1, NULL);

	t_graph_edge	*edge = twl_lst_first(node0->edges_);

	mt_assert(twl_lst_len(node0->edges_) == 1);
	mt_assert(edge->id_ == 2);
	twl_graph_node_del(node0, NULL);
	twl_graph_node_del(node1, NULL);
	twl_graph_node_del(node2, NULL);
	twl_graph_node_del(node3, NULL);
}

void	suite_twl_graph_edge_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_edges_advanced);
}
