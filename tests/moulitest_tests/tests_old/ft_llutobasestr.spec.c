#include "project.h"
#include <limits.h>

UT_TEST(twl_llutobasestr)
{
	UT_ASSERT(strcmp(twl_llutobasestr(10, 16), "a") == 0);
	UT_ASSERT(strcmp(twl_llutobasestr(48879, 16), "beef") == 0);
	UT_ASSERT(strcmp(twl_llutobasestr(4242424242, 16), "fcde41b2") == 0);
	UT_ASSERT(strcmp(twl_llutobasestr(LLONG_MAX, 16), "7fffffffffffffff") == 0);
	UT_ASSERT(strcmp(twl_llutobasestr(ULLONG_MAX, 16), "ffffffffffffffff") == 0);
}
