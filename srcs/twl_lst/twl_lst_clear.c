/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_clear__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:23:44 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/25 14:56:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdlib.h>

static void	del_elem_without_link(t_twl_lst_elem *elem, void (*delfn)())
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

void	twl_lst_clear__(t_lst *lst, void (*delfn)())
{
	twl_lst_iter_elem__(lst, (void *)del_elem_without_link, delfn);
	lst->head = NULL;
}
