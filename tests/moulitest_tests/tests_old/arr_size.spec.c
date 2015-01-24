#include "project.h"
#include <arr.h>

UT_TEST(arr_size)
{
	char *arr[4];
	arr[0] = strdup("aaa");
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;
	UT_ASSERT(arr_size(arr) == 3);

	char *arr2[4];
	arr2[0] = NULL;
	UT_ASSERT(arr_size(arr2) == 0);
}
