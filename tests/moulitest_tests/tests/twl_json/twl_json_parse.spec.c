#include <project.h>
#include "twl_json.h"

static void simple_test_boolean_true(t_test *test)
{
	t_json_node		*node;

	node = twl_json_parse("true");
	mt_assert(twl_json_node_is_bool(node) == true);
	mt_assert(twl_json_node_get_bool(node) == true);
}

static void simple_test_boolean_false(t_test *test)
{
	t_json_node		*node;

	node = twl_json_parse("false");
	mt_assert(twl_json_node_is_bool(node) == true);
	mt_assert(twl_json_node_get_bool(node) == false);
}

void	suite_twl_json_parse(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test_boolean_true);
	SUITE_ADD_TEST(suite, simple_test_boolean_false);
}
