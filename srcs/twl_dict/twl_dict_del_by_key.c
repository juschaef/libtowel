/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_del_by_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:47:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 19:48:57 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_lst.h>

void twl_dict_del_by_key(t_lst *lst, char *key, void (*delfn)())
{
	t_twl_lst_elem	*elem;

	elem = twl_dict_get_elem(lst, key);
	twl_lst__link_(elem->prev, elem->next);
	if (!elem->prev)
		lst->elems = elem->next;
	twl_lstelem_del(elem, delfn);
}
