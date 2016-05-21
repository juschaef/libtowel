#include <project.h>
#include "twl_string.h"

#define mt_test_memmove(name, _buf, mem1, mem2, n)	\
static void test_## name(t_test *test)				\
{													\
	char	buf1[100] = _buf;						\
	char	buf2[100] = _buf;						\
	mt_assert(buf1 mem1 == twl_memmove(buf1 mem1, buf1 mem2, n));	\
	memmove(buf2 mem1, buf2 mem2, n);				\
	mt_assert(strcmp(buf1, buf2) == 0);				\
}

mt_test_memmove(num1, "abcdefghijklmnopqrstuvwxyz", + 3, + 0, 10);
mt_test_memmove(num2, "abcdefghijklmnopqrstuvwxyz", + 0, + 3, 10);
mt_test_memmove(num3, "abcdefghijklmnopqrstuvwxyz", + 1, + 0, 1);
mt_test_memmove(num4, "abcdefghijklmnopqrstuvwxyz", + 0, + 1, 1);

void	suite_twl_memmove(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
}
