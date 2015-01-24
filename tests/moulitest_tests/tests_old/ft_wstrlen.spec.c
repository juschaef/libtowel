#include "project.h"
#include <string.h>

UT_TEST(ft_wstrlen)
{
	UT_ASSERT(ft_wstrlen(L"") == 0);
	UT_ASSERT(ft_wstrlen(L"米") == 1);
	UT_ASSERT(ft_wstrlen(L"米米") == 2);
	UT_ASSERT(ft_wstrlen(L"𠜎𠜎𠜎") == 3);
	UT_ASSERT(ft_wstrlen(L"αααα") == 4);
}
