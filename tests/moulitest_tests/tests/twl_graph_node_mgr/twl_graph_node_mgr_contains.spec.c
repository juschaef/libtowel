#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	t_graph_node *node = twl_graph_node_mgr_find_by_id(graph->nodes_, twl_graph_add_node(graph, strdup("A")));
	mt_assert(twl_graph_node_mgr_contains(graph->nodes_, node) == true);
	twl_graph_del(graph, free, free);
}

static void test_not_found(t_test *test)
{
	t_graph		*graph;
	t_graph		*graph_empty;

	graph = twl_graph_new();
	graph_empty = twl_graph_new();
	t_graph_node *node = twl_graph_node_mgr_find_by_id(graph->nodes_, twl_graph_add_node(graph, strdup("A")));
	mt_assert(twl_graph_node_mgr_contains(graph_empty->nodes_, node) == false);
	twl_graph_del(graph, free, free);
}

void	suite_twl_graph_node_mgr_contains(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_not_found);
}
