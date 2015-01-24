#include "project.h"
#include <string.h>

UT_TEST(ft_wchar_to_str)
{
	char s[1000];

	sprintf(s, "%C", L'a');
	UT_ASSERT(strcmp(ft_wchar_to_str(L'a'), s) == 0);
	
	sprintf(s, "%C", L'α');
	UT_ASSERT(strcmp(ft_wchar_to_str(L'α'), s) == 0);
	
	sprintf(s, "%C", L'米');
	UT_ASSERT(strcmp(ft_wchar_to_str(L'米'), s) == 0);
	
	sprintf(s, "%C", L'𠜎');
	UT_ASSERT(strcmp(ft_wchar_to_str(L'𠜎'), s) == 0);
}
