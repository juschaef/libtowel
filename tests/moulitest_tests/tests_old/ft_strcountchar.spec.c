#include "project.h"
#include <limits.h>

UT_TEST(twl_strcountchar)
{
	UT_ASSERT(twl_strcountchar("", 'a') == 0);
	UT_ASSERT(twl_strcountchar("abca", 'a') == 2);
	UT_ASSERT(twl_strcountchar("aaaaaa", 'a') == 6);
	UT_ASSERT(twl_strcountchar("aaabaaa", 'a') == 6);
}
