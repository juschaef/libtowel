/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_indexof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:04:45 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/30 15:50:54 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

int		twl_lst_indexof(t_lst *lst, void *target, int (*cmp_fn)())
{
	t_lst_elem		*elem;
	int				i;

	elem = lst->head;
	i = 0;
	while (elem)
	{
		if (cmp_fn(elem->data, target))
			return (i);
		elem = elem->next;
		i++;
	}
	return (-1);
}
