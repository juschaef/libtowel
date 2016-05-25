#include <project.h>
#include "twl_graph.h"

static void test_edges_advanced(t_test *test)
{
	t_graph_node	*node0 = twl_graph_node_new(0, "000");
	t_graph_node	*node1 = twl_graph_node_new(1, "111");
	t_graph_node	*node2 = twl_graph_node_new(2, "222");
	t_graph_node	*node3 = twl_graph_node_new(3, "333");
	t_graph_node	*node4 = twl_graph_node_new(3, "444");

	twl_graph_edge_new(0, node0, node1, NULL);
	twl_graph_edge_new(1, node0, node2, NULL);
	twl_graph_edge_new(2, node0, node3, NULL);

	t_lst			*neighbors = twl_graph_node_neighbors(node0);
	t_graph_node	*neighbors_0 = twl_lst_get(neighbors, 0);
	t_graph_node	*neighbors_1 = twl_lst_get(neighbors, 1);
	t_graph_node	*neighbors_2 = twl_lst_get(neighbors, 2);
	mt_assert(twl_lst_len(neighbors) == 3);
	mt_assert(strcmp(twl_graph_node_get_data(neighbors_0), "111") == 0);
	mt_assert(strcmp(twl_graph_node_get_data(neighbors_1), "222") == 0);
	mt_assert(strcmp(twl_graph_node_get_data(neighbors_2), "333") == 0);
	twl_lst_del(neighbors, NULL);
}

void	suite_twl_graph_node_neighbors(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_edges_advanced);
}
