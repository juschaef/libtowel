#include "project.h"
#include "twl_htab.h"

static void simple_test(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	twl_htab_set(htab, "kayA", "AAA", NULL);
	twl_htab_set(htab, "keyB", "BBB", NULL);
	mt_assert(strcmp(twl_htab_get(htab, "kayA"), "AAA") == 0);
	mt_assert(strcmp(twl_htab_get(htab, "keyB"), "BBB") == 0);
	twl_htab_del(htab, NULL);
}

static void test_not_exist(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	twl_htab_set(htab, "kayA", "AAA", NULL);
	twl_htab_set(htab, "keyB", "BBB", NULL);
	mt_assert(twl_htab_get(htab, "kayZ") == NULL);
	twl_htab_del(htab, NULL);
}

void	suite_twl_htab_set(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_not_exist);
}
