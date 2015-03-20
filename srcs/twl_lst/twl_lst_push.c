/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 11:58:59 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void	twl_lst_push(t_lst *lst, void *data)
{
	t_lst_elem__ *tmpelem;
	t_lst_elem__ *newelem;

	newelem = twl_lst_create_elem__(data);
	if (!newelem)
		return ;
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
