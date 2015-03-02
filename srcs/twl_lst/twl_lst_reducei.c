/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_reducei.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:25:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:00:17 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

int twl_lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo)
{
	t_twl_lst_elem	*elem;

	elem = lst->head;
	while (elem)
	{
		memo = fn(elem->data, memo);
		elem = elem->next;
	}
	return (memo);
}
