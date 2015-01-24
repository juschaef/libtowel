#include <project.h>
#include <twl_str.h>

static void simple_test(t_test *test)
{
	char s[] = "jambonbon";
	char *out;

	out = twl_str_replace(s, "bon", "bas");
	mt_assert(strcmp(out, "jambasbas") == 0);
}

static void empty_string(t_test *test)
{
	char s[] = "";
	char *out;

	out = twl_str_replace(s, "bon", "bas");
	mt_assert(strcmp(out, "") == 0);
}


static void multiple_replacements(t_test *test)
{
	char s[] = "aaabbbcccaaabbbccc111222333111222333";
	char *out;

	out = twl_str_replace(s, "aaa", "xxx");
	out = twl_str_replace(out, "bbb", "www");
	out = twl_str_replace(out, "111", "888");
	out = twl_str_replace(out, "333", "999");
	mt_assert(strcmp(out, "xxxwwwcccxxxwwwccc888222999888222999") == 0);
}

void	suite_twl_str_replace(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, multiple_replacements);
}
