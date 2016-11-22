#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_string("ABC");
	mt_assert(strcmp(node->value.string, "ABC") == 0);
	mt_assert(node->type == JSON_STRING);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_string(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
