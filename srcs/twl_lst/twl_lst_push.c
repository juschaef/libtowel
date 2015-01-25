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
	t_twl_lst_elem *tmpelem;
	t_twl_lst_elem *newelem;

	newelem = twl_lst_create_elem_(data);
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
		twl_lst_link_(tmpelem, tmpelem->next);
	}
}
