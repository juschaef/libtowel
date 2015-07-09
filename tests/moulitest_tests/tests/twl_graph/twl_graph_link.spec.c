#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;
	t_graph_node	*node0;
	t_graph_node	*node1;

	graph = twl_graph_new();
	node0 = twl_graph_node_new(strdup("A"));
	node1 = twl_graph_node_new(strdup("B"));
	twl_graph_add(graph, node0);
	twl_graph_add(graph, node1);
	twl_graph_link(node0, node1);
	t_graph_node  *tmp1 = twl_lst_first(node0->links_);
	t_graph_node  *tmp2 = twl_lst_first(node1->links_);
	mt_assert(tmp1->id_ == node1->id_);
	mt_assert(tmp2->id_ == node0->id_);
}

void	suite_twl_graph_link(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
