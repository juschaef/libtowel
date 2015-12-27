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

void				twl_lst_push_back(t_lst *lst, void *data)
{
	t_lst_elem__ *tmpelem;
	t_lst_elem__ *newelem;

	newelem = twl_lst_create_elem__(data);
	if (!lst->head)
	{
		lst->head = newelem;
	}
	else
	{
		tmpelem = lst->head;
		while (tmpelem->next)
			tmpelem = tmpelem->next;
		tmpelem->next = newelem;
		twl_lst_link__(tmpelem, tmpelem->next);
	}
}
