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
