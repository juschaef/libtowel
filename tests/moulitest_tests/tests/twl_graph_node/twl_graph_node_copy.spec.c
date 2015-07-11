#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph_node			*node;
	t_graph_node			*node_new;

	node = twl_graph_node_new(0, strdup("A"));
	node_new = twl_graph_node_copy(node);
	mt_assert(twl_graph_node_get_id(node) == twl_graph_node_get_id(node_new));
	mt_assert(strcmp(twl_graph_node_get_data(node), twl_graph_node_get_data(node_new)) == 0);
}
void	suite_twl_graph_node_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
