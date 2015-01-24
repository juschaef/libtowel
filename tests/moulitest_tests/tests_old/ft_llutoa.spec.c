#include "project.h"
#include <limits.h>

UT_TEST(twl_llutoa)
{
	UT_ASSERT(strcmp(twl_llutoa(0L), "0") == 0);
	UT_ASSERT(strcmp(twl_llutoa(1L), "1") == 0);
	UT_ASSERT(strcmp(twl_llutoa(42L), "42") == 0);
	UT_ASSERT(strcmp(twl_llutoa(ULLONG_MAX), "18446744073709551615") == 0);
}
