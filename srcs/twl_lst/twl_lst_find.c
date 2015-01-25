/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:51:42 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/25 19:52:41 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>

void		*twl_lst_find(t_lst *lst, t_twl_iter_fn *iter_fn, void *context)
{
	t_twl_lst_elem	*elem;

	elem = lst->head;
	while (elem)
	{
		if (iter_fn(elem->data, context) != NULL)
			return (elem->data);
		elem = elem->next;
	}
	return (NULL);
}
