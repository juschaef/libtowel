#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph		*graph;

	graph = twl_graph_new();
	mt_assert(twl_lst_len(graph->nodes_) == 0);
	twl_lst_del(graph->nodes_, NULL);
	free(graph);
}

void	suite_twl_graph_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
