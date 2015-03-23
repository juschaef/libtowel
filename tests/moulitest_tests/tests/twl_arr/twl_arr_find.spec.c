#include <project.h>
#include "twl_arr.h"
#include "twl_xstring.h"

static bool			find_fn(void *str, void *key)
{
	if (twl_strequ(str, key))
		return (1);
	return (0);
}

static void			simple_test(t_test *test)
{
	char			*arr[4];

	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	char *find;

	find = twl_arr_find(arr, find_fn, "ccc");
	mt_assert(strcmp(find, "ccc") == 0);
}

void	suite_twl_arr_find(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
