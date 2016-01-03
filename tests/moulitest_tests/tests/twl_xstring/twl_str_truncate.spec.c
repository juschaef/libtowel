#include <project.h>
#include "twl_printf.h"

#define TEST_TWL_STR_TRUNCATE(test_name, str, len, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char		*actual; \
		actual = twl_str_truncate(str, len); \
		if (debug) \
		{ \
			printf("input     : <%s> len=%d\n", str, len); \
			printf("actual    : <%s>\n", actual); \
			printf("expected  : <%s>\n", expected); \
		} \
		mt_assert(strcmp(actual, expected) == 0); \
		free(actual); \
	}

TEST_TWL_STR_TRUNCATE(01, "123456789012345", 10, "1234567...", false);
TEST_TWL_STR_TRUNCATE(02, "123456789012345", 4, "1...", false);
TEST_TWL_STR_TRUNCATE(03, "123456789012345", 3, "123", false);
TEST_TWL_STR_TRUNCATE(04, "123456789012345", 2, "12", false);
TEST_TWL_STR_TRUNCATE(05, "123456789012345", 0, "", false);

void	suite_twl_str_truncate(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
}
