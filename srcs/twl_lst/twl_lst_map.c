/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 15:57:41 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

t_lst		*twl_lst_map(t_lst *lst, void *(*f)(void *data))
{
	t_lst		*new_lst;
	t_twl_lst_elem	*elem;

	elem = lst->elems;
	new_lst = twl_lst_new();
	while (elem)
	{
		twl_lst_push(new_lst, f(elem->data));
		elem = elem->next;
	}
	return (new_lst);
}
