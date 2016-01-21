/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_printf.h"

void	twl_lst_iternp(t_lst *lst, void (*f)(void *data, void *prev_data,
		 void *next_data, void *context), void *context)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	void			*next_data;
	void			*prev_data;

	elem = lst->head;
	prev_data = NULL;
	while (elem)
	{
		next = elem->next;
		next_data = next ? next->data : NULL;
		f(elem->data, prev_data, next_data, context);
		prev_data = elem->data;
		elem = next;
	}
}
