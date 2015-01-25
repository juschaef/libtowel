/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_del_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 11:58:52 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include <stdlib.h>

void	twl_lst_del_elem(t_lst *lst, int index, void (*delfn)())
{
	t_twl_lst_elem *elem;

	elem = twl_lst_get_(lst, index);
	twl_lst_link_(elem->prev, elem->next);
	if (!elem->prev)
		lst->head = elem->next;
	if (delfn)
		delfn(elem->data);
	if (elem->key)
		free(elem->key);
	elem->data = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	elem->key = NULL;
	free(elem);
	(void)lst;
}
