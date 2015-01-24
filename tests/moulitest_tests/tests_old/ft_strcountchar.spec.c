#include "project.h"
#include <limits.h>

UT_TEST(ft_strcountchar)
{
	UT_ASSERT(ft_strcountchar("", 'a') == 0);
	UT_ASSERT(ft_strcountchar("abca", 'a') == 2);
	UT_ASSERT(ft_strcountchar("aaaaaa", 'a') == 6);
	UT_ASSERT(ft_strcountchar("aaabaaa", 'a') == 6);
}
