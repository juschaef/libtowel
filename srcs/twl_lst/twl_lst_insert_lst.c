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
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

void	twl_lst_insert_lst(t_lst *lst_dest, int index, t_lst *lst_src)
{
	t_lst_elem__ *elem1;
	t_lst_elem__ *elem2;

	elem1 = twl_lst_get_elem__(lst_dest, index);
	elem2 = elem1->prev;
	if (index == 0)
		lst_dest->head = lst_src->head;
	else if (index >= (int)twl_lst_len(lst_dest))
		twl_putstr_fd("\n[warning] Index does not exist !\n", 2);
	else
		twl_lst_link__(elem2, lst_src->head);
	twl_lst_link__(twl_lst_get_elem__(lst_src, -1), elem1);
}
