#include <project.h>
#include "twl_byte.h"

static void simple_test(t_test *test)
{
	int				nbr;

	nbr = 0x01020304;
	twl_byterev(&nbr, sizeof(nbr));
	mt_assert(nbr == 0x04030201);
}

void	suite_twl_byterev(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
