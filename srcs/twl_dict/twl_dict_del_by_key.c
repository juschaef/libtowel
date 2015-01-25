/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_del_by_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:47:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:36:02 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_lst.h>

void twl_dict_del_by_key(t_dict *dict, char *key, void (*delfn)())
{
	t_twl_dict_elem	*elem;

	elem = twl_dict_get_elem__(dict, key);
	twl_lst_link__(elem->prev, elem->next);
	if (!elem->prev)
		dict->head = elem->next;
	twl_lst_del_elem__(dict, elem, delfn);
}
