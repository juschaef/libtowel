#include "project.h"

UT_TEST(twl_strnewc)
{
	UT_ASSERT(memcmp(twl_strnewc(3, 'c'), "ccc", 3) == 0);
	UT_ASSERT(memcmp(twl_strnewc(0, 'c'), "", 0) == 0);
	UT_ASSERT(memcmp(twl_strnewc(10, 'x'), "xxxxxxxxxx", 10) == 0);
}
