#include "project.h"
#include "twl_htab.h"
#include "twl_xstring.h"

static int del_counter;

static void delfn(void *data)
{
	del_counter++;
	free(data);
}

static void simple_test(t_test *test)
{
	t_htab			*htab;

	htab = twl_htab_new();
	mt_assert(twl_htab_get_size(htab) == 0);
	twl_htab_set(htab, "kayA", twl_strdup("AAA"), delfn);
	twl_htab_set(htab, "keyB", twl_strdup("BBB"), delfn);
	twl_htab_set(htab, "keyC", twl_strdup("CCC"), delfn);
	del_counter = 0;
	twl_htab_del(htab, delfn);
	mt_assert(del_counter == 3);
}

void	suite_twl_htab_del(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
