/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/03/09 17:37:59 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

size_t		twl_lst_count(t_lst *lst, bool (*f)(void *data, void *context),
																void *context)
{
	int				count;
	t_lst_elem__	*elem;

	count = 0;
	elem = lst->head;
	while (elem)
	{
		if (f(elem->data, context))
			count++;
		elem = elem->next;
	}
	return (count);
}
