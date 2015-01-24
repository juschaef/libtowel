/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 15:57:05 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void	*twl_lst_reduce(t_lst *lst, void *(*fn)(void *data, void *memo), void *context)
{
	t_twl_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		context = fn(elem, context);
		elem = elem->next;
	}
	return (context);
}