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
#include "twl_lst.h"

static void			del_elem_without_link(t_lst_elem__ *elem, void (*delfn)())
{
	if (delfn)
		delfn(elem->data);
	if (elem->key)
		free(elem->key);
	elem->data = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	elem->key = NULL;
	free(elem);
}

void				twl_lst_clear(t_lst *lst, void (*delfn)())
{
	twl_lst_iter_elem__(lst, (void *)del_elem_without_link, delfn);
	lst->head = NULL;
}
