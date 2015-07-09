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
	t_graph		*graph;

	counter = 0;

	graph = twl_graph_new();
	twl_graph_add(graph, twl_graph_node_new(strdup("B")));
	twl_graph_add(graph, twl_graph_node_new(strdup("C")));
	twl_graph_add(graph, twl_graph_node_new(strdup("D")));

	twl_graph_del(graph, del_string_data_fn);
	mt_assert(counter == 3);
}

void	suite_twl_graph_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
