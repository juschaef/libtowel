#include <project.h>
#include "twl_jnode.h"

static void simple_test(t_test *test)
{
	t_jnode		*node;

	node = twl_jnode_new_seq(JSON_ARRAY);
	mt_assert(twl_lst_len(node->value.seq) == 0);
	mt_assert(node->type == JSON_ARRAY);
	twl_jnode_del(node);
}

void	suite_twl_jnode_new_seq(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
