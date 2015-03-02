#include "project.h"
#include "twl_arr.h"

UT_TEST(twl_arr_rev)
{
	char *arr[4];
	char **arr2;

	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	arr2 = twl_arr_rev(arr);

	UT_ASSERT(strequ(arr2[0], "ccc"));
	UT_ASSERT(strequ(arr2[1], "bbb"));
	UT_ASSERT(strequ(arr2[2], "aaa"));
}
