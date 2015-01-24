#include "project.h"

UT_TEST(ft_strpad)
{
	UT_ASSERT(strequ(ft_strpad("ab", 1, FT_STRPAD_LEFT, ' '), "ab"));
	UT_ASSERT(strequ(ft_strpad("a", 1, FT_STRPAD_LEFT, ' '), "a"));
	UT_ASSERT(strequ(ft_strpad("a", 2, FT_STRPAD_LEFT, ' '), " a"));
	UT_ASSERT(strequ(ft_strpad("bon", 7, FT_STRPAD_LEFT, 'b'), "bbbbbon"));
	UT_ASSERT(strequ(ft_strpad("bon", 7, FT_STRPAD_RIGHT, 'b'), "bonbbbb"));
	UT_ASSERT(strequ(ft_strpad("bon", 1, FT_STRPAD_RIGHT, 'b'), "bon"));
}
