/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_clear__.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:23:44 by annguyen          #+#    #+#             */
/*   Updated: 2015/03/02 11:47:13 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"

static void		del_elem_without_link(t_lst_elem__ *elem, void (*delfn)())
{
	if (delfn)
		delfn(elem->data);
	if (elem->key)
		free(elem->key);
	elem->data = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	elem->key = NULL;
}

void			twl_lst_clear__(t_lst *lst, void (*delfn)())
{
	twl_lst_iter_elem__(lst, (void *)del_elem_without_link, delfn);
	lst->head = NULL;
}
