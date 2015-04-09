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

void	*twl_lst_reduce(t_lst *lst, void *(*fn)(void *data, void *memo),
																void *context)
{
	t_lst_elem__	*elem;

	elem = lst->head;
	while (elem)
	{
		context = fn(elem->data, context);
		elem = elem->next;
	}
	return (context);
}
