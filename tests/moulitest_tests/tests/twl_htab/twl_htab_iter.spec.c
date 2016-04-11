#include "project.h"
#include "twl_htab.h"

static void iter_fn(void *data, void *ctx)
{
	strcat(ctx, data);
}

static void simple_test(t_test *test)
{
	t_htab			*htab;
	char			ctx[100];

	bzero(ctx, 100);
	htab = twl_htab_new();
	twl_htab_set(htab, "kayA", "AAA", NULL);
	twl_htab_set(htab, "keyB", "BBB", NULL);
	twl_htab_set(htab, "keyC", "CCC", NULL);
	twl_htab_iter(htab, iter_fn, ctx);
	mt_assert(strlen(ctx) == 9);
	mt_assert(strstr(ctx, "AAA") != NULL);
	mt_assert(strstr(ctx, "BBB") != NULL);
	mt_assert(strstr(ctx, "CCC") != NULL);
	twl_htab_del(htab, NULL);
}

void	suite_twl_htab_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
