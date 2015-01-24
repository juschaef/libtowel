/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldict_del_by_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:47:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 17:42:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_lst.h>

void ldict_del_elem(t_lst *lst, char *key, void (*delfn)())
{
	t_twl_lst_elem	*elem;

	elem = ldict_get(lst, key);
	lstelem_del(elem, delfn);
}
