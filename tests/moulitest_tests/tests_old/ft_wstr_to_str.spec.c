#include "project.h"
#include <string.h>

UT_TEST(ft_wstr_to_str)
{
	char s[1000];

	sprintf(s, "%S", L"zα米𠜎");
	UT_ASSERT(strcmp(ft_wstr_to_str(L"zα米𠜎"), s) == 0);
}
