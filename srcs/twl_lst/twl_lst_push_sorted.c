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


#include <stdio.h>

void	twl_lst_push_sorted(t_lst *lst, void *data, int (*cmp_fn)(void *data1, void *data2))
{
	t_lst_elem__ *tmpelem;
	t_lst_elem__ *newelem;

	newelem = twl_lst_create_elem__(data);
	tmpelem = lst->head;
	if (!lst->head)
	{
		lst->head = newelem;
	}
	else if (cmp_fn(tmpelem->data, newelem->data) > 0)
	{
		twl_lst_link__(newelem, tmpelem);
		lst->head = newelem;
	}
	else
	{
		while (tmpelem->next)
		{
			if (cmp_fn(tmpelem->next->data, newelem->data) < 0)
			{
				tmpelem = tmpelem->next;
			}
			else
			{
				break;
			}
		}
		twl_lst_link3__(tmpelem, newelem, tmpelem->next);
	}
}
