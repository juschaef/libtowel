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

size_t		twl_lst_count(t_lst *lst, bool (*f)(void *data, void *context),
																void *context)
{
	int				count;
	t_lst_elem__	*elem;

	count = 0;
	elem = lst->head;
	while (elem)
	{
		if (f(elem->data, context))
			count++;
		elem = elem->next;
	}
	return (count);
}
