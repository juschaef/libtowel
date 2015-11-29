#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_object();
	mt_assert(twl_dict_len(node->value.object) == 0);
	mt_assert(node->type == JSON_OBJECT);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_object(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
