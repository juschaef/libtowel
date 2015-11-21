#include <project.h>
#include "twl_vector2.h"

static void simple_test(t_test *test)
{
	t_vector2		*v1 = twl_vector2_new(1,1);
	t_vector2		*v2 = twl_vector2_new(1,2);

	mt_assert(!twl_vector2_is_equal(v1, v2));
	twl_vector2_del(v1);
	twl_vector2_del(v2);
}

static void simple_test2(t_test *test)
{
	t_vector2		*v1 = twl_vector2_new(1,1);
	t_vector2		*v2 = twl_vector2_new(1,2);

	v2->y = 1;
	mt_assert(twl_vector2_is_equal(v1, v2));
	twl_vector2_del(v1);
	twl_vector2_del(v2);
}

void	suite_twl_vector2_is_equal(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_test2);
}
