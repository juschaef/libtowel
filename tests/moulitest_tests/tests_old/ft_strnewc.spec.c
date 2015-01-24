#include "project.h"

UT_TEST(ft_strnewc)
{
	UT_ASSERT(memcmp(ft_strnewc(3, 'c'), "ccc", 3) == 0);
	UT_ASSERT(memcmp(ft_strnewc(0, 'c'), "", 0) == 0);
	UT_ASSERT(memcmp(ft_strnewc(10, 'x'), "xxxxxxxxxx", 10) == 0);
}
