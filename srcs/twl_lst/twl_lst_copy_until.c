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

t_lst				*twl_lst_copy_until(t_lst *lst,
					void *(*copy_fn)(void *data), void *sentinel)
{
	t_lst			*lst_new;
	t_lst_elem__	*elem;

	elem = lst->head;
	lst_new = twl_lst_new();
	while (elem)
	{
		if (elem->data == sentinel)
			break ;
		if (copy_fn)
			twl_lst_push_back(lst_new, copy_fn(elem->data));
		else
			twl_lst_push_back(lst_new, elem->data);
		elem = elem->next;
	}
	(void)sentinel;
	return (lst_new);
}
