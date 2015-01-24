#include "project.h"

static void *twl_lst_join(t_twl_lst_elem *elem, void *memo)
{
	memo = twl_strjoinfree(memo, elem->data, 'l');
	if (elem->next)
		memo = twl_strjoinfree(memo, ", ", 'l');
	return (memo);
}

static void *sum(t_twl_lst_elem *elem, void *memo)
{
	*(int *)memo = *(int *)elem->data + *(int *)memo;
	return (memo);
}

UT_TEST(twl_lst_reduce)
{
	t_lst	*lst;
	lst = twl_lst_init();
	int memo = 0;
	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 3;
	int nbr4 = 4;

	twl_lst_push(lst, twl_lst_create_elem(&nbr1));
	twl_lst_push(lst, twl_lst_create_elem(&nbr2));
	twl_lst_push(lst, twl_lst_create_elem(&nbr3));
	twl_lst_push(lst, twl_lst_create_elem(&nbr4));

	twl_lst_reduce(lst, sum, &memo);
	UT_ASSERT(memo == 10);
	free(lst);

	lst = twl_lst_init();
	char *str1 = "pomme";
	char *str2 = "jambon";
	char *str3 = "carrote";
	char *str4 = "beurre";
	char *output = strdup("");

	twl_lst_push(lst, twl_lst_create_elem(str1));
	twl_lst_push(lst, twl_lst_create_elem(str2));
	twl_lst_push(lst, twl_lst_create_elem(str3));
	twl_lst_push(lst, twl_lst_create_elem(str4));

	output = twl_lst_reduce(lst, twl_lst_join, output);
	UT_ASSERT(strcmp(output, "pomme, jambon, carrote, beurre") == 0);
	free(lst);
	free(output);
}
