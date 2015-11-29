#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_prim(JSON_BOOL, true);
	twl_jnode_set_key(node, "abc");
	mt_assert(strcmp(twl_jnode_get_key(node), "abc") == 0);
	twl_jnode_del(node);
}

void	suite_twl_jnode_set_key(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
