/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 16:51:54 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

t_lst *twl_lst_copy(t_lst *lst, void *(*copy_fn)(void *data))
{
	t_lst			*lst_new;
	t_lst_elem__	*elem;

	elem = lst->head;
	lst_new = twl_lst_new();
	while (elem)
	{
		if (copy_fn)
			twl_lst_push(lst_new, copy_fn(elem->data));
		else
			twl_lst_push(lst_new, elem->data);
		elem = elem->next;
	}
	return (lst_new);
}
