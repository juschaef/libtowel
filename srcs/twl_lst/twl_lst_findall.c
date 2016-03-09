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

t_lst				*twl_lst_findall(t_lst *lst, bool (*iter_fn)(void *data,
												void *context), void *context)
{
	t_lst_elem__	*elem;
	t_lst			*new_lst;

	new_lst = twl_lst_new();
	elem = lst->head;
	while (elem)
	{
		if (iter_fn(elem->data, context))
			twl_lst_push_back(new_lst, elem->data);
		elem = elem->next;
	}
	return (new_lst);
}
