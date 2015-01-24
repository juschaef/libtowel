/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_reducei.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 15:35:56 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int twl_lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo)
{
	t_twl_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		memo = fn(elem->data, memo);
		elem = elem->next;
	}
	return (memo);
}
