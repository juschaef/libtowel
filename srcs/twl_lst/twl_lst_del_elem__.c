/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_del_elem__.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:45:12 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdlib.h>

void	twl_lst_del_elem__(t_lst *lst, t_twl_lst_elem *elem, void (*delfn)())
{
	twl_lst_link__(elem->prev, elem->next);
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
