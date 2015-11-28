#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_prim(JSON_BOOL, true);
	mt_assert(node->value.prim == 1);
	mt_assert(node->type == JSON_BOOL);
	twl_jnode_del(node);
}

static void simple_test2(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_prim(JSON_NUMBER, 42);
	mt_assert(node->value.prim == 42);
	mt_assert(node->type == JSON_NUMBER);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_prim(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
