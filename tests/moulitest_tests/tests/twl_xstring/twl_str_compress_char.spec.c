#include <project.h>
#include "twl_printf.h"

static void test_compress_two_char_to_one(t_test *test)
{
	mt_assert(strcmp(twl_str_compress_char("a  b", ' '), "a b") == 0);
}

static void test_compress_many_chars(t_test *test)
{
	mt_assert(strcmp(twl_str_compress_char("__a___b____c____", '_'), "_a_b_c_") == 0);
}

static void test_empty_string(t_test *test)
{
	mt_assert(strcmp(twl_str_compress_char("", '_'), "") == 0);
}

static void test_string_with_only_compressed_char(t_test *test)
{
	mt_assert(strcmp(twl_str_compress_char("*****", '*'), "*") == 0);
}

static void test_with_not_matching_char(t_test *test)
{
	mt_assert(strcmp(twl_str_compress_char("***", '#'), "***") == 0);
}

void	suite_twl_str_compress_char(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_compress_two_char_to_one);
	SUITE_ADD_TEST(suite, test_compress_many_chars);
	SUITE_ADD_TEST(suite, test_empty_string);
	SUITE_ADD_TEST(suite, test_string_with_only_compressed_char);
	SUITE_ADD_TEST(suite, test_with_not_matching_char);
}
