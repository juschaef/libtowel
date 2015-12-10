#include <project.h>
#include "twl_printf.h"
#include "twl_arr.h"

static void simple_trim(t_test *test)
{
	char					**segs;

	segs = twl_strsplit_trim_chars(" \t\n aaa ; \t bbb \n", ';', "\t\n ");
	mt_assert(strcmp(segs[0], "aaa") == 0);
	mt_assert(strcmp(segs[1], "bbb") == 0);
}

static void simple_trim_empty_string(t_test *test)
{
	char					**segs;

	segs = twl_strsplit_trim_chars(" \t\n ; aaa ; \t bbb \n", ';', "\t\n ");
	mt_assert(strcmp(segs[0], "") == 0);
	mt_assert(strcmp(segs[1], "aaa") == 0);
	mt_assert(strcmp(segs[2], "bbb") == 0);
}

static void if_statement_for_42sh_ast(t_test *test)
{
	char					**segs;

	segs = twl_strsplit_trim_chars("if [ 2 -eq 2 ] ; then echo YES; else echo NO ; fi ; echo abc", ';', "\t\n ");
	mt_assert(strcmp(segs[0], "if [ 2 -eq 2 ]") == 0);
	mt_assert(strcmp(segs[1], "then echo YES") == 0);
	mt_assert(strcmp(segs[2], "else echo NO") == 0);
	mt_assert(strcmp(segs[3], "fi") == 0);
	mt_assert(strcmp(segs[4], "echo abc") == 0);
}

void	suite_twl_strsplit_trim_chars(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_trim);
	SUITE_ADD_TEST(suite, simple_trim_empty_string);
	SUITE_ADD_TEST(suite, if_statement_for_42sh_ast);
}
