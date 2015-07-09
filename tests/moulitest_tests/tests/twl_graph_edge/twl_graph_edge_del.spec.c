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

void	suite_twl_graph_edge_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
