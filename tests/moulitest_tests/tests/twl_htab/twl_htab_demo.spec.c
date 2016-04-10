#include "project.h"
#include "twl_htab.h"
#include "twl_xstring.h"

static void del_data_fn(void *data)
{
	// any fancy del function
	free(data);
}

static void demo1(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	/* If neede you can set your own functions for
		htab->compare_fn = default_compare;
		htab->hash_fn = default_hash;
		htab->copy_key_fn = default_copy_key;
		The default funciton are in `twl_htab_new.c`
	*/

	twl_htab_set(htab, "keyA", twl_strdup("AAA"), del_data_fn);
	twl_htab_set(htab, "keyB", twl_strdup("BBB"), del_data_fn);
	twl_htab_set(htab, "keyC", twl_strdup("CCC"), del_data_fn);

	/* check initial data */
	mt_assert(twl_strcmp(twl_htab_get(htab, "keyA"), "AAA") == 0);
	mt_assert(twl_strcmp(twl_htab_get(htab, "keyB"), "BBB") == 0);
	mt_assert(twl_strcmp(twl_htab_get(htab, "keyC"), "CCC") == 0);
	mt_assert(twl_htab_len(htab) == 3);

	/* set to replace a value */
	twl_htab_set(htab, "keyA", twl_strdup("AAA1"), del_data_fn);
	mt_assert(twl_strcmp(twl_htab_get(htab, "keyA"), "AAA1") == 0);
	mt_assert(twl_htab_len(htab) == 3);

	twl_htab_del(htab, del_data_fn);
}

void	suite_twl_htab_demo(t_suite *suite)
{
	SUITE_ADD_TEST(suite, demo1);
}
