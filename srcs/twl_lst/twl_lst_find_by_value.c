/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_find_by_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/23 17:21:24 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void		*twl_lst_find_by_value(t_lst *lst, int (*f)(void *data, void *value), void *value)
{
	t_twl_lst_elem	*elem;

	elem = lst->head;
	while (elem)
	{
		if (f(elem->data, value))
			return (elem->data);
		elem = elem->next;
	}
	return (NULL);
}
