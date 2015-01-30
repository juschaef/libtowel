/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 23:55:58 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include "twl_printf.h"

void	twl_lst_filter(t_lst *lst, t_bool (*filter_fn)(void *data, void *context),
											void *context, void (*delfn)(void *))
{
	t_twl_lst_elem	*elem;
	t_twl_lst_elem	*next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		if (!filter_fn(elem->data, context))
			twl_lst_del_elem__(lst, elem, delfn);
		elem = next;
	}
}
