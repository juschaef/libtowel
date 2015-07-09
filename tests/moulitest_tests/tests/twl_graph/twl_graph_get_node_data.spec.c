#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph			*g;
	t_graph_node_id		node_id;

	g = twl_graph_new();
	node_id = twl_graph_add_node(g, strdup("ABC"));
	mt_assert(strcmp(twl_graph_get_node_data(g, node_id), "ABC") == 0);
}

static void test_null(t_test *test)
{
	t_graph			*g;
	t_graph_node_id		node_id;

	g = twl_graph_new();
	node_id = twl_graph_add_node(g, strdup("ABC"));
	mt_assert(twl_graph_get_node_data(g, 42) == NULL);
}

void	suite_twl_graph_get_node_data(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_null);
}
