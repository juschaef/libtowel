/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_iter_elem_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:54:56 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_printf.h"

void	twl_lst_iter_elem__(t_lst *lst,
				void (*f)(t_twl_lst_elem *elem, void *context), void *context)
{
	t_twl_lst_elem	*elem;
	t_twl_lst_elem	*next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		f(elem, context);
		elem = next;
	}
}
