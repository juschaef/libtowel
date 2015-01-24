#include "project.h"

static void *lst_join(t_lst_elem *elem, void *memo)
{
	memo = ft_strjoinfree(memo, elem->data, 'l');
	if (elem->next)
		memo = ft_strjoinfree(memo, ", ", 'l');
	return (memo);
}

static void *sum(t_lst_elem *elem, void *memo)
{
	*(int *)memo = *(int *)elem->data + *(int *)memo;
	return (memo);
}

UT_TEST(lst_reduce)
{
	t_lst	*lst;
	lst = lst_init();
	int memo = 0;
	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 3;
	int nbr4 = 4;

	lst_push(lst, lst_create_elem(&nbr1));
	lst_push(lst, lst_create_elem(&nbr2));
	lst_push(lst, lst_create_elem(&nbr3));
	lst_push(lst, lst_create_elem(&nbr4));

	lst_reduce(lst, sum, &memo);
	UT_ASSERT(memo == 10);
	free(lst);

	lst = lst_init();
	char *str1 = "pomme";
	char *str2 = "jambon";
	char *str3 = "carrote";
	char *str4 = "beurre";
	char *output = strdup("");

	lst_push(lst, lst_create_elem(str1));
	lst_push(lst, lst_create_elem(str2));
	lst_push(lst, lst_create_elem(str3));
	lst_push(lst, lst_create_elem(str4));

	output = lst_reduce(lst, lst_join, output);
	UT_ASSERT(strcmp(output, "pomme, jambon, carrote, beurre") == 0);
	free(lst);
	free(output);
}
