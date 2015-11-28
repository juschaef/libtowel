#include <project.h>
#include "twl_json_node.h"

static void simple_test(t_test *test)
{
	t_json_node		*node;

	node = twl_json_node_new();
	mt_assert(node != NULL);
	twl_json_node_del(node);
}

void	suite_twl_json_node_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
