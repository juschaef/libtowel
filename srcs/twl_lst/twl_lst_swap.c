/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "twl_lst.h"
#include "twl_arr.h"

static	void	lst_swap_static(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void			twl_lst_swap(t_lst *lst, int i, int j)
{
	t_lst_elem__ *elemi;
	t_lst_elem__ *elemj;

	if (i > j)
		lst_swap_static(&i, &j);
	elemj = twl_lst_popi(lst, j);
	elemi = twl_lst_popi(lst, i);
	twl_lst_insert(lst, i, elemj);
	if ((int)twl_lst_len(lst) == j)
		twl_lst_push_back(lst, elemi);
	else
		twl_lst_insert(lst, j, elemi);
}
