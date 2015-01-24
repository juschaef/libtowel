#include <project.h>
#include <arr.h>

#define FILE 1
#define DIR 2


int get_item_order(char *path)
{
	if (*path == 'f')
		return FILE;
	else
		return DIR;
}

 bool 		arr_sort_obj_type_should_swap(void *item1, void *item2, void *context)
{
	char *s1 = item1;
	char *s2 = item2;
	(void)context;
	return (get_item_order(s1) < get_item_order(s2));
}

 bool 		arr_sort_ft_strcmp_should_swap(void *str1, void *str2, void *context)
{
	char *s1;
	char *s2;

	s1 = str1;
	s2 = str2;
	s1 += 2;
	s2 += 2;
	(void)context;
	return (ft_strcmp(s1, s2) < 0);
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

	arr = arr_init(99);
	arr_push(arr, strdup("d_zzz"));
	arr_push(arr, strdup("d_ccc"));
	arr_push(arr, strdup("d_www"));
	arr_push(arr, strdup("f_bbb"));
	arr_push(arr, strdup("f_ccc"));
	arr_push(arr, strdup("f_bbb"));
	arr_push(arr, strdup("d_aaa"));
	arr_push(arr, strdup("f_aaa"));
	arr_push(arr, strdup("f_ccc"));
	arr_push(arr, strdup("f_bbb"));
	arr_push(arr, strdup("f_zaa"));
	arr_push(arr, strdup("f_zcc"));
	arr_push(arr, strdup("f_zbb"));
	arr_push(arr, strdup("d_bbb"));

	arr_sort(arr, arr_sort_ft_strcmp_should_swap, NULL);
	arr_sort(arr, arr_sort_obj_type_should_swap, NULL);
	// arr_iter(arr, iter_fn, NULL);

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

void	suite_arr_sort(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
