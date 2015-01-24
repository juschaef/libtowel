#include "project.h"
#include <arr.h>

UT_TEST(arr_rev)
{
	char *arr[4];
	char **arr2;

	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	arr2 = arr_rev(arr);

	UT_ASSERT(strequ(arr2[0], "ccc"));
	UT_ASSERT(strequ(arr2[1], "bbb"));
	UT_ASSERT(strequ(arr2[2], "aaa"));
}
