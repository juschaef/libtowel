/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_del_by_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:47:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:59:20 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_dict.h"
#include "twl_lst.h"

void	twl_dict_delone(t_dict *dict, char *key, void (*delfn)())
{
	t_dict_elem	*elem;

	elem = twl_dict_get_elem__(dict, key);
	twl_lst_link__(elem->prev, elem->next);
	if (!elem->prev)
		dict->head = elem->next;
	twl_lst_del_elem__(dict, elem, delfn);
}
