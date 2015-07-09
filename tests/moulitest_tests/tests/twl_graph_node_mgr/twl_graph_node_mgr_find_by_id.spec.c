#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	t_graph_node_id node_id = twl_graph_add_node(graph, strdup("A"));
	mt_assert(twl_graph_node_mgr_find_by_id(graph->nodes_, node_id)->id_ == node_id);
}

static void test_not_found(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	mt_assert(twl_graph_node_mgr_find_by_id(graph->nodes_, 4200) == NULL);
}

void	suite_twl_graph_node_mgr_find_by_id(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_not_found);
}
