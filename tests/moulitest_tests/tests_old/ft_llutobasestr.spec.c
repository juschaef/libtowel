#include "project.h"
#include <limits.h>

UT_TEST(ft_llutobasestr)
{
	UT_ASSERT(strcmp(ft_llutobasestr(10, 16), "a") == 0);
	UT_ASSERT(strcmp(ft_llutobasestr(48879, 16), "beef") == 0);
	UT_ASSERT(strcmp(ft_llutobasestr(4242424242, 16), "fcde41b2") == 0);
	UT_ASSERT(strcmp(ft_llutobasestr(LLONG_MAX, 16), "7fffffffffffffff") == 0);
	UT_ASSERT(strcmp(ft_llutobasestr(ULLONG_MAX, 16), "ffffffffffffffff") == 0);
}
