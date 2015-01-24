/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 16:58:00 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_push(t_lst *lst, void *data)
{
	t_lst_elem *tmpelem;
	t_lst_elem *newelem;

	newelem = lst_create_elem_(data);
	newelem->parent = lst;
	if (!lst->elems)
	{
		lst->elems = newelem;
	}
	else
	{
		tmpelem = lst->elems;
		while (tmpelem->next)
			tmpelem = tmpelem->next;
		tmpelem->next = newelem;
		lst__link_(tmpelem, tmpelem->next);
	}
}
