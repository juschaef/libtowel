/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 17:19:38 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "ft_printf.h"

void	lst_iter(t_lst *lst, void (*f)(void *data, void *context), void *context)
{
	t_lst_elem	*elem;
	t_lst_elem	*next;

	elem = lst->elems;
	while (elem)
	{
		next = elem->next;
		f(elem->data, context);
		elem = next;
	}
}
