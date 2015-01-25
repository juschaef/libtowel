#include <project.h>
#include <twl_arr.h>

#define FILE 1
#define DIR 2


int get_item_order(char *path)
{
	if (*path == 'f')
		return FILE;
	else
		return DIR;
}

 bool 		twl_arr_sort_obj_type_should_swap(void *item1, void *item2, void *context)
{
	char *s1 = item1;
	char *s2 = item2;
	(void)context;
	return (get_item_order(s1) < get_item_order(s2));
}

 bool 		twl_arr_sort_twl_strcmp_should_swap(void *str1, void *str2, void *context)
{
	char *s1;
	char *s2;

	s1 = str1;
	s2 = str2;
	s1 += 2;
	s2 += 2;
	(void)context;
	return (strcmp(s1, s2) < 0);
}
/*
static void iter_fn(void *elem, void *context)
{
	char *str;

	str = elem;
	printf("%s\n", str);
	(void)context;
}
*/
static void simple_test(t_test *test)
{
	char **arr;

	arr = twl_arr_new(99);
	twl_arr_push(arr, strdup("d_zzz"));
	twl_arr_push(arr, strdup("d_ccc"));
	twl_arr_push(arr, strdup("d_www"));
	twl_arr_push(arr, strdup("f_bbb"));
	twl_arr_push(arr, strdup("f_ccc"));
	twl_arr_push(arr, strdup("f_bbb"));
	twl_arr_push(arr, strdup("d_aaa"));
	twl_arr_push(arr, strdup("f_aaa"));
	twl_arr_push(arr, strdup("f_ccc"));
	twl_arr_push(arr, strdup("f_bbb"));
	twl_arr_push(arr, strdup("f_zaa"));
	twl_arr_push(arr, strdup("f_zcc"));
	twl_arr_push(arr, strdup("f_zbb"));
	twl_arr_push(arr, strdup("d_bbb"));

	twl_arr_sort(arr, twl_arr_sort_twl_strcmp_should_swap, NULL);
	twl_arr_sort(arr, twl_arr_sort_obj_type_should_swap, NULL);
	// twl_arr_iter(arr, iter_fn, NULL);

	int i = 0;
	mt_assert(strcmp(arr[i++], "f_aaa") == 0);
	mt_assert(strcmp(arr[i++], "f_bbb") == 0);
	mt_assert(strcmp(arr[i++], "f_bbb") == 0);
	mt_assert(strcmp(arr[i++], "f_bbb") == 0);
	mt_assert(strcmp(arr[i++], "f_ccc") == 0);
	mt_assert(strcmp(arr[i++], "f_ccc") == 0);
	mt_assert(strcmp(arr[i++], "f_zaa") == 0);
	mt_assert(strcmp(arr[i++], "f_zbb") == 0);
	mt_assert(strcmp(arr[i++], "f_zcc") == 0);
	mt_assert(strcmp(arr[i++], "d_aaa") == 0);
	mt_assert(strcmp(arr[i++], "d_bbb") == 0);
	mt_assert(strcmp(arr[i++], "d_ccc") == 0);
	mt_assert(strcmp(arr[i++], "d_www") == 0);
	mt_assert(strcmp(arr[i++], "d_zzz") == 0);
}

void	suite_twl_arr_sort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
