#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_primitive(JSON_BOOL, true);
	mt_assert(node->value.primitive == 1);
	mt_assert(node->type == JSON_BOOL);
	twl_jnode_del(node);
}

static void simple_test2(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_primitive(JSON_NUMBER, 42);
	mt_assert(node->value.primitive == 42);
	mt_assert(node->type == JSON_NUMBER);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_primitive(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
