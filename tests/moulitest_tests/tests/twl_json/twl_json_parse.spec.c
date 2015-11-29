#include <project.h>
#include "twl_json.h"

static void test_array_of_bool(t_test *test)
{
	char			json_str[] = "[true,false]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_two_levels_array(t_test *test)
{
	char			json_str[] = "[[true],false]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_array_of_numbers(t_test *test)
{
	char			json_str[] = "[[21],42]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

static void test_null(t_test *test)
{
	char			json_str[] = "[null,42]";
	t_jnode			*node;
	char			*json_dump_res;

	node = twl_json_parse(json_str);
	json_dump_res = twl_json_dump(node);
	mt_assert(node && twl_strcmp(json_dump_res, json_str) == 0);

	twl_jnode_del(node);
}

void	suite_twl_json_parse(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_array_of_bool);
	SUITE_ADD_TEST(suite, test_two_levels_array);
	SUITE_ADD_TEST(suite, test_array_of_numbers);
	SUITE_ADD_TEST(suite, test_null);
}
