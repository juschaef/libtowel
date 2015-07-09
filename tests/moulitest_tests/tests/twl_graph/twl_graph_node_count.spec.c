#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	twl_graph_add_node(graph, strdup("A"));
	twl_graph_add_node(graph, strdup("B"));
	twl_graph_add_node(graph, strdup("C"));
	twl_graph_add_node(graph, strdup("D"));
	twl_graph_add_node(graph, strdup("E"));
	mt_assert(twl_graph_node_count(graph) == 5);
}

static void empty_graph(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	mt_assert(twl_graph_node_count(graph) == 0);
}

void	suite_twl_graph_node_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, empty_graph);
}
