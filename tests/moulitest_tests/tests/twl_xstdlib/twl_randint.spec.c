#include <project.h>
#include "twl_xstdlib.h"
#include <string.h>

static void simple_test(t_test *test)
{
	int i;

	i = twl_randint(0, 10);
	mt_assert(i >= 0 && i <= 10);
	

}

void	suite_twl_randint(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
