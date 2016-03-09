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

t_lst		*twl_lst_map(t_lst *lst, void *(*f)(void *data))
{
	t_lst			*new_lst;
	t_lst_elem__	*elem;

	elem = lst->head;
	new_lst = twl_lst_new();
	while (elem)
	{
		twl_lst_push_back(new_lst, f(elem->data));
		elem = elem->next;
	}
	return (new_lst);
}
