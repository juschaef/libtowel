#include "project.h"
#include "twl_htab.h"

static void simple_test(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	mt_assert(twl_htab_len(htab) == 0);
	twl_htab_set(htab, "kayA", "AAA", NULL);
	twl_htab_set(htab, "keyB", "BBB", NULL);
	twl_htab_set(htab, "keyC", "CCC", NULL);
	mt_assert(twl_htab_len(htab) == 3);
	twl_htab_del(htab, NULL);
}

static void test_set_multiple_times(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	mt_assert(twl_htab_len(htab) == 0);
	twl_htab_set(htab, "kayA", "AAA1", NULL);
	twl_htab_set(htab, "kayA", "AAA2", NULL);
	twl_htab_set(htab, "kayA", "AAA3", NULL);
	twl_htab_set(htab, "keyB", "BBB", NULL);
	twl_htab_set(htab, "keyC", "BBB", NULL);
	twl_htab_set(htab, "keyD", "BBB", NULL);
	mt_assert(twl_htab_len(htab) == 4);
	twl_htab_del(htab, NULL);
}

void	suite_twl_htab_len(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_set_multiple_times);
}
