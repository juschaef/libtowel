#include <project.h>
#include "twl_string.h"

#define mt_test_strncpy(name, src, dst, n, debug)		\
static void test_## name(t_test *test)					\
{														\
	char src1[101];memset(src1,'0',100);*src1=0;src1[100]=0;strcat(src1,src);\
	char src2[101];memset(src2,'0',100);*src2=0;src2[100]=0;strcat(src2,src);\
	char dst1[101];memset(dst1,'0',100);*dst1=0;dst1[100]=0;strcat(dst1,dst);\
	char dst2[101];memset(dst2,'0',100);*dst2=0;dst2[100]=0;strcat(dst2,dst);\
	twl_strncpy(dst1, src1, n); strncpy(dst2, src2, n);	\
	if (debug)											\
	{													\
		printf("%s -- %s\n", src, dst);					\
		printf("src1: %s\n", src1);						\
		printf("dst1: %s\n", dst1);						\
		printf("src2: %s\n", src2);						\
		printf("dst2: %s\n", dst2);						\
    }													\
	mt_assert(memcmp(dst1, dst2, 100) == 0);			\
}

mt_test_strncpy(num1a, "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10, true);
mt_test_strncpy(num2a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz", 10, true);
mt_test_strncpy(num3a, "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 40, true);
mt_test_strncpy(num4a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz", 40, true);
mt_test_strncpy(num1b, "abcde", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10, true);
mt_test_strncpy(num2b, "ABCDE", "abcdefghijklmnopqrstuvwxyz", 10, true);
mt_test_strncpy(num3b, "abcde", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 40, true);
mt_test_strncpy(num4b, "ABCDE", "abcdefghijklmnopqrstuvwxyz", 40, true);
mt_test_strncpy(num1c, "abcdefghijklmnopqrstuvwxyz", "ABCDE", 10, true);
mt_test_strncpy(num2c, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcde", 10, true);
mt_test_strncpy(num3c, "abcdefghijklmnopqrstuvwxyz", "ABCDE", 40, true);
mt_test_strncpy(num4c, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcde", 40, true);

void	suite_twl_strncpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1a);
	SUITE_ADD_TEST(suite, test_num2a);
	SUITE_ADD_TEST(suite, test_num3a);
	SUITE_ADD_TEST(suite, test_num4a);
	SUITE_ADD_TEST(suite, test_num1b);
	SUITE_ADD_TEST(suite, test_num2b);
	SUITE_ADD_TEST(suite, test_num3b);
	SUITE_ADD_TEST(suite, test_num4b);
	SUITE_ADD_TEST(suite, test_num1c);
	SUITE_ADD_TEST(suite, test_num2c);
	SUITE_ADD_TEST(suite, test_num3c);
	SUITE_ADD_TEST(suite, test_num4c);
}
