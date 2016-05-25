#include <project.h>
#include "twl_graph.h"

static bool find_fn(void *data, void *ctx)
{
	return (strcmp(data, ctx) == 0);
}

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	twl_graph_add_node(graph, strdup("AAA"));
	twl_graph_add_node(graph, strdup("BBB"));
	twl_graph_add_node(graph, strdup("CCC"));

	char			*data;
	data = twl_graph_find_node_data(graph, find_fn, "BBB");
	mt_assert(strcmp(data, "BBB") == 0);
	twl_graph_del(graph, free, free);
}


void	suite_twl_graph_find_node_data(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
