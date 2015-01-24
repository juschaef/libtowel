#include "project.h"
#include <arr.h>

UT_TEST(arr_del)
{
	char **arr;
	char *str;

	arr = (char **)malloc(sizeof(char *) * 4);
	str = strdup("aaa");
	arr[0] = str;
	arr[1] = strdup("bbb");
	arr[2] = strdup("ccc");
	arr[3] = NULL;

	arr_del(arr);

	UT_ASSERT(arr[0] == NULL);
}
