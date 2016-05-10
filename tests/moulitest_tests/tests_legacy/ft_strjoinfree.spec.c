#include "project.h"

UT_TEST(twl_strjoinfree)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = strdup("aaa");
	str2 = strdup("bbb");
	str3 = twl_strjoinfree(str1, str2, 'b');
	UT_ASSERT(strequ(str3, "aaabbb"));
	free(str3);

	str1 = strdup("aaa");
	str2 = strdup("bbb");
	str3 = twl_strjoinfree(str1, str2, 'l');
	UT_ASSERT(strequ(str3, "aaabbb"));
	free(str3);
	free(str2);

	str1 = strdup("aaa");
	str2 = strdup("bbb");
	str3 = twl_strjoinfree(str1, str2, 'r');
	UT_ASSERT(strequ(str3, "aaabbb"));
	free(str3);
	free(str1);

	str1 = strdup("aaa");
	str2 = strdup("bbb");
	str3 = twl_strjoinfree(str1, str2, 0);
	UT_ASSERT(strequ(str3, "aaabbb"));
	free(str3);
	free(str2);
	free(str1);

	UT_ASSERT_W(0 && "test free needed");
}
