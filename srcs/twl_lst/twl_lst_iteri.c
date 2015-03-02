/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_iteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 14:23:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_printf.h"

void	twl_lst_iteri(t_lst *lst, void (*f)(void *data,
									void *context, int index), void *context)
{
	t_twl_lst_elem	*elem;
	t_twl_lst_elem	*next;
	int				index;

	elem = lst->head;
	index = 0;
	while (elem)
	{
		next = elem->next;
		f(elem->data, context, index);
		elem = next;
		index++;
	}
}
