/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_iteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/03/07 14:36:19 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_printf.h"

void	twl_lst_iteri(t_lst *lst, void (*iter_fn)(void *data,
									int index, void *context), void *context)
{
	t_lst_elem		*elem;
	t_lst_elem		*next;
	int				index;

	elem = lst->head;
	index = 0;
	while (elem)
	{
		next = elem->next;
		iter_fn(elem->data, index, context);
		elem = next;
		index++;
	}
}
