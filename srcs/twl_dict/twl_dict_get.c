/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:36:07 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>

void		*twl_dict_get(t_dict *dict, char *key)
{
	t_twl_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (elem->data);
		elem = elem->next;
	}
	return (NULL);
}
