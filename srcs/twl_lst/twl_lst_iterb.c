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
** This function iter from end to head in en Linked list
** and apply the 'f' function
*/

void				twl_lst_iterb(t_lst *lst, void (*f)(void *data,
												void *context), void *context)
{
	t_lst_elem__	*elem;

	elem = lst->head;
	while (elem)
	{
		if (!elem->next)
			break ;
		elem = elem->next;
	}
	while (elem)
	{
		f(elem->data, context);
		elem = elem->prev;
	}
}
