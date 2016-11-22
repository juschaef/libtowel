#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new();
	mt_assert(node != NULL);
	twl_jnode_del(node);
}

void	suite_twl_jnode_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
