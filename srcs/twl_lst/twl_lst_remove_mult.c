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

#include "twl_lst.h"

/*
** This function delete the element between begin (include) and end (exclude)
*/

void				twl_lst_remove_mult(t_lst *lst, int begin, int end,
															void (*delfn)())
{
	t_lst			*remove_lst;
	t_lst_elem__	*elem1;
	t_lst_elem__	*elem2;

	remove_lst = twl_lst_slice(lst, begin, end);
	elem2 = twl_lst_get_elem__(lst, end);
	if (begin == 0)
	{
		elem1 = NULL;
		lst->head = elem2;
	}
	else
	{
		elem1 = twl_lst_get_elem__(lst, begin - 1);
	}
	twl_lst_link__(elem1, elem2);
	twl_lst_del(remove_lst, delfn);
}
