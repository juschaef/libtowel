#include "twl_dict.h"
#include "project.h"

static void replace_first_letter(char *key, void *data, void *context_)
{
	char *str;

	str = data;
	*str = *key;
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
	twl_dict_iter(dict, replace_first_letter, c);

	mt_assert(strcmp(twl_dict_get(dict, "0key"), "0aa") == 0);
	mt_assert(strcmp(twl_dict_get(dict, "1key"), "1bb") == 0);
	mt_assert(strcmp(twl_dict_get(dict, "2key"), "2cc") == 0);
}

void	suite_twl_dict_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
