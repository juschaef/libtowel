/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/01/31 19:07:57 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <twl_lst.h>
#include <twl_arr.h>
#include <stdlib.h>

static void 	swap_elems_directions(t_twl_lst_elem *elem)
{
	t_twl_lst_elem *tmp_elem;

	tmp_elem = elem->next;
	elem->next = elem->prev;
	elem->prev = tmp_elem;
}

void			twl_lst_rev(t_lst *lst)
{
	t_twl_lst_elem *elem;
	t_twl_lst_elem *tmp_elem;

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
