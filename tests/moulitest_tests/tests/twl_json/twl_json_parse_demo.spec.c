#include <project.h>
#include "twl_json.h"

static void demo_parser(t_test *test)
{
	char			json_str[] = "{ \"name\" : \"Jack\", \"age\" : 27 }";
	t_jnode			*jack;

	jack = twl_json_parse(json_str);

	mt_assert(jack->type == JSON_OBJECT);

	t_jnode			*jack_name = twl_jnode_object_get(jack, "name");
	mt_assert(jack_name->type == JSON_STRING);
	mt_assert(strcmp(twl_jnode_get_string(jack_name), "Jack") == 0);

	t_jnode			*jack_age = twl_jnode_object_get(jack, "age");
	mt_assert(jack_age->type == JSON_NUMBER);
	mt_assert(twl_jnode_get_primitive(jack_age) == 27);

	twl_jnode_del(jack);
}

static void demo_parser_mixt_array(t_test *test)
{
	char			json_str[] = "[\"cat\", 42, true, false, null]";
	t_jnode			*list;

	list = twl_json_parse(json_str);

	mt_assert(list->type == JSON_ARRAY);

	t_jnode			*cat = twl_jnode_array_get(list, 0);
	mt_assert(cat->type == JSON_STRING);
	mt_assert(strcmp(twl_jnode_get_string(cat), "cat") == 0);

	t_jnode			*num42 = twl_jnode_array_get(list, 1);
	mt_assert(num42->type == JSON_NUMBER);
	mt_assert(twl_jnode_get_primitive(num42) == 42);

	t_jnode			*mybool = twl_jnode_array_get(list, 2);
	mt_assert(mybool->type == JSON_BOOL);
	mt_assert(twl_jnode_get_primitive(mybool) == true);

	t_jnode			*mybool2 = twl_jnode_array_get(list, 3);
	mt_assert(mybool2->type == JSON_BOOL);
	mt_assert(twl_jnode_get_primitive(mybool2) == false);

	t_jnode			*mynull = twl_jnode_array_get(list, 4);
	mt_assert(mynull->type == JSON_NULL);

	twl_jnode_del(list);
}

void	suite_twl_json_parse_demo(t_suite *suite)
{
	SUITE_ADD_TEST(suite, demo_parser);
	SUITE_ADD_TEST(suite, demo_parser_mixt_array);
}
