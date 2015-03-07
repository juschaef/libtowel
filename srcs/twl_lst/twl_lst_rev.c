/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/02/02 17:48:29 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_string.h"
#include "twl_lst.h"
#include "twl_arr.h"

static void		swap_elems_directions(t_lst_elem__ *elem)
{
	t_lst_elem__ *tmp_elem;

	tmp_elem = elem->next;
	elem->next = elem->prev;
	elem->prev = tmp_elem;
}

void			twl_lst_rev(t_lst *lst)
{
	t_lst_elem__ *elem;
	t_lst_elem__ *tmp_elem;

	elem = lst->head;
	while (elem)
	{
		tmp_elem = elem->next;
		swap_elems_directions(elem);
		if (!tmp_elem)
			lst->head = elem;
		elem = tmp_elem;
	}
}
