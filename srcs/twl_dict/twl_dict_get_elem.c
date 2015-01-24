/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_get_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:21:39 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>

t_twl_lst_elem		*twl_dict_get_elem(t_lst *lst, char *key)
{
	t_twl_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
