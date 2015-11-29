#include "twl_dict.h"
#include "project.h"

static void replace_first_letter(char *key, void *data, void *next_, void *context_)
{
	char *str;
	char *next;

	str = data;
	*str = *key;
	next = next_;
	if (next)
		str[1] = next[1];
	else
		str[1] = '.';
	(void)context_;
}

static void simple_test(t_test *test)
{
	t_dict	*dict;
	dict = twl_dict_new();

	twl_dict_add(dict, "0key", strdup("aaa"));
	twl_dict_add(dict, "1key", strdup("bbb"));
	twl_dict_add(dict, "2key", strdup("ccc"));

	char *c = "z";
	twl_dict_itern(dict, replace_first_letter, c);

	mt_assert(strcmp(twl_dict_get(dict, "0key"), "0ba") == 0);
	mt_assert(strcmp(twl_dict_get(dict, "1key"), "1cb") == 0);
	mt_assert(strcmp(twl_dict_get(dict, "2key"), "2.c") == 0);
}

void	suite_twl_dict_itern(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
