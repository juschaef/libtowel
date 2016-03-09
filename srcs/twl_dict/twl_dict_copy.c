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
#include "twl_dict.h"

t_lst				*twl_dict_copy(t_dict *dict, void *(*copy_fn)(void *data))
{
	t_lst			*new;
	t_lst_elem__	*elem;

	elem = dict->head;
	new = twl_dict_new();
	while (elem)
	{
		if (copy_fn)
			twl_dict_add(new, elem->key, copy_fn(elem->data));
		else
			twl_dict_add(new, elem->key, elem->data);
		elem = elem->next;
	}
	return (new);
}
