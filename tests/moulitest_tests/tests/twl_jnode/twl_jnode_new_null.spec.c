#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_null();
	mt_assert(node->type == JSON_NULL);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_null(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
