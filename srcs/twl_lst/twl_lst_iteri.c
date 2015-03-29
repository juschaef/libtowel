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
#include "twl_printf.h"

void	twl_lst_iteri(t_lst *lst, void (*iter_fn)(void *data,
									int index, void *context), void *context)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	int				index;

	elem = lst->head;
	index = 0;
	while (elem)
	{
		next = elem->next;
		iter_fn(elem->data, index, context);
		elem = next;
		index++;
	}
}
