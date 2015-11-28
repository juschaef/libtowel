#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new();
	mt_assert(node->value.primitive == 0);
	mt_assert(node->value.sequence == NULL);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
