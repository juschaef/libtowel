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

void				twl_lst_iter2n(t_lst *lst,
		void (*f)(void *data, void *next, void *ctx1, void *ctx2),
		void *ctx1, void *ctx2)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	void			*next_data;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		next_data = next ? next->data : NULL;
		f(elem->data, next_data, ctx1, ctx2);
		elem = next;
	}
}
