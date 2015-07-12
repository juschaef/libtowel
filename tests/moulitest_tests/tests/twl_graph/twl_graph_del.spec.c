#include <project.h>
#include "twl_xstdio.h"
#include "twl_graph.h"

static int node_del_counter;
static int edge_del_counter;

static void del_node_data_fn(void *elem)
{
	node_del_counter++;
	free(elem);
}

static void del_edge_data_fn(void *elem)
{
	edge_del_counter++;
	free(elem);
}

static void simple_test(t_test *test)
{
	t_graph		*graph;

	node_del_counter = 0;
	edge_del_counter = 0;

	COUCOU;
	graph = twl_graph_new();
	t_graph_node_id	nodeA_id = twl_graph_add_node(graph, strdup("node A"));
	t_graph_node_id	nodeB_id = twl_graph_add_node(graph, strdup("node B"));
	t_graph_node_id	nodeC_id = twl_graph_add_node(graph, strdup("node C"));
	twl_graph_add_edge(graph, nodeA_id, nodeB_id, strdup("edge 1"));
	twl_graph_add_edge(graph, nodeB_id, nodeC_id, strdup("edge 2"));

	twl_graph_del(graph, del_node_data_fn, del_edge_data_fn);
	mt_assert(node_del_counter == 3);
	mt_assert(edge_del_counter == 2);
}

void	suite_twl_graph_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
